#include <stdio.h>
int main(){
	int a,i,j,me[4],you[4];
	int speedme=0,speedyou=0,itemme=0,itemyou=0;
	char select[1000];
	scanf("%d",&a);
	for(i=0;i<=a-1;i++){
		speedme=0,speedyou=0,itemme=0,itemyou=0;
		for(j=0;j<=3;j++){
			scanf("%d",&me[j]);
			if(itemme<me[j]){
				itemme=me[j];
			}
		}
		for(j=0;j<=3;j++){
			scanf("%d",&you[j]);
			if(itemyou<you[j]){
				itemyou=you[j];
			}
		}
		speedme=me[0]+me[1]+me[2]+me[3];
		speedyou=you[0]+you[1]+you[2]+you[3];
		if(speedme>speedyou&&itemme>itemyou||speedme<=speedyou&&itemme<=itemyou){
			select[i]='R';
		}
		else if(speedme>speedyou&&itemme<=itemyou){
			select[i]='S';
		}
		else if(itemme>itemyou&&speedme<=speedyou){
			select[i]='I';
		}
	}
	for(i=0;i<=a-1;i++){
		printf("%c\n",select[i]);
	}
}
