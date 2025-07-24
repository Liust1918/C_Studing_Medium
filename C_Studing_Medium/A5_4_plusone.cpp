//记忆多个数值并加一

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STAGE 5
#define MAX_LEVEL 10
#define MIN_LEVEL 2


int sleep_po(unsigned long ms) {
	clock_t start=clock(), end;
	do{
		if ((end=clock())==(clock_t)-1) {
			return 0;
		}
	} while ((1000.0*(end-start)/CLOCKS_PER_SEC)<ms);
	return 1;
}

int main_5_4(void) {
	clock_t startTime, endTime;
	srand((unsigned)time(NULL));
	int currentWin = 0;
	int totalWin = 0;
	int eachWin[MAX_STAGE] = { 0 };
	startTime = clock();
	int ranArray[MAX_LEVEL] = { 0 };
	int inputArray[MAX_LEVEL] = {0};
	int sLevel = 0;
	int i;
	int stage;
	puts("加一训练开始！");
	puts("来记忆2位的数值");
	puts("请输入原数值加1后的值");

	do{
		printf_s("请从%d ~ %d LEVEL 中选择\n",MIN_LEVEL,MAX_LEVEL);
		scanf_s("%d", &sLevel);
	} while (sLevel>MAX_LEVEL||sLevel<MIN_LEVEL);

	

	for ( stage = 0; stage < MAX_STAGE; stage++){
		currentWin = 0;
		printf_s("\n 第%d关卡开始 ! \n", stage + 1);

		for ( i = 0; i <sLevel ; i++){
			ranArray[i] = 10 + rand() % 90;
			printf_s("%d ", ranArray[i]);
		}
		sleep_po(500 * sLevel);
		printf_s("\r");

		for ( i = 0; i < sLevel; i++){
			printf_s("第%d个数:", i + 1);
			scanf_s("%d", &inputArray[i]);
		}

		for ( i = 0; i < sLevel; i++){
			if (ranArray[i]+1==inputArray[i]) {
				printf("对   ");
				currentWin++;
			}
			else {
				printf("错   ");
			}
		}
		

		puts("");
		totalWin += currentWin;
		eachWin[stage] = currentWin;

		for ( i = 0; i < sLevel; i++){
			printf("%d ", ranArray[i]);
		}
		printf_s("答对了%d个 \n", currentWin);

	}
	

	endTime = clock();
	printf_s("在%d中你答对了%d个 \n",MAX_STAGE*sLevel,totalWin);
	for ( i = 0; i < MAX_STAGE; i++){
		printf_s("第%d关卡:%d \n", i + 1, eachWin[i]);
	}
	printf_s("用时%.3lf秒", (double)(endTime - startTime) / CLOCKS_PER_SEC);

	return 0;
}