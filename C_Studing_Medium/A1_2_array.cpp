/* ��ʾ�����Ԫ�ظ����͸���Ԫ�ص�ֵ*/
#include <stdio.h>

int main_2(void) {
	int array1[] = { 1,2,3,4,5 };
	int len = sizeof(array1) / sizeof(array1[0]);
	printf_s("�������Ԫ�ظ���Ϊ==%d \n", len);
	for ( int i = 0;i < len;i++){
		printf_s("����[%d]==%d \n", i, array1[i]);
	}

	return 1;
}