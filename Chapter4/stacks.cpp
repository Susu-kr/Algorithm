#include <iostream>
#include"stacks.h"

// IntStack : Operand_S
int Initialize(IntStack *s, int max) {
	if (max < 1)
		return -1;
	s->max = max;
	s->stk = new double[max + 1];
	s->ptr = 0;
	s->stk[0] = 0.0;
	return 0;
}

int Push(IntStack *s, double x) {
	if (s->ptr >= s->max) {
		return -1;
	}
	s->stk[s->ptr++] = x;
	return 0;
}

double Pop(IntStack *s) {
	if (s->ptr <= 0) return -1;
	s->stk[s->ptr--];
	return s->stk[s->ptr];
}

int Peek(const IntStack *s, double *x) {
	if (s->ptr <= 0) return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

void Print(const IntStack *s) {
	int i;
	std::cout << "stack : ";
	for (i = 0; i < s->ptr; i++) {
		std::cout << s->stk[i] << " ";
	}
}

void Terminate(IntStack *s) {
	if (s->stk != NULL) {
		free(s->stk);
	}
	s->max = s->ptr = 0;
}

// CharStack : Operator_S
int Initialize(CharStack *s, int max) {
	if (max < 1)
		return -1;
	s->max = max;
	s->stk = new char[max + 1];
	s->ptr = 0;
	s->stk[0] = 0;
	return 0;
}

int Push(CharStack *s, char x) {
	if (s->ptr >= s->max) {
		return -1;
	}
	s->stk[s->ptr++] = x;
	return 0;
}

int Pop(CharStack *s) {
	if (s->ptr <= 0) return -1;
	s->stk[s->ptr--];
	return s->stk[s->ptr];
}

int Peek(const CharStack *s, char *x) {
	if (s->ptr <= 0) return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

void Print(const CharStack *s) {
	int i;
	std::cout << "stack : ";
	for (i = 0; i < s->ptr; i++) {
		std::cout << s->stk[i] << " ";
	}
}

void Terminate(CharStack *s) {
	if (s->stk != NULL) {
		free(s->stk);
	}
	s->max = s->ptr = 0;
}

int IsEmpty(const CharStack *s) {
	return s->ptr <= 0;
}