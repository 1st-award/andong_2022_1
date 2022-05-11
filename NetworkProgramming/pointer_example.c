#include <stdio.h>

void main() {
	int x;
	int* ptr;
	
	x = 1;
	printf("x : %d\n", x);
	printf("x의 주소 : %p\n\n", &x);
	
	ptr = &x;
	printf("ptr이 가리키고 있는 주소 값: %p\n", ptr);
	printf("ptr의 주소값 : %p\n", &ptr);
	printf("ptr이 가리키는 곳의 값 %d\n\n", *ptr);
	
	
	*ptr = 2;
	printf("*ptr = 2\nx : %d\n\n", x);
	
	x = 3;
	printf("x = 3\n*ptr = %d\n", *ptr);
}
