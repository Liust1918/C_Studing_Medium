// �˸�� \b
// Ҫ��:1.ÿ��һ��,�Ӻ�����������ַ�
//      2. ����˳�����

//sleep ����
// clock_t clock(void)  ���ظý��̵��ô���������ʱ��
// ���� �ӳ���ʼ��,��������ʹ�õ�ʱ��ticksֵ ,ʧ���򷵻�-1 (clock_t����)
// ʹ����: ��clock��������ticksֵ���ٳ��� CLOCK_PER_SEC,�Ϳ��Ի�����к���,�ý���-��ʼ,���ʵ�ʵĳ���ʱ������ʱ��

//�����ַ�  printf_s("\b \b");   
// ����: "ABC"
//  1.����ȴ�  "ABC|"  ִ��\b,���"AB|C"
//  2.��ִ�пո�, ���"AB |";
//  3.��ִ��\b  ,�ͱ��"AB|"

#include <stdio.h>
#include <time.h>

/*��ͣn����   ������������Ÿý���,��ʵ����ͣ,ֱ������ʱ��,�ٷ���1,����м�ʧ��,�򷵻�0*/
int sleep(unsigned long sec) {
	clock_t start = clock();
	clock_t end;
	do {
		if ((end=clock())==(clock_t)-1) {
			return 0;//���ش���
		}
	} while ((1000.0*(end-start)/CLOCKS_PER_SEC)<=sec);

	return 1;
}

int main_3(void) {
	printf_s("ABCDERF");
	for (int i = 0; i < 7; i++){
		sleep(1 * 1000.0);
		printf_s("\b \b");
	}
	return 0;
}