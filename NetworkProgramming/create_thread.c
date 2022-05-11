#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

void* exThreadFunc(void *no);
int sum = 0;

int main(int argc, char* argv[]) {
	int result, number, i, rst;
	pthread_t ex_thread[10];

	if(argc != 2) {
		printf("usage: %s number\n", argv[0]);
		exit(0);
	}

	number = atoi(argv[1]);
	for(i = 0; i < number; ++i) {
		result = pthread_create(&ex_thread[i], NULL, exThreadFunc, (void*) &i);
		printf("%d Thread Id at Main = %ud\n", i, (int)ex_thread[i]);

		if(result < 0) {
			perror("thread create error\n");
			continue;
		}
		sleep(1);
	}

	for(i = 0; i < number; ++i) {
		pthread_join(ex_thread[i], (void*)&rst);
	}
}

void* exThreadFunc(void* no) {
	int seq;
	pthread_t id;

	seq = *((int*)no);
	id = pthread_self();
	printf("%d Thread Id at exThreadFunc = %ud\n", seq, (int)id);

	srand(time(NULL));
	sleep(rand()%5);

	sum++;
	printf("%d <---------- Thread Ended with sum = %d ---------->\n", seq, sum);
}


