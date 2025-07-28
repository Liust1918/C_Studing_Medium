/*文件的复制*/
#define _CRT_SECURE_NO_WARNINGS

/*
每次使用都要，重新编译
1.在命令行中输入  xx.exe，把输入的内容显示到屏幕里面
2.在命令行中输入，xx.exe 文件名1 文件名2... 把文件内容都显示在屏幕里面
3.在命令行中输入，xx.exe 文件名1>文件名2,把文件名1的内容复制到文件名2
*/

/*
在 <stdio.h> 中，系统已经为你定义好了三个标准文件指针：
extern FILE *stdin;   // 标准输入（通常是键盘）
extern FILE *stdout;  // 标准输出（通常是屏幕）
extern FILE *stderr;  // 标准错误输出（通常是屏幕）

在命令行显示内容为什么要用fprintf(stderr,"输出内容",...);
fprintf(stderr,"文件%s无法打开", *argv);
如果打开失败，使用 标准错误输出 stderr 显示错误信息，防止错误信息混杂在文件内容中。
如果不使用stderr,而使用stdout,会把错误内容也很覆盖到另外一个文件.

*/

#include <stdio.h>

void copy(FILE* src, FILE* dest) {
	int ch;
	//标准输入流
	while ((ch = fgetc(src)) != EOF) {
		//标准输出流
		fputc(ch, dest);
	}
}

//第一个字符串是.exe文件名称 
int main_9_2(int argc,char* argv[]) {

	FILE* fp;
	//如果argv只有一个参数(.exe文件名),就不复制文件
	if (argc<2) {
		copy(stdin, stdout);//屏幕输入和输出
		return 0;
	}
	//如果argv有多个参数
	while(--argc>0){
		//*++argv 第二个文件名的字符串
		if ((fp = fopen(*++argv, "r")) == NULL) {
			//前面argv已经++，这里直接解引用
			fprintf(stderr,"文件%s无法打开", *argv);
			//如果打开失败，使用 标准错误输出 stderr 显示错误信息，防止错误信息混杂在文件内容中。
			//如果不使用stderr,而使用stdout,会把错误内容也很覆盖到另外一个文件.
		}
		else {
			copy(fp, stdout);//a.txt>b.txt
			fclose(fp);
		}
		puts("");
	}
	
		
	

	return 0;
}