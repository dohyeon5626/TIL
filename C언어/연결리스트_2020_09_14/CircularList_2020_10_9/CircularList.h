#ifndef _CIRCULAR_H_
#define _CIRCULAR_H_

typedef struct _node {
	char Item;
	struct _node* Next;
} Node;

typedef Node* Ldata;

typedef struct _list {
	Ldata Tail;
	Ldata Before;
	Ldata Cur;
	int NumOfData;
	int (*func)(Ldata, Ldata);
} List;

void InitList(List*);
void LInsert(List*, Ldata);
int LFirst(List*, Ldata);
int LNext(List*, Ldata);
Ldata LRemove(List*);
void LPrint(List*);
int LCount(List*);
void SetSortRule(List*, int (*comp)(Ldata, Ldata));

#endif#pragma once
