#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_LEN 128
int main(int argc, char *argv[]) {
   struct sockaddr_in server_addr, client_addr;
   int server_fd, client_fd;   /* 소켓 번호 */
   int len, msg_size;
   char buf[BUF_LEN+1];
   
   if(argc !=2){ /*컴파일 당시 요구되는 인자가 제대로 들어갔는지를 파악하기 위함*/
      printf("usage: %s port\n", argv[0]);
      exit(0);
   }
   /* 소켓 생성 */
   if((server_fd = socket(PF_INET, SOCK_STREAM, 0)) < 0){
      printf("Server: Can't open stream socket.");
      exit(0);
   }
   
   /* server_addr을 '\0'으로 초기화 */
   bzero((char *)&server_addr, sizeof(server_addr));
   /* server_addr 세팅 */
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
   server_addr.sin_port = htons(atoi(argv[1]));
   
   /* bind() 호출 */
   if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
      printf("Server: Can't bind local address.\n");
      exit(0);
   }
   
   /* 소켓을 수동 대기모드로 세팅 */
   listen(server_fd, 5);
   
   /* iterative echo 서비스 수행 */
      printf("Server : waiting connection request.\n");
      len = sizeof(client_addr);
      
      /* 연결요청을 기다림 */
      client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &len);
	printf("client_family: %d, client_addr: %s, client_port: %d\n",
	client_addr.sin_family, inet_ntoa(client_addr.sin_addr), client_addr.sin_port);
	printf("client sock num: %d\n", client_fd);
      if(client_fd < 0) {
         printf("Server: accept failed.\n");
         exit(0);
      }
      printf("Server : A client connected.\n");
      while(msg_size = recv(client_fd, buf, sizeof(buf), 0) != 0){
      printf("msg_size: %d\nbuf: %s", msg_size, buf);
      send(client_fd, buf, msg_size, 0);
      // send(1, buf, msg_size, 0);
   }
   close(client_fd);
   close(server_fd);
}
