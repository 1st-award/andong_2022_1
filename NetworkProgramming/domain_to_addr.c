#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>

void main(int argc, char* argv[]) {
	struct hostent *myhost;
	struct in_addr myinaddr;
	struct hostent *domain_name;
	int i;

	if(argc < 2) {
		printf("사용법 : %s host_name(도매인 네임)\n", argv[0]);
		return;
	}

	printf("입력한 도메인: %s\n", argv[i]);
	myhost = gethostbyname(argv[1]);

	if(myhost == 0) {
		printf("error at gethostbyname\n");
		return;
	}

	i = 0;
	while(myhost->h_addr_list[i] != NULL) {
		myinaddr.s_addr = *((u_long *)(myhost->h_addr_list[i]));

		printf("IP 주소(2진수, ntohl X): 0x%x(16진수)\n", myinaddr.s_addr);
		printf("IP 주소(2진수, ntohl O): 0x%x(16진수)\n", ntohl(myinaddr.s_addr));

		printf("IP address : %s\n", inet_ntoa(myinaddr));
		
		domain_name = gethostbyaddr(&myinaddr.s_addr, 4, AF_INET);
		printf("Again Address To Domain : %s\n", domain_name->h_name);		
		i++;
	}
}
