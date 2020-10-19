#include <stdio.h>
float number[1000][1000];
int main(){
	int T;
	int i,j;
	scanf("%d",&T);
	for(i=0;i<=T-1;i++){
		for(j=0;j<=3;j++){
			scanf("%f",&number[i][j]);
		}
	}
	for(i=0;i<=T-1;i++){
		if(number[i][0]+number[i][1]-number[i][2]==number[i][3]){
			printf("%d+%d-%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]+number[i][1]*number[i][2]==number[i][3]){
			printf("%d+%d*%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]+number[i][1]/number[i][2]==number[i][3]){
			printf("%d+%d/%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]+(number[i][1]+number[i][2]/10)==number[i][3]){
			printf("%d+%d.%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]-number[i][1]+number[i][2]==number[i][3]){
			printf("%d-%d+%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]-number[i][1]*number[i][2]==number[i][3]){
			printf("%d-%d*%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]-number[i][1]/number[i][2]==number[i][3]){
			printf("%d-%d/%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]-(number[i][1]+number[i][2]/10)==number[i][3]){
			printf("%d-%d.%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]*number[i][1]+number[i][2]==number[i][3]){
			printf("%d*%d+%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]*number[i][1]-number[i][2]==number[i][3]){
			printf("%d*%d-%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]*number[i][1]/number[i][2]==number[i][3]){
			printf("%d*%d/%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]*(number[i][1]+number[i][2]/10)==number[i][3]){
			printf("%d*%d.%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]/number[i][1]+number[i][2]==number[i][3]){
			printf("%d/%d+%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]/number[i][1]-number[i][2]==number[i][3]){
			printf("%d/%d-%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]/number[i][1]*number[i][2]==number[i][3]){
			printf("%d/%d*%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if(number[i][0]/(number[i][1]+number[i][2]/10)==number[i][3]){
			printf("%d/%d.%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if((number[i][0]+number[i][1]/10)+number[i][2]==number[i][3]){
			printf("%d.%d+%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if((number[i][0]+number[i][1]/10)-number[i][2]==number[i][3]){
			printf("%d.%d-%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if((number[i][0]+number[i][1]/10)*number[i][2]==number[i][3]){
			printf("%d.%d*%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
		else if((number[i][0]+number[i][1]/10)/number[i][2]==number[i][3]){
			printf("%d.%d/%d=%d\n", (int)number[i][0], (int)number[i][1], (int)number[i][2], (int)number[i][3]);
		}
	}
}
