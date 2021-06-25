#pragma once
#include <string>
#include <iostream>

using namespace std;

class Node {
private:
	string name;
	int count;
	Node* next;
	Node* prev;
	friend class List;
};

class List {
private:
	Node * head;
	Node * tail;
public:
	List();
	~List();
	bool empty() const { return head->next == tail; }; // ����Ʈ�� ����ִ��� Ȯ��
	int ListSize();
	void insert(Node * v, string name, int count);
	void insertFront(string name, int count) { insert(head, name, count); } // �� �տ� ����
	void insertBack(string name, int count) { insert(tail->prev, name, count); }// �� �ڿ� ����
	void insertSearch(int num, string name, int count); // ������ ��ġ�� ã�� ����
	void sortingInsert(string name, int count); // ���Ļ���.
	void remove(Node * v);
	void removeFront() { remove(head->next); } // �� ���� ����
	void removeBack() {	remove(tail->prev);	}; // �� �ڸ� ����
	void removeIndex(int num); // �ش���ġ�� ��� ����
	void removeSearch(int count); // ������ ����� ã�� ����
	void removeSearch(string name); // ������ ����� ã�� ����
	void SearchList(int count); // �˻�
	void show(); // ���
};
