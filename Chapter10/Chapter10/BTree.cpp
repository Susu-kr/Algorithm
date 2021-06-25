#include "BTree.h"
/*
	����
	���� Ʈ���� Ȱ���� �˻� ���α׷��� �ۼ��϶�
	����/����/�˻�/���/����

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
	else if (node->data.num < tree->data.num) { // ���� ��� �ܰ迡���� Ʈ���� ��Ʈ�� ũ�� ��
		if (tree->left == NULL) {// root ���� �۰� �����ڽ��� ���� ���
			tree->left = node;
			tree->left->height = tree->height + 1;
			Max_Height = tree->left->height;
			length++;
		}
		else // ���� �ڽ��� ���� -> ���� �ڽĺ��� �ٽ� ��Һ�
			BST_InsertNode(tree->left, node);
	}
	else if (node->data.num > tree->data.num) { // root���� ū���
		if (tree->right == NULL) {
			tree->right = node;
			tree->right->height = tree->height + 1;
			Max_Height = tree->right->height;
			length++;
		}
		else // ������ �ڽ��� ���� -> ������ �ڽĺ��� �ٽ� ��Һ�
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
			������ ��� : tree	, ������ ����� �θ� : parent
			������ ���(tree)�� removeNode�� ���� �� ����
		*/
	if (tree == NULL) return NULL; // root �������� ����

	Node * removeNode = NULL;
	if (tree->data.num > target)
		removeNode = BST_RemoveNode(tree->left, tree, target);
	else if (tree->data.num < target)
		removeNode = BST_RemoveNode(tree->right, tree, target);
	else if (tree->data.num == target) {
		removeNode = tree;
		// 1. �����Ϸ��� ����� �ڽ� ����Ʈ���� 0�� ��� (�ܸ����)
		if (tree->left == NULL && tree->right == NULL) {
			if (parent->left == tree) parent->left = NULL;
			if (parent->right == tree) parent->right = NULL;
		}

		// 2. �����Ϸ��� ����� �ڽ� ����Ʈ���� 1�� ���
		else if (tree->left == NULL || tree->right == NULL) {
			Node * temp = NULL;
			if (tree->left != NULL) temp = tree->left;
			else temp = tree->right;

			if (parent->left == tree) parent->left = temp;
			else parent->right = temp;
		}

		// 3. �����Ϸ��� ����� �ڽ� ����Ʈ���� 2�� ���
		else if (tree->left != NULL && tree->right != NULL) {
			// ������ ����� ���� ����Ʈ������ ũ��, ������ ����� ������ ����Ʈ������ �۾ƾ���
			Node * min = BST_SearchMinNode(tree->right);
			min = BST_RemoveNode(tree, NULL, min->data.num);
			tree->data = min->data;
		}
	}
	return removeNode;
}

void BST::BST_PreOrder(Node * tree, vector<DATA>& pre)
{	// ���湮 -> ���� �ڽ� -> ������ �ڽ�
	if (tree == NULL) return;
	pre.push_back(tree->data);
	BST_PreOrder(tree->left, pre);
	BST_PreOrder(tree->right, pre);
}

void BST::BST_InOrder(Node * tree, vector<DATA>& in)
{	// ���� �ڽ� -> ���湮 -> ������ �ڽ�
	if (tree == NULL) return;
	BST_InOrder(tree->left, in);
	in.push_back(tree->data);
	BST_InOrder(tree->right, in);
}

void BST::BST_PostOrder(Node * tree, vector<DATA>& pos)
{	// ���� �ڽ� -> ������ �ڽ� -> ��� �湮
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



