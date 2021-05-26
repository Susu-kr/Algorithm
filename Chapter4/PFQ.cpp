#include "PostfixQueue.h"
#include <iostream>
int Initialize(Queue *q, int max) {
	if (max < 1)
		return -1;
	q->num = q->front = q->rear = 0;
	q->que = new char[max + 1];
	q->max = max;
	return 0;
}

int Enque(Queue *q, char x) {
	if (q->num >= q->max) {
		return -1;
	}
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)
			q->rear = 0;
	}
	return 0;
}

char Deque(Queue *q, char *x) {
	if (q->num <= 0) return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
	}
	return *x;
}

int Peek(const Queue *q, char *x) {
	if (q->num <= 0) return -1;
	*x = q->que[q->front];
	return 0;
}

int IsEmpty(const Queue *q) {
	return q->num <= 0;
}

void Print(const Queue *q) {
	int i;
	std::cout << "queue : ";
	for (i = 0; i < q->num; i++) {
		std::cout << q->que[(i + q->front) % q->max];
	}
}

void Terminate(Queue *q) {
	if (q->que != NULL) {
		free(q->que);
	}
	q->max = q->num = q->front = q->rear = 0;
}