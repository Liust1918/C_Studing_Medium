//记忆训练成绩打印效果
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STAGE 5
#define MAX_LEVEL 10
#define MIN_LEVEL 2

int sleep_po2(unsigned long ms) {
	clock_t start = clock(), end;
	do{
		if ((end=clock())==(clock_t)-1) {
			return 0;
		}
	} while ((1000.0*(end-start)/CLOCKS_PER_SEC)<ms);

	return 1;
}


int main_5_5(void) {
	clock_t startTime, endTime;
	srand((unsigned)time(NULL));
	int sLevel = 0;
	int currentWin = 0;
	int totalWin = 0;
	int eachWin[MAX_STAGE] = { 0 };
	int ranArray[MAX_STAGE] = { 0 };
	int inputArray[MAX_STAGE] = { 0 };
	int stage;
	int i;
	puts("加一训练开始！");
	puts("来记忆2位的数值");
	puts("请输入原数值加1后的值");

	do{
		printf_s("请在%d~%d LEVEL 中选择:", MIN_LEVEL, MAX_LEVEL);
		scanf_s("%d", &sLevel);
	} while (sLevel>MAX_LEVEL||sLevel<MIN_LEVEL);

	startTime = clock();
	for ( stage = 0; stage < MAX_STAGE; stage++){
		currentWin = 0;
		printf_s("\n第%d关卡开始 ！ \n",stage+1);

		//随机
		for ( i = 0; i < sLevel; i++){
			ranArray[i] = 10 + rand() % 90;
			printf_s("%d ", ranArray[i]);
		}

		//消失
		sleep_po2(300 * sLevel);
		printf_s("\r");

		//输入
		for ( i = 0; i < sLevel; i++){
			printf_s("第%d个数:", i+1);
			scanf_s("%d", &inputArray[i]);
		}

		//判断和统计
		for (i = 0; i < sLevel; i++){
			if (inputArray[i]==ranArray[i]+1) {
				printf_s("对 ");
				currentWin++;
			}
			else {
				printf_s("错 ");
			}
		}
		totalWin += currentWin;
		eachWin[stage] = currentWin;
	}
	
	
	endTime = clock();
	printf_s("在%d中你答对了%d个 \n", MAX_STAGE * sLevel, totalWin);
	for ( i = 0; i < MAX_STAGE; i++){
		printf_s("第%d次的正确", i + 1);

		for (int j = 0; j < eachWin[i]; j++){
			printf_s("* ");
		}
		putchar('\n');
	}
	printf_s("用时%.3lf秒", (double)(endTime - startTime) / CLOCKS_PER_SEC);
	return 0;
}
