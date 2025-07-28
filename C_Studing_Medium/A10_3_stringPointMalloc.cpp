/*Ϊ�ַ���ָ��(char**)��̬����ռ�*/
/*
1.��ʾ�м����ַ���
2.��0��ʼÿ������
3.���ȫ����ʾ
*/
/*
char**==char[n][m]
1.��calloc����(char**)alloc
2.��ÿ��char*��mallco(strlen+1)����

Ϊʲô�� char** ������ char p[n][m]
��Ϊ��

char p[n][m] �ǹ̶����ȶ�ά���飬�ڴ���ջ�Ϸ��䣬��������ʱ�������

char** �Ƕ�̬��������飬�����䣬�ʺϴ���ȷ������/���ȵ��ַ�����


ע��ָ��һ��Ҫfree,��������ָ��=NULL
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	int n;
	int i;
	puts("Ҫ���ü����ַ���");
	scanf_s("%d", &n);
	char** p;
	
	p = (char**)calloc(n, sizeof(char*));
	if (p==NULL) {
		printf_s("�ڴ����ʧ��");
		return 1;
	}

	//��ʼ��ָ��
	for ( i = 0; i < n; i++){
		*(p + i) = NULL;
	}
	//��������
	for (i = 0; i < n; i++){
		char temp[64];
		printf_s("p[%d]==", i); scanf_s("%s", temp, 64);
		*(p + i) =(char*) malloc(strlen(temp) + 1);
		if (*(p+i)!=NULL) {
			strcpy(*(p + i), temp);
		}
		else {
			for (int j = 0; j < n; j++){
				free(*(p + j));
			}
			free(p);
			return 1;
		}

	}

	for ( i = 0; i < n; i++){
		printf_s("p[%d]==%s \n", i, *(p + i));
	}

	for (i = 0; i < n; i++) {
		free(*(p + i));
	}
	free(p);


	return 0;
}