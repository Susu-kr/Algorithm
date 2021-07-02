#include <iostream>
#include "Hash.h"

using namespace std;

typedef enum {
	TERMINATE, INSERT, REMOVE, SEARCH, CLEAR, DUMP
}Menu;

Menu SelectMenu(void) {
	int ch;
	do {
		cout << "(1)�߰� (2)���� (3)�˻� (4)��� ���� (5)���� (0)���� : ";
		cin >> ch;
	} while (ch < TERMINATE || ch > DUMP);
	return(Menu)ch;
}

int main(void) {
	Menu menu = CLEAR;
	HashTable hash;
	hash.Initialize(&hash, 13);
	while (menu != TERMINATE) {
		int result;
		Node * temp = new Node();
		switch (menu = SelectMenu())
		{
		case INSERT:
		{
			int num;
			string name;
			cout << "��ȣ : ";
			cin >> num;
			cout << "�̸� : ";
			cin >> name;
			temp->data.num = num;
			temp->data.name = name;
			result = hash.Insert(&hash, temp);
			if (result == 1) cout << "�ߺ��Դϴ�.\n";
			else if (result == 2) cout << "�޸� ����\n";
		}
			break;
		case REMOVE:
		{
			cout << "��ȣ : ";
			int n;
			cin >> n;
			result = hash.Remove(&hash, n);
			if (result == 1) cout << "�� ��ȣ�� �����Ͱ� �������� �ʽ��ϴ�.\n";
		}
			break;
		case SEARCH:
		{
			int n;
			cout << "�˻��� ��ȣ�� �Է� : ";
			cin >> n;
			temp = hash.Search(&hash, n);
			if (temp == NULL) cout << "�˻��� �����߽��ϴ�.\n";
			else {
				cout << temp->data.num << ", " << temp->data.name << endl;
			}
		}
			break;
		case CLEAR:
			hash.Clear(&hash);
			break;
		case DUMP:
			hash.Dump(&hash);
			break;
		}
	}
	hash.Terminate(&hash);
	return 0;
}