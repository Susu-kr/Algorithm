/*
	1. 1����
	2. �ǿ����� ����ǥ�� postFixQueue
	3. ������
		operator stack : (
		operand stack : )

	ex > ((4x2 + 12) x (123 + 7))	Operator Stack			PostFixQueue				Operand Stack
					(						(
					(						(
					4											4
					x						x
					2											2
		:									((x					4 2
					+						((+					4 2 x
					12						((+					4 2 x 12
					)			( �� ���������� ������ �̵�		4 2 x 12 +
											(
					x						(x					4 2 x 12 +
					(						(x(
					123						(x(					4 2 x 12 + 123
					+						(x(+				4 2 x 12 + 123
					7						(x(+				4 2 x 12 + 123 7
					)			( �� ���������� ������ �̵�		4 2 x 12 + 123 7 +
					)			( �� ���������� ������ �̵�		4 2 x 12 + 123 7 + x
	ex >								Operator Stack			PostFixQueue				Operand Stack
					4											2 x 12 + 123 7 + x				  4
					2											x 12 + 123 7 + x				 4 2
					x																	������ ������ ��� �߰�
																12 + 123 7 + x					  8
					12											+ 123 7 + x						 8 12
					+											123 7 + x				������ ������ ��� �߰�
																123 7 + x						  20
					123											7 + x							20 123
					7											+ x								20 123 7
					+											x						������ ������ ��� �߰�
																x								20 130
					x																	������ ������ ��� �߰�
																								 2600
*/

#include <iostream>
#include <string>
#include "stacks.h"
#include "PostfixQueue.h"
using namespace std;

int main(void) {
	string s;
	CharStack operator_S;
	IntStack operand_S;
	Queue Postfix_Q;
	if (Initialize(&operator_S, 64) == -1 || Initialize(&operand_S, 64) == -1) {
		puts("���� ������ �����Ͽ����ϴ�.");
		return 1;
	}
	if (Initialize(&Postfix_Q, 64) == 1) {
		puts("ť ������ �����Ͽ����ϴ�.");
		return 1;
	}
	cout << "������ �Է��ϼ��� : \n";
	getline(cin, s);
	string st = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-') {
			if (i != 0) {
				if (s[i - 1] >= '0' && s[i - 1] <= '9' || s[i - 1] == ')') {
					if(s[i+1] != '(' && i < s.size())st += '+';
				}
			}
		}
		st += s[i];
	}
	s = st;
	char x;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case ' ':	// ���� ����
			break;
		case '(':
			Push(&operator_S, s[i]);
			break;
		case ')':
			while (1) { // ( ���ö�����
				Peek(&operator_S, &x); // stack ���� ��
				if (x == '(') {
					Pop(&operator_S); // ( ��
					while (1) {
						Peek(&operator_S, &x); // stack ���� ��
						cout << IsEmpty(&operator_S) << endl;
						if (x == '(' || IsEmpty(&operator_S) == 1) break;
						else if(x != ' ') {
							Enque(&Postfix_Q, x); // ( ���ö����� ť�� ����
							Enque(&Postfix_Q, ' '); // ����
							Pop(&operator_S); // ��
						}
					}
					break;
				}
				Enque(&Postfix_Q, x); // ( ���ö����� ť�� ����
				Enque(&Postfix_Q, ' '); // ����
				Pop(&operator_S); // ��
			}
			break;
		case '*': // x, / �� ������ �켱���� �����Ƿ� ����
			Push(&operator_S, s[i]);
			break;
		case '/':
			Push(&operator_S, s[i]);
			break;
		case '+':
			// ������ �켱 ������ �����Ƿ� ��, �������� ���� �����Ѵٸ� �������� ���� ������ ���ϰ� ť�� ����
			while (IsEmpty(&operator_S) != 1) {
				Peek(&operator_S, &x);
				if (x == '*' || x == '/') {
					Pop(&operator_S);
					Enque(&Postfix_Q, x);
					Enque(&Postfix_Q, ' ');

				}
				else break;
			}
			Push(&operator_S, s[i]);
			break;
		case '-':
			Peek(&operator_S, &x);
			Enque(&Postfix_Q, s[i]);

			break;
		default:
			Enque(&Postfix_Q, s[i]);
			Enque(&Postfix_Q, ' ');

			break;
		}
		Print(&operator_S);
		cout << "\t\t\t\t";
		Print(&Postfix_Q);
		cout << endl;
	}
	cout << "====================================================================================" << endl;
	string temp;
	double k;
	while (!IsEmpty(&Postfix_Q)) {
		double t = 0;
		Deque(&Postfix_Q, &x);
		if (x >= '0' && x <= '9' || x == '.' || x == '-') temp += x; // ���ڸ� ����
		switch (x) {
		case ' ':
			if (temp != "") { // ����� ���ڰ� ������ ��츸
				Push(&operand_S, stod(temp)); // string -> int �ٲٰ� ����
				temp = "";
			}
			break;
		case '*':
			Peek(&operand_S, &k); // ���� �� �ҷ��ͼ� k�� ����
			t = k;
			Pop(&operand_S); // �� ����
			Peek(&operand_S, &k); // �� ���� ���� �� k�� ����
			t *= k;
			Pop(&operand_S); // ���� �� ����
			Push(&operand_S, t); // �׸��� ���� �� ����
			break;
		case '/':
			Peek(&operand_S, &k);
			t = k;
			Pop(&operand_S);
			Peek(&operand_S, &k);
			t = k / t;
			Pop(&operand_S);
			Push(&operand_S, t);
			break;
		case '+':
			Peek(&operand_S, &k);
			t = k;
			Pop(&operand_S);
			Peek(&operand_S, &k);
			t = k + t;
			Pop(&operand_S);
			Push(&operand_S, t);
			break;
		case '-':
			break;
		}
		Print(&Postfix_Q);
		cout << "\t\t\t\t";
		Print(&operand_S);
		cout << endl;
	}
	double res;
	Peek(&operand_S, &res);
	cout << s << " : " << res << endl;

	Terminate(&operator_S);
	Terminate(&operand_S);
	Terminate(&Postfix_Q);
	return 0;
}