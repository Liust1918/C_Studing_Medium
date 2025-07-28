/*bcopy:文件的分块复制 */
/*
1.在命令行中，将a.txt文件中内容(分块复制)到另外文件上
例如:在命令行中输入xx.exe a.txt b.txt
    读取16个字符 写入16个字符
    读取13个字符 写入13个字符
*/

/*
1.声明多个指针,FILE* src, *dest; 必须后面也加*
2.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BSIZE 16 //每块读取/写入16个字符

int main_9_5(int argc, char* argv[]) {


    FILE* src, * dest;
    unsigned char buf[BSIZE];//一块缓冲区
    int n;//每次读取成功的字符个数

    if (argc!= 3) {
        fprintf(stderr, "参数不正确\n");
        return 1;
    }
    if ((src = fopen(*++argv, "rb")) == NULL) {
        fprintf(stderr, "文件%s无法正常打开\n", *argv);
        return 1;
    }
    if ((dest = fopen(*++argv, "wb")) == NULL) {
        fprintf(stderr, "文件%s无法正常打开\n", *argv);
        fclose(src);
        return 1;
    }
    while ((n = fread(buf, sizeof(char), BSIZE, src))>0){
        fprintf(stderr, "读取了%d个字符 ", n);
        n=fwrite(buf, sizeof(char), n, dest);
        fprintf(stderr, "写入了%d个字符 \n", n);
    }


    fclose(dest);
    fclose(src);
    

	return 0;
}