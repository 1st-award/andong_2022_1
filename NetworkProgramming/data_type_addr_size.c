#include <stdio.h>

void main() {
	double _double;
	int _int;
	short _short;
	char _char;
	
	printf("char의 주소 : %p\t크기 : %d\n", &_char, sizeof(_char));
	printf("short의 주소 : %p\t크기 : %d\n", &_short, sizeof(_short));
	printf("int의 주소 : %p\t크기 : %d\n", &_int, sizeof(_int));
	printf("double의 주소 : %p\t크기 : %d\n", &_double, sizeof(_double));
}
