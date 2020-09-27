#ifndef _NODEPOINT_LIST_H_
#define _NODEPOINT_LIST_H_

typedef struct _point {
	char name;
	int x1, x2, x3, x4, sum;
	struct _point* Next;
}Point;

typedef Point* Ldata;

typedef struct _pointlist {
	Ldata Head, Before, Cur;
	int NumOfData;
	int (*comp)(Ldata, Ldata);
}PointList;

typedef PointList List;

void InitList(List*);
void Linsert(List*, Ldata);
int LFirst(List*, Ldata);
int LNext(List*, Ldata);
Ldata LRemove(List*);
void Lprint(List*);
void OverlapLprint(List*);
void SetSortRule(List*, int (*comp)(Ldata, Ldata));
void LInsert(List* plist, Ldata pdata);
void SInsert(List* plist, Ldata pdata);
#endif