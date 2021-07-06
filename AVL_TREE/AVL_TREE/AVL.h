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
	int		GetHeight(Node * node);		// ����� ���� ��ȯ
	void 	SetHeight(Node * node);		// ȸ���� ������ ���Ŀ� ���� �缳��
	int		GetDiff(Node * node);		// ������ ���̸� ��ȯ
	Node*	LL(Node * node);			// LLȸ��
	Node*	RR(Node * node);			// RRȸ��
	Node*	LR(Node * node);			// LRȸ��
	Node*	RL(Node * node);			// RLȸ��
	Node*	balance(Node * node);		// Ʈ���� ���� ���߱�
	Node*	minNode(Node * node);		// ������ �ڽĿ��� �ּҰ� ��� ã��
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