/* %*s ���������ո�����    n����," "���ַ�
printf_s("%*s",n," ")
printf_s("%*s",��Ϳ��,�ַ�)  ��ʾn���������ַ�
����ַ�����<��Ϳ��,ǰ��������ո�
����ַ�����>��Ϳ��,��Ϳ��ʧЧ

*/
/*
2.7 ����ˮƽ��Ұ������

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main_9(void) {
	int stage=3;
	int a, b, c;
	int result;
	int n;
	clock_t start, end;

	
	srand(time(NULL));
	printf_s("������Ұ����ѵ����ʼ \n");
	start = clock();

	for (int i = 0; i < stage; i++){
		a = 10 + rand() % 90;
		b = 10 + rand() % 90;
		c = 10 + rand() % 90;
		n = rand() % 7;
		
		do{
			printf_s("%d%*s+%*s%d%*s+%*s%d%*s==", a, n, " ", n, " ", b, n, " ", n, " ", c, n, " ");
			scanf_s("%d", &result);
			if (a+b+c==result) {
				break;
			}
			printf_s("������� ���������� \n");
		} while (1);
	}
	end = clock();
	printf_s("��ʱ��%.1lf ��",(double)( (end - start) / CLOCKS_PER_SEC));



	return 0;
}