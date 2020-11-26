#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* link;
};
struct Node* pHead = NULL;
struct Node* pPoint = NULL;
void insert(int num);
void Print_link();
void Remove(int num);
void insert(int num) {
	struct Node* new_node = malloc(sizeof(struct Node));
	printf("입력 값 : %d\n", num);
	new_node->data = num;
	if(pHead==NULL){
		pHead = new_node;
		new_node->link = NULL;
		pPoint = pHead;
	}
	else {
		pPoint->link = new_node;
		new_node->link = NULL;
		pPoint = new_node;
	}
	Print_link();
}

void Print_link() {
	struct Node* pPrint = pHead;
	printf("출력 : ");
	while(pPrint!=NULL){
		printf("%d ",pPrint->data);
		pPrint = pPrint->link;
	}
	printf("\n\n");
}

void Remove(int num){
	struct Node* pRemove = pHead;
	struct Node* tmp = pHead;
	printf("삭제할 번호 : %d\n", num);
	int i = 1;
	while (pRemove != NULL) {
		if (i + 1 == num) {
			tmp = pRemove;
		}
		else if ( i == num) {
			if (num > 1) {
				tmp->link = pRemove->link;
				free(pRemove);
			}
			else if (num==1){
				pHead = pRemove->link;
				free(pRemove);
			}
			break;
		}
		pRemove = pRemove->link;
		i++;
	}
	Print_link();
	printf("\n\n");
}

int main() {
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	Remove(3);
	Print_link();
}