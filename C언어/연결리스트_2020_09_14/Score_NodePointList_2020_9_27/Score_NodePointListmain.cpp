#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Score_NodePointList.h"

Ldata NewPoint(char name, int x1, int x2, int x3, int x4) {
	Ldata Npoint = (Point*)malloc(sizeof(Point));
	Npoint->x1 = x1;
	Npoint->x2 = x2;
	Npoint->x3 = x3;
	Npoint->x4 = x4;
	Npoint->sum = x1+x2+x3+x4;
	Npoint->name = name;
	Npoint->Next = NULL;
	return Npoint;
}

int WholsPred(Ldata d1, Ldata d2) {
	if (d1->sum > d2->sum)return 0;
	else return 1;
}

int main(void) {
	List* MyList = (List*)malloc(sizeof(List));
	InitList(MyList);
	int a;
	SetSortRule(MyList, WholsPred);
	int x1, x2, x3, x4;
	char name;
	for (a = 0; a <= 9; a++) {
		scanf("%c %d %d %d %d", &name, &x1, &x2, &x3, &x4);
		while (getchar() != '\n');
		LInsert(MyList, NewPoint(name, x1, x2, x3, x4));
	}
	printf("\n+------+-----<중복 제거 전 명단>-----+-----+\n");
	printf("| name | Kor | Eng | Mat | Com | Sum | Rnk |\n");
	printf("+------+-----+-----+-----+-----+-----+-----+\n");
	Lprint(MyList);
	printf("+------------------------------------------+\n\n\n");
	printf("+------+-----<중복 제거 후 명단>-----+-----+\n");
	printf("| name | Kor | Eng | Mat | Com | Sum | Rnk |\n");
	printf("+------+-----+-----+-----+-----+-----+-----+");
	OverlapLprint(MyList);
	printf("\n+------------------------------------------+\n");
}