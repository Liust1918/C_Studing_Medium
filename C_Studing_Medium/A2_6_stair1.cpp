/*�������ַ�ÿ��ƫ��1λ��ʾ*/
/*�ظ���ʾ��0��9*/
#include <stdio.h>

int main_8(void) {
	int i, j;
	int points;
	puts("��ϣ����ʾ������");
	scanf_s("%d", &points);

	for (i = 1; i <=points; i++){
		for ( j = 1; j <i; j++){
			putchar(' ');
		}
		printf_s("%d \n", i%10);
	}
	return 0;
}