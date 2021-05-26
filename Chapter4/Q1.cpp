/*
	1. 1글자
	2. 피연산자 후위표기 postFixQueue
	3. 연산자
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
					)			( 를 만날떄까지 데이터 이동		4 2 x 12 +
											(
					x						(x					4 2 x 12 +
					(						(x(
					123						(x(					4 2 x 12 + 123
					+						(x(+				4 2 x 12 + 123
					7						(x(+				4 2 x 12 + 123 7
					)			( 를 만날떄까지 데이터 이동		4 2 x 12 + 123 7 +
					)			( 를 만날떄까지 데이터 이동		4 2 x 12 + 123 7 + x
	ex >								Operator Stack			PostFixQueue				Operand Stack
					4											2 x 12 + 123 7 + x				  4
					2											x 12 + 123 7 + x				 4 2
					x																	연산자 적용후 결과 추가
																12 + 123 7 + x					  8
					12											+ 123 7 + x						 8 12
					+											123 7 + x				연산자 적용후 결과 추가
																123 7 + x						  20
					123											7 + x							20 123
					7											+ x								20 123 7
					+											x						연산자 적용후 결과 추가
																x								20 130
					x																	연산자 적용후 결과 추가
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
		puts("스택 생성에 실패하였습니다.");
		return 1;
	}
	if (Initialize(&Postfix_Q, 64) == 1) {
		puts("큐 생성에 실패하였습니다.");
		return 1;
	}
	cout << "수식을 입력하세요 : \n";
	getline(cin, s);
	cout << s << endl;
	char x;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case ' ':	// 공백 무시
			break;
		case '(':
			Push(&operator_S, s[i]);
			break;
		case ')':
			while (1) { // ( 나올때까지
				Peek(&operator_S, &x); // stack 맨위 값
				if (x == '(') {
					Pop(&operator_S); // ( 팝
					break;
				}
				Enque(&Postfix_Q, ' '); // 공백
				Enque(&Postfix_Q, x); // ( 나올때까지 큐에 삽입
				Pop(&operator_S); // 팝
			}
			break;
		case '*': // x, / 는 연산자 우선순위 높으므로 삽입
			Push(&operator_S, s[i]);
			Enque(&Postfix_Q, ' '); // 숫자가 아니므로 공백
			break;
		case '/':
			Push(&operator_S, s[i]);
			Enque(&Postfix_Q, ' '); // 숫자가 아니므로 공백
			break;
		case '+':
			// 연산자 우선 순위가 낮으므로 곱, 나눗셈이 먼저 존재한다면 존재하지 않을 때까지 팝하고 큐에 삽입
			while (1) {
				Peek(&operator_S, &x);
				if (x == '*' || x == '/') {
					Pop(&operator_S);
					Enque(&Postfix_Q, ' ');
					Enque(&Postfix_Q, x);
				}
				else break;
			}
			Enque(&Postfix_Q, ' ');
			Push(&operator_S, s[i]);
			break;
		case '-':
			while (1) { // 연산자 우선 순위가 낮으므로 곱, 나눗셈이 먼저 존재한다면 존재하지 않을 때까지 팝하고 큐에 삽입
				Peek(&operator_S, &x);
				if (x == '*' || x == '/') {
					Pop(&operator_S);
					Enque(&Postfix_Q, ' ');
					Enque(&Postfix_Q, x);
				}
				else break;
			}
			Enque(&Postfix_Q, ' ');
			Push(&operator_S, s[i]);
			break;
		default:
			Enque(&Postfix_Q, s[i]);
			break;
		}
		Print(&operator_S);
		cout << "\t\t\t\t";
		Print(&Postfix_Q);
		cout << endl;
	}
	cout << "====================================================================================" << endl;
	string temp;
	int k;
	while (!IsEmpty(&Postfix_Q)) {
		int t = 0;
		Deque(&Postfix_Q, &x);
		if (x >= '0' && x <= '9') temp += x; // 숫자만 저장
		switch (x) {
		case ' ':
			if (temp != "") { // 저장된 숫자가 존재한 경우만
				Push(&operand_S, stoi(temp)); // string -> int 바꾸고 삽입
				temp = "";
			}
			break;
		case '*':
			Peek(&operand_S, &k); // 맨위 값 불러와서 k에 저장
			t = k;
			Pop(&operand_S); // 후 삭제
			Peek(&operand_S, &k); // 그 다음 맨위 값 k에 저장
			t *= k;
			Pop(&operand_S); // 연산 후 삭제
			Push(&operand_S, t); // 그리고 계산된 값 삽입
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
			Peek(&operand_S, &k);
			t = k;
			Pop(&operand_S);
			Peek(&operand_S, &k);
			t = k - t;
			Pop(&operand_S);
			Push(&operand_S, t);
			break;
		}
		Print(&Postfix_Q);
		cout << "\t\t\t\t";
		Print(&operand_S);
		cout << endl;
	}
	int res;
	Peek(&operand_S, &res);
	cout << s << " : " << res << endl;

	Terminate(&operator_S);
	Terminate(&operand_S);
	Terminate(&Postfix_Q);
	return 0;
}