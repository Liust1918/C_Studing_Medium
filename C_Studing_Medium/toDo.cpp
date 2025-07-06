#include <stdio.h>

int main(void) {

	//函数执行
	//1.2变量
	//声明变量
	int vx, vy;
	//赋值变量
	vx = 10;
	vy = vx + 10;
	//初始化变量
	int vz = 20;

	//1.3输入和显示
	//显示  %d 十进制
	//转换说明: 输入->内存->显示  内存(1+1)传到%d
	printf("\n 1+1=%d ", 1 + 1);

	//显示字符串，自带换行
	puts("显示字符串");

	return 0;
}