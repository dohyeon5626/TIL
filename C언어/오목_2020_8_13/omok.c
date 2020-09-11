#include <stdio.h>
#include <windows.h>
int pan[15][15] = { 0 }, color = 0;
int highc = 0, widthc = 0, side1c = 0, side2c = 0;
int highch = 0, widthch = 0, side1ch = 0, side2ch = 0;
int up(int x,int y) {
	if (pan[x - 1][y]==color + 1) {
		return up(x - 1, y) + 1;
	}
	else if (pan[x - 1][y] == 0&&pan[x - 2][y] == color + 1) {
		if (pan[x - 2][y] == color + 1 && pan[x - 3][y] == color + 1 && pan[x - 4][y] == 0) {
			highc += 2;
			return 2;
		}
		if (pan[x - 2][y] == color + 1 && pan[x - 3][y] == 0) {
			highc += 1;
			return 1;
		}
	}
	else if (pan[x - 1][y] == (color + 1) % 2 + 1) {
		highch = 1;
		return 0;
	}
	return 0;
}
int down(int x, int y) {
	if (pan[x + 1][y] == color + 1) {
		return down(x + 1, y) + 1;
	}
	else if (pan[x + 1][y] == 0 && pan[x + 2][y] == color + 1) {
		if (pan[x + 2][y] == color + 1 && pan[x + 3][y] == color + 1 && pan[x + 4][y] == 0) {
			highc += 2;
			return 2;
		}
		if (pan[x + 3][y] == 0) {
			highc += 1;
			return 1;
		}
	}
	else if (pan[x + 1][y] == (color + 1) % 2 + 1) {
		highch = 1;
		return 0;
	}
	return 0;
}
int left(int x, int y){
	if (pan[x][y - 1] == color + 1) {
		return left(x, y - 1) + 1;
	}
	else if (pan[x][y - 1] == 0 && pan[x][y - 2] == color + 1) {
		if (pan[x][y - 2] == color + 1 && pan[x][y -3] == color + 1 && pan[x][y - 4] == 0) {
			widthc += 2;
			return 2;
		}
		if (pan[x][y - 3] == 0) {
			widthc += 1;
			return 1;
		}
	}
	else if (pan[x][y - 1] == (color + 1) % 2 + 1) {
		widthch = 1;
		return 0;
	}
	return 0;
}
int right(int x, int y) {
	if (pan[x][y + 1] == color + 1) {
		return right(x, y + 1) + 1;
	}
	else if (pan[x][y + 1] == 0 && pan[x][y + 2] == color + 1) {
		if (pan[x][y + 2] == color + 1 && pan[x][y + 3] == color + 1 && pan[x][y + 4] == 0) {
			widthc += 2;
			return 2;
		}
		if (pan[x][y + 3] == 0) {
			widthc += 1;
			return 1;
		}
	}
	else if (pan[x][y + 1] == (color + 1) % 2 + 1) {
		widthch = 1;
		return 0;
	}
	return 0;
}
int leftside1(int x, int y) {
	if (pan[x - 1][y - 1] == color + 1) {
		return leftside1(x - 1, y - 1) + 1;
	}
	else if (pan[x - 1][y - 1] == 0 && pan[x - 2][y - 2] == color + 1) {
		if (pan[x - 2][y - 2] == color + 1 && pan[x - 3][y - 3] == color + 1 && pan[x - 4][y - 4] == 0) {
			side1c += 2;
			return 2;
		}
		if (pan[x - 3][y - 3] == 0) {
			side1c += 1;
			return 1;
		}
	}
	else if (pan[x - 1][y - 1] == (color + 1) % 2 + 1) {
		side1ch = 1;
		return 0;
	}
	return 0;
}
int leftside2(int x, int y) {
	if (pan[x + 1][y + 1] == color + 1) {
		return leftside2(x + 1, y + 1) + 1;
	}
	else if (pan[x + 1][y + 1] == 0 && pan[x + 2][y + 2] == color + 1) {
		if (pan[x + 2][y + 2] == color + 1 && pan[x + 3][y + 3] == color + 1 && pan[x + 4][y + 4] == 0) {
			side1c += 2;
			return 2;
		}
		if (pan[x + 3][y + 3] == 0) {
			side1c += 1;
			return 1;
		}
	}
	else if (pan[x + 1][y + 1] == (color + 1) % 2 + 1) {
		side1ch = 1;
		return 0;
	}
	return 0;
}
int rightside1(int x, int y) {
	if (pan[x - 1][y + 1] == color + 1) {
		return rightside1(x - 1, y + 1) + 1;
	}
	else if (pan[x - 1][y + 1] == 0 && pan[x - 2][y + 2] == color + 1) {
		if (pan[x - 2][y + 2] == color + 1 && pan[x - 3][y + 3] == color + 1 && pan[x - 4][y + 4] == 0) {
			side2c += 2;
			return 2;
		}
		if (pan[x - 3][y + 3] == 0) {
			side2c += 1;
			return 1;
		}
	}
	else if (pan[x - 1][y + 1] == (color + 1) % 2 + 1) {
		side2ch = 1;
		return 0;
	}
	return 0;
}
int rightside2(int x, int y) {
	if (pan[x + 1][y - 1] == color + 1) {
		return rightside2(x + 1, y - 1) + 1;
	}
	else if (pan[x + 1][y - 1] == 0 && pan[x + 2][y - 2] == color + 1) {
		if (pan[x + 2][y - 2] == color + 1 && pan[x + 3][y - 3] == color + 1 && pan[x + 4][y - 4] == 0) {
			side2c += 2;
			return 2;
		}
		if (pan[x + 3][y - 3] == 0) {
			side2c += 1;
			return 1;
		}
	}
	else if (pan[x + 1][y - 1] == (color + 1) % 2 + 1) {
		side2ch = 1;
		return 0;
	}
	return 0;
}
int check(int x,int y) {
	int u, d, l, r,ls1,ls2, rs1, rs2;
	if (pan[x][y]>0) {
		printf("이미 돌이 놓아진 칸에 돌을 놓을 수 없습니다\n");
		return -1;
	}
	if (x<0||y<0||x>14||y>14) {
		printf("그 위치에 돌을 놓을 수 없습니다\n");
		return -1;
	}
	u = up(x,y);
	d = down(x,y);
	l = left(x,y);
	r = right(x,y);
	ls1 = leftside1(x, y);
	ls2 = leftside2(x, y);
	rs1 = rightside1(x, y);
	rs2 = rightside2(x, y);
	if (!!(u+d==2&&highch==0)+!!(l+r==2&&widthch==0)+!!(ls1+ls2==2&&side1ch==0)+!!(rs1+rs2==2&&side2ch==0)>=2&&color==0) {
		printf("그 위치에 돌을 놓을 수 없습니다(3X3)\n");
		return -1;
	}
	if (u+d-highc==4||l+r-widthc==4||ls1+ls2-side1c==4||rs1+rs2-side2c==4) {
		highc = widthc = side1c = side2c = 0;
		highch = widthch = side1ch = side2ch = 0;
		return -2;
	}
	highc = widthc = side1c = side2c = 0;
	highch = widthch = side1ch = side2ch = 0;
	return 0;
}
int main() {
	int x=0, y=0;
	int i,j,c;
	printf("    ");
	for (i = 0; i <= 14; i++) {
		printf("%2d", i + 1);
	}
	printf("(y)\n");
	for (i = 0; i <= 14; i++) {
		printf("%2d-", i + 1);
		for (j = 0; j <= 14; j++) {
			if (pan[i][j] == 0) {
					printf("─┼");
			}
		}
		printf("\n");
	}
	printf("(x)\n");
	while (1) {
		if (color==0) {
			printf("검은돌을 놓을 자리를 입력하시오\n○(x y)");
		}
		else {
			printf("흰돌을 놓을 자리를 입력하시오\n●(x y)");
		}
		scanf("%d %d", &x, &y);
		c = check(x-1, y-1);
		if(c==0){
			if (color == 0) {
				pan[x - 1][y - 1] = 1;
			}
			else {
				pan[x - 1][y - 1] = 2;
			}
			system("cls");
			color++;
			color = color % 2;
			printf("    ");
			for (i = 0; i <= 14; i++) {
				printf("%2d", i + 1);
			}
			printf("(y)\n");
			for (i = 0; i <= 14; i++) {
				printf("%2d-", i + 1);
				for (j = 0; j <= 14; j++) {
					if (pan[i][j] == 0) {
						if (pan[i][j - 1] == 1 && j > 0 || pan[i][j - 1] == 2 && j > 0) {
							printf("┼");
						}
						else {
							printf("─┼");
						}
					}
					else if (pan[i][j] == 1) {
						if (pan[i][j - 1] == 1 && j > 0 || pan[i][j - 1] == 2 && j > 0) {
							printf("○");
						}
						else {
							printf("-○");
						}
					}
					else if (pan[i][j] == 2) {
						if (pan[i][j - 1] == 1 && j > 0 || pan[i][j - 1] == 2 && j > 0) {
							printf("●");
						}
						else {
							printf("-●");
						}
					}
				}
				printf("\n");
			}
			printf("(x)\n");
		}
		else if (c == -2) {
			if (color == 0) {
				pan[x - 1][y - 1] = 1;
			}
			else {
				pan[x - 1][y - 1] = 2;
			}
			system("cls");
			printf("    ");
			for (i = 0; i <= 14; i++) {
				printf("%2d", i + 1);
			}
			printf("(y)\n");
			for (i = 0; i <= 14; i++) {
				printf("%2d-", i + 1);
				for (j = 0; j <= 14; j++) {
					if (pan[i][j] == 0) {
						if (pan[i][j - 1] == 1 && j > 0 || pan[i][j - 1] == 2 && j > 0) {
							printf("┼");
						}
						else {
							printf("─┼");
						}
					}
					else if (pan[i][j] == 1) {
						if (pan[i][j - 1] == 1 && j > 0 || pan[i][j - 1] == 2 && j > 0) {
							printf("○");
						}
						else {
							printf("-○");
						}
					}
					else if (pan[i][j] == 2) {
						if (pan[i][j - 1] == 1 && j > 0 || pan[i][j - 1] == 2 && j > 0) {
							printf("●");
						}
						else {
							printf("-●");
						}
					}
				}
				printf("\n");
			}
			printf("(x)\n");
			if (color==0) {
				printf("검은돌이 이겼습니다");
			}
			else {
				printf("흰돌이 이겼습니다");
			}
			break;
		}		
	}
	system("pause");
}