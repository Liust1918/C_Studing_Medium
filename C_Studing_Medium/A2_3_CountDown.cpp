/*倒计时后显示程序运行时间*/

#include <stdio.h>
#include <time.h>

int sleep2(unsigned long sec) {
	clock_t start = clock();
	clock_t end;
	do{
		if ((end=clock())==(clock_t)-1) {
			return 0;
		}

	} while ((1000.0*(end-start)/CLOCKS_PER_SEC)<=sec);
	return 1;
}

int main_5(void) {
	int i;
	clock_t now;
	for ( i = 10; i > 0 ; i--){
		printf_s("\r %2d", i);
		sleep2(1000);
	}
	printf_s("\r 啪");
	now = clock();
	printf_s("程序开始运行后经过了%.1f秒. \n", (double)now/ CLOCKS_PER_SEC);

	return 0;
}