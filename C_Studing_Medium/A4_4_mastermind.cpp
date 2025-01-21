/*珠玑妙算
1.计算机生成4个不同的数字
2.用户输入如"1234"这样连续数字
3.用户不能输入空格字符
4.计算机返回用户输入数字中，有多少个数字与答案相符，在这其中又有多少位置是一致的.
5.可以重复输入
6.回答正确后，返回用了多少次猜,用时多少，以及最后是否要继续

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/*  生成4个不同数字的组合并且存入数组x*/
void make4digits_1(int x[],int n) {
	srand((unsigned)time(NULL));
	int i,j;
	int val;
	for ( i = 0; i < n; i++){
		do {
			val = rand() % 10;
			for ( j = 0; j< i; j++){
				if (x[j]==val) {
					break;
				}
			}

		} while (j<i);
		x[i] = val;
	}
}

/*检查已输入的字符串s的有效性*/
int check_1(const char s[],int n) {
	int i, j;
	int length;
	//字符串不超过4
	length = strlen(s);
	if (length>4) {
		return 1;
	}

	// 不包含了除了数字以外的字符
	for (i = 0; i < length; i++){
		if (s[i]<'0'|| s[i]>'9') {
			return 2;
		}
		//字符串不重复
		for (j = 0;  j< i; j++){
			if (s[i]==s[j]) {
				return 3;
			}
		}
	}

	return 0;
}

/*hit和blow的判断*/
//hit  是数值和位置一样
//blow 是数值一样,位置不一样
void judge_1(const char s[], const int n[], int* hit, int* blow, int n) {



}

/*显示判断结果*/
void print_result(int snum, int spos) {

}

int main(void) {


	puts("来玩珠玑妙算");
	puts("猜猜4个数字");
	puts("其中不包含相同数字");
	puts("请像4307这样连续输入数字");
	puts("不能输入空格字符");


	return 0;
}