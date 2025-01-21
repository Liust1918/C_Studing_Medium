/* %*s 参数决定空格数量    n参数," "空字符
printf_s("%*s",n," ")
printf_s("%*s",最低宽度,字符)  显示n个参数的字符
如果字符长度<最低宽度,前面左边填充空格
如果字符长度>最低宽度,最低宽度失效

*/
/*
2.7 扩大水平视野的心算

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main_9(void) {
	int stage=3;
	int a, b, c;
	int result;
	int n;
	clock_t start, end;

	
	srand(time(NULL));
	printf_s("扩大视野心算训练开始 \n");
	start = clock();

	for (int i = 0; i < stage; i++){
		a = 10 + rand() % 90;
		b = 10 + rand() % 90;
		c = 10 + rand() % 90;
		n = rand() % 7;
		
		do{
			printf_s("%d%*s+%*s%d%*s+%*s%d%*s==", a, n, " ", n, " ", b, n, " ", n, " ", c, n, " ");
			scanf_s("%d", &result);
			if (a+b+c==result) {
				break;
			}
			printf_s("结果错误 请重新输入 \n");
		} while (1);
	}
	end = clock();
	printf_s("用时间%.1lf 秒",(double)( (end - start) / CLOCKS_PER_SEC));



	return 0;
}