/*���ڷ��ʿɱ�����ĺ���
(�ص���⣺�����ĵ�ַ��������)
*/
#include <stdio.h>
typedef char* va_list; //?
#define va_start(ap,sw) (ap=(va_list)&sw + sizeof(va_list))
#define va_end(ap) ((va_list)0)
#define va_arg(ap,type) (*(type*)((ap += sizeof(type*)) - sizeof(type*))) //type����ʽ����,ֻ��ռλ��

double vsum(int sw, ...) {
	//sw������ε���ʼ��ַ  ��char*����Ϊchar��1Byte
	double sum = 0.0;
	char* ap = (char*)&sw + sizeof(char*);

	switch (sw) {
	case 0: //int + int 
		/*
		����һ  
		sum += *(int*)ap;    //ȡֵ
		ap += sizeof(int*);  //ָ���ƶ�
		sum += *(int*)ap;    //��ȡֵ
		*/
		/*
		�򻯷���һ
		*/
		sum += (*(int*)((ap += sizeof(int*)) - sizeof(int*)));
		sum += (*(int*)((ap += sizeof(int*)) - sizeof(int*)));
		
		break;
	case 1:
	/*	sum += *(int*)ap;
		ap += sizeof(int*);
		sum += *(long*)ap;*/
		sum += va_arg(ap, int);
		sum += va_arg(ap, long);
		break;
	case 2:
		/*sum += *(int*)ap;
		ap += sizeof(int*);
		sum += *(long*)ap;
		ap += sizeof(long*);
		sum += *(double*)ap;*/
		sum += va_arg(ap, int);
		sum += va_arg(ap, long);
		sum += va_arg(ap, double);
		break;
	}


	//��ֹ��ָ��
	ap = (char*)0; 
	return sum;
}

int main(void) {

	printf("10+2                 =%.2lf \n", vsum(0, 10, 2));
	printf_s("57+300000L           =%.2f \n", vsum(1, 57, 300000L));
	printf_s("98+2L+3.14           =%.2f \n", vsum(2, 98, 2L,3.14));


	return 0;
}