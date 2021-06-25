#include "DoubleLinkedList.h"

List::List() {
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
}

List::~List() {
	while (!empty()) removeFront();
	delete head;
	delete tail;
}

int List::ListSize()
{
	int cnt = 0;
	Node * cur = head;
	while (cur->next != tail) {
		cur = cur->next;
		cnt++;
	}
	return cnt;
}

void List::insert(Node * v, string n, int c)
{
	Node * t = new Node;
	t->name = n;
	t->count = c;
	t->next = v->next;
	t->prev = v;
	v->next->prev = t;
	v->next = t;
}

void List::insertSearch(int num, string n, int c)
{
	if (head == NULL) {
		//cout << "리스트가 비어있으므로 맨 앞에 삽입\n";
		insertFront(n, c);
	}
	else {
		if (ListSize() - 1 < num) {
			//cout << "삽입하고자 하는 위치가 리스트 사이즈보다 크므로 맨뒤에 삽입\n";
			insertBack(n, c);
		}
		else {
			Node * cur = head->next;
			for (int i = 0; i < num; i++) {
				cur = cur->next;
			}
			insert(cur->prev, n, c);
		}
	}
}

void List::sortingInsert(string n, int c)
{
	if (head->next == tail) {
		//cout << "리스트가 비어있으므로 맨앞에 삽입\n";
		insertFront(n, c);
	}
	else {
		int min = head->next->count;
		bool chk = false;
		if (min > c) {
			//cout << "맨 앞의 노드보다 값이 작으므로 맨 앞에 삽입\n";
			insertFront(n, c);
		}
		else {
			Node * cur = head->next;
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

void List::remove(Node * v)
{
	Node * p = v->prev;
	Node * n = v->next;
	p->next = n;
	n->prev = p;
	delete v;
}

void List::removeIndex(int num)
{
	if (head->next == tail) cout << "리스트가 비어있으므로 삭제 실패.\n";
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
			Node * cur = head->next;
			for (int i = 0; i < num; i++) {
				cur = cur->next;
			}
			remove(cur);
		}
	}
}

void List::removeSearch(int count)
{
	if (head->next == tail) cout << "리스트가 비어있습니다.\n";
	else {
		if (head->next->count == count) removeFront();
		else {
			Node * cur = head->next;
			while (cur->next != NULL) {
				cur = cur->next;
				if (cur->count == count) {
					remove(cur);
					return;
				}
			}
			cout << "해당 노드가 존재하지 않습니다.\n";
		}
	}
}

void List::removeSearch(string n)
{
	if (head->next == tail) cout << "리스트가 비어있습니다.\n";
	else {
		if (head->next->name == n) 	removeFront();
		else {
			Node * cur = head->next;
			while (cur->next != NULL) {
				cur = cur->next;
				if (cur->name == n) {
					remove(cur);
					return;
				}
			}
			if (cur->next == NULL && cur->name == n) removeBack();
			else cout << "해당 노드가 존재하지 않습니다.\n";
		}
	}
}

void List::SearchList(int count)
{
	Node * cur = head->next;
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
	if (head->next == tail) {
		cout << "리스트가 비어있습니다.\n";
	}
	else {
		Node * cur = head->next;
		while (cur->next != NULL) {
			cout << cur->count << ", " << cur->name << "\t";
			cur = cur->next;
		}
		cout << endl;
	}
}
