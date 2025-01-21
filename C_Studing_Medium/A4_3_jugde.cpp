/*对比数字并给出提示  
1.hit 数字的位置和值是一样的
2.blow 值一样，位置不一样
例如
1234
1023
hit:1
blow:2

学习:数字int转char值   char值='0'+数字
学习:指针和函数,通过指针传递变量,在函数内修改该变量

15
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void judge(const char s[], const int no[], int* hit, int* blow,int n) {
	int i, j;
	*hit = 0;
	*blow = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n;j++) {
			if (s[i]==no[j]+'0') {
				if (i==j) {
					(*hit)++;
				}else {
					(*blow)++;
				}
			}
		}
	}
}

int main_15(void) {
	int i;
	int computer[4] = { 1,2,3,4 };
	char human[20] = "1224";
	int bitNo = 0;
	int blowNo = 0;
	judge(human, computer, &bitNo, &blowNo,4);
	printf_s("bit==%d blow==%d \n", bitNo, blowNo);



	return 0;
}