#include <stdio.h>
#include <stdlib.h>
#include "Accounting.h"

void clear_screen();

int main()
{
	Acc acc[1000]; // (1)

	char name1[10]; //�� �̸�
	int acnum1; //�� ���¹�ȣ
	int acnum2; //��� ���¹�ȣ
	int money; //�۱� �� �Ա�, ��ݽ� ���� �Ը�
	int chic; //���� ���� ����
	char cort; // ���� ���� ����

	while (1) {
		printf("0.���� ����\n1.���� ����\n2.������ �� ����\n3.������ü Ȯ��\n");
		fputs("�ɼ� �Է� : ", stdout);
		scanf("%d", &chic);
		if (chic == 0)
		{
			puts("���񽺰� ���������� ����Ǿ����ϴ�.");
			return 0;
		}
		else if (chic == 1)
		{
			printf("1.���� �߰�\n2.���� ����\n3.���� ����\n");
			printf("�ɼ� �Է� : ");
			scanf("%d", &chic);
			if (chic == 1) {
				printf("���¸� ���� �̸��� �ݾ��� �Է��Ͻÿ� : ");
				scanf("%s %d", name1, &money);
				add_account(name1, money, acc);
			}
			else if (chic == 2) {
				printf("������ ������ �̸��� ���¹�ȣ�� �Է��Ͻÿ� : ");
				scanf("%s %d", name1, &acnum1);
				printf("���� ���¸� �����Ͻðڽ��ϱ�?(y or n)");
				while (getchar() != '\n');
				scanf("%c", &cort);
				if (cort == 'y')
					delete_account(acnum1, acc);
			}
			else if (chic == 3) {
				printf("��ȸ�� ���¹�ȣ�� �Է��ϼ��� : ");
				scanf("%d", &acnum1);
				show_info(acnum1, acc);
			}
			else {
				printf("�������� �ʴ� ����Դϴ�.\n");
			}
		}
		else if (chic == 2)
		{
			printf("1.�۱�\n2.�Ա�\n3.���\n");
			fputs("�ɼ� �Է� : ", stdout);
			scanf("%d", &chic);
			if (chic == 1)
			{
				printf("�ڽ��� ���¹�ȣ, ���� ����� ���¹�ȣ, �۱��� ���� �Է��Ͻÿ� : ");
				scanf("%d %d %d", &acnum1, &acnum2, &money);
				send(acnum1, acnum2, money, acc);
			}
			else if (chic == 2)
			{
				printf("�ڽ��� ���¹�ȣ, �Ա��� ���� �Է��Ͻÿ� : ");
				scanf("%d %d", &acnum1, &money);
				pay_push(acnum1, money, acc);
			}
			else if (chic == 3)
			{
				printf("�ڽ��� ���¹�ȣ, ����� ���� �Է��Ͻÿ� : ");
				scanf("%d %d", &acnum1, &money);
				pay_pop(acnum1, money, acc);
			}
			else
				printf("�������� �ʴ� ����Դϴ�.\n");
		}
		else if (chic == 3)
			check(acc);
		else
			printf("�������� �ʴ� ����Դϴ�.\n");

		clear_screen();
	}
}

void clear_screen()
{
	while (getchar() != '\n'); // �Լ��� �����ϴ� �͵� ������ �ʾ�
	getchar();
	system("cls");
}