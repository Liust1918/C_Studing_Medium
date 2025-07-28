/*为字符串指针(char**)动态分配空间*/
/*
1.显示有几个字符串
2.从0开始每个输入
3.最后全部显示
*/
/*
char**==char[n][m]
1.先calloc分配(char**)alloc
2.在每个char*用mallco(strlen+1)分配

为什么用 char** 而不是 char p[n][m]
因为：

char p[n][m] 是固定长度二维数组，内存在栈上分配，不能运行时灵活变更。

char** 是动态数组的数组，灵活分配，适合处理不确定个数/长度的字符串。


注意指针一定要free,可以先让指针=NULL
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	int n;
	int i;
	puts("要设置几个字符串");
	scanf_s("%d", &n);
	char** p;
	
	p = (char**)calloc(n, sizeof(char*));
	if (p==NULL) {
		printf_s("内存分配失败");
		return 1;
	}

	//初始化指针
	for ( i = 0; i < n; i++){
		*(p + i) = NULL;
	}
	//输入内容
	for (i = 0; i < n; i++){
		char temp[64];
		printf_s("p[%d]==", i); scanf_s("%s", temp, 64);
		*(p + i) =(char*) malloc(strlen(temp) + 1);
		if (*(p+i)!=NULL) {
			strcpy(*(p + i), temp);
		}
		else {
			for (int j = 0; j < n; j++){
				free(*(p + j));
			}
			free(p);
			return 1;
		}

	}

	for ( i = 0; i < n; i++){
		printf_s("p[%d]==%s \n", i, *(p + i));
	}

	for (i = 0; i < n; i++) {
		free(*(p + i));
	}
	free(p);


	return 0;
}