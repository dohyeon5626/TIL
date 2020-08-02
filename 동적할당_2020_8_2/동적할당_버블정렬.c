#include <stdio.h>
#include <stdlib.h>

int main() {
	int *ptr, a, i, j, change;

	scanf("%d",&a);
	ptr = (int*)malloc(sizeof(int) * a);
	for (i = 0; i < a; i++) {
		scanf("%d", &ptr[i]);
	}

	for (i = 0; i < a; i++) {
		printf("%d ", ptr[i]);
	}
	puts("");

	for (i = 0; i <= a - 2;i++) {
		for (j = 0; j <= a - i -2;j++) {
			if (ptr[j]>ptr[j+1]) {
				change = ptr[j+1];
				ptr[j+1] = ptr[j];
				ptr[j] = change;
			}
		}
		for (j = 0; j <= a - 1; j++) {
			printf("%d ", ptr[j]);
		}
		printf("\n");
	}
	for (i = 0; i <= a - 1;i++) {
		printf("%d ", ptr[i]);
	}

	free(ptr);
	return 0;
}