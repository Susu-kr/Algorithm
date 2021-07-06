#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Node {
	int				height;
	int				num;
	string			name;
	struct Node *	left;
	struct Node *	right;
};

class AVL
{
private:
	Node * root;

public:
	AVL() { root = nullptr; }
	Node*	GetRoot() { return root; }
	int		GetMax(int a, int b) { return a > b ? a : b; }
	int		GetHeight(Node * node);		// 노드의 높이 반환
	void 	SetHeight(Node * node);		// 회전을 수행한 이후에 높이 재설정
	int		GetDiff(Node * node);		// 높이의 차이를 반환
	Node*	LL(Node * node);			// LL회전
	Node*	RR(Node * node);			// RR회전
	Node*	LR(Node * node);			// LR회전
	Node*	RL(Node * node);			// RL회전
	Node*	balance(Node * node);		// 트리의 균형 맞추기
	Node*	minNode(Node * node);		// 오른쪽 자식에서 최소값 노드 찾기
	Node*	search(Node * node, int num);
	Node*	insert_Recursive(Node *& node, int num, string name);
	void	insert(int num, string name);
	Node*	remove_Recursive(Node * node, int num);
	void	remove(int num);
	void	Show_Recursive(Node * node, int level);
	void	Show(int level);
	void	Delete(Node * node);

	void	preorder(Node * node);
	void	inorder(Node * node);
	void	postorder(Node * node);


};