// 退格符 \b
// 要求:1.每隔一秒,从后面逐个消除字符
//      2. 最后退出程序

//sleep 方法
// clock_t clock(void)  返回该进程调用处理器多少时间
// 返回 从程序开始起,处理器被使用的时钟ticks值 ,失败则返回-1 (clock_t类型)
// 使用例: 用clock方法返回ticks值，再除以 CLOCK_PER_SEC,就可以获得运行毫秒,用结束-开始,获得实际的程序时间运行时间

//消除字符  printf_s("\b \b");   
// 例如: "ABC"
//  1.光标先从  "ABC|"  执行\b,变成"AB|C"
//  2.再执行空格, 变成"AB |";
//  3.再执行\b  ,就变成"AB|"

#include <stdio.h>
#include <time.h>

/*暂停n毫秒   用这个方法挂着该进程,来实现暂停,直到满足时间,再返回1,如果中间失败,则返回0*/
int sleep(unsigned long sec) {
	clock_t start = clock();
	clock_t end;
	do {
		if ((end=clock())==(clock_t)-1) {
			return 0;//返回错误
		}
	} while ((1000.0*(end-start)/CLOCKS_PER_SEC)<=sec);

	return 1;
}

int main_3(void) {
	printf_s("ABCDERF");
	for (int i = 0; i < 7; i++){
		sleep(1 * 1000.0);
		printf_s("\b \b");
	}
	return 0;
}