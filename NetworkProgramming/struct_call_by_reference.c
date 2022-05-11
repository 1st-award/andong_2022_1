#include <stdio.h>

struct scores {
	int kor;
	int eng;
	int math;
	float average;
};

float avg(struct scores* p) {
	return ((float)(p->kor + p->eng + p->math)/3);
}

void main() {
	struct scores data[5];
	int i;
	for(i=0; i<5; ++i) {
		printf("%d번째 학생 국어 영어 수학 순으로 입력 : ", i+1);
		scanf("%d %d %d", &data[i].kor, &data[i].eng, &data[i].math);
	}
	
	for(i=0; i<5; ++i) {
		data[i].average = avg(&data[i]); 
	}	
	
	puts("학생들의 평균");
	for(i=0; i<5; ++i) {
		printf("%d번째 학생 국어 영어 수학 평균 : %.2f\n", i+1, data[i].average);
	}
}
