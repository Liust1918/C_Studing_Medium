/*�Ա����ֲ�������ʾ  
1.hit ���ֵ�λ�ú�ֵ��һ����
2.blow ֵһ����λ�ò�һ��
����
1234
1023
hit:1
blow:2

ѧϰ:����intתcharֵ   charֵ='0'+����
ѧϰ:ָ��ͺ���,ͨ��ָ�봫�ݱ���,�ں������޸ĸñ���

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