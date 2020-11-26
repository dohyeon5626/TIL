#include	<iostream>
using	namespace	std;
struct	Node
{
	int	data;
	Node* link;
};
class	CMyList
{
private:
	int check(int x){
		if (pHead == nullptr) {
			return 0;
		}
		Node* Print = pHead;
		while (Print->link != nullptr) {
			if (Print->data!=x) {
				Print = Print->link;
			}
			else {
				return 1;
			}
		}
		if (Print->data != x) {
			return 0;
		}
		return 1;
	}
public:
	CMyList() {}
	~CMyList() {}
	void	Insert(int	num) {
		if (check(num)==0) {
			cout << endl;
			Node* new_node = new Node;
			new_node->data = num;
			new_node->link = nullptr;
			if (pHead == nullptr) {
				pHead = new_node;
				pPoint = new_node;
			}
			else {
				pPoint->link = new_node;
				pPoint = new_node;
			}
			PrintData();
		}
		else {
			//중복
			cout << num << " 는 중복입니다!" << endl;
		}
	}
	void	PrintData() {
		if (pHead == nullptr) {
			cout << "출력할 데이터가 없습니다." << endl;
			return;
		}
		Node* Print = pHead;
		int i = 1;
		cout << "CMyList 데이터 : ";
		while (Print->link != nullptr) {
			cout << Print->data << " - ";
			Print = Print->link;
			i++;
		}
		cout << Print->data<< endl;
		cout << "데이터 개수 : " << i << "개\n" << endl;
	}
private:
	Node* pHead = nullptr;
	Node* pPoint = nullptr;
};
int main() {
	CMyList hello;
	int choice = 99, answer=0;
	while (1) {
		cout << "--------------------- \nCMyList 메뉴\n1 삽입\n2 출력\n0 종료\n---------------------\n메뉴를 고르세요(숫자 입력) :";
		cin >> choice;
		if (cin.fail() == false) {
			cin.clear();
			cin.ignore(1024, '\n');
			if (choice == 1) {
				cout << endl;
				cout << "삽입할 데이터를 입력해주세요 : ";
				cin >> answer;
				while (cin.fail() == true) {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "숫자를 입력하세요~!\n" << endl;
					cout << "삽입할 데이터를 입력해주세요 : ";
					cin >> answer;
				}
				cin.clear();
				cin.ignore(1024, '\n');
				hello.Insert(answer);
			}
			else if (choice == 2) {
				cout << endl;
				hello.PrintData();
			}
			else if (choice == 0) {
				break;
			}
			else {
				cout << "0, 1, 2 중 숫자를 입력하세요~!" << endl;
			}
		}
		else {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "0, 1, 2 중 숫자를 입력하세요~!" << endl;
		}
	}
}