/*文件的复制*/

/*
1.用户提交了文件名，我希望把文件里面的内容全部显示在屏幕里面

*/

#include <stdio.h>


int main(int argc,char* argv[]) {

	int ch;
	//标准输入流
	while ((ch=fgetc(stdin))!=EOF) {
		//标准输出流
		fputc(ch, stdout);
	}

	return 0;
}