#include "AVL.h"

int AVL::GetHeight(Node * node)
{
	if (node == NULL) return -1;
	return node->height;
}

void AVL::SetHeight(Node * node)
{
	if (node == NULL) { return; }
	node->height = GetMax(GetHeight(node->left), GetHeight(node->right)) + 1;
}

int AVL::GetDiff(Node * node)
{
	if (node == NULL) return 0;
	return GetHeight(node->left) - GetHeight(node->right);
}
/* LL(Y rotates to the left):
		k2                       k1
	   /  \                     /  \
	  X    k1         ==>      k2   Z
		  /  \                /  \
		 Y    Z              X    Y
 */
Node * AVL::LL(Node * node)
{
	Node * leftChild = node->left;
	node->left = leftChild->right;	// 해당 노드의 왼쪽자식 = 왼쪽자식의 오른쪽자식
	leftChild->right = node;		// 왼쪽자식의 오른쪽자식 = 해당 노드
	SetHeight(node);
	SetHeight(leftChild);
	return leftChild;
}
/* RR(Y rotates to the right):
		k2                   k1
	   /  \                 /  \
	  k1   Z     ==>       X   k2
	 / \                      /  \
	X   Y                    Y    Z
*/
Node * AVL::RR(Node * node)
{
	Node * rightChild = node->right;
	node->right = rightChild->left; // 해당 노드의 오른쪽자식 = 오른쪽자식의 왼쪽자식
	rightChild->left = node;		 // 오른쪽자식의 왼쪽자식 = 해당 노드
	SetHeight(node);
	SetHeight(rightChild);
	return rightChild;
}
/* LR(B rotates to the left, then C rotates to the right):
	  k3                         k3                       k2
	 /  \                       /  \                     /  \
	k1   D                     k2   D                   k1   k3
   /  \         ==>           /  \        ==>          / \   / \
  A    k2                    k1   C                   A  B  C   D
	  /  \                  /  \
	 B    C                A    B
*/
Node * AVL::LR(Node * node)
{
	Node * leftChild = node->left;
	node->left = RR(leftChild);	 // RR 수행 후 LL 수행
	return LL(node);
}
/* RL(D rotates to the right, then C rotates to the left):
	   k3                         k3                          k2
	  /  \                       /  \                        /  \
	 A    k1                    A    k2                     k3   k1
		 /  \       ==>             /  \         ==>       /  \  / \
		k2   B                     C    k1                A   C D   B
	   /  \                            /  \
	  C    D                          D    B
 */
Node * AVL::RL(Node * node)
{
	Node * rightChild = node->right;
	node->right = LL(rightChild);	 // LL 수행 후 RR 수행
	return RR(node);
}

Node * AVL::balance(Node * node)
{
	if (node == NULL) return NULL;
	int diff = GetDiff(node);
	if (diff == 2) { // LL LR
		if (GetDiff(node->left) == 1)
			node = LL(node);
		else
			node = LR(node);
	}
	else if (diff == -2) { // RR RL
		if (GetDiff(node->right) == -1)
			node = RR(node);
		else
			node = RL(node);
	}
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

Node* AVL::insert_Recursive(Node *& node, int num, string name)
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
		return node;
	}
	SetHeight(node);
	return node;
}

void AVL::insert(int num, string name)
{
	root = insert_Recursive(this->root, num, name);
}

Node * AVL::remove_Recursive(Node * node, int num)
{
	Node * temp = node;
	if (node == NULL) return NULL;
	if (num < node->num) node->left = remove_Recursive(node->left, num);
	else if (num > node->num) node->right = remove_Recursive(node->right, num);
	// 3. 삭제하려는 노드의 자식 서브트리가 2인 경우
	else if (node->left != NULL && node->right != NULL) {
		// 삭제될 노드의 왼쪽 서브트리보다 크고, 삭제될 노드의 오른쪽 서브트리보단 작아야함
		Node * min = minNode(node->right);
		node->num = min->num;
		node->name = min->name;
		node->left = remove_Recursive(node->left, min->num);
	}
	else {
		if (node->left == NULL) node = node->right;
		else if (node->right == NULL) node = node->left;
		delete temp;
	}
	SetHeight(node);
	node = balance(node);
	return node;
}

void AVL::remove(int num)
{
	root = remove_Recursive(this->root, num);
}

void AVL::Show_Recursive(Node * node, int level)
{
	if (node != NULL) {
		Show_Recursive(node->right, level + 1);
		cout << "\n";
		if (node == root) cout << "Root : ";
		for (int i = 0; i < level && node != root; i++)	cout << "\t";
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