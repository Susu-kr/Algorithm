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
		//cout << "����Ʈ�� ��������Ƿ� �� �տ� ����\n";
		insertFront(n, c);
	}
	else {
		if (ListSize() - 1 < num) {
			//cout << "�����ϰ��� �ϴ� ��ġ�� ����Ʈ ������� ũ�Ƿ� �ǵڿ� ����\n";
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
		//cout << "����Ʈ�� ��������Ƿ� �Ǿտ� ����\n";
		insertFront(n, c);
	}
	else {
		int min = head->next->count;
		bool chk = false;
		if (min > c) {
			//cout << "�� ���� ��庸�� ���� �����Ƿ� �� �տ� ����\n";
			insertFront(n, c);
		}
		else {
			Node * cur = head->next;
			int cnt = 0;
			while (cur->next != NULL) {
				cur = cur->next;
				cnt++;
				if (cur->count > c) {
					//cout << cnt - 1 << "��° ��庸�� ���� ũ��, " << cnt << "��° ��庸�� ���� �����Ƿ�" << cnt << "��°�� ����\n";
					insertSearch(cnt, n, c);
					chk = true;
					break;
				}
			}
			if (!chk) {
				//cout << "�����Ϸ��� ����� ���� ���� ũ�Ƿ� �ǵڿ� ����\n";
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
	if (head->next == tail) cout << "����Ʈ�� ��������Ƿ� ���� ����.\n";
	else {
		if (ListSize() < num) {
			//cout << "�����ϰ��� �ϴ� ��ġ�� ����Ʈ ������� ũ�Ƿ� �ǵڿ� ����\n";
			removeBack();
		}
		else if (num <= 0) {
			//cout << "�����ϰ��� �ϴ� ��ġ�� 0�̰ų� ������ �� �� ����\n";
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
	if (head->next == tail) cout << "����Ʈ�� ����ֽ��ϴ�.\n";
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
			cout << "�ش� ��尡 �������� �ʽ��ϴ�.\n";
		}
	}
}

void List::removeSearch(string n)
{
	if (head->next == tail) cout << "����Ʈ�� ����ֽ��ϴ�.\n";
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
			else cout << "�ش� ��尡 �������� �ʽ��ϴ�.\n";
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
	if (cnt == 0) cout << "�ش� ��尡 �������� �ʽ��ϴ�.\n";
}

void List::show()
{
	if (head->next == tail) {
		cout << "����Ʈ�� ����ֽ��ϴ�.\n";
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
