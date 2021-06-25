/*
	����1.
	�Է� ������ ������� ��ȣ ������� ���ĵ� ����Ʈ�� �����ϴ� ���α׷��� �ۼ��϶�.
	1. ����Ʈ �ʱ�ȭ
	2. ��� �߰�
		2.1 ���� �տ� �߰�
		2.2 �ǵڿ� �߰�
		2.3 ��� ���̿� �߰�
	3. ��� ����
		3.1 ���� �� ��� ����
		3.2 �� �� ��� ����
		3.3 ���� ��� ����
	4. �˻�
		��ȣ�� �Է� �޾Ƽ� �ش� ��ȣ�� �̸� ���
	5. ���
		����Ʈ ��ü ������ ���

	ex)
	�޴� ����
		1. �л� �߰�
		2. �л� ����
		3. ��ü ���
		4. ����

		1 -> ��ȣ : 3
			 �̸� : ȫ�浿
		1 -> ��ȣ : 2
			 �̸� : ���
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
	bool empty() const; // ����Ʈ�� ����ִ��� Ȯ��
	int ListSize();
	void insertFront(string name, int count); // �� �տ� ����
	void insertBack(string name, int count); // �� �ڿ� ����
	void insertSearch(int num, string name, int count); // ������ ��ġ�� ã�� ����
	void removeFront(); // �� ���� ����
	void removeBack(); // �� �ڸ� ����
	void removeIndex(int num); // �ش���ġ�� ��� ����
	void removeSearch(int count); // ������ ����� ã�� ����
	void removeSearch(string name); // ������ ����� ã�� ����
	void SearchList(int count); // �˻�
	void show(); // ���
	void sortingInsert(string name, int count); // ����
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
		//cout << "����Ʈ�� ��������Ƿ� �� �տ� ����\n";
		insertFront(n, c);
	}
	else {
		if (ListSize()-1 < num) {
			//cout << "�����ϰ��� �ϴ� ��ġ�� ����Ʈ ������� ũ�Ƿ� �ǵڿ� ����\n";
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
	if(head == NULL) cout << "����Ʈ�� ����־� ������ �Ұ����մϴ�.\n";
	else {
		Node * cur = head->next;
		delete head;
		head = cur;
	}
}

void List::removeBack()
{
	if (head == NULL) cout << "����Ʈ�� ����־� ������ �Ұ����մϴ�.\n";
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
	if (head == NULL) cout << "����Ʈ�� ��������Ƿ� ���� ����.\n";
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
	if (head == NULL) cout << "����Ʈ�� ����ֽ��ϴ�.\n";
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
			cout << "�ش� ��尡 �������� �ʽ��ϴ�.\n";
		}
	}
}

void List::removeSearch(string n)
{
	if (head == NULL) cout << "����Ʈ�� ����ֽ��ϴ�.\n";
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
			else cout << "�ش� ��尡 �������� �ʽ��ϴ�.\n";
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
	if (cnt == 0) cout << "�ش� ��尡 �������� �ʽ��ϴ�.\n";
}

void List::show()
{
	Node * cur = head;
	if (head == NULL) {
		cout << "����Ʈ�� ����ֽ��ϴ�.\n";
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
		//cout << "����Ʈ�� ��������Ƿ� �Ǿտ� ����\n";
		insertFront(n, c);
	}
	else {
		int min = head->count;
		bool chk = false;
		if (min > c) {
			//cout << "�� ���� ��庸�� ���� �����Ƿ� �� �տ� ����\n";
			insertFront(n, c);
		}
		else {
			Node * cur = head;
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

int main() {
	List student;
	cout << "�޴� ����\n";
	cout << "1. �л� �߰�\n2. �л� ����\n3. ��ü ���\n4. ����\n";
	int N;
	cin >> N;
	int count;
	string name;
	while (1) {
		switch (N)
		{
		case 1:
			cout << "��ȣ : ";
			cin >> count;
			cout << "�̸� : ";
			cin >> name;
			student.sortingInsert(name, count);
			break;
		case 2:
			cout << "1. ��ȣ�� ����, 2. �̸����� ���� : ";
			cin >> count;
			while (1) {
				if (count == 1) {
					cout << "�����Ͻ� ��ȣ�� �Է��ϼ��� : ";
					cin >> count;
					student.removeSearch(count);
					break;
				}
				else if (count == 2) {
					cout << "�����Ͻ� �̸��� �Է��ϼ��� : ";
					cin >> name;
					student.removeSearch(name);
					break;
				}
				else {
					cout << "1. ��ȣ�� ����, 2. �̸����� ���� : ";
					cin >> count;
				}
			}
			break;
		case 3:
			cout << "���\n";
			student.show();
			break;
		case 4:
			cout << "���α׷��� �����մϴ�.\n";
			return 0;
		}
		cout << "1. �л� �߰�\n2. �л� ����\n3. ��ü ���\n4. ����\n";
		cin >> N;
	}
	return 0;
}