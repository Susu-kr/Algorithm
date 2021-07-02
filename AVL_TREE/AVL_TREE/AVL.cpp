#include "AVL.h"

int AVL::GetHeight(Node * node)
{
	if (node == NULL) return 0;
	
	return node->height;
}

void AVL::SetHeight(Node * node)
{
	int h = 0;
	if (node != NULL) {
		int left = GetHeight(node->left);
		int right = GetHeight(node->right);
		h = GetMax(GetHeight(node->left), GetHeight(node->right)) + 1;
	}
    node->height = h;
}

int AVL::GetDiff(Node * node)
{
	if (node == NULL) return 0;
	return GetHeight(node->left) - GetHeight(node->right);
}

Node * AVL::LL(Node * node)
{
	Node * leftChild = node->left;
	node->left = leftChild->right;	// 해당 노드의 왼쪽자식 = 왼쪽자식의 오른쪽자식
	leftChild->right = node;		// 왼쪽자식의 오른쪽자식 = 해당 노드
	return leftChild;
}

Node * AVL::RR(Node * node)
{
	Node * rightChild = node->right;
	node->right = rightChild->left; // 해당 노드의 오른쪽자식 = 오른쪽자식의 왼쪽자식
	rightChild->left = node;		 // 오른쪽자식의 왼쪽자식 = 해당 노드
	return rightChild;
}

Node * AVL::LR(Node * node)
{
	Node * leftChild = node->left;
	node->left = RR(leftChild);	 // RR 수행 후 LL 수행
	return LL(node);
}

Node * AVL::RL(Node * node)
{
	Node * rightChild = node->right;
	node->right = LL(rightChild);	 // LL 수행 후 RR 수행
	return RR(node);
}

Node * AVL::balance(Node * node)
{
	if (node == NULL) return NULL;
	node->left = balance(node->left);
	node->right = balance(node->right);
	int diff = GetDiff(node);
	if (diff > 1) { // LL LR
		if (GetDiff(node->left) > 0)
			node = LL(node);
		else
			node = LR(node);
	}
	else if (diff < -1) { // RR RL
		if (GetDiff(node->right) <= -1)
			node = RR(node);
		else
			node = RL(node);
	}
	SetHeight(node);
	return node;
}

Node * AVL::minNode(Node * node)
{
	if (node == NULL) return NULL;
	if (node->left == NULL) return node;
	else return minNode(node->left);
}

Node * AVL::search(Node * node, int num)
{
	if (node == NULL) return NULL;
	if (node->num == num) return node;
	else if (node->num > num) search(node->left, num);
	else if (node->num < num) search(node->right, num);
	return nullptr;
}

bool AVL::insert_Recursive(Node *& node, int num, string name)
{
	if (node == NULL) {
		Node * temp = new Node();
		temp->num = num;
		temp->name = name;
		temp->height = 1;
		temp->left = NULL;
		temp->right = NULL;
		node = temp;
	}
	else if (num < node->num) { // 왼쪽 자식
		insert_Recursive(node->left, num, name);
		node = balance(node);
	}
	else if (num > node->num) {
		insert_Recursive(node->right, num, name);
		node = balance(node);
	}
	else {
		cout << "데이터 중복" << endl;
		return false;
	}
	return true;
}

bool AVL::insert(int num, string name)
{
	return insert_Recursive(this->root, num, name);
}

Node * AVL::remove_Recursive(Node * node, Node * parent, int num)
{
	if (node == NULL) return NULL;
	Node * removeNode = NULL;
	if (num < node->num) {
		removeNode = remove_Recursive(node->left, node, num);
	}
	else if (num > node->num) {
		removeNode = remove_Recursive(node->right, node, num);
	}
	else if(node->num == num){
		removeNode = node;
		if (node->left == NULL && node->right == NULL) {
			if (parent->left == node) parent->left = NULL;
			if (parent->right == node) parent->right = NULL;
		}
		if (node->left == NULL || node->right == NULL) {
			// 자식 둘 중 하나가 NULL
			Node* temp = NULL;
			if (node->left != NULL) temp = node->left; // 왼쪽 자식이 NULL
			else temp = node->right;

			if (parent->left == node) parent->left = temp;
			else parent->right = temp; // 오른쪽 자식이 NULL
		}
		// 3. 삭제하려는 노드의 자식 서브트리가 2인 경우
		else if (node->left != NULL && node->right != NULL) {
			// 삭제될 노드의 왼쪽 서브트리보다 크고, 삭제될 노드의 오른쪽 서브트리보단 작아야함
			Node * min = minNode(node->right);
			min = remove_Recursive(node, NULL, min->num);
			node->num = min->num;
		}
	}
	return removeNode;
}

Node * AVL::remove(int num)
{
	Node * temp = remove_Recursive(root, NULL, num);
	balance(root);
	return temp;
}

void AVL::Show_Recursive(Node * node, int level)
{
	if (node != NULL) {
		Show_Recursive(node->right, level + 1);
		cout << "\n";
		if (node == root) {
			cout << "Root : ";
		}
		for (int i = 0; i < level && node != root; i++) {
			cout << "\t";
		}
		cout << node->num << "," << node->name << "(" << node->height << ")\t";
		Show_Recursive(node->left, level + 1);
	}
}

void AVL::Show(int level)
{
	Show_Recursive(root, level);
	cout << endl;
}

void AVL::Delete(Node * node)
{
	if (node == NULL) return;
	Delete(node->left);
	Delete(node->right);
	delete node;
}

void AVL::preorder(Node * node)
{
	if (node == NULL) return;
	cout << node->num << "," << node->name << " ";
	preorder(node->left);
	preorder(node->right);
}

void AVL::inorder(Node * node)
{
	if (node == NULL) return;
	inorder(node->left);
	cout << node->num << "," << node->name << " ";
	inorder(node->right);
}

void AVL::postorder(Node * node)
{
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->num << "," << node->name << " ";
}

