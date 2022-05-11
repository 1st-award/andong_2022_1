#include <stdio.h>
#include <string.h>

void reverse_string(char* str) {
	// 문자열을 뒤집는 함수
	int i, str_length = strlen(str);
	for(i=0; i<str_length /2; ++i) {
		str[i] = str[i] ^ str[str_length-2-i];
		str[str_length-2-i] = str[i] ^ str[str_length-2-i];
		str[i] = str[str_length-2-i] ^ str[i];
	}	
}


void main(void) {
	char str[10];
    	char buffer[100];

	printf("키보드로부터 str 배열에 문자열 입력: ");
	fgets(str, sizeof(str), stdin);

	reverse_string(str);
	// 입력 받은 문자열과 "Input String : "값을 합쳐서 buffer 배열에 저장
	sprintf(buffer, "Reverse Input String : %s", str);
	printf("%s", buffer);
}

