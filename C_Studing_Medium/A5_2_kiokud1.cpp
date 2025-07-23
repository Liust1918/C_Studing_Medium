#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEVEL 50
#define MIN_LEVEL 3
#define MAX_STGAE 5
//5.2 带等级的记忆训练

//在 Microsoft 的 scanf_s 规则中：
//如果你使用% s（读字符串），必须提供目标 char[] 的 缓冲区大小，否则会触发访问冲突（访问未授权内存）
//scanf_s("%s", input, (unsigned)_countof(input));	✅ 安全，VS推荐方式

//printf_s("\r%*s\r 请输入答案:", selectedLevel, "");

//技巧:生成大n位随机数的方法 用字符串(char数组) 一个个char随机数字0-9 在用strcmp比较字符串

int sleep_k1(unsigned long ms) {
	clock_t start = clock(), end;

	do{
		if ((end=clock())==(clock_t)-1) {
			return 0;
		}
	} while (1000.0*(end-start)/CLOCKS_PER_SEC < ms);
	return 1;
}

int main_5_2(void) {
	clock_t startTime, endTime;
	int selectedLevel=0;
	int winNum = 0;
	int stage = 0;
	int i;
	srand((unsigned)time(NULL));
	puts("可以设置等级的记忆训练");
	do{
		printf_s("请选择 %d ~ %d 等级 \n", MIN_LEVEL, MAX_LEVEL);
		scanf_s("%d", &selectedLevel);
	} while (selectedLevel>MAX_LEVEL||selectedLevel<MIN_LEVEL);

	printf("来记忆 %d 位的数值吧 \n", selectedLevel);

	startTime = clock();
	do{
		char num[MAX_LEVEL + 1]; //记忆的字符串数字
		char input[MAX_LEVEL * 2]; //输入的字符串数字 (char 1Byte  int 2Byte)

		//生成大n位随机数的方法 用字符串(char数组) 一个个char随机数字
		num[0] = '1' + rand() % 9; //第一位不能为0
		for ( i = 1; i < selectedLevel; i++){
			num[i] = '1' + rand() % 9;
		}
		num[selectedLevel] = '\0';

		//显示记忆数字
		printf_s("%s", num);
		sleep_k1(125 * selectedLevel);

		printf_s("\r%*s\r 请输入答案:", selectedLevel, "");
		scanf_s("%s", input,(unsigned)sizeof(input));
		if (strcmp(num,input)!=0) {
			puts("回答错误");
		}
		else {
			puts("回答正确");
			winNum++;
		}
	} while (++stage<MAX_STGAE);
	endTime = clock();
	printf("你在难度%d LEVEL 中的%d 轮回答 中 正确回答了%d个问题 用时%.3lfs \n", selectedLevel, MAX_STGAE, winNum, (double)((endTime-startTime) / CLOCKS_PER_SEC));

	return 0;
}