#include "BTree.h"
/*
	문제
	이진 트리를 활용한 검색 프로그램을 작성하라
	삽입/삭제/검색/출력/종료

*/

Node * BST::BST_SearchNode(Node * tree, int target)
{
	if (tree == NULL) return NULL;
	if (tree->data.num == target) return tree;
	else if (tree->data.num > target)
		BST_SearchNode(tree->left, target);
	else if (tree->data.num < target)
		BST_SearchNode(tree->right, target);
}

void BST::BST_InsertNode(Node * tree, Node * node)
{
	if (root == NULL) {
		root = node;
		root->height = 0;
		Max_Height = 0;
		length = 1;
		return;
	}
	else if (node->data.num < tree->data.num) { // 현재 재귀 단계에서의 트리의 루트와 크기 비교
		if (tree->left == NULL) {// root 보다 작고 왼쪽자식이 없는 경우
			tree->left = node;
			tree->left->height = tree->height + 1;
			Max_Height = tree->left->height;
			length++;
		}
		else // 왼쪽 자식이 존재 -> 왼쪽 자식부터 다시 대소비교
			BST_InsertNode(tree->left, node);
	}
	else if (node->data.num > tree->data.num) { // root보다 큰경우
		if (tree->right == NULL) {
			tree->right = node;
			tree->right->height = tree->height + 1;
			Max_Height = tree->right->height;
			length++;
		}
		else // 오른쪽 자식이 존재 -> 오른쪽 자식부터 다시 대소비교
			BST_InsertNode(tree->right, node);
	}
}

Node * BST::BST_SearchMinNode(Node * tree)
{
	if (tree == NULL) return NULL;
	if (tree->left == NULL) return tree;
	else return BST_SearchMinNode(tree->left);
}

Node * BST::BST_RemoveNode(Node * tree, Node * parent, int target)
{
	/*
			삭제할 노드 : tree	, 삭제할 노드의 부모 : parent
			삭제할 노드(tree)는 removeNode에 저장 후 리턴
		*/
	if (tree == NULL) return NULL; // root 에서부터 시작

	Node * removeNode = NULL;
	if (tree->data.num > target)
		removeNode = BST_RemoveNode(tree->left, tree, target);
	else if (tree->data.num < target)
		removeNode = BST_RemoveNode(tree->right, tree, target);
	else if (tree->data.num == target) {
		removeNode = tree;
		// 1. 삭제하려는 노드의 자식 서브트리가 0인 경우 (단말노드)
		if (tree->left == NULL && tree->right == NULL) {
			if (parent->left == tree) parent->left = NULL;
			if (parent->right == tree) parent->right = NULL;
		}

		// 2. 삭제하려는 노드의 자식 서브트리가 1인 경우
		else if (tree->left == NULL || tree->right == NULL) {
			Node * temp = NULL;
			if (tree->left != NULL) temp = tree->left;
			else temp = tree->right;

			if (parent->left == tree) parent->left = temp;
			else parent->right = temp;
		}

		// 3. 삭제하려는 노드의 자식 서브트리가 2인 경우
		else if (tree->left != NULL && tree->right != NULL) {
			// 삭제될 노드의 왼쪽 서브트리보다 크고, 삭제될 노드의 오른쪽 서브트리보단 작아야함
			Node * min = BST_SearchMinNode(tree->right);
			min = BST_RemoveNode(tree, NULL, min->data.num);
			tree->data = min->data;
		}
	}
	return removeNode;
}

void BST::BST_PreOrder(Node * tree, vector<DATA>& pre)
{	// 노드방문 -> 왼쪽 자식 -> 오른쪽 자식
	if (tree == NULL) return;
	pre.push_back(tree->data);
	BST_PreOrder(tree->left, pre);
	BST_PreOrder(tree->right, pre);
}

void BST::BST_InOrder(Node * tree, vector<DATA>& in)
{	// 왼쪽 자식 -> 노드방문 -> 오른쪽 자식
	if (tree == NULL) return;
	BST_InOrder(tree->left, in);
	in.push_back(tree->data);
	BST_InOrder(tree->right, in);
}

void BST::BST_PostOrder(Node * tree, vector<DATA>& pos)
{	// 왼쪽 자식 -> 오른쪽 자식 -> 노드 방문
	if (tree == NULL) return;
	BST_PostOrder(tree->left, pos);
	BST_PostOrder(tree->right, pos);
	pos.push_back(tree->data);
}

void BST::BST_Print(Node * tree)
{
	if (tree != NULL) {
		BST_Print(tree->left);
		cout << "(" << tree->data.num << ", " << tree->data.name << ") height : " << tree->height << "\n";
		BST_Print(tree->right);
	}
}

void BST::BST_TreePrint(Node * tree)
{

}

void BST::BST_Delete(Node * tree)
{
	if (tree == NULL) return;
	else {
		BST_Delete(tree->left);
		BST_Delete(tree->right);
	}
}



