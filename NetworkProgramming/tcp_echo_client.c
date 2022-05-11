#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define BUF_LEN 128

void main(int argc, char* argv[]) {
	struct sockaddr_in serv_addr;
	int msg_len, s, len;
	char buf[BUF_LEN+1];
	char stop[5] = "stop\n";
	if(argc != 3) {
		printf("usage %s ip port\n");
		exit(0);
	}

	if((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		printf("sock error\n");
		exit(0);
	}

	bzero((char*) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));
	

	if(connect(s, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
		printf("connect error\n");
		exit(0);
	}

	while(1) {
		printf("input string any: ");
		if(fgets(buf, BUF_LEN, stdin)) {
			buf[BUF_LEN] = '\0';
			msg_len = sizeof(buf);
			if(!strcmp(stop, buf)) {
				close(s);
				exit(0);
			}
		}
		else {
			printf("fgets error\n");
			exit(0);
		}


		if(send(s, buf, msg_len, 0) < 0) {
			printf("send error\n");
			exit(0);
		}

		if((msg_len = recv(s, buf, BUF_LEN, 0)) < 0) {
			printf("recv error\n");
			exit(0);
		}

		printf("recv >> %s", buf);
	}
}

