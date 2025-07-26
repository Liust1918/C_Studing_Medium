/*寻找缺失的数字*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STAGE 5

int main_7_1(void) {
	clock_t startTime, endTime;
	int i, j=0;
	srand((unsigned)time(NULL));
	int num[9] = { 1,2,3,4,5,6,7,8,9 };
	int b[8] = { 0 };
	int stage = 0;
	double usedTime = 0;
	int input;
	int win = 0;
	startTime = clock();
	do{
		
	//生成随机数
		int guessIndex = rand() % 8;
		int guess = num[guessIndex];
	//从数组中去掉随机数
		j = 0;
		for ( i = 0; i < 9; i++){
			if (guess!=num[i]) {
				b[j++] = num[i];
			}
		}

	//显示数组
		for ( i = 0; i < 8; i++){
			printf_s("%d ", b[i]);
		}

	//输入判断
		scanf_s("%d", &input);
		if (input==guess) {
			win++;
			puts("回答正确");
		}
		else {
			puts("回答错误");
		}


	} while (stage++<MAX_STAGE);
	endTime = clock();
	//时间统计
	usedTime = (double)(endTime - startTime / CLOCKS_PER_SEC);

	if (usedTime>12.5) {
		puts("反应太慢");
	}
	else if (usedTime > 10.0) {
		puts("反应有点慢");
	}
	else if (usedTime > 8.5) {
		puts("反应还行");
	}
	else {
		puts("反应真快");
	}


	return 0;
}