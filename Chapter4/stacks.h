#pragma once
typedef struct {
	int max;
	int ptr;
	double *stk;
}IntStack;

int Initialize(IntStack *s, int max);
int Push(IntStack *s, double x);
double Pop(IntStack *s);
int Peek(const IntStack *s, double *x);
void Print(const IntStack *s);
void Terminate(IntStack *s);

typedef struct {
	int max;
	int ptr;
	char *stk;
}CharStack;

int Initialize(CharStack *s, int max);
int Push(CharStack *s, char x);
int Pop(CharStack *s);
int Peek(const CharStack *s, char *x);
void Print(const CharStack *s);
void Terminate(CharStack *s);
int IsEmpty(const CharStack *s);