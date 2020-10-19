#include <stdio.h>
#include <math.h>

struct node
{
	int standard;
	int index;
	int abs;
}nodes[500000];

void swap(struct node *a, struct node *b){
	struct node temp;
	temp = *a;
	*a=*b;
	*b=temp;
	return;
}

void quickSort(struct node *nodes, int low, int high){
	int pivot, i , j;
	if(low < high){
		pivot = low;
		i = low;
		j = high;
		while(i<j){			
			while(nodes[i].standard <= nodes[pivot].standard && i<= high){
				i++;
			}
			while(nodes[j].standard > nodes[pivot].standard && j>=low){
				j--;
			}
			if(i<j){
				swap(&nodes[i], &nodes[j]);
			}
		}
		swap(&nodes[j], &nodes[pivot]);
		quickSort(nodes, low, j-1);
		quickSort(nodes, j+1, high);
	} 
	return;
}

int main(){
	int number, i;
	int S,K,point=0;
	scanf("%d",&number);
	point=number-1;
	scanf("%d %d",&S,&K);
	for(i=0; i<number; i++){
		scanf("%d",&nodes[i].standard);
		nodes[i].index = i+1;
		nodes[i].abs = abs(S-nodes[i].standard);
	}
	quickSort(nodes, 0, number-1);
	for(i=0; i<number; i++){
		if(nodes[i].standard>S){
			point=i-1;
			break;
		}
	}
	int x,y;
	x=point;
	y=point+1;
	for(i=0;i<K;i++){
		if(nodes[x].abs<=nodes[y].abs){
			if(x>=0){
				printf("%d ",nodes[x].index);
				x--;
			}
			else{
				printf("%d ",nodes[y].index);
				y++;
			}
		}
		else if(nodes[x].abs>nodes[y].abs){
			if(y<number){
				printf("%d ",nodes[y].index);
				y++;
			}
			else{
				printf("%d ",nodes[x].index);
				x--;
			}
		}
	}
}
