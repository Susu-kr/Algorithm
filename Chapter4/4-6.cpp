#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int *que;
}IntQueue;

int Initialize(IntQueue *q, int max);

int Enque(IntQueue *q, int x);

int Deque(IntQueue *q, int *x);

int Peek(const IntQueue *q, int *x);

void Clear(IntQueue *q);

int Capacity(const IntQueue *q);

int Size(const IntQueue *q);

int IsEmpty(const IntQueue *q);

int IsFull(const IntQueue *q);

int Search(const IntQueue *q, int x);

void Print(const IntQueue *q);

void Terminate(IntQueue *q);


int main(void) {
	IntQueue q;
	if (Initialize(&q, 64) == -1) {
		puts("ť ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while (1) {
		int m, x;
		printf("���� ������ �� : %d / %d\n", Size(&q), Capacity(&q));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (0)���� : ");
		scanf("%d", &m);

		if (m == 0) break;
		switch (m)
		{
		case 1:
			printf("������ : ");
			scanf("%d", &x);
			if (Enque(&q, x) == -1) {
				puts("\a���� : ��ť�� �����Ͽ����ϴ�.");
			}
			break;
		case 2:
			if ((x = Deque(&q, &x)) == -1) {
				puts("\a���� : ��ť�� �����Ͽ����ϴ�.");
			}
			else {
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			}
			break;
		case 3:
			if (Peek(&q, &x) == -1) {
				puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
			}
			else {
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			}
			break;
		case 4:
			Print(&q);
			break;
		}
	}
	Terminate(&q);
	return 0;
}

int Initialize(IntQueue *q, int max) {
	if (max < 1)
		return -1;
	q->num = q->front = q->rear = 0;
	q->que = new int[max + 1];
	q->max = max;
	return 0;
}

int Enque(IntQueue *q, int x) {
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

int Deque(IntQueue *q, int *x) {
	if (q->num <= 0) return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
	}
	return *x;
}

int Peek(const IntQueue *q, int *x) {
	if (q->num <= 0) return -1;
	*x = q->que[q->front];
	return 0;
}

void Clear(IntQueue *q) {
	q->num = q->front = q->rear = 0;
}

int Capacity(const IntQueue *q) {
	return q->max;
}

int Size(const IntQueue *q) {
	return q->num;
}

int IsEmpty(const IntQueue *q) {
	return q->num <= 0;
}

int IsFull(const IntQueue *q) {
	return q->num >= q->max;
}

int Search(const IntQueue *q, int x) {
	int i, idx;
	for (i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;
	}
	return -1;
}

void Print(const IntQueue *q) {
	int i;
	for (i = 0; i < q->num; i++) {
		printf("%d ", q->que[(i + q->front) % q->max]);
	}
	putchar('\n');
}

void Terminate(IntQueue *q) {
	if (q->que != NULL) {
		free(q->que);
	}
	q->max = q->num = q->front = q->rear = 0;
}