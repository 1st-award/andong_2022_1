#include <stdio.h>

int add(int a, int b)
{
	int sum = 0;
	sum = a + b;
	return sum;
}

int sub(int a, int b) {
	int sub = 0;
	sub = a - b;
	return sub;
}

int mul(int a, int b) {
	int mul = 0;
	mul = a * b;
	return mul;
}

int div(int a, int b) {
	int div = 0;
	div = a / b;
	return div;
}

void main()
{
	 int x, y;
	 int sum, select;
	 
	 do {
	 	printf("1. 더하기\n2. 빼기\n3. 곱하기\n4. 나누기\n0. 종료\n입력하세요 : ");
	 	scanf("%d", &select);
	 	
	 	if(select == 0) {
	 		return;
		 }
	 	
	 	printf("\n두 정수를 입력하세요 : ");
	 	scanf("%d %d", &x, &y);
	 	
	 	switch(select) {
	 		case 1:
	 			sum = add(x, y);
	 			break;
	 		case 2:
	 			sum = sub(x, y);
				 break;
			case 3:
				sum = mul(x, y);
				break;
			case 4:
				if (y == 0) {
					printf("x를 0으로 나눌 수 없습니다.\n\n");
					break;
				} 
				sum = div(x, y);
				break;
			default:
				printf("번호를 잘못입력했습니다.");
		 }
		 printf("SUM : %d\n\n", sum);
	 } while(select != 0);
	 
	 
}
