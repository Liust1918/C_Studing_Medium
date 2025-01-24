/*��������
1.���������4����ͬ������
2.�û�������"1234"������������
3.�û���������ո��ַ�
4.����������û����������У��ж��ٸ������������������������ж���λ����һ�µ�.
5.�����ظ�����
6.�ش���ȷ�󣬷������˶��ٴβ�,��ʱ���٣��Լ�����Ƿ�Ҫ����

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



/*  ����4����ͬ���ֵ���ϲ��Ҵ�������x*/
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

/*�����������ַ���s����Ч��*/
int check_1(const char s[]) {
	int i, j;
	int length;
	//�ַ���������4
	length = strlen(s);
	if (length>4) {
		return 1;
	}

	// �������˳�������������ַ�
	for (i = 0; i < length; i++){
		if (s[i]<'0'|| s[i]>'9') {
			return 2;
		}
		//�ַ������ظ�
		for (j = 0;  j< i; j++){
			if (s[i]==s[j]) {
				return 3;
			}
		}
	}

	return 0;
}

/*hit��blow���ж�*/
//hit  ����ֵ��λ��һ��
//blow ����ֵһ��,λ�ò�һ��
void judge_1(const char s[], const int n[], int* hit, int* blow,int len) {
	for (int i=0; i < len; i++) {
		for (int j = 0; j < len; j++){
			//�ַ����ֺ����ֽ��бȽ�: �����ַ�-'0'==����
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

/*��ʾ�жϽ��
snum��������ͬ
spos�����ֺ�λ����ͬ
*/
void print_result(int snum, int spos) {
	if (spos ==4) {
		puts("�ش���ȷ");
	}
	else if (snum==0) {
		puts("��Щ��������û�д�����");
	}
	else {
		printf_s("��Щ�����������%d�������� \n",snum);
		if (spos==0) {
			puts("�������ֵ�λ�ö���һ��");
		}
		else {
			printf_s("������%d�����ֵ�λ����һ�µ� \n", spos);
		}
	}

	
	//����n��
	//��ʱ ������
	//�밴���������...
	//����
}

int main(void) {

	int try_no=0;//�������
	int ckk_code;//�Ѿ�������ַ����ļ����
	int hit=0;//���ֺ�λ�ö���ȷ�����ָ���
	int blow=0;//������ȷ����λ�ò���ȷ�����ָ���
	int n[4];//Ҫ�µ�����
	char result[10];//���������
	clock_t start, end;//��ʼʱ�䣬����ʱ��	

	puts("������������");
	puts("�²�4������");
	puts("���в�������ͬ����");
	puts("����4307����������������");
	puts("��������ո��ַ�");
	
	make4digits_1(n, 4);
	start = clock();
	do{
		puts("������4������");
		scanf_s("%s", &result);
		check_1(result);
		judge_1(result, n, &hit, &blow, 4);
		print_result(hit + blow, hit); //hit ���ֺ�λ��һ��  blow ����һ��λ�ò�һ��
		try_no++;
	} while (hit!=4);
	end = clock();
	printf_s("����%d��,��ʱ%.lf �� \n",try_no,(double)(end-start)/CLOCKS_PER_SEC );
	

	return 0;
}