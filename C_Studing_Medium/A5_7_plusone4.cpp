/*Ϊ�������鶯̬����洢�ռ�*/
/*
ͷ�ļ�: #include <stdlib.h>
��ʽ:  void calloc(size_t n,size_t size);
���ܣ�Ϊn����СΪsize�ֽڵĶ�������ڴ�ռ䣬�Ŀռ��ڵ�����λ�����ʼ��Ϊ0
����ֵ��������ɹ����򷵻�һ��ָ���ѷ���Ŀռ俪ͷ��ָ�룬������ʧ�ܣ��򷵻ؿ�ָ��.

*/

#include <stdio.h>
#include <stdlib.h>

int main_5_7(void) {
	int n;
	int i;

	puts("����������Ҫ����ĳ���");
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