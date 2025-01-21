/*用十六进制和二进制打印字符串*/

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
void strdumb(const char* str) {
	int i;
	while (*str) {
		//打印字符,无法打印就打印*字符
		unsigned char x = (unsigned char)*str;
		printf_s(" %c ", isprint(x) ? x : '*');
		//打印十六进制
		printf_s(" %0*X ", (CHAR_BIT + 3) / 4, x);
		putchar('|');
		//打印二进制   char 1字符=8位  1U和八位进行&运算
		for (i = CHAR_BIT-1; i >= 0; i--) {
			printf_s("%c", ((x >> i) & 1U)?'1':'0');
		}
		putchar('\n');

		str++;
	}


}

int main_11(void) {

	puts("汉字");
	strdumb("汉字");

	putchar('\n');
	puts("12中国话AB");
	strdumb("12中国话AB");
	putchar('\n');

	return 0;
}