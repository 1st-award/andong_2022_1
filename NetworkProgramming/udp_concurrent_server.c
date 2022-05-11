#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_LEN 128
char buf[BUF_LEN];
int server_fd, msg_size;
void* udpRxThread(void* clientSocket);

int main(int argc, char* argv[]) {
	struct sockaddr_in server_addr, client_addr;
	int thr_id, len, rst;
	pthread_t udp_s_thread;

	if(argc != 2) {
		printf("usage: %s port\n", argv[0]);
		exit(0);
	}
	
	if((server_fd = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
		printf("Server: Can't open diagram socket\n");
		exit(0);
	}

	bzero((char*)&server_addr, sizeof(server_addr));
	server_addr.sin_family = PF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));

	if(bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
		printf("UDP Server: Can't bind local address\n");
		exit(0);
	}

	len = sizeof(client_addr);
	while(1) {
		printf("Server is waiting recive...\n");
		msg_size = recvfrom(server_fd, buf, BUF_LEN, 0, (struct sockaddr*) &client_addr, &len);
		if (msg_size < 0) {
			printf("recv error\n");
			continue;
		}

		thr_id = pthread_create(&udp_s_thread, NULL, udpRxThread, (void*)&client_addr);
		if(thr_id < 0) {
			perror("thread create error\n");
			continue;
		}
		pthread_join(udp_s_thread, (void*) &rst);
	}
	close(server_fd);
}

void* udpRxThread(void* temp_client_addr) {
	int client_len;
	struct sockaddr_in client_addr;
	pthread_t id;
	
	client_addr = *((struct sockaddr_in*) temp_client_addr);
	client_len = sizeof(client_addr);
	id = pthread_self();

	printf("Thread[%ud]-Rx Msg: %s\n", id, buf);
	sendto(server_fd, buf, msg_size, 0, (struct sockaddr*)&client_addr, client_len);
	bzero((char*) buf, BUF_LEN);
}
