//<stdlib.h>
//int rand(void) ����0~RAND_MAX��intֵ    ��ȡ�����(α���)
//��ͬ������ RAND_MAX��ֵ��һ��
//void srand(unsigned seed); Ϊrand����һ������ ������д��rand����ǰ��

//������ʱ����Ϊ���� <time.h> time(NULL)   (��ʵ����α���)

//�����ж�
//����1: ����ֵ����Ŀ��������ʾ(��Ŀ��ֵ��)��С��Ŀ��ֵ����ʾ(��Ŀ��ֵС)
//����2: ���Բ�������ֵ
//����3  ���������Ŀ������
//����4: Ŀ��������0~9�������
//����5: ��������3������,������ʾ������n��,��¼������n�ε�ֵ,���ҽ�ֵ�������,ÿ������ֵ����Ŀ��ֵ����.������ʾ��ȷ��Ŀ��ֵ(ʹ�ö����)
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define inputNumber 3

//1.1�����ж�
int main_1(void) {

	srand((unsigned)time(NULL));
	int dest = rand() % 10;
	int inputValue;
	int remainTimes= inputNumber;
	int totalTimes = remainTimes;
	int input[inputNumber];

	do{
		
		puts("����Ƕ���? (0~9)");
		scanf_s("%d", &inputValue);
		input[totalTimes - remainTimes] = inputValue;
		remainTimes--;
		if (inputValue > dest) {
			puts("��ʵ�����ִ�");
		}
		else if (inputValue < dest) {
			puts("��ʵ������С");
		}
	} while ((inputValue != dest)&&(remainTimes>0));

	if (inputValue==dest) {
		printf_s("��ϲ��,�¶���,��һ������%d��. \n",totalTimes-remainTimes);
	}
	else {
		printf_s("��û�в¶�,����%d \n",dest);
	}
	for (int i = 0; i < totalTimes-remainTimes; i++){
		printf_s("��%4d��:%4d ��𰸲�%4d \n", i + 1, input[i], input[i] - dest);
	}


	return 0;
}