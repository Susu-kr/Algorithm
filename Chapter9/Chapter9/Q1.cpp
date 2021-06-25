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

using namespace std;

class Node {
private:
	string name;
	int count;
	Node* next;
	friend class List;
};

class List {
private:
	Node * head;
public:
	List() : head(NULL) {}
	~List() { while (!empty()) removeFront(); }
	bool empty() const; // 리스트가 비어있는지 확인
	int ListSize();
	void insertFront(string name, int count); // 맨 앞에 삽입
	void insertBack(string name, int count); // 맨 뒤에 삽입
	void insertSearch(int num, string name, int count); // 삽입할 위치를 찾아 삽입
	void removeFront(); // 맨 앞을 제거
	void removeBack(); // 맨 뒤를 제거
	void removeIndex(int num); // 해당위치의 노드 삭제
	void removeSearch(int count); // 제거할 대상을 찾아 제거
	void removeSearch(string name); // 제거할 대상을 찾아 제거
	void SearchList(int count); // 검색
	void show(); // 출력
	void sortingInsert(string name, int count); // 정렬
};

bool List::empty() const
{
	return head == NULL;
}

int List::ListSize()
{
	int cnt = 1;
	Node * cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
		cnt++;
	}
	return cnt;
}

void List::insertFront(string n, int c)
{
	Node * temp = new Node;
	temp->name = n;
	temp->count = c;
	temp->next = head;
	head = temp;
}

void List::insertBack(string n, int c)
{
	if (head == NULL) {
		insertFront(n, c);
	}
	else {
		Node * cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		Node * temp = new Node;
		temp->name = n;
		temp->count = c;
		cur->next = temp;
	}
}

void List::insertSearch(int num, string n, int c)
{
	if (head == NULL) {
		//cout << "리스트가 비어있으므로 맨 앞에 삽입\n";
		insertFront(n, c);
	}
	else {
		if (ListSize()-1 < num) {
			//cout << "삽입하고자 하는 위치가 리스트 사이즈보다 크므로 맨뒤에 삽입\n";
			insertBack(n, c);
		}
		else {
			Node * cur = head;
			for (int i = 1; i < num; i++) {
				cur = cur->next;
			}
			Node * temp = new Node;
			temp->name = n;
			temp->count = c;
			temp->next = cur->next;
			cur->next = temp;
		}
	}
}

void List::removeFront()
{
	if(head == NULL) cout << "리스트가 비어있어 삭제가 불가능합니다.\n";
	else {
		Node * cur = head->next;
		delete head;
		head = cur;
	}
}

void List::removeBack()
{
	if (head == NULL) cout << "리스트가 비어있어 삭제가 불가능합니다.\n";
	else {
		if (head->next == NULL) removeFront();
		else {
			Node * cur = head;
			Node * temp = NULL;
			while (cur->next != NULL) {
				temp = cur;
				cur = cur->next;
			}
			temp->next = NULL;
			delete cur;
		}
	}
}

void List::removeIndex(int num)
{
	if (head == NULL) cout << "리스트가 비어있으므로 삭제 실패.\n";
	else {
		if (ListSize() < num) {
			//cout << "삭제하고자 하는 위치가 리스트 사이즈보다 크므로 맨뒤에 삭제\n";
			removeBack();
		}
		else if (num <= 0) {
			//cout << "삭제하고자 하는 위치가 0이거나 작으면 맨 앞 삭제\n";
			removeFront();
		}
		else {
			Node * cur = head;
			Node * temp = cur;
			for (int i = 0; i < num; i++) {
				temp = cur;
				cur = cur->next;
			}
			temp->next = cur->next;
			delete cur;
		}
	}
}

void List::removeSearch(int count)
{
	if (head == NULL) cout << "리스트가 비어있습니다.\n";
	else {
		if (head->count == count) {
			removeFront();
		}
		else {
			Node * cur = head;
			Node * temp = head;
			while (cur->next != NULL) {
				temp = cur;
				cur = cur->next;
				if (cur->count == count) {
					temp->next = cur->next;
					delete cur;
					return;
				}
			}
			cout << "해당 노드가 존재하지 않습니다.\n";
		}
	}
}

void List::removeSearch(string n)
{
	if (head == NULL) cout << "리스트가 비어있습니다.\n";
	else {
		if (head->name == n) {
			removeFront();
		}
		else {
			Node * cur = head;
			Node * temp = head;
			while (cur->next != NULL) {
				temp = cur;
				cur = cur->next;
				if (cur->name == n) {
					temp->next = cur->next;
					delete cur;
					return;
				}
			}
			if (cur->next == NULL && cur->name == n) {
				temp->next = NULL;
				delete cur;
			}
			else cout << "해당 노드가 존재하지 않습니다.\n";
		}
	}
}

void List::SearchList(int count)
{
	Node * cur = head;
	int cnt = 0;
	while (cur->next != NULL) {
		if (cur->count == count) {
			cnt++;
			cout << cur->count << ", " << cur->name << endl;
		}
		cur = cur->next;
	}
	if (cnt == 0) cout << "해당 노드가 존재하지 않습니다.\n";
}

void List::show()
{
	Node * cur = head;
	if (head == NULL) {
		cout << "리스트가 비어있습니다.\n";
	}
	else {
		while (cur != NULL) {
			cout << cur->count << ", " << cur->name << "\t";
			cur = cur->next;
		}
		cout << endl;
	}
}

void List::sortingInsert(string n, int c)
{
	if (head == NULL) {
		//cout << "리스트가 비어있으므로 맨앞에 삽입\n";
		insertFront(n, c);
	}
	else {
		int min = head->count;
		bool chk = false;
		if (min > c) {
			//cout << "맨 앞의 노드보다 값이 작으므로 맨 앞에 삽입\n";
			insertFront(n, c);
		}
		else {
			Node * cur = head;
			int cnt = 0;
			while (cur->next != NULL) {
				cur = cur->next;
				cnt++;
				if (cur->count > c) {
					//cout << cnt - 1 << "번째 노드보다 값이 크고, " << cnt << "번째 노드보다 값이 작으므로" << cnt << "번째에 삽입\n";
					insertSearch(cnt, n, c);
					chk = true;
					break;
				}
			}
			if (!chk) {
				//cout << "삽입하려는 노드의 값이 제일 크므로 맨뒤에 삽입\n";
				insertBack(n, c);
			}
		}
	}

}

int main() {
	List student;
	cout << "메뉴 선택\n";
	cout << "1. 학생 추가\n2. 학생 삭제\n3. 전체 출력\n4. 종료\n";
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
			cout << "프로그램을 종료합니다.\n";
			return 0;
		}
		cout << "1. 학생 추가\n2. 학생 삭제\n3. 전체 출력\n4. 종료\n";
		cin >> N;
	}
	return 0;
}