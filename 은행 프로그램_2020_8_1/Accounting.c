#include <stdio.h>
#include <stdlib.h>
#include "Accounting.h"

void clear_screen();

int main()
{
	Acc acc[1000]; // (1)

	char name1[10]; //내 이름
	int acnum1; //내 계좌번호
	int acnum2; //상대 계좌번호
	int money; //송금 및 입금, 출금시 돈의 규모
	int chic; //서비스 선택 변수
	char cort; // 서비스 선택 변수

	while (1) {
		printf("0.서비스 종료\n1.계좌 관리\n2.계좌의 돈 관리\n3.계좌전체 확인\n");
		fputs("옵션 입력 : ", stdout);
		scanf("%d", &chic);
		if (chic == 0)
		{
			puts("서비스가 정상적으로 종료되었습니다.");
			return 0;
		}
		else if (chic == 1)
		{
			printf("1.계좌 추가\n2.계좌 삭제\n3.계좌 관리\n");
			printf("옵션 입력 : ");
			scanf("%d", &chic);
			if (chic == 1) {
				printf("계좌를 만들 이름과 금액을 입력하시오 : ");
				scanf("%s %d", name1, &money);
				add_account(name1, money, acc);
			}
			else if (chic == 2) {
				printf("삭제할 계좌의 이름과 계좌번호를 입력하시오 : ");
				scanf("%s %d", name1, &acnum1);
				printf("정말 계좌를 삭제하시겠습니까?(y or n)");
				while (getchar() != '\n');
				scanf("%c", &cort);
				if (cort == 'y')
					delete_account(acnum1, acc);
			}
			else if (chic == 3) {
				printf("조회할 계좌번호를 입력하세요 : ");
				scanf("%d", &acnum1);
				show_info(acnum1, acc);
			}
			else {
				printf("존재하지 않는 명령입니다.\n");
			}
		}
		else if (chic == 2)
		{
			printf("1.송금\n2.입금\n3.출금\n");
			fputs("옵션 입력 : ", stdout);
			scanf("%d", &chic);
			if (chic == 1)
			{
				printf("자신의 계좌번호, 보낼 상대의 계좌번호, 송금할 돈을 입력하시오 : ");
				scanf("%d %d %d", &acnum1, &acnum2, &money);
				send(acnum1, acnum2, money, acc);
			}
			else if (chic == 2)
			{
				printf("자신의 계좌번호, 입금할 돈을 입력하시오 : ");
				scanf("%d %d", &acnum1, &money);
				pay_push(acnum1, money, acc);
			}
			else if (chic == 3)
			{
				printf("자신의 계좌번호, 출금할 돈을 입력하시오 : ");
				scanf("%d %d", &acnum1, &money);
				pay_pop(acnum1, money, acc);
			}
			else
				printf("존재하지 않는 명령입니다.\n");
		}
		else if (chic == 3)
			check(acc);
		else
			printf("존재하지 않는 명령입니다.\n");

		clear_screen();
	}
}

void clear_screen()
{
	while (getchar() != '\n'); // 함수로 구현하는 것도 나쁘지 않아
	getchar();
	system("cls");
}