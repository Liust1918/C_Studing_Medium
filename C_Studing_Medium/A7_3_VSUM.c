/*用于访问可变参数的函数
(重点理解：参数的地址是连续的)
*/
#include <stdio.h>
typedef char* va_list; //?
#define va_start(ap,sw) (ap=(va_list)&sw + sizeof(va_list))
#define va_end(ap) ((va_list)0)
#define va_arg(ap,type) (*(type*)((ap += sizeof(type*)) - sizeof(type*))) //type是形式参数,只是占位符

double vsum(int sw, ...) {
	//sw后面入参的起始地址  用char*是因为char是1Byte
	double sum = 0.0;
	char* ap = (char*)&sw + sizeof(char*);

	switch (sw) {
	case 0: //int + int 
		/*
		方法一  
		sum += *(int*)ap;    //取值
		ap += sizeof(int*);  //指针移动
		sum += *(int*)ap;    //在取值
		*/
		/*
		简化方法一
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


	//防止空指针
	ap = (char*)0; 
	return sum;
}

int main(void) {

	printf("10+2                 =%.2lf \n", vsum(0, 10, 2));
	printf_s("57+300000L           =%.2f \n", vsum(1, 57, 300000L));
	printf_s("98+2L+3.14           =%.2f \n", vsum(2, 98, 2L,3.14));


	return 0;
}