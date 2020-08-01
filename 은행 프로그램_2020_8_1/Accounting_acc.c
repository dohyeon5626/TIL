#include "Accounting.h"
#include <string.h>

static int num_of_account = 0;

void add_account(const char* name, int bal, Acc* account_arr)
{
	static int acnum = 1;
	if (num_of_account >= MAX_CLIENT)
	{
		printf("�� �̻� ���¸� ���� �� �����ϴ�\n");
		return;
	}
	if (bal < 0)
	{
		puts("�߸��� ���� �Է��ϼ̽��ϴ�.");
		return;
	}
	strcpy(account_arr[num_of_account].name, name);
	account_arr[num_of_account].bal = bal;
	account_arr[num_of_account].acnum = acnum;
	printf("������ ���¹�ȣ�� %d�Դϴ�\n", acnum);
	acnum++;
	num_of_account++;
	printf("���°� �߰��Ǿ����ϴ�\n");
}

void delete_account(int acnum, Acc* account_arr)
{
	int i = get_index(account_arr, acnum);
	if (i == -1)
	{
		printf("���� ���¹�ȣ �Դϴ�\n");
		return;
	}
	for (; i < num_of_account - 1; i++)
	{
		strcpy(account_arr[i].name, account_arr[i + 1].name);
		account_arr[i].bal = account_arr[i + 1].bal;
		account_arr[i].acnum = account_arr[i + 1].acnum;
	}
	num_of_account--;
	puts("�����Ǿ����ϴ�.");
}

void show_info(int acnum,Acc* account_arr)
{
	int error;
	error = get_index(account_arr, acnum);
	if (error == -1) {
		printf("���� �����Դϴ�\n");
		return;
	}
	else {
		printf("������ ����:%s\n", account_arr[error].name);
		printf("������ �ܾ�:%d\n", account_arr[error].bal);
	}
}

int get_index(Acc* account_arr, int acnum)
{
	int i;
	for (i = 0; i < num_of_account; i++)
	{
		if (acnum == account_arr[i].acnum)
			return i;
	}
	return -1;
}

void send(int acnum1, int acnum2, int money, Acc* account_arr)
{
	int a, b;
	a = get_index(account_arr, acnum1);
	b = get_index(account_arr, acnum2);

	if (a==-1 || b==-1) {
		printf("���� ���¹�ȣ�� �Է��ϼ̽��ϴ�\n");
		return;
	}
	if (account_arr[a].bal < money)
	{
		puts("�ܾ��� �����մϴ�.");
		return;
	}
	account_arr[a].bal = account_arr[a].bal - money;
	account_arr[b].bal = account_arr[b].bal + money; // ���մ��Կ�����
	printf("%s������ ���忡�� %s������ �������� %d���� �۱ݵǾ����ϴ�\n", account_arr[a].name, account_arr[b].name, money);
	
	return 0;
}

void pay_push(int acnum, int money, Acc* account_arr)
{
	int a;
	a = get_index(account_arr, acnum);
	if (a == -1) {
		printf("���� ���¹�ȣ�� �Է��ϼ̽��ϴ�\n");
		return;
	}
	if (money < 0)
	{
		puts("�߸��� ���� �Է��ϼ̽��ϴ�.");
		return;
	}
	account_arr[a].bal = account_arr[a].bal + money;
	printf("%s������ �������� %d���� �ԱݵǾ����ϴ�\n", account_arr[a].name, money);
}

void pay_pop(int acnum, int money, Acc* account_arr)
{
	int a; //
	a = get_index(account_arr, acnum);
	if (a == -1) {
		printf("���� ���¹�ȣ�� �Է��ϼ̽��ϴ�\n");
		return;
	}
	if (money < 0)
	{
		puts("�߸��� ���� �Է��ϼ̽��ϴ�.");
		return;
	}
	if (account_arr[a].bal < money)
	{
		puts("�ܾ��� �����մϴ�.");
		return;
	}
	account_arr[a].bal = account_arr[a].bal - money;
	printf("%s������ ���忡�� %d���� ��ݵǾ����ϴ�\n", account_arr[a].name, money);
}

void check(Acc* account_arr)
{
	int i;
	if (num_of_account==0) {
		printf("��ϵ� ���� �����ϴ�\n");
	}
	for (i = 0; i < num_of_account;i++) {
		printf("���¹�ȣ:%d\n���� ����:%s\n���� �ܾ�%d\n\n", account_arr[i].acnum, account_arr[i].name, account_arr[i].bal);
	}
}