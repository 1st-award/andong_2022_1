#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>

void main() {
	int fd1, fd2, fd3, sd1, sd2;
	
	fd1 = open("/etc/passwd", O_RDONLY, 0);
	printf("/etc/passwd's file descriptor = %d\n", fd1);

	sd1 = socket(PF_INET, SOCK_STREAM, 0);
	printf("stream socket descriptor = %d\n", sd1);

	sd2 = socket(PF_INET, SOCK_DGRAM, 0);
	printf("datagram socket descriptor = %d\n", sd2);

	fd2 = open("/etc/hosts", O_RDONLY, 0);
	printf("/etc/hosts's file descriptor = %d\n", fd2);

	fd3 = open("/usr/bin/cd", O_RDONLY, 0);
	printf("/usr/bin/cd's file descriptor = %d\n ", fd3);

	close(fd1);
	close(sd1);
	close(sd2);
	close(fd2);
	close(fd3);
}
