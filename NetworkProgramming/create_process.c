#include <stdio.h>
#include <unistd.h>

int sum = 0;

void main(argc, argv)
int argc;
char *argv[];
{
	int child1, child2, child3, pid, status, wait(), fork();
	void exit();

	if((child1 = fork()) == 0) {
		printf("child1: childid1 = %d, ppid = %d\n", getpid(), getppid());
		sum++;
		printf("child1: <==========- sum=%d -==========>\n", sum);
		sleep(2);
		execl("/bin/date", "date", (char*)0);
	}

	if((child2 = fork()) == 0) {
		printf("child2: childid2 = %d, ppid = %d\n", getpid(), getppid());
		sum++;
		printf("child2: <==========- sum=%d -==========>\n", sum);
		sleep(2);
		execl("/bin/ls", "ls", "-a", (char*)0);
	}

	if((child3 = fork()) == 0) {
		printf("child3: childid3 = %d, ppid = %d\n", getpid(), getppid());
		sum++;
		printf("child3: <==========- sum=%d -==========>\n", sum);
		execl("/bin/whoami", "whoami", (char*)0);
	}

	sleep(2);
	printf("parent: waiting for children\n");
	while((pid = wait(&status)) != -1) {
		if(child1 == pid) {
			printf("parent: child1 is terminated\n");
		}
		else if(child2 == pid) {
			printf("parent: child2 is terminated\n");
		}
		else if(child3 == pid) {
			printf("parent: child3 is terminated\n");
		}
	}

	printf("parent: all children terminated\n");
	printf("parent: <==========- sum=%d -==========>\n", sum);
	exit(0);
}
