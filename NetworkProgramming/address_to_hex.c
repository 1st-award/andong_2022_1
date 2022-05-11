#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void main(int argc, char* argv[]) {
	char* haddr;
	struct in_addr host_ip;

	if(argc < 2) {
		printf("사용법 : %s IP 주소(dotted decimal)\n", argv[0]);
		return;
	}

	haddr = argv[1];
	host_ip.s_addr = inet_addr(haddr);

	printf("정수 값 IP 주소(16진수) : 0x%x\n", host_ip.s_addr);
	printf("정수 값 IP 주소 (8진수) : 0%o\n", host_ip.s_addr);
	printf("정수 값 IP 주소(10진수) : %d\n", host_ip.s_addr);
	printf("Dotted Decimal IP 주소로 다시변환 : %s\n", inet_ntoa(host_ip));
}
