#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define BUF_LEN 128

char* getReverseString(char* string) {
        int i, length = strlen(string);
        char* reverseString = strcpy(reverseString, string);
        char tempChar;

        for(i = 0; i<length/2; ++i) {
		if(reverseString[i] != '\n' || reverseString[i] != '\0') {
                	tempChar = reverseString[i];
	                reverseString[i] = reverseString[length-(i+1)];
	                reverseString[length-(i+1)] = tempChar;
		}
        }
        return reverseString;
}


int main (int argc, char* argv[]) {
	struct sockaddr_in server_addr, client_addr;
	int s;
	int len, msg_size;
	char buf[BUF_LEN+1];
	char* reverse_string;

	if(argc!=2) {
		printf("usage: %s port\n", argv[0]);
		exit(0);
	}


	if((s = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
		printf("Server >> Can't open diagram socket.\n");
		exit(0);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));

	if(bind(s, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0 ) {
		printf("Server >> Can't bind local address.\n");
		exit(0);
	}
	len = sizeof(struct sockaddr);
	
	while(1) {
		printf("Server >> waiting request.\n");
		
		if((msg_size = recvfrom(s, buf, BUF_LEN, 0, (struct sockaddr*) &client_addr, &len)) < 0) {
			printf("recvfrom error\n");
			exit(1);
		}
		printf("Server >> A client data received.\n");
		reverse_string = getReverseString(buf);

		if(sendto(s, reverse_string, strlen(reverse_string), 0, (struct sockaddr*) &client_addr, len) < 0) {
			printf("sendto error\n");
			exit(1);
		}
		printf("sendto complete\n");
	}
}
