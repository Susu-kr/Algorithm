#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int max;
	int ptr;
	int *stk;
}IntStack;

int Initialize(IntStack *s, int max);

int Push(IntStack *s, int x);

int Pop(IntStack *s);

int Peek(const IntStack *s, int *x);

void Clear(IntStack *s);

int Capacity(const IntStack *s);

int Size(const IntStack *s);

int IsEmpty(const IntStack *s);

int IsFull(const IntStack *s);

int Search(const IntStack *s, int x);

void Print(const IntStack *s);

void Terminate(IntStack *s);


int main(void) {
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("���� ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while (1) {
		int menu, x;
		printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (0)���� : ");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1:
			printf("������ : ");
			scanf("%d", &x);
			if (Push(&s, x) == -1) {
				puts("\a���� : Ǫ�ÿ� �����Ͽ����ϴ�.");
			}
			break;
		case 2:
			if ((x=Pop(&s)) == -1) {
				puts("\a���� : �˿� �����Ͽ����ϴ�.");
			}
			else {
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			}
			break;
		case 3:
			if (Peek(&s, &x) == -1) {
				puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
			}
			else {
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			}
			break;
		case 4:
			Print(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}

int Initialize(IntStack *s, int max) {
	if (max < 1)
		return -1;
	s->max = max;
	s->stk = new int[max + 1];
	s->ptr = 0;
	s->stk[0] = 0;
	return 0;
}

int Push(IntStack *s, int x) {
	if (s->ptr >= s->max) {
		return -1;
	}
	s->stk[s->ptr++] = x;
	return 0;
}

int Pop(IntStack *s) {
	if (s->ptr <= 0) return -1;
	s->stk[s->ptr--];
	return s->stk[s->ptr];
}

int Peek(const IntStack *s, int *x) {
	if (s->ptr <= 0) return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

void Clear(IntStack *s) {
	s->ptr = 0;
}

int Capacity(const IntStack *s) {
	return s->max;
}

int Size(const IntStack *s) {
	return s->ptr;
}

int IsEmpty(const IntStack *s) {
	return s->ptr <= 0;
}

int IsFull(const IntStack *s) {
	return s->ptr >= s->max;
}

int Search(const IntStack *s, int x) {
	int i;
	for (i = s->ptr - 1; i >= 0; i--) {
		if (s->stk[i] == x)
			return i;
	}
	return -1;
}

void Print(const IntStack *s) {
	int i;
	for (i = 0; i < s->ptr; i++) {
		printf("%d ", s->stk[i]);
	}
	putchar('\n');
}

void Terminate(IntStack *s) {
	if (s->stk != NULL) {
		free(s->stk);
	}
	s->max = s->ptr = 0;
}