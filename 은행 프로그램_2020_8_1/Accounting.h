#ifndef __ACCOUNTING__
#define __ACCOUNTING__
#define MAX_CLIENT 1000

typedef struct _Acc
{
	char name[20];
	int bal;	// 잔액
	int acnum;	// 계좌번호
}Acc;

// 계정 관리
void add_account(const char* name, int bal, Acc* account_arr);
void delete_account(int acnum, Acc* account_arr);
void show_info(int acnum, Acc* account_arr);

// 은행 시스템
void send(int acnum1, int acnum2, int money, Acc* account_arr);
void pay_push(int acnum, int money, Acc* account_arr);
void pay_pop(int acnum, int money, Acc* account_arr);

// 전체 고객 정보 조회 - 관리자 용
void check(Acc* account_arr);

int get_index(Acc* account_arr, int acnum);
#endif  