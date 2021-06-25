#include <iostream>
#include <string>
#include <vector>
#include "BTree.h"

int main() {
	int N;
	string s;
	BST B;

	while (1) {
		cout << "(1) 삽입  (2) 삭제  (3) 검색  (4) 출력  (0) 종료 : ";
		cin >> N;
		switch (N)
		{
		case 0: {
			cout << "프로그램 종료\n";
			B.BST_Delete(B.getRoot());
			return 0;
		}
			break;
		case 1: {
			cout << "삽입하는 데이터를 입력하세요.\n번호 : ";
			cin >> N;
			cout << "이름 : ";
			cin >> s;
			DATA D = { N, s };
			Node * temp = new Node(D);
			B.BST_InsertNode(B.getRoot(), temp);
		}
			break;
		case 2: {
			cout << "삭제하는 데이터를 입력하세요.\n번호 : ";
			cin >> N;
			Node * temp = B.BST_RemoveNode(B.getRoot(), NULL, N);
			if (temp == NULL) cout << "존재하지 않는 데이터입니다.\n";
			else cout << "삭제되었습니다.\n";
		}
			break;
		case 3: {
			cout << "검색하는 데이터를 입력하세요.\n번호 : ";
			cin >> N;
			Node * temp = B.BST_SearchNode(B.getRoot(), N);
			if (temp == NULL) cout << "존재하지 않는 데이터입니다.\n";
			else cout << temp->data.num << ", " << temp->data.name << endl;
		}
			break;
		case 4: {
			vector<DATA> pre, in, pos, DFS;
			cout << "트리 출력\n";
			B.BST_PreOrder(B.getRoot(), pre);
			B.BST_InOrder(B.getRoot(), in);
			B.BST_PostOrder(B.getRoot(), pos);
			cout << "전위순회 : ";
			for (auto i : pre) cout << "(" << i.num << ", " << i.name << ") ";
			cout << "\n중위순회 : ";
			for (auto i : in) cout << "(" << i.num << ", " << i.name << ") ";
			cout << "\n후위순회 : ";
			for (auto i : pos) cout << "(" << i.num << ", " << i.name << ") ";
			cout << "\n오름차순 출력 : ";
			B.BST_Print(B.getRoot());

			cout << "\n\n 트리 구조 출력\n";
			B.BST_TreePrint(B.getRoot());

			cout << endl;
		}
			break;
		}
		cout << endl;
	}
}