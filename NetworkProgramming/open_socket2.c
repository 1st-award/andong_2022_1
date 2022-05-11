#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>

void main() {
	int fd1, fd2, fd3, sd1, sd2, sd3, sd4;
	
	fd1 = open("/etc/passwd", O_RDONLY, 0);
	printf("/etc/passwd descripter : %d\n", fd1);
 	// 추가한 stdio.h 파일
	fd3 = open("/usr/include/stdio.h", O_RDONLY, 0);
	printf("/usr/include/stdio.h file descripter : %d\n",  fd1);

	sd1 = socket(PF_INET, SOCK_STREAM, 0);
	printf("stream socket desciprter : %d\n", sd1);

	sd2 = socket(PF_INET, SOCK_DGRAM, 0);
	printf("datagram socket descripter : %d\n", sd2);
	
	fd2 = open("/etc/hosts", O_RDONLY, 0);
	printf("/etc/hosts descripter : %d\n", fd2);
	
	// 추가한 TCP 소캣	
	sd3 = socket(PF_INET, SOCK_STREAM, 0);
	printf("stream socket2 descripter : %d\n", sd3);
	// 추가한 UDP 소캣
	sd4 = socket(PF_INET, SOCK_DGRAM, 0);
	printf("datagram socket2 descripter : %d\n", sd4);

	close(fd1);
	close(sd1);
	close(sd2);
	close(fd2);
	close(fd3);
	close(sd3);
	close(sd4);
}
