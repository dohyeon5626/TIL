#include <stdio.h>
int main(){
	int a,b,c,t[3]={0},i,j,count,star[100000]={0},value=0;
	for(i=0;i<=2;i++){
		scanf("%d:%d:%d",&a,&b,&c);
		t[i]=c+b*100+a*60*100;
	}
	scanf("%d",&count);
	for(i=0;i<=count-1;i++){
		scanf("%d:%d:%d",&a,&b,&c);
		value=c+b*100+a*60*100;
		if(value>t[0]){
			star[i]=0;
		}
		else if(value<=t[0]&&value>t[1]){
			star[i]=1;
		}
		else if(value<=t[1]&&value>t[2]){
			star[i]=2;
		}
		else if(value<=t[2]){
			star[i]=3;
		}
	}
	for(i=0;i<=count-1;i++){
		if(star[i]==0){
			printf(":(");
		}
		else{
			for(j=1;j<=star[i];j++){
				printf("*");
			}
		}
		printf("\n");
	}
}
