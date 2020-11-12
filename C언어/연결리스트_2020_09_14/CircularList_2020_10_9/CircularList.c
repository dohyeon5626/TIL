#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

void InitList(List* plist) { //����Ʈ�� �ʱ�ȭ
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

void LInsert(List* plist, Ldata pdata) { //�ڷ� ����
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

int LFirst(List* plist, Ldata pdata) { //ù �ڷᰡ �ִ°�?
	if (LCount(plist)) {
		plist->Before = plist->Tail;
		plist->Cur = plist->Tail->Next;
		pdata->Item = plist->Cur->Item;
		return 1; //ù �ڷ� ����
	}
	return 0; //����� �ڷᰡ ����
}

int LNext(List* plist, Ldata pdata) { //���� �ڷᰡ �ִ°�?
	if (plist->Cur->Next) {
		plist->Before = plist->Cur;
		plist->Cur = plist->Cur->Next;
		pdata->Item = plist->Cur->Item;
		return 1; //���� �ڷ� ����
	}
	return 0; //���� �ڷ� ����
}

Ldata LRemove(List* plist) { //�ڷ� ����
	if (LCount(plist)) {
		Ldata rpos = plist->Cur; //������ ��ġ
		printf("[%c] ", rpos->Item);
		if (rpos == plist->Tail) plist->Tail = plist->Before;
		plist->Before->Next = rpos->Next;
		plist->Cur = plist->Before; //������ ���� CurrentPosition
		plist->NumOfData--; //�ڷ� ���� ����
		return rpos; //������ �ڷ� ��ȯ
	}
}

void SetSortRule(List* plist, int (*comp)(Ldata, Ldata)) {
	plist->func = comp;
}

int LCount(List* plist) {
	return plist->NumOfData;
}