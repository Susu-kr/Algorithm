#pragma once
typedef struct {
	int max;
	char num;
	int front;
	int rear;
	char *que;
}Queue;

int Initialize(Queue *q, int max);
int Enque(Queue *q, char x);
char Deque(Queue *q, char *x);
int Peek(const Queue *q, char *x);
int IsEmpty(const Queue *q);
void Print(const Queue *q);
void Terminate(Queue *q);
