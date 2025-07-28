/*命令行参数自定义制图表*/
/*
1.在命令行中输入  xx.exe -t2 a.txt ,控制a.txt内容里面的输出宽度
2.把a\tb\tc中\t默认宽带，改成2宽度.(a____b____c=>a__b__c)

*/

/*
'\t'制表符(相当于键盘 Tab 键)

*/
#define _CRT_SECURE_NO_WARNINGS //fopen在vs里面会警告
#include <stdio.h>
#include <stdlib.h>

void copy(FILE* src, FILE* dest, int width) {
	int ch, pos = 1;//pos光标从1开始
	while ((ch = fgetc(src) )!= EOF) {
		int num;/*空格的数量*/
		switch (ch) {
		case '\t':
			num = width - (pos - 1) % width;//重点，
			/*
			1.当前字符位于第 pos 列。
            2.一个 tab 需要跳到 下一个 width 整数倍位置。
            举例：如果当前 pos = 5，width = 4，下一个 tab 停靠列是 8。
            所以需要填 3 个空格：8 - 5 = 3
			*/
			for (; num > 0; num--) {
				fputc(' ', dest);
				pos++;
			}
			
			break;
		case '\n':
			fputc(ch, dest);
			pos = 1;
			break;
		default:
			fputc(ch, dest);
			pos++;
			break;
		}
		
	}

}

int main_9_3(int argc,char* argv[]) {
	FILE* fp;
	int width = 8;
	if (argc<2) {
		copy(stdin, stdout,width);
	}
	else {

		while (--argc>0) {
			// 拿到"-t2"字符串
			//1.++argv==指针移到第二个字符串
			//2.*++argv==解引用，获得第二个字符串("-t2"的首地址,str[])
			//3.**++argv==解引用，获得第二个字符串中的第一个字符('-',str[][0])
			if (**++argv=='-') {
				//1.*argv==解引用，获得第二个字符串("-t2"的首地址,str[])
				//2.++(*argv)==,指针前移,获得获得第二个字符串中的第二个字符('t',str[][1])
				if ((*++(*argv))=='t') {
					width = atoi(++(*argv));//后面不知道有多少个字符，使用atoi直接都转string->int
					//直接用获得获得第二个字符串中的第三个字符的地址(也就是首地址)
				}
				else {
					fputs("参数不正确\n", stderr);
					return 1;
				}
			}
			else if ((fp = fopen(*argv, "r")) == NULL) {
					fprintf(stderr, "文件%s无法正确打开 \n", *argv);
					return 1;
				}
				else {
					copy(fp, stdout, width);
					fclose(fp);
				}
			}

			
		
	}

	return 0;
}

/*

E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe a.txt
a               b               c
d               e               f
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe -t4 a.txt
a       b       c
d       e       f
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe -t2 a.txt
a   b   c
d   e   f
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe -t0 a.txt
a
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe -t1 a.txt
a  b  c
d  e  f
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe -t12 a.txt
a                       b                       c
d                       e                       f
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>

*/
