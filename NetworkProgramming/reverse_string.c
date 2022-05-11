/*
input string than print reverse
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
char* getString() {
	char* string = calloc(100, sizeof(char));
	int i;
	
	printf("Input String : ");
	scanf("%[^\n]s", string);
	
	return string;
}

char* getReverseString(char* string) {
	int i, length = strlen(string);
	char* reverseString = strcpy(reverseString, string);
	char tempChar;
	
	for(i = 0; i<length/2; ++i) {
		tempChar = reverseString[i];
		reverseString[i] = reverseString[length-(i+1)];
		reverseString[length-(i+1)] = tempChar;
	}
	return reverseString;
}

void main() {
	char* string = getString();
	char* reverseString = getReverseString(string);
	printf("Reverse Result : %s\n", reverseString);
}

