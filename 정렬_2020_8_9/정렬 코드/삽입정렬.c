#include <stdio.h>
int main(){
	int a[1000];
	int i,j,key,change,n;
	printf("��� ���� �Է¹����� �Է��Ͻÿ�\n");
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
