#include <stdio.h>
int main(){
	char a[100000];
	int i=0,c=0;
	scanf("%s",a);
	while(1){
		if(a[i]=='S'){
			c++;
		}
		else if(a[i]=='T'){
			do{
				c++;
			}while(c%4!=0);
		}
		else if(a[i]==NULL){
			break;
		}
		i++;
	}
	printf("%d",c);
}
