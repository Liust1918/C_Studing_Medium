/*把数字字符每次偏移1位显示*/
/*重复显示从0到9*/
#include <stdio.h>

int main_8(void) {
	int i, j;
	int points;
	puts("你希望显示多少行");
	scanf_s("%d", &points);

	for (i = 1; i <=points; i++){
		for ( j = 1; j <i; j++){
			putchar(' ');
		}
		printf_s("%d \n", i%10);
	}
	return 0;
}