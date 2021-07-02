#include <iostream>
#include "Hash.h"

using namespace std;

typedef enum {
	TERMINATE, INSERT, REMOVE, SEARCH, CLEAR, DUMP
}Menu;

Menu SelectMenu(void) {
	int ch;
	do {
		cout << "(1)추가 (2)삭제 (3)검색 (4)모두 삭제 (5)덤프 (0)종료 : ";
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
			cout << "번호 : ";
			cin >> num;
			cout << "이름 : ";
			cin >> name;
			temp->data.num = num;
			temp->data.name = name;
			result = hash.Insert(&hash, temp);
			if (result == 1) cout << "중복입니다.\n";
			else if (result == 2) cout << "메모리 부족\n";
		}
			break;
		case REMOVE:
		{
			cout << "번호 : ";
			int n;
			cin >> n;
			result = hash.Remove(&hash, n);
			if (result == 1) cout << "이 번호의 데이터가 존재하지 않습니다.\n";
		}
			break;
		case SEARCH:
		{
			int n;
			cout << "검색할 번호를 입력 : ";
			cin >> n;
			temp = hash.Search(&hash, n);
			if (temp == NULL) cout << "검색에 실패했습니다.\n";
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