/*����4����ͬ���ֵ���ϲ���������x*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void make4digits(int x[]) {
	int len = 4;
	int i;
	int j;
	int val;
	srand((unsigned)time(NULL));
	for (i = 0; i < len; i++){
		do{
			val = rand() % 10;
			for ( j = 0; j < i; j++){
				if (val==x[j]) {
					break; //�������������������ڵ��� �ظ����˳�for,���������һ��
				}
			}
		} while (j<i);//���for�е�j<i�������㣬������while
		x[i] = val;//ѡ������valֱ�Ӵ���
	}


}

int main_13(void) {
	int ch[4];
	make4digits(ch);
	for (int i = 0; i < 4; i++){
		printf_s("[%d]==%d \n", i, ch[i]);
	}

	return 0;
}