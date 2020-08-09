#include <stdio.h>

int sort[7]={0};
int data[7]={0};

void merge(int l,int m,int r){
	int sl=l;
	int er=m+1;
	int i=l;
	while(i<=r){
		if(data[sl]<data[er]&&sl<=m&&er<=r){
			sort[i]=data[sl];
			sl++;
			i++;
		}
		else if(data[sl]>=data[er]&&sl<=m&&er<=r){
			sort[i]=data[er];
			er++;
			i++;
		}
		else if(sl>m&&er<=r){
			sort[i]=data[er];
			er++;
			i++;
		}
		else if(sl<=m&&er>r){
			sort[i]=data[sl];
			sl++;
			i++;
		}
	}
	for(i=0;i<=r;i++){
		data[i]=sort[i];
	}
}

void mergesort(int l,int r){
	int m;
	if(l<r){
		m=(l+r)/2;
		mergesort(l,m);
		mergesort(m+1,r);
		merge(l,m,r);
	}
}

int main(){
	printf("7개의 수를 입력하시오");
	for (int i = 0; i <= 6;i++) {
		scanf("%d",&data[i]);
	}
	mergesort(0,6);
	for(int i=0;i<=6;i++){
		printf("%d ",data[i]);
	}
	printf("\n");
}
