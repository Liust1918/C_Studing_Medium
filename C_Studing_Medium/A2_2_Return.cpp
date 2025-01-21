//重写行
//回车符 \r   将当前位置移动到本行开头

#include <stdio.h>
#include <time.h>

int sleep1(unsigned long sec) {
	clock_t start = clock();
	clock_t end;
	do{

		if ((end=clock())==(clock_t)-1){
			return 0;
		}

	} while ((1000.0*(end-start)/CLOCKS_PER_SEC)<=sec);
	return 1;
}


int main_4(void) {

	printf_s("My Name is YI.");
	sleep1(2000);
	printf_s("\r How do you do");
	sleep1(2000);
	printf_s("\r Thanks");


	return 0;
}