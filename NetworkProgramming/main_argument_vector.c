#include <stdio.h>
#include <string.h>

void main(int argc, char* argv[]) {
	char** arg_string;
	char name[20];
	char locate[20];
	char phone_number[30];
	int age;
	
	if(argc != 5) {
		printf("%s [이름] [나이] [지역] [전화번호]로 입력해주세요.\n", argv[0]);
		return;
	}

	arg_string = argv;
	strcpy(name, argv[1]);
	age = atoi(argv[2]);
	strcpy(locate, argv[3]);
	strcpy(phone_number, argv[4]);

	printf("arg1 = %s arg2 = %s arg3 = %s arg4 = %s\n", argv[1], argv[2], argv[3], argv[4]);
	printf("string1 = %s string2 = %s string3 = %s string4 = %s\n", arg_string[1], arg_string[2], arg_string[3], arg_string[4]);

	printf("name = %s, age = %d, locate = %s,  phone_number = %s\n", name, age, locate, phone_number);
}
