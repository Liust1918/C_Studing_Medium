/*��������
1.���������4����ͬ������
2.�û�������"1234"������������
3.�û���������ո��ַ�
4.����������û����������У��ж��ٸ������������������������ж���λ����һ�µ�.
5.�����ظ�����
6.�ش���ȷ�󣬷������˶��ٴβ�,��ʱ���٣��Լ�����Ƿ�Ҫ����

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/*  ����4����ͬ���ֵ���ϲ��Ҵ�������x*/
void make4digits_1(int x[],int n) {
	srand((unsigned)time(NULL));
	int i,j;
	int val;
	for ( i = 0; i < n; i++){
		do {
			val = rand() % 10;
			for ( j = 0; j< i; j++){
				if (x[j]==val) {
					break;
				}
			}

		} while (j<i);
		x[i] = val;
	}
}

/*�����������ַ���s����Ч��*/
int check_1(const char s[],int n) {
	int i, j;
	int length;
	//�ַ���������4
	length = strlen(s);
	if (length>4) {
		return 1;
	}

	// �������˳�������������ַ�
	for (i = 0; i < length; i++){
		if (s[i]<'0'|| s[i]>'9') {
			return 2;
		}
		//�ַ������ظ�
		for (j = 0;  j< i; j++){
			if (s[i]==s[j]) {
				return 3;
			}
		}
	}

	return 0;
}

/*hit��blow���ж�*/
//hit  ����ֵ��λ��һ��
//blow ����ֵһ��,λ�ò�һ��
void judge_1(const char s[], const int n[], int* hit, int* blow, int n) {



}

/*��ʾ�жϽ��*/
void print_result(int snum, int spos) {

}

int main(void) {


	puts("������������");
	puts("�²�4������");
	puts("���в�������ͬ����");
	puts("����4307����������������");
	puts("��������ո��ַ�");


	return 0;
}