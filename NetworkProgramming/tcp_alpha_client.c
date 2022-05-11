#ifndef __linux__
#include <Windows.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#else
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#endif
#define BUF_LEN 128

int main(int argc, char *argv[]){
   int s, n, i, len_in, len_out;
   struct sockaddr_in server_addr;
   char *haddr;
   char *ender = "end\n";
   char buf[BUF_LEN+1];
   
   if(argc != 3){
      printf("usage: %s ip_address port\n", argv[0]);
      exit(0);
   }
   haddr = argv[1];
   
   if((s = socket(PF_INET, SOCK_STREAM, 0)) < 0){
      printf("Cant't create socket\n");
      exit(0);
   }
   /* echo 서버의 소켓주소 구조체 작성 */
   bzero((char *)&server_addr, sizeof(server_addr)); /*char로 형변환해서 bzero의 원형인 int char
   순의 자료형을 형변환 해줘서 워닝 안 뜨게 하는 게 목적*/
   server_addr.sin_family = AF_INET; /*pf_inet이랑 혼용가능*/
   server_addr.sin_addr.s_addr = inet_addr(haddr);
   server_addr.sin_port = htons(atoi(argv[2]));
   
   /* 연결요청 */
   if(connect(s, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
      printf("Can't connect.\n");
      exit(0);
   }
	printf("sock num: %d\n", s);
   
   /* 키보드 입력을 받음 과제 : byebye 입력시 while문 해제 */
   while(1){
      printf("Input any string : ");
      if(fgets(buf, BUF_LEN, stdin)) { 
	 /*stdin에서 정규입력신호로 작동하라고 언급을 했기 때문에 키보드로 입력을 받을 수 있음*/
         buf[BUF_LEN] = '\0';
         len_out = strlen(buf);
         if(!strcmp(ender,buf)){
            break;
         }
         for(i=0;i<BUF_LEN+1;i++){
               if(islower(buf[i])){
                  buf[i] = toupper(buf[i]);
            }
         }    
      }
      else {
	printf("fgets error\n");
        exit(0);
	}
   /* echo 서버로 메시지 송신 */ /*while (strcmp(ender,buf))*/

	if (send(s, buf, len_out, 0) < 0) {
            printf("write error\n");
            exit(0);
         }

   /* 수신된 echo 메시지 화면 출력 */
	printf("Echoed string : ");
      	if(n = recv(s, buf, BUF_LEN, 0) < 0) {
		printf("read error\n");
		exit(0);
	}   
	printf("%s", buf);
   }
   
   close(s);
   return(0);
}

