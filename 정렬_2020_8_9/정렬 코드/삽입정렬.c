#include <stdio.h>
int main(){
	int a[1000];
	int i,j,key,change,n;
	printf("몇개의 수를 입력받을지 입력하시요\n");
	scanf("%d",&n); 
	for(i=0;i<=n-1;i++){
		scanf("%d",&a[i]); 
	}
	for(i=1;i<=n-1;i++){
		key=i;
		for(j=i-1;j>=0;j--){
			if(a[key]<a[j]){
				change=a[key];
				a[key]=a[j];
				a[j]=change;
				key=j;
			}
		}
	}
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
}
