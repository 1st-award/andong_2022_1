#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

void main() {
	char argv[3][2][10] = {{"echo", "udp"}, {"daytime", "tcp"}, {"ssh", "tcp"}};
	struct servent* pmyservent;
	int i = 0;

	while(i < 3) {
		pmyservent = getservbyname(argv[i][0], argv[i][1]);

		printf("%s %d\n", pmyservent->s_name, ntohs(pmyservent->s_port));
		i++;
	}
}


