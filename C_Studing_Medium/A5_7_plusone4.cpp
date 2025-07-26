/*为整数数组动态分配存储空间*/
/*
头文件: #include <stdlib.h>
格式:  void calloc(size_t n,size_t size);
功能：为n个大小为size字节的对象分配内存空间，改空间内的所有位都会初始化为0
返回值：若分配成功，则返回一个指向已分配的空间开头的指针，若分配失败，则返回空指针.

*/

#include <stdio.h>
#include <stdlib.h>

int main_5_7(void) {
	int n;
	int i;

	puts("请输入你想要数组的长度");
	scanf_s("%d", &n);

	int* p = (int*)calloc(n, sizeof(int));
	if (p==NULL) {
		return 1;
	}

	for ( i = 0; i < n; i++){
		*(p + i) = i;
	}

	for ( i = 0; i < n; i++){
		printf_s("p[%d]=%d \n", i, *(p + i));
	}

	return 0;
}