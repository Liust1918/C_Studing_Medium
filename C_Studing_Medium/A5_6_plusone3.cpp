/*�����MAX�����������СΪMAX��������*/
//1.ֻ������MAX��Ԫ��
//2.��������������Ԫ��,ֻ������������MAX��Ԫ��
// ���� ���� 1 2 3 4 5   => 6 1 2 3 4
//     ���  1 2 3 4 5  => 1 2 3 4 6

#include <stdio.h>

#define MAX 5  //���鳤��

int main_5_6(void) {
	int retry = 0;
	int countInput = 0; //�������
	int a[MAX] = { 0 }; //�洢����
	int i;

	puts("����������������鵱��");

	do{

		printf_s("�����%d������== \n", countInput+1);
		scanf_s("%d", &a[countInput >= MAX ? countInput++ % MAX : countInput++]);

		puts("���Ƿ����  ��==0 ��==1 ");
		scanf_s("%d", &retry);
	} while (retry==0);

	i = countInput - MAX;
	if (i<0) {
		i = 0;
	}
	for (;  i< countInput; i++){
		printf_s("a[%d]==%d \n", i+1, a[i % MAX]);
	}

	return 0;
}