#include <iostream>
#include <string>
#include <vector>
#include "BTree.h"

int main() {
	int N;
	string s;
	BST B;

	while (1) {
		cout << "(1) ����  (2) ����  (3) �˻�  (4) ���  (0) ���� : ";
		cin >> N;
		switch (N)
		{
		case 0: {
			cout << "���α׷� ����\n";
			B.BST_Delete(B.getRoot());
			return 0;
		}
			break;
		case 1: {
			cout << "�����ϴ� �����͸� �Է��ϼ���.\n��ȣ : ";
			cin >> N;
			cout << "�̸� : ";
			cin >> s;
			DATA D = { N, s };
			Node * temp = new Node(D);
			B.BST_InsertNode(B.getRoot(), temp);
		}
			break;
		case 2: {
			cout << "�����ϴ� �����͸� �Է��ϼ���.\n��ȣ : ";
			cin >> N;
			Node * temp = B.BST_RemoveNode(B.getRoot(), NULL, N);
			if (temp == NULL) cout << "�������� �ʴ� �������Դϴ�.\n";
			else cout << "�����Ǿ����ϴ�.\n";
		}
			break;
		case 3: {
			cout << "�˻��ϴ� �����͸� �Է��ϼ���.\n��ȣ : ";
			cin >> N;
			Node * temp = B.BST_SearchNode(B.getRoot(), N);
			if (temp == NULL) cout << "�������� �ʴ� �������Դϴ�.\n";
			else cout << temp->data.num << ", " << temp->data.name << endl;
		}
			break;
		case 4: {
			vector<DATA> pre, in, pos, DFS;
			cout << "Ʈ�� ���\n";
			B.BST_PreOrder(B.getRoot(), pre);
			B.BST_InOrder(B.getRoot(), in);
			B.BST_PostOrder(B.getRoot(), pos);
			cout << "������ȸ : ";
			for (auto i : pre) cout << "(" << i.num << ", " << i.name << ") ";
			cout << "\n������ȸ : ";
			for (auto i : in) cout << "(" << i.num << ", " << i.name << ") ";
			cout << "\n������ȸ : ";
			for (auto i : pos) cout << "(" << i.num << ", " << i.name << ") ";
			cout << "\n�������� ��� : ";
			B.BST_Print(B.getRoot());

			cout << "\n\n Ʈ�� ���� ���\n";
			B.BST_TreePrint(B.getRoot());

			cout << endl;
		}
			break;
		}
		cout << endl;
	}
}