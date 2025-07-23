#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//5.1 ��������ѵ��
// \r ���ص����׺�,�������ݽ��и���
// ���� printf("Hello World\rABC");   ��� ABClo World

#define MAX_GROUP 5

int sleep_k(unsigned long ms) {
	clock_t start=clock(), end;
	do{
		if ((end=clock())==(clock_t)-1) {
			return 0;
		}
	} while (1000.0*(end - start )/ CLOCKS_PER_SEC < ms);

	return 1;
}

int main_5_1(void) {
	clock_t startTime=clock(), endTime;
	srand((unsigned)time(NULL));
	int winNum = 0;
	int run_group = 0;
	int inputNum;
	int ranNum;
	puts("��������ѵ��");

	do{
		ranNum = 1000 + rand() % 9000;
		printf_s("\r%4d ", ranNum);
		sleep_k(500);
		printf_s("\r�������: ");
		scanf_s("%d", &inputNum);
		if (inputNum==ranNum) {
			puts("�ش���ȷ");
			winNum++;
		}
		else {
			puts("�ش����");
		}

	} while (++run_group<MAX_GROUP);
	endTime = clock();
	printf("��%d�лش���ȷ����=%d  ��ʱ=%.3lfs \n",MAX_GROUP, winNum, (double)(endTime - startTime)/ CLOCKS_PER_SEC);


	return 0;
}