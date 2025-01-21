/*字符滚动显示*/
/*逐个显示字符,待字符显示完毕后,再从后往前逐个消去字符，反复执行此操作*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int sleep_A2_5(unsigned long msec) {
	clock_t start = clock();
	clock_t end;
	do{
		if ((end=clock())==(clock_t)-1) {
			break;
			return 0;
		}
	} while ((1000.0*(end-start)/CLOCKS_PER_SEC)<=msec);

	return 1;
}

int main_7(void) {
	char* input;
	int i;
	while (1){
		input = (char*)"ABDF223SD5F";
		int len = strlen(input);
		for ( i = 0; i < len; i++){
			putchar(*input++);
			sleep_A2_5(500);
		}

		for ( i = 0; i < len; i++){
			printf_s("\b \b");
			sleep_A2_5(500);
		}
	}


	return 0;
}