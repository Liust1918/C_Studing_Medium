/*����ѵ�� (����3����λ��������)*/
// Ҫ�� 1.�������������λ��������,��������ȷ��ʱ�򣬲ŷ��ش���ʱ�䣬��������ʱ��,���ػش���󣬲���������лش�
//      2. �������ʱ��,���ҶԲ�ͬ����ʱ��,���ز�ͬ����

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main_6(void) {
	int a, b, c;
	srand(time(NULL));
	a = 100+rand() % 900;
	b = 100+rand() % 900;
	c = 100+rand() % 900;
	int result;
	clock_t start = clock();
	while (1){
		printf_s("%d + %d + %d == \n", a, b, c);
		scanf_s("%d", &result);
		if (a+b+c==result) {
			break;
		}
		printf_s("���ź� ��ش����,����������: \n");
	}

	double useTime =(double)(  (clock() - start) / CLOCKS_PER_SEC);
	if (useTime>30) {
		printf_s("ʱ��̫�� %.1lf", useTime);
	}
	else if (useTime>17) {
		printf_s("������%.1lf", useTime);
	}
	else {
		printf_s("��ǿ��%.1lf", useTime);
	}

	return 0;
}