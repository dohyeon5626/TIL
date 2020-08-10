#include <stdio.h>
int main() {
	int a[10001];
	int n, i, j, temp;
	printf("몇개를 입력할지 입력하시오");
	scanf("%d",&n);
    for (i=1; i<=n; i++)
        scanf("%d",&a[i]); 
    for(i=1; i<n; i++) {
		for(j=1	;j<n-i+1;j++) {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for (i = 1; i <= n; i++)
        printf("%d\n", a[i]);
    return 0;
}

