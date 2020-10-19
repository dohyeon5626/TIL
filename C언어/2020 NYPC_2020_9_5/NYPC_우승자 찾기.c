#include <stdio.h>
int N, K;
int win_check[1001]={0};
int person[10000]={0};
int count=1;

void f(int x){
	int i;
	int check[1001]={0};
	
	for(i=x+1;i<=K-1;i++){
		if(person[i]==person[x]){
			count++;
			win_check[person[i]]=1;
			return;
		}
		check[person[i]]+=1;
		if(check[person[i]]==2){
			return;
		}
	}
}


int main(){
	int i;
	
	scanf("%d %d", &N, &K);
	
	for(i=0;i<=K-1;i++){
		scanf("%d", &person[i]);
	}
	win_check[person[0]]=1;
	for(i=1;i<=K-1;i++){
		if(win_check[person[i]]==0){
			f(i);
		}
	}
	printf("%d\n", count);
	for(i=1;i<=N;i++){
		if(win_check[i]==1){
			printf("%d ", i);
		}
	}
}
