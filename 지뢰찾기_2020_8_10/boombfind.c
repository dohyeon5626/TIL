#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int correct[20][20] = { 0 }, data[20][20] = { 0 },count=0;
void blank(int x, int y) {
	if (data[x][y] == 0) {
		correct[x][y] = 1;
		count++;
	}
	else if(data[x][y] > 0){
		correct[x][y] = 1;
		count++;
		return;
	}
	else {
		return;
	}
	if (data[x + 1][y] >= -1 && x + 1 <= 19 && correct[x + 1][y] == 0) {
		blank(x + 1, y);
	}
	if (data[x - 1][y] >= -1 && x - 1 >= 0 && correct[x - 1][y] == 0) {
		blank(x - 1, y);
	}
	if (data[x][y + 1] >= -1 && y + 1 <= 19 && correct[x][y + 1] == 0) {
		blank(x, y + 1);
	}
	if (data[x][y - 1] >= -1 && y - 1 >= 0 && correct[x][y - 1] == 0) {
		blank(x, y - 1);
	}
	return;
}
int main() {
	int i, j, x, y, out = 0;
	int boomb;
	printf("지뢰의 개수를 입력하시오");
	scanf("%d",&boomb);
	if (boomb >= 0) {
		if (boomb == 0) {
			printf("game clear");
		}
		else if (boomb>0) {
			for (i = 0; i <= boomb - 1; i++) {
				x = rand() % 20;
				y = rand() % 20;
				if (data[x][y] == -1) {
					i--;
				}
				else {
					data[x][y] = -1;
					if (data[x - 1][y] != -1 && x - 1 >= 0) {
						data[x - 1][y]++;
					}
					if (data[x + 1][y] != -1 && x + 1 <= 19) {
						data[x + 1][y]++;
					}
					if (data[x][y - 1] != -1 && y - 1 >= 0) {
						data[x][y - 1]++;
					}
					if (data[x][y + 1] != -1 && y + 1 <= 19) {
						data[x][y + 1]++;
					}
					if (data[x - 1][y - 1] != -1 && x - 1 >= 0 && y - 1 >= 0) {
						data[x - 1][y - 1]++;
					}
					if (data[x - 1][y + 1] != -1 && x - 1 >= 0 && y + 1 <= 19) {
						data[x - 1][y + 1]++;
					}
					if (data[x + 1][y - 1] != -1 && x + 1 <= 19 && y - 1 >= 0) {
						data[x + 1][y - 1]++;
					}
					if (data[x + 1][y + 1] != -1 && x + 1 <= 19 && y + 1 <= 19) {
						data[x + 1][y + 1]++;
					}
				}
			}
			while (1) {
				system("cls");
				printf("    (y)");
				for (i = 0; i <= 19; i++) {
					printf("\t%d", i + 1);
				}
				printf("\n");
				printf("(x)");
				for (i = 0; i <= 19; i++) {
					printf("\t▽");
				}
				printf("\n\n");
				for (i = 0; i <= 19; i++) {
					printf("%d - ", i + 1);
					for (j = 0; j <= 19; j++) {
						if (correct[i][j] == 1) {
							if (data[i][j] == -1 && out == -1) {
								printf("\t*");
							}
							else if (data[i][j] == 0) {
								printf("\t");
							}
							else {
								printf("\t%d", data[i][j]);
							}
						}
						else {
							printf("\t□");
						}
					}
					printf("\n\n");
				}
				if (count == 400 - boomb) {
					break;
				}
				if (out == 0) {
					printf("탐지할 공간을 입력하시오\nx:");
					scanf("%d", &x);
					printf("\ny:");
					scanf("%d", &y);
					if (x < 0 || y < 0) {
						printf("오류입니다");
						break;
					}
					if (data[x - 1][y - 1] == -1) {
						out = -1;
					}
					else {
						blank(x - 1, y - 1);
						if (count == 400 - boomb) {
							break;
						}
					}
				}
				else {
					break;
				}
			}
			system("cls");
			printf("    (y)");
			for (i = 0; i <= 19; i++) {
				printf("\t%d", i + 1);
			}
			printf("\n");
			printf("(x)");
			for (i = 0; i <= 19; i++) {
				printf("\t▽");
			}
			printf("\n\n");
			for (i = 0; i <= 19; i++) {
				printf("%d - ", i + 1);
				for (j = 0; j <= 19; j++) {
					if (correct[i][j] == 1 || data[i][j] == -1) {
						if (data[i][j] == -1) {
							printf("\t*");
						}
						else if (data[i][j] == 0) {
							printf("\t");
						}
						else {
							printf("\t%d", data[i][j]);
						}
					}
					else {
						printf("\t□");
					}
				}
				printf("\n\n");
			}
			if (out == 0 && count == 400 - boomb) {
				printf("game clear\n");
			}
			else {
				printf("game over\n");
			}
		}
	}
	else {
			printf("오류입니다\n");
	}
	system("pause");
}