#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct DATA {
	int num;
	string name;
};

class Node {
public:
	DATA data;
	int height;
	Node* left = NULL;
	Node* right = NULL;
	Node(DATA d) : data({ d.num, d.name }), left(NULL), right(NULL) {}
};


class BST {
private:
	Node * root;
	int Max_Height;
	int length;
public:
	BST() : root(NULL) {}
	Node * getRoot() { return root; }
	Node * BST_SearchNode(Node * tree, int target);
	void BST_InsertNode(Node* tree, Node * node);
	Node * BST_SearchMinNode(Node * tree);
	Node * BST_RemoveNode(Node * tree, Node * parent, int target);
	void BST_PreOrder(Node * tree, vector<DATA> & pre);
	void BST_InOrder(Node * tree, vector<DATA> & in);
	void BST_PostOrder(Node * tree, vector<DATA> & pos);
	void BST_Print(Node * tree); // InOrder : 오름차순
	void BST_TreePrint(Node * tree); // BFS
	void BST_Delete(Node * tree);
};