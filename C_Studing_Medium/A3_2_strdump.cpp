/*��ʮ�����ƺͶ����ƴ�ӡ�ַ���*/

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
void strdumb(const char* str) {
	int i;
	while (*str) {
		//��ӡ�ַ�,�޷���ӡ�ʹ�ӡ*�ַ�
		unsigned char x = (unsigned char)*str;
		printf_s(" %c ", isprint(x) ? x : '*');
		//��ӡʮ������
		printf_s(" %0*X ", (CHAR_BIT + 3) / 4, x);
		putchar('|');
		//��ӡ������   char 1�ַ�=8λ  1U�Ͱ�λ����&����
		for (i = CHAR_BIT-1; i >= 0; i--) {
			printf_s("%c", ((x >> i) & 1U)?'1':'0');
		}
		putchar('\n');

		str++;
	}


}

int main_11(void) {

	puts("����");
	strdumb("����");

	putchar('\n');
	puts("12�й���AB");
	strdumb("12�й���AB");
	putchar('\n');

	return 0;
}