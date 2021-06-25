/*
	문제1.
	입력 순서와 상관없이 번호 순서대로 정렬된 리스트를 구현하는 프로그램을 작성하라.
	1. 리스트 초기화
	2. 노드 추가
		2.1 제일 앞에 추가
		2.2 맨뒤에 추가
		2.3 노드 사이에 추가
	3. 노드 삭제
		3.1 제일 앞 노드 삭제
		3.2 맨 뒤 노드 삭제
		3.3 사이 노드 삭제
	4. 검색
		번호를 입력 받아서 해당 번호의 이름 출력
	5. 출력
		리스트 전체 데이터 출력

	ex)
	메뉴 선택
		1. 학생 추가
		2. 학생 삭제
		3. 전체 출력
		4. 종료

		1 -> 번호 : 3
			 이름 : 홍길동
		1 -> 번호 : 2
			 이름 : 김모씨
*/

#include <string>
#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main() {
	List student;
	cout << "메뉴 선택\n";
	cout << "1. 학생 추가  2. 학생 삭제  3. 전체 출력  4. 검색  5. 종료 : ";
	int N;
	cin >> N;
	int count;
	string name;
	while (1) {
		switch (N)
		{
		case 1:
			cout << "번호 : ";
			cin >> count;
			cout << "이름 : ";
			cin >> name;
			student.sortingInsert(name, count);
			break;
		case 2:
			cout << "1. 번호로 삭제, 2. 이름으로 삭제 : ";
			cin >> count;
			while (1) {
				if (count == 1) {
					cout << "삭제하실 번호를 입력하세요 : ";
					cin >> count;
					student.removeSearch(count);
					break;
				}
				else if (count == 2) {
					cout << "삭제하실 이름을 입력하세요 : ";
					cin >> name;
					student.removeSearch(name);
					break;
				}
				else {
					cout << "1. 번호로 삭제, 2. 이름으로 삭제 : ";
					cin >> count;
				}
			}
			break;
		case 3:
			cout << "출력\n";
			student.show();
			break;
		case 4:
			cout << "검색할 번호를 입력하세요 : ";
			cin >> count;
			student.SearchList(count);
			break;
		case 5:
			cout << "프로그램을 종료합니다.\n";
			return 0;
		}
		cout << "1. 학생 추가  2. 학생 삭제  3. 전체 출력  4. 검색  5. 종료 : ";

		cin >> N;
	}
	return 0;
}


