#pragma once
#ifndef HASH_H_
#define HASH_H_
/*
	�ؽ����̺� ���α׷� �ۼ�
	����/����/�˻�/��λ���/���/����
*/
#include <string>
#include <iostream>

using namespace std;

struct DATA {
	int		num;
	string	name;
};

class Node{
public:
	DATA data;
	Node * next;
	Node() : data({ 0, "" }), next(NULL) {}
};

class HashTable {
private:
	int		size;
	Node	**table;
public:
	int Initialize(HashTable *h, int size); // �ؽ� ���̺� �ʱ�ȭ
	Node *Search(const HashTable * h, int n); // �˻�
	int Insert(HashTable * h, Node * d); // ������ �߰�
	int Remove(HashTable * h, int n); // ������ ����
	void Dump(const HashTable * h); // �ؽ� ���̺� ����(dump) ���
	void Clear(HashTable * h); // ��� ������ ����
	void Terminate(HashTable * h); // �ؽ� ���̺� ����
};

#endif // !HASH_H_
