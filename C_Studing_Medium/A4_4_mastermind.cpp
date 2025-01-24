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
int check_1(const char s[]) {
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
void judge_1(const char s[], const int n[], int* hit, int* blow,int len) {
	for (int i=0; i < len; i++) {
		for (int j = 0; j < len; j++){
			//字符数字和数字进行比较: 数字字符-'0'==数字
			if (s[i]-'0' == n[j]) {
				if (i==j) {
					(*hit)++;
				}
				else {
					(*blow)++;
				}
			}
		}
	}


}

/*显示判断结果
snum是数字相同
spos是数字和位置相同
*/
void print_result(int snum, int spos) {
	if (spos ==4) {
		puts("回答正确");
	}
	else if (snum==0) {
		puts("这些数字里面没有答案数字");
	}
	else {
		printf_s("这些数字里面包括%d个答案数字 \n",snum);
		if (spos==0) {
			puts("但是数字的位置都不一致");
		}
		else {
			printf_s("其中有%d个数字的位置是一致的 \n", spos);
		}
	}

	
	//用了n秒
	//用时 多少秒
	//请按任意键继续...
	//测试
}

int main(void) {

	int try_no=0;//输入次数
	int ckk_code;//已经输入的字符串的检查结果
	int hit=0;//数字和位置都正确的数字个数
	int blow=0;//数字正确但是位置不正确的数字个数
	int n[4];//要猜的数字
	char result[10];//输入的数字
	clock_t start, end;//开始时间，结束时间	

	puts("来玩珠玑妙算");
	puts("猜猜4个数字");
	puts("其中不包含相同数字");
	puts("请像4307这样连续输入数字");
	puts("不能输入空格字符");
	
	make4digits_1(n, 4);
	start = clock();
	do{
		puts("请输入4个数字");
		scanf_s("%s", &result);
		check_1(result);
		judge_1(result, n, &hit, &blow, 4);
		print_result(hit + blow, hit); //hit 数字和位置一样  blow 数字一样位置不一样
		try_no++;
	} while (hit!=4);
	end = clock();
	printf_s("用了%d次,用时%.lf 秒 \n",try_no,(double)(end-start)/CLOCKS_PER_SEC );
	

	return 0;
}