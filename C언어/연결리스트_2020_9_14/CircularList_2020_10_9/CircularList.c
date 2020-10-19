#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

void InitList(List* plist) { //리스트의 초기화
	plist->Tail = NULL;
	plist->Before = NULL;
	plist->Cur = NULL;
	plist->NumOfData = 0;
	plist->func = NULL;
}

void PrintNode(Ldata pnode) {
	printf("%c ", pnode->Item);
}

void LPrint(List* plist) {
	int last = LCount(plist), b;
	if (last) {
		Ldata pdata = plist->Tail->Next;
		for (b = 0; b < last; b++, pdata = pdata->Next) {
			PrintNode(pdata);
		} printf("\n");
	}
}

void SInsert(List* plist, Ldata pdata) {
	Ldata Before = plist->Tail;
	if (plist->func(Before, pdata)) {
		while (plist->func(pdata, Before->Next))
			Before = Before->Next;
		pdata->Next = Before->Next; Before->Next = pdata;
	}
	else {
		pdata->Next = Before->Next; Before->Next = pdata; plist->Tail = pdata;
	}
}

void LInsert(List* plist, Ldata pdata) { //자료 삽입
	if (plist->Tail) {
		if (plist->func)
			SInsert(plist, pdata);
		else {
			pdata->Next = plist->Tail->Next;
			plist->Tail->Next = pdata;
			plist->Tail = pdata;
		}
	}
	else {
		plist->Tail = pdata;
		pdata->Next = pdata;
	}
	plist->NumOfData++;
}

int LFirst(List* plist, Ldata pdata) { //첫 자료가 있는가?
	if (LCount(plist)) {
		plist->Before = plist->Tail;
		plist->Cur = plist->Tail->Next;
		pdata->Item = plist->Cur->Item;
		return 1; //첫 자료 있음
	}
	return 0; //저장된 자료가 없음
}

int LNext(List* plist, Ldata pdata) { //다음 자료가 있는가?
	if (plist->Cur->Next) {
		plist->Before = plist->Cur;
		plist->Cur = plist->Cur->Next;
		pdata->Item = plist->Cur->Item;
		return 1; //다음 자료 있음
	}
	return 0; //다음 자료 없음
}

Ldata LRemove(List* plist) { //자료 삭제
	if (LCount(plist)) {
		Ldata rpos = plist->Cur; //삭제할 위치
		printf("[%c] ", rpos->Item);
		if (rpos == plist->Tail) plist->Tail = plist->Before;
		plist->Before->Next = rpos->Next;
		plist->Cur = plist->Before; //삭제한 후의 CurrentPosition
		plist->NumOfData--; //자료 개수 감소
		return rpos; //삭제된 자료 반환
	}
}

void SetSortRule(List* plist, int (*comp)(Ldata, Ldata)) {
	plist->func = comp;
}

int LCount(List* plist) {
	return plist->NumOfData;
}