//<stdlib.h>
//int rand(void) 返回0~RAND_MAX的int值    获取随机数(伪随机)
//不同编译器 RAND_MAX的值不一样
//void srand(unsigned seed); 为rand生成一个种子 （必须写在rand方法前）

//可以用时间作为种子 <time.h> time(NULL)   (其实还是伪随机)

//猜数判定
//设置1: 输入值大于目标数，显示(比目标值大)，小于目标值，显示(比目标值小)
//设置2: 可以不断输入值
//设置3  设置随机的目标数字
//设置4: 目标数字是0~9的随机数
//设置5: 可以输入3次限制,并且显示输入了n次,记录输入了n次的值,并且将值输出出来,每个输入值距离目标值多少.并且显示正确的目标值(使用对象宏)
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define inputNumber 3

//1.1猜数判定
int main_1(void) {

	srand((unsigned)time(NULL));
	int dest = rand() % 10;
	int inputValue;
	int remainTimes= inputNumber;
	int totalTimes = remainTimes;
	int input[inputNumber];

	do{
		
		puts("你猜是多少? (0~9)");
		scanf_s("%d", &inputValue);
		input[totalTimes - remainTimes] = inputValue;
		remainTimes--;
		if (inputValue > dest) {
			puts("比实际数字大");
		}
		else if (inputValue < dest) {
			puts("比实际数字小");
		}
	} while ((inputValue != dest)&&(remainTimes>0));

	if (inputValue==dest) {
		printf_s("恭喜你,猜对了,你一个用了%d次. \n",totalTimes-remainTimes);
	}
	else {
		printf_s("你没有猜对,答案是%d \n",dest);
	}
	for (int i = 0; i < totalTimes-remainTimes; i++){
		printf_s("第%4d次:%4d 离答案差%4d \n", i + 1, input[i], input[i] - dest);
	}


	return 0;
}