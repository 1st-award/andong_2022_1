#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void main(int argc, char *argv[])
{
	char name[20];
	char select[5];
	char c_result[5]; 
	int n_select, c_select;
	srand(time(NULL));
	 
	if(argc != 2)
		return; 	
	strcpy(select, argv[1]);
	
	if (strcmp(select, "가위") == 0)
		n_select = 1;
	else if (strcmp(select, "바위") == 0)
		n_select = 2;
	else if (strcmp(select, "보") == 0)
		n_select = 3;
	else {
		puts("잘못 입력하셨습니다.");
		return; 
	}
	
	c_select = rand()%3 + 1;
	if (c_select == 1)
		strcpy(c_result, "가위");
	else if(c_select == 2)
		strcpy(c_result, "바위");
	else
		strcpy(c_result, "보");
	
	if(n_select == c_select)
		printf("나 : %s 컴퓨터: %s\n비겼습니다.\n", select, c_result);
	else if(c_select > (n_select+1)%3)
		printf("나 : %s 컴퓨터: %s\n당신이 이겼습니다.\n", select, c_result);
	else
		printf("나 : %s 컴퓨터: %s\n컴퓨터가 이겼습니다.\n", select, c_result);
}
