#include "Hash.h"

int HashTable::Initialize(HashTable * h, int size)
{
	if ((h->table = (Node**)calloc(size, sizeof(Node *))) == NULL) {
		h->size = 0;
		return 0;
	}
	h->size = size;
	for (int i = 0; i < size; i++)
		h->table[i] = NULL;
	return 1;
}

Node * HashTable::Search(const HashTable * h, int n)
{
	int key =n % h->size;				// 검색하는 데이터의 해시 값
	Node * p = h->table[key];				// 선택한 노드
	while (p != NULL) {
		if (p->data.num == n) return p;// 검색 성공
		p = p->next;						// 다음 노드 검색
	}
	return NULL;							// 실패
}

int HashTable::Insert(HashTable * h, Node * d)
{
	int key = d->data.num % h->size;
	Node * p = h->table[key];
	while (p != NULL) {
		if (p->data.num == d->data.num) return 1; // 이미 등록된 키
		p = p->next;
	}
	Node * temp;
	if ((temp = (Node*)calloc(1, sizeof(Node))) == NULL) return 2;
	temp = d;
	temp->next = h->table[key];
	h->table[key] = temp;
	return 0;
}

int HashTable::Remove(HashTable * h, int n)
{
	int key =n % h->size;
	Node * p = h->table[key];		// 현재 노드
	Node ** pp = &h->table[key];		// 현재 선택한 노드에 대한 포인터
	while (p != NULL) {
		if (p->data.num == n) {
			*pp = p->next;
			free(p);
			return 0;
		}
		pp = &p->next;
		p = p->next;
	}
	return 1;
}

void HashTable::Dump(const HashTable * h)
{
	for (int i = 0; i < h->size; i++) {
		Node * p = h->table[i];
		cout << i << " ";
		while (p != NULL) {
			cout << "-> " << p->data.num << ", " << p->data.name << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void HashTable::Clear(HashTable * h)
{
	for (int i = 0; i < h->size; i++) {
		Node * p = h->table[i];
		while (p != NULL) {
			Node * next = p->next;
			free(p);
			p = next;
		}
		h->table[i] = NULL;
	}
}

void HashTable::Terminate(HashTable * h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
}
