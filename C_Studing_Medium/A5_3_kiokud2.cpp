//'a' - 'A' == 32
//所以你可以用 ASCII 运算实现大小写转换：
//char lower = 'A' + 32;  // => 'a'
//char upper = 'z' - 32;  // => 'Z'

//一个数组 'A'-'Z' 'a'-'z'
// az[i] = 'A' + i;    az[i+26] = 'a' + i;

//数组最好初始化

//5.3 字符串记忆训练

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STAGE 5
#define MAX_LEVEL 30
#define MIN_LEVEL 3

int sleep_k2(unsigned long ms) {
	clock_t start = clock(), end;
	do{
		if((end=clock())==(clock_t)-1){
			return 0;
		}
	} while (1000.0*(end-start)/CLOCKS_PER_SEC < ms);
	return 1;
}

//一个数组填入char 'A'-'Z' 'a'-'z'
void getCharArray(char az[]) {
	int len = 26;
	int i;
	// 'A'-'Z'
	for (i = 0; i < len; i++){
		az[i] = 'A' + i;
	}
	//'a'-'z'
	for (i = 0; i < len; i++) {
		az[i+26] = 'a' + i;
	}
}



int main_5_3(void) {
	clock_t startTime, endTime;
	int winNum = 0;
	int stage = 0;
	int sLevel = 0;
	char az[53] = {0};
	int i;
	srand((unsigned)time(NULL));
	do{
		printf("请在 %d ~ %d LEVEL 选择 \n", MIN_LEVEL, MAX_LEVEL);
		scanf_s("%d", &sLevel);
	} while (sLevel>MAX_LEVEL||sLevel<MIN_LEVEL);

	getCharArray(az);


	startTime = clock();
	do{
		
		char num[MAX_LEVEL + 1] = {0};
		char input[MAX_LEVEL * 2];
		//随机
		for ( i = 0; i < sLevel; i++){
			num[i] = az[(rand() %( strlen(az)-1))];
		}

		printf_s("%s", num);
		sleep_k2(125 * sLevel);

		//输入
		printf_s("\r%*s\r 请输入答案：", sLevel, "");
		scanf_s("%s", input, (unsigned)_countof(input));

		//判断
		if (strcmp(num,input)!=0) {
			puts("回答错误");
		}
		else {
			puts("回答正确");
			winNum++;
		}


	} while (++stage<MAX_STAGE);
	endTime = clock();
	printf("你在难度%d LEVEL 中的%d 轮回答 中 正确回答了%d个问题 用时%.3lfs \n", sLevel, MAX_STAGE, winNum, (double)((endTime - startTime) / CLOCKS_PER_SEC));


	return 0;
}
