/*文件的转储(二进制)*/
/*
1.在命令行中输入xx.exe  a.txt ,把a.txt内的16进制地址,每个字符的16进制码,内容输出到屏幕里面

*/

/*
将内容打印到命令行屏幕,可以用fprintf()
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <climits>
#include <ctype.h>



void hdump(FILE* src, FILE* dest) {
	unsigned char buf[16];//字符缓冲区
	unsigned long count=0; //输出地址，本质上是在文件里面第几个字符
	int n;//保存成功读取个数
	int i;
	while ((n=fread(buf,sizeof(char), 16, src))>0) {
		//1.打印地址count
		fprintf(dest, "%08lX ", count);//lX==16进制,8位0补齐
		//2.打印每个字符的码
		for ( i = 0; i < n; i++){
			fprintf(dest, "%0*X ",(CHAR_BIT+3)/4, buf[i]);			
		}
		//3.填充空格
		if (n<16) {
			for ( i = n; i < 16; i++){
				fprintf(dest, "%*s ", (CHAR_BIT + 3) / 4, "");
			}
		}
		//4.打印内容
		for ( i = 0; i < 16; i++){
			if (isprint(buf[i])) {
				fputc(buf[i], dest);
			}
			else {
				fputc('.', dest);
			}
		}

		fputc('\n',dest);
		count += 16;
	}

}

int main_9_4(int argc, char* argv[]) {

	FILE* fp;

		while (--argc>0) {
			if ((fp=fopen(*++argv,"rb")) == NULL) {
				fprintf(stderr, "文件%s无法正确打开\n", *argv);
				//如果不使用stderr,所有的错误内容也很覆盖到另外一个文件.
			}
			else {
				hdump(fp, stdout);
				fclose(fp);
			}
			puts("");
		}
	


	return 0;
}