/*Ѱ��ȱʧ������*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STAGE 5

int main_7_1(void) {
	clock_t startTime, endTime;
	int i, j=0;
	srand((unsigned)time(NULL));
	int num[9] = { 1,2,3,4,5,6,7,8,9 };
	int b[8] = { 0 };
	int stage = 0;
	double usedTime = 0;
	int input;
	int win = 0;
	startTime = clock();
	do{
		
	//���������
		int guessIndex = rand() % 8;
		int guess = num[guessIndex];
	//��������ȥ�������
		j = 0;
		for ( i = 0; i < 9; i++){
			if (guess!=num[i]) {
				b[j++] = num[i];
			}
		}

	//��ʾ����
		for ( i = 0; i < 8; i++){
			printf_s("%d ", b[i]);
		}

	//�����ж�
		scanf_s("%d", &input);
		if (input==guess) {
			win++;
			puts("�ش���ȷ");
		}
		else {
			puts("�ش����");
		}


	} while (stage++<MAX_STAGE);
	endTime = clock();
	//ʱ��ͳ��
	usedTime = (double)(endTime - startTime / CLOCKS_PER_SEC);

	if (usedTime>12.5) {
		puts("��Ӧ̫��");
	}
	else if (usedTime > 10.0) {
		puts("��Ӧ�е���");
	}
	else if (usedTime > 8.5) {
		puts("��Ӧ����");
	}
	else {
		puts("��Ӧ���");
	}


	return 0;
}