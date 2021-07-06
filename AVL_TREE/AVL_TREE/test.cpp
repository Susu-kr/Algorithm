#include "AVL.h"

int main() {
	AVL T;
	//int num, N;
	//string name;
	//while (1) {
	//	cout << "(1) 삽입 (2) 삭제 (3) 검색 (4) 출력 (5) 순회 (0) 종료 : ";
	//	cin >> N;
	//	switch (N)
	//	{
	//	case 0:
	//		cout << "프로그램 종료\n";
	//		T.Delete(T.GetRoot());
	//		return 0;
	//	case 1:
	//	{
	//		cout << "삽입하는 데이터를 입력하세요.\n번호 : ";
	//		cin >> num;
	//		cout << "이름 : ";
	//		cin >> name;
	//		T.insert(num, name);
	//		T.Show(1);
	//	}
	//		break;
	//	case 2:
	//	{
	//		cout << "삭제하려는 데이터를 입력하세요.\n번호 : ";
	//		cin >> num;
	//		T.remove(num);
	//	}
	//		break;
	//	case 3:
	//	{
	//		cout << "검색하려는 데이터를 입력하세요.\n번호 : ";
	//		cin >> num;
	//		Node * temp = T.search(T.GetRoot(),num);
	//		if (temp == NULL) cout << "찾고자 하는 데이터가 없습니다.\n";
	//		else cout << temp->num << ", " << temp->name << endl;
	//	}
	//		break;
	//	case 4:
	//	{
	//		cout << "AVL Tree를 출력합니다.\n";
	//		T.Show(1);
	//	}
	//		break;
	//	case 5:
	//		cout << "원하는 순회를 선택하세요.\n(1) 전위순회 (2) 중위순회 (3) 후위순회 : ";
	//		cin >> num;
	//		switch (num)
	//		{
	//		case 1:
	//		{
	//			cout << "전위순회\n";
	//			T.preorder(T.GetRoot());
	//			cout << endl;
	//		}
	//			break;
	//		case 2:
	//		{
	//			cout << "중위순회\n";
	//			T.inorder(T.GetRoot());
	//			cout << endl;
	//		}
	//			break;
	//		case 3:
	//		{
	//			cout << "후위순회\n";
	//			T.postorder(T.GetRoot());
	//			cout << endl;
	//		}
	//			break;
	//		}
	//		break;
	//	}
	//	cout << "-------------------------------------------------------\n";
	//}

	T.insert(5, "a");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.insert(15, "b");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.insert(25, "c");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.insert(18, "d");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.insert(37, "e");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.insert(1, "f");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.insert(3, "g");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.insert(8, "h");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.insert(9, "i");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.insert(12, "j");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.insert(14, "k");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.remove(5);
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.remove(1);
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	T.remove(3);
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	//cout << T.search(T.GetRoot(), 12)->num << T.search(T.GetRoot(), 12)->name << endl;
	T.insert(3, "g");
	T.Show(1);
	cout << "-------------------------------------------------------\n";
	return 0;
}