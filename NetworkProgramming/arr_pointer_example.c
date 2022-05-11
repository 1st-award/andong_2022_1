#include <stdio.h>

void main()
{
	int i, *ptr;
	int arr[4];
	for(i=0; i<4; i++)
		arr[i] = i;
	printf("arr 배열의 시작 주소 : %p\n", arr);
	//arr[i] 방식을 이용한 배열 접근
	for(i=0; i<4; i++) {
		printf("arr[%d]의 주소 : %p ", i, &arr[i]);
		printf("arr[%d] : %d\n ", i, arr[i]);
	}
	printf("\n");
	
	ptr = arr;
	for(i=0; i<4; i++) {
		printf("ptr이 가리키는 주소 : %p ", ptr);
		printf("ptr이 가리키는 값 : %d\t가리키는 변수의 크기 %d\n", *ptr++, sizeof(*ptr));
	}
	
	printf("\narr배열의 크기 %d(int형(4byte)의 방이 4개 = 16byte)\n", sizeof(arr));
	printf("포인터 변수의 크기 %d(64bit기준 주소의 크기 8byte)\n", sizeof(ptr));
}
