/*һ���ַ����ļ��̴�����ϰ*/
/*
������Ϸ�����������ʼ.
����������
How do you do?
�����������˻س�,����ַ��ſ��Լ���
��ʾ��ʱ
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

int main_8_1(void) {

	clock_t startTime, endTime;
	char* str =(char*) "How do you do?";
	int len = strlen(str);
	int i;

	printf_s("%s\n", str);
	for ( i = 0; i < len; i++){
		char key;
		do {
			key = _getch();
			if (isprint(key)) {
				putchar(key);	
				if (key != str[i]) {
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
			}
			
		} while (key!=str[i]);
	}
	

	return 0;
}