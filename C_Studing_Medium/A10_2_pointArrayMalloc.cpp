/*为字符串动态分配空间*/
/*
function 1.请输入字符串str,生成一个副本，并且显示原本和副本在屏幕
function 2.先问输入几个字符串，然后从0开始一个一个字符串输入,最后全部显示
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
(char*)malloc(字符长度+1) //+1是结束符号'\0'
内存申请完，要释放 free(指针)

int arr[a][15] 这是错误的,数组大小只能设置成常量,不能设置成变量
*/

void function1() {
	char str[16];
	char* pt;
	puts("请输入内容");
	scanf_s("%15s", str, (unsigned)_countof(str));

	pt = (char*)malloc(strlen(str) + 1);
	if (pt) {
		
		strcpy(pt, str);
		
		printf_s("原本:%s\n", str);
		printf_s("副本：%s\n", pt);
		free(pt);
	}
	else {
		printf_s("内存分配失败 \n");
	}

}

/*
名称	声明形式	本质	举例
指针数组	type* arr[N];	一个数组，元素是指针	char* arr[3];
arr ─┬─→ "apple"
	 ├─→ "banana"
	 └─→ "cherry"

数组指针	type (*p)[N];	一个指针，指向数组	int (*p)[5];
arr: [1, 2, 3, 4, 5]
 p ──→ &arr
	 └───>  整个数组

*/
/*
char (*p)[15];
意思是：
 p 是一个指针，指向一个长度为 15 的 char 数组。
也可以理解为：
*p 是一个 char[15]

p[i] 是第 i 个 char[15]（即第 i 个字符串）

*/
void funtion2() {
	int n=0;
	char (*p)[15];//数值指针,主体是指针,类似于p->char[15],相当于p[n][15]
	int i;
	puts("设置几个字符串？");
	scanf_s("%d", &n);
	p =(char(*)[15]) malloc(n * sizeof(*p));//重点,不能char*[15],因为[]优先级很高,会变成指针数组
	if (p==NULL) {
		puts("内存分配失败");
		return;
	}
	for ( i = 0; i < n; i++){
		printf_s("p[%d]=", i);
		scanf_s("%15s", *(p + i), (unsigned)_countof(*p));
		putchar('\n');
	}
	for ( i = 0; i < n; i++){
		printf_s("p[%d]=%s \n", i,*(p+i));
	}

	free(p);
}

int main_10_2(void) {
	
	function1();
	funtion2();

	return 0;
}