/* ����ĸ����ѵ��    */

/*
������������3�����ֻ�Ӣ����ĸ�б���ȥ���ַ�.
���磺��ʾA?C:��������B
     ��ʾ45?:��������6
���¿ո����ʼ.
*/

/*
#include <conio.h> ��C���Ա�׼�⡣
int _getch()
char ch = _getch();
����:
1.�Ӽ��̶�ȡһ���ַ�,���ý��뻺����
2.���ȴ��س�
3.���ڿ���̨�ϻ��������ַ����㰴��ȥ���ͷ��أ�����������Ļ����ʾ��
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


#define MAX_STAGE 5
void printInstruction() {
    puts("������������3�����ֻ�Ӣ����ĸ�б���ȥ���ַ�.");
    puts("���磺��ʾA?C:��������B");
    puts("��ʾ45?:��������6");
    puts("���¿ո����ʼ.");
    while (_getch()!=' ') {
        ;
    } 

}

int main_7_4(void) {
    //��ʱ
    //��ս����
    //����1-9 A-Z a-z
    //�������ɵ�����ַ���(������3�����ֻ�Ӣ����ĸ)
    //���
    //��������֣���д��ĸ������Сд��ĸ
    //���3��,�����������ȡ
    //�����3���ַ�������һ���������ַ���
    //�û������꣬���ûس�(isprint�ж������ַ�)
    //ͳ����ȷ����
    printInstruction();

    clock_t startTime, endTime;
    int stage;
    char* str[3] = { (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ",(char*)"123456789",(char*)"abcdefghijklmnopqrstuvwxyz" };

    int startIndex = 0;
    int hideIndex = 0;
    srand((unsigned)time(NULL));
    int x;
    int i;
    int key;
    int win = 0;

    startTime = clock();
    for ( stage = 0; stage < MAX_STAGE; stage++){
        x = rand() % 3;//ѡ��0 1 2 ���� ��д��ĸ Сд��ĸ
        startIndex = rand()%(strlen(str[x])-2); //ѡ������0-(len-2)���һ����ʼ
        hideIndex = rand() % 3;
        for ( i = 0; i < 3; i++){ //��ʾ3���ַ�
            if (i==hideIndex) {
                putchar('?');
            }
            else {
                putchar(str[x][startIndex + i]);
            }
        }
        printf_s("==");
        do{
            key = _getch();
            if (isprint(key)) {
                putchar(key);
                putchar('\b');//����     
               
            }
        } while (key != (str[x][startIndex + hideIndex]));
        win++;

        putchar('\n');
    }
    endTime = clock();

    printf_s("��ʱ%.2lf �ش���ȷ=%d", (double)(endTime - startTime) / CLOCKS_PER_SEC, win);

    return 0;
}