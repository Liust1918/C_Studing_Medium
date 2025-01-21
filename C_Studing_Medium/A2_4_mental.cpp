/*心算训练 (连加3个三位数的整数)*/
// 要求 1.计算三个随机三位数的整数,当输入正确的时候，才返回答题时间，输入错误的时候,返回回答错误，并且允许进行回答
//      2. 计算答题时间,并且对不同答题时间,返回不同评价

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main_6(void) {
	int a, b, c;
	srand(time(NULL));
	a = 100+rand() % 900;
	b = 100+rand() % 900;
	c = 100+rand() % 900;
	int result;
	clock_t start = clock();
	while (1){
		printf_s("%d + %d + %d == \n", a, b, c);
		scanf_s("%d", &result);
		if (a+b+c==result) {
			break;
		}
		printf_s("很遗憾 你回答错误,请重新输入: \n");
	}

	double useTime =(double)(  (clock() - start) / CLOCKS_PER_SEC);
	if (useTime>30) {
		printf_s("时间太长 %.1lf", useTime);
	}
	else if (useTime>17) {
		printf_s("还可以%.1lf", useTime);
	}
	else {
		printf_s("很强啊%.1lf", useTime);
	}

	return 0;
}