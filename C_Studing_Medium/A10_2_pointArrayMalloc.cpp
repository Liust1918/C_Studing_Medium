/*Ϊ�ַ�����̬����ռ�*/
/*
function 1.�������ַ���str,����һ��������������ʾԭ���͸�������Ļ
function 2.�������뼸���ַ�����Ȼ���0��ʼһ��һ���ַ�������,���ȫ����ʾ
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
(char*)malloc(�ַ�����+1) //+1�ǽ�������'\0'
�ڴ������꣬Ҫ�ͷ� free(ָ��)

int arr[a][15] ���Ǵ����,�����Сֻ�����óɳ���,�������óɱ���
*/

void function1() {
	char str[16];
	char* pt;
	puts("����������");
	scanf_s("%15s", str, (unsigned)_countof(str));

	pt = (char*)malloc(strlen(str) + 1);
	if (pt) {
		
		strcpy(pt, str);
		
		printf_s("ԭ��:%s\n", str);
		printf_s("������%s\n", pt);
		free(pt);
	}
	else {
		printf_s("�ڴ����ʧ�� \n");
	}

}

/*
����	������ʽ	����	����
ָ������	type* arr[N];	һ�����飬Ԫ����ָ��	char* arr[3];
arr ���Щ��� "apple"
	 ������ "banana"
	 ������ "cherry"

����ָ��	type (*p)[N];	һ��ָ�룬ָ������	int (*p)[5];
arr: [1, 2, 3, 4, 5]
 p ������ &arr
	 ��������>  ��������

*/
/*
char (*p)[15];
��˼�ǣ�
 p ��һ��ָ�룬ָ��һ������Ϊ 15 �� char ���顣
Ҳ�������Ϊ��
*p ��һ�� char[15]

p[i] �ǵ� i �� char[15]������ i ���ַ�����

*/
void funtion2() {
	int n=0;
	char (*p)[15];//��ֵָ��,������ָ��,������p->char[15],�൱��p[n][15]
	int i;
	puts("���ü����ַ�����");
	scanf_s("%d", &n);
	p =(char(*)[15]) malloc(n * sizeof(*p));//�ص�,����char*[15],��Ϊ[]���ȼ��ܸ�,����ָ������
	if (p==NULL) {
		puts("�ڴ����ʧ��");
		return;
	}
	for ( i = 0; i < n; i++){
		printf_s("p[%d]=", i);
		scanf_s("%15s", *(p + i), (unsigned)_countof(*p));
		putchar('\n');
	}
	for ( i = 0; i < n; i++){
		printf_s("p[%d]=%s \n", i,*(p+i));
	}

	free(p);
}

int main_10_2(void) {
	
	function1();
	funtion2();

	return 0;
}