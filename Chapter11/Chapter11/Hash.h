#pragma once
#ifndef HASH_H_
#define HASH_H_
/*
	해쉬테이블 프로그램 작성
	삽입/삭제/검색/모두삭제/출력/종료
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
	int Initialize(HashTable *h, int size); // 해시 테이블 초기화
	Node *Search(const HashTable * h, int n); // 검색
	int Insert(HashTable * h, Node * d); // 데이터 추가
	int Remove(HashTable * h, int n); // 데이터 삭제
	void Dump(const HashTable * h); // 해시 테이블 덤프(dump) 출력
	void Clear(HashTable * h); // 모든 데이터 삭제
	void Terminate(HashTable * h); // 해시 테이블 종료
};

#endif // !HASH_H_
