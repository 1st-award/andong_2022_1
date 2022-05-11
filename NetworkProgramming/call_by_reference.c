#include <stdio.h>

void swap(int *a, int *b)
{
	printf("swap을 실행합니다.\n");
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *b ^ *a;
}

void main()
{
	int x, y;
	printf("두 정수를 입력하세요 : ");
	scanf("%d %d", &x, &y);
	printf("x : %d, y : %d\n", x, y);
	swap(&x, &y);
	printf("x : %d, y : %d\n", x, y);
}
