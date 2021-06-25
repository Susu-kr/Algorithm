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
	bool empty() const { return head->next == tail; }; // 리스트가 비어있는지 확인
	int ListSize();
	void insert(Node * v, string name, int count);
	void insertFront(string name, int count) { insert(head, name, count); } // 맨 앞에 삽입
	void insertBack(string name, int count) { insert(tail->prev, name, count); }// 맨 뒤에 삽입
	void insertSearch(int num, string name, int count); // 삽입할 위치를 찾아 삽입
	void sortingInsert(string name, int count); // 정렬삽입.
	void remove(Node * v);
	void removeFront() { remove(head->next); } // 맨 앞을 제거
	void removeBack() {	remove(tail->prev);	}; // 맨 뒤를 제거
	void removeIndex(int num); // 해당위치의 노드 삭제
	void removeSearch(int count); // 제거할 대상을 찾아 제거
	void removeSearch(string name); // 제거할 대상을 찾아 제거
	void SearchList(int count); // 검색
	void show(); // 출력
};
