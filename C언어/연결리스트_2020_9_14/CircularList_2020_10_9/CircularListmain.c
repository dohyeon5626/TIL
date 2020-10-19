#include <stdio.h>
#include <conio.h> //getch() 함수를 사용하기 위하여
#include "CircularList.h"
//#include "CircularList.c"
#define SSR(small,large) ((small)<(large))

int WhoIsPred(Ldata d1, Ldata d2) {
	if (SSR(d1->Item, d2->Item)) return 0;
	else return 1;
}

Ldata NewNode(char Item) {
	Ldata NN = (Node*)malloc(sizeof(Node));
	NN->Item = Item;
	NN->Next = NULL;
	return NN;
}

char Delete(List* plist, int N) { //해적 원형 리스트 plist에 대하여 N의 간격으로 제거
	int a = 0;
	Ldata Cur = (Node*)malloc(sizeof(Node));
	LFirst(plist, Cur);
	for (int i = 1; i < N; i++) {
		LNext(plist, Cur);
	}
	LRemove(plist);
	LPrint(plist);
	plist->Tail = plist->Cur;
	while (!(plist->NumOfData==1)) {
		for (int i = 1; i < N+1; i++) {
			LNext(plist, Cur);
		}
		LRemove(plist);
		LPrint(plist);
		plist->Tail = plist->Cur;
	}
	return plist->Cur->Item;
}

int main(void) {
	List* MyList = (List*)malloc(sizeof(List));
	int a = 0;
	char A[33] = "abcdefABCDEFGHIJKLMNOPQRSTUVWXYZ";
	InitList(MyList); int MAX, NN; //리스트의 초기화
	printf("인원수(<= 33), 간격 "); scanf("%d %d", &MAX, &NN);
	printf("\n새로운 노드를 정렬하여 리스트에 추가 \n");
	SetSortRule(MyList, WhoIsPred);
	while (A[a] && a < MAX) //리스트에 자료 추가
		LInsert(MyList, NewNode(A[a++]));
	LPrint(MyList);
	printf("\n끝까지 남은 멤버는 누구일까? ");// getch();
	printf("\n%d번째 자료를 순환하며 제거 \n", NN);
	printf("\n남아 있는 멤버: %c \n", Delete(MyList, NN));
}

