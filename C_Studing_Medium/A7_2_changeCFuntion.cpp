/*�ı��׼C������Ϊ*/
/*
�ı�ԭ��C��׼����putchar�������
*/

/*
undefine

#undef C���Ա�׼�⺯��
�޸ĺ���
#define C���Ա�׼�⺯��  �޸ĺ���

����:  
#undef putchar
int __putchar(int ch){}
#define putchar __putchar

*/

/*
����ͷ�ļ� xxx.h
����ͷ�ļ� #include "xxx.h"

���ܴ���ͷ�ļ��к���/���ظ�����
���������������һ�������ͷ�ļ���
#ifndef ����(��д)
#define ����(��д)
.....

#endif

���ã����û�ж���ú꣬����������������������ݣ�
     ����Ѿ�������ú꣬�������������ݣ������ظ����롣
*/

//#include <stdio.h>
//#undef putchar
//int __putchar(int ch) {
//    putchar('#');
//  return  putchar(ch);
//}
//#define putchar __putchar

#include "test.h"
#include "test.h"

int main_7_2(void) {
    putchar('5');
    return 0;
}

