#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_LEN 128
void* tcpRxThread(void* clientSocket);

int main(int argc, char* argv[]) {
	struct sockaddr_in server_addr, client_addr;
	int server_fd, client_fd, thr_id, len, rst;
	pthread_t tcp_s_thread;

	if(argc != 2) {
		printf("usage: %s port\n", argv[0]);
		exit(0);
	}
	
	if((server_fd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Server: Can't open stream socket\n");
		exit(0);
	}

	bzero((char*)&server_addr, sizeof(server_addr));
	server_addr.sin_family = PF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));

	if(bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
		printf("TCP Server: Can't bind local address\n");
		exit(0);
	}

	listen(server_fd, 5);
	len = sizeof(client_addr);

	while(1) {
		printf("Server is waiting a new connection request...\n");

		client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &len);
		if(client_fd < 0) {
			printf("Server: accept failed\n");
			continue;
		}

		printf("Server: A client is connected\n");
		thr_id = pthread_create(&tcp_s_thread, NULL, tcpRxThread, (void*)&client_fd);
		if(thr_id < 0) {
			perror("thread create error\n");
			continue;
		}
		pthread_join(tcp_s_thread, (void*)&rst);
	}
	close(server_fd);
}

void* tcpRxThread(void* clientSocket) {
	int msg_size, c_socket;
	char buf[BUF_LEN];
	pthread_t id;

	id = pthread_self();
	c_socket = *((int*)clientSocket);

	msg_size = recv(c_socket, buf, BUF_LEN, 0);
	printf("Thread[%ud]-Rx Msg: %s\n", id, buf);
	send(c_socket, buf, msg_size, 0);

	close(c_socket);
}
