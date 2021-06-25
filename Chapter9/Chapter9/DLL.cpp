/*
	����1.
	�Է� ������ ������� ��ȣ ������� ���ĵ� ����Ʈ�� �����ϴ� ���α׷��� �ۼ��϶�.
	1. ����Ʈ �ʱ�ȭ
	2. ��� �߰�
		2.1 ���� �տ� �߰�
		2.2 �ǵڿ� �߰�
		2.3 ��� ���̿� �߰�
	3. ��� ����
		3.1 ���� �� ��� ����
		3.2 �� �� ��� ����
		3.3 ���� ��� ����
	4. �˻�
		��ȣ�� �Է� �޾Ƽ� �ش� ��ȣ�� �̸� ���
	5. ���
		����Ʈ ��ü ������ ���

	ex)
	�޴� ����
		1. �л� �߰�
		2. �л� ����
		3. ��ü ���
		4. ����

		1 -> ��ȣ : 3
			 �̸� : ȫ�浿
		1 -> ��ȣ : 2
			 �̸� : ���
*/

#include <string>
#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main() {
	List student;
	cout << "�޴� ����\n";
	cout << "1. �л� �߰�  2. �л� ����  3. ��ü ���  4. �˻�  5. ���� : ";
	int N;
	cin >> N;
	int count;
	string name;
	while (1) {
		switch (N)
		{
		case 1:
			cout << "��ȣ : ";
			cin >> count;
			cout << "�̸� : ";
			cin >> name;
			student.sortingInsert(name, count);
			break;
		case 2:
			cout << "1. ��ȣ�� ����, 2. �̸����� ���� : ";
			cin >> count;
			while (1) {
				if (count == 1) {
					cout << "�����Ͻ� ��ȣ�� �Է��ϼ��� : ";
					cin >> count;
					student.removeSearch(count);
					break;
				}
				else if (count == 2) {
					cout << "�����Ͻ� �̸��� �Է��ϼ��� : ";
					cin >> name;
					student.removeSearch(name);
					break;
				}
				else {
					cout << "1. ��ȣ�� ����, 2. �̸����� ���� : ";
					cin >> count;
				}
			}
			break;
		case 3:
			cout << "���\n";
			student.show();
			break;
		case 4:
			cout << "�˻��� ��ȣ�� �Է��ϼ��� : ";
			cin >> count;
			student.SearchList(count);
			break;
		case 5:
			cout << "���α׷��� �����մϴ�.\n";
			return 0;
		}
		cout << "1. �л� �߰�  2. �л� ����  3. ��ü ���  4. �˻�  5. ���� : ";

		cin >> N;
	}
	return 0;
}


