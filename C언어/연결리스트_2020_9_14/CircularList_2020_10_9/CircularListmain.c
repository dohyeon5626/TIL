#include <stdio.h>
#include <conio.h> //getch() �Լ��� ����ϱ� ���Ͽ�
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

char Delete(List* plist, int N) { //���� ���� ����Ʈ plist�� ���Ͽ� N�� �������� ����
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
	InitList(MyList); int MAX, NN; //����Ʈ�� �ʱ�ȭ
	printf("�ο���(<= 33), ���� "); scanf("%d %d", &MAX, &NN);
	printf("\n���ο� ��带 �����Ͽ� ����Ʈ�� �߰� \n");
	SetSortRule(MyList, WhoIsPred);
	while (A[a] && a < MAX) //����Ʈ�� �ڷ� �߰�
		LInsert(MyList, NewNode(A[a++]));
	LPrint(MyList);
	printf("\n������ ���� ����� �����ϱ�? ");// getch();
	printf("\n%d��° �ڷḦ ��ȯ�ϸ� ���� \n", NN);
	printf("\n���� �ִ� ���: %c \n", Delete(MyList, NN));
}

