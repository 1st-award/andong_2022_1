#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
void main(int argc, char* argv[]) {
	struct hostent* pmyhostent;
	struct in_addr host_addr;
	int i;

	if(argc != 2) {
		printf("usage %s name_host\n", argv[0]);
		exit(0);
	}

	pmyhostent = gethostbyname(argv[1]);

	while(pmyhostent->h_addr_list[i] != NULL) {
		host_addr.s_addr = *((u_long*)pmyhostent->h_addr_list[i]);
		
		printf("%x (ntohl(X)\n", host_addr.s_addr);
		printf("%x (ntohl(O)\n", ntohl(host_addr.s_addr));
		printf("%s\n", inet_ntoa(host_addr));
		i++;
	}
}
