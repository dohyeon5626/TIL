#include "Accounting.h"
#include <string.h>

static int num_of_account = 0;

void add_account(const char* name, int bal, Acc* account_arr)
{
	static int acnum = 1;
	if (num_of_account >= MAX_CLIENT)
	{
		printf("더 이상 계좌를 만들 수 없습니다\n");
		return;
	}
	if (bal < 0)
	{
		puts("잘못된 값을 입력하셨습니다.");
		return;
	}
	strcpy(account_arr[num_of_account].name, name);
	account_arr[num_of_account].bal = bal;
	account_arr[num_of_account].acnum = acnum;
	printf("귀하의 계좌번호는 %d입니다\n", acnum);
	acnum++;
	num_of_account++;
	printf("계좌가 추가되었습니다\n");
}

void delete_account(int acnum, Acc* account_arr)
{
	int i = get_index(account_arr, acnum);
	if (i == -1)
	{
		printf("없는 계좌번호 입니다\n");
		return;
	}
	for (; i < num_of_account - 1; i++)
	{
		strcpy(account_arr[i].name, account_arr[i + 1].name);
		account_arr[i].bal = account_arr[i + 1].bal;
		account_arr[i].acnum = account_arr[i + 1].acnum;
	}
	num_of_account--;
	puts("삭제되었습니다.");
}

void show_info(int acnum,Acc* account_arr)
{
	int error;
	error = get_index(account_arr, acnum);
	if (error == -1) {
		printf("없는 계좌입니다\n");
		return;
	}
	else {
		printf("귀하의 성함:%s\n", account_arr[error].name);
		printf("귀하의 잔액:%d\n", account_arr[error].bal);
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
		printf("없는 계좌번호를 입력하셨습니다\n");
		return;
	}
	if (account_arr[a].bal < money)
	{
		puts("잔액이 부족합니다.");
		return;
	}
	account_arr[a].bal = account_arr[a].bal - money;
	account_arr[b].bal = account_arr[b].bal + money; // 복합대입연산자
	printf("%s고객님의 통장에서 %s고객님의 통장으로 %d원이 송금되었습니다\n", account_arr[a].name, account_arr[b].name, money);
	
	return 0;
}

void pay_push(int acnum, int money, Acc* account_arr)
{
	int a;
	a = get_index(account_arr, acnum);
	if (a == -1) {
		printf("없는 계좌번호를 입력하셨습니다\n");
		return;
	}
	if (money < 0)
	{
		puts("잘못된 값을 입력하셨습니다.");
		return;
	}
	account_arr[a].bal = account_arr[a].bal + money;
	printf("%s고객님의 통장으로 %d원이 입금되었습니다\n", account_arr[a].name, money);
}

void pay_pop(int acnum, int money, Acc* account_arr)
{
	int a; //
	a = get_index(account_arr, acnum);
	if (a == -1) {
		printf("없는 계좌번호를 입력하셨습니다\n");
		return;
	}
	if (money < 0)
	{
		puts("잘못된 값을 입력하셨습니다.");
		return;
	}
	if (account_arr[a].bal < money)
	{
		puts("잔액이 부족합니다.");
		return;
	}
	account_arr[a].bal = account_arr[a].bal - money;
	printf("%s고객님의 통장에서 %d원이 출금되었습니다\n", account_arr[a].name, money);
}

void check(Acc* account_arr)
{
	int i;
	if (num_of_account==0) {
		printf("등록된 고객이 없습니다\n");
	}
	for (i = 0; i < num_of_account;i++) {
		printf("계좌번호:%d\n고객의 성함:%s\n고객의 잔액%d\n\n", account_arr[i].acnum, account_arr[i].name, account_arr[i].bal);
	}
}