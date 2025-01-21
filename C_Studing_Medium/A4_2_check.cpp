/*检查已输入的字符串s的有效性

1.字符串长度不为4          return 1
2.包含了除了数字以外的字符 return 2
3.含有相同数字             return 3
4.字符串有效               return 0

学习
1.数字字符转字符的int值  ==目标值-'0';
2.排除数字以外的字符  目标值>'9'||目标值<'0'
3.字符串输入

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
	case 1:puts("字符串长度不为4  "); break;
	case 2:puts("包含了除了数字以外的字符"); break;
	case 3:puts("含有相同数字"); break;
	case 0:printf_s("%s", ch);break;
	}

	return 0;
}
