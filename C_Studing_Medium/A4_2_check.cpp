/*�����������ַ���s����Ч��

1.�ַ������Ȳ�Ϊ4          return 1
2.�����˳�������������ַ� return 2
3.������ͬ����             return 3
4.�ַ�����Ч               return 0

ѧϰ
1.�����ַ�ת�ַ���intֵ  ==Ŀ��ֵ-'0';
2.�ų�����������ַ�  Ŀ��ֵ>'9'||Ŀ��ֵ<'0'
3.�ַ�������

*/
//14
#define _CRT_SECURE_NO_WARNINGS -1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int check(const char s[]) {
	int i;
	int j;
	int len = (int)strlen(s);
	if (len > 4) {
		return 1;
	}

	for (i = 0; i < len; i++) {
		if (s[i] > '9' || s[i] < '0') {
			return 2;
		}
		for (j = 0; j < i; j++) {
			if (s[i] == s[j]) {
				return 3;
			}
		}
	}

	return 0;
}


void copyStrToNum(int dest[], const char source[], int n) {
	for (int i = 0; i < n; i++) {
		dest[i] = source[i] - '0';
	}
}

int main_14(void) {
	char ch[100];
	scanf("%s", ch);

	int res = check(ch);
	switch (res) {
	case 1:puts("�ַ������Ȳ�Ϊ4  "); break;
	case 2:puts("�����˳�������������ַ�"); break;
	case 3:puts("������ͬ����"); break;
	case 0:printf_s("%s", ch);break;
	}

	return 0;
}
