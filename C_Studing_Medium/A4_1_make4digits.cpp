/*生成4个不同数字的组合并存入数组x*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void make4digits(int x[]) {
	int len = 4;
	int i;
	int j;
	int val;
	srand((unsigned)time(NULL));
	for (i = 0; i < len; i++){
		do{
			val = rand() % 10;
			for ( j = 0; j < i; j++){
				if (val==x[j]) {
					break; //如果发现随机数和数组内的数 重复就退出for,再重新随机一次
				}
			}
		} while (j<i);//如果for中的j<i条件满足，就跳出while
		x[i] = val;//选出来的val直接存入
	}


}

int main_13(void) {
	int ch[4];
	make4digits(ch);
	for (int i = 0; i < 4; i++){
		printf_s("[%d]==%d \n", i, ch[i]);
	}

	return 0;
}