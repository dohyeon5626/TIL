#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Score_NodePointList.h"

void SetSortRule(List* plist, int (*comp)(Ldata, Ldata)) {
	plist->comp = comp;
}

void InitList(List* plist) {
	Ldata Head = (Point*)malloc(sizeof(Point));
	plist->Head = Head;
	plist->Head->Next = NULL;
	plist->NumOfData = 0;
	plist->comp = NULL;
}

void PNode(Ldata pnode) {
	printf("|%3c   |%3d %5d %5d %5d %5d", pnode->name,pnode->x1, pnode->x2, pnode->x3, pnode->x4, pnode->sum);
}

void Lprint(List* plist) {
	Ldata pdata = plist->Head->Next;
	int i= 0;
	while (pdata) {
		i++;
		PNode(pdata);
		printf("%6d  |",i);
		if (pdata->Next != NULL) {
			printf("\n");
		}
		pdata = pdata->Next;
	}printf("\n");
}

void LInsert(List* plist, Ldata pdata) {
	if (plist->comp)
	{
		SInsert(plist, pdata);
	}
	else {
		pdata->Next = plist->Head->Next;
		plist->Head->Next = pdata;
	}
	plist->NumOfData++;
}

void SInsert(List* plist, Ldata pdata) {
	Ldata Before = plist->Head;
	while (Before->Next && plist->comp(pdata, Before->Next)) {
		Before = Before->Next;
	}
	pdata->Next = Before->Next;
	Before->Next = pdata;
}

void OverlapLprint(List* plist) {
	Ldata pdata = plist->Head->Next;
	int i = 0;
	int erst=-1;
	while (pdata) {
		i++;
		if (pdata->sum!=erst) {
			printf("\n");
			PNode(pdata);
			printf("%6d  |", i);
			erst = pdata->sum;
		}
		pdata = pdata->Next;
	}
}