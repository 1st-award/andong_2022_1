#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define BUF_LEN 128

void main(int argc, char* argv[]) {
	struct sockaddr_in serv_addr, client_addr;
	int s, c, msg_len, len;
	char buf[BUF_LEN+1];

	if(argc != 2) {
		printf("usage %s port\n", argv[1]);
		exit(0);
	}

	if((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		printf("sock error\n");
		exit(0);
	}

	bzero((char*) &serv_addr, sizeof(serv_addr));
	bzero((char*) &client_addr, sizeof(client_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(s, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
		printf("bind error\n");
		exit(0);
	}

	listen(s, 5);
	
	while(1) {
		printf("wait client\n");
		len = sizeof(client_addr);
		c = accept(s, (struct sockaddr*) &client_addr, &len);

		if(c < 0) {
			printf("accept error\n");
			exit(0);
		}

		while(msg_len = recv(c, buf, BUF_LEN, 0) != 0) {
			printf("send to client >> %s %d", buf, msg_len);
			send(c, buf, msg_len, 0);
		}
		close(c);
	}
	close(s);
}
