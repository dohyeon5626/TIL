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
			//�ߺ�
			cout << num << " �� �ߺ��Դϴ�!" << endl;
		}
	}
	void	PrintData() {
		if (pHead == nullptr) {
			cout << "����� �����Ͱ� �����ϴ�." << endl;
			return;
		}
		Node* Print = pHead;
		int i = 1;
		cout << "CMyList ������ : ";
		while (Print->link != nullptr) {
			cout << Print->data << " - ";
			Print = Print->link;
			i++;
		}
		cout << Print->data<< endl;
		cout << "������ ���� : " << i << "��\n" << endl;
	}
private:
	Node* pHead = nullptr;
	Node* pPoint = nullptr;
};
int main() {
	CMyList hello;
	int choice = 99, answer=0;
	while (1) {
		cout << "--------------------- \nCMyList �޴�\n1 ����\n2 ���\n0 ����\n---------------------\n�޴��� ������(���� �Է�) :";
		cin >> choice;
		if (cin.fail() == false) {
			cin.clear();
			cin.ignore(1024, '\n');
			if (choice == 1) {
				cout << endl;
				cout << "������ �����͸� �Է����ּ��� : ";
				cin >> answer;
				while (cin.fail() == true) {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "���ڸ� �Է��ϼ���~!\n" << endl;
					cout << "������ �����͸� �Է����ּ��� : ";
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
				cout << "0, 1, 2 �� ���ڸ� �Է��ϼ���~!" << endl;
			}
		}
		else {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "0, 1, 2 �� ���ڸ� �Է��ϼ���~!" << endl;
		}
	}
}