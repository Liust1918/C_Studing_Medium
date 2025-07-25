/*将最多MAX个数，存入大小为MAX的数组内*/
//1.只能输入MAX个元素
//2.可以输入任意多个元素,只保留最后输入的MAX个元素
// 例如 输入 1 2 3 4 5   => 6 1 2 3 4
//     输出  1 2 3 4 5  => 1 2 3 4 6

#include <stdio.h>

#define MAX 5  //数组长度

int main_5_6(void) {
	int retry = 0;
	int countInput = 0; //输入次数
	int a[MAX] = { 0 }; //存储数组
	int i;

	puts("将任意个数存入数组当中");

	do{

		printf_s("输入第%d个数字== \n", countInput+1);
		scanf_s("%d", &a[countInput >= MAX ? countInput++ % MAX : countInput++]);

		puts("你是否继续  是==0 否==1 ");
		scanf_s("%d", &retry);
	} while (retry==0);

	i = countInput - MAX;
	if (i<0) {
		i = 0;
	}
	for (;  i< countInput; i++){
		printf_s("a[%d]==%d \n", i+1, a[i % MAX]);
	}

	return 0;
}