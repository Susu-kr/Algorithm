#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max3(int a, int b, int c) {
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
}

int main(void) {

	printf("Max : %d", max3(3, 2, 4));

	return 0;
}