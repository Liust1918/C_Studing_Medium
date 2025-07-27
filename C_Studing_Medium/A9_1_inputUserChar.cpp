/*直接输出玩家输入的字符*/

/*
在命令行中，输入一个一个字符，按回车才显示完整字符串
在命令行，按control+z,实际上就是输入EOF 

*/

#include <stdio.h>

int main_9_1(void) {

	int ch;
	while ((ch=getchar())!=EOF) {
		putchar(ch);
	}

	return 0;
}