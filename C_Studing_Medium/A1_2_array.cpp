/* 显示数组的元素个数和各个元素的值*/
#include <stdio.h>

int main_2(void) {
	int array1[] = { 1,2,3,4,5 };
	int len = sizeof(array1) / sizeof(array1[0]);
	printf_s("该数组的元素个数为==%d \n", len);
	for ( int i = 0;i < len;i++){
		printf_s("数组[%d]==%d \n", i, array1[i]);
	}

	return 1;
}