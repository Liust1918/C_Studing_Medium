/*�����в����Զ�����ͼ��*/
/*
1.��������������  xx.exe -t2 a.txt ,����a.txt���������������
2.��a\tb\tc��\tĬ�Ͽ�����ĳ�2���.(a____b____c=>a__b__c)

*/

/*
'\t'�Ʊ��(�൱�ڼ��� Tab ��)

*/
#define _CRT_SECURE_NO_WARNINGS //fopen��vs����ᾯ��
#include <stdio.h>
#include <stdlib.h>

void copy(FILE* src, FILE* dest, int width) {
	int ch, pos = 1;//pos����1��ʼ
	while ((ch = fgetc(src) )!= EOF) {
		int num;/*�ո������*/
		switch (ch) {
		case '\t':
			num = width - (pos - 1) % width;//�ص㣬
			/*
			1.��ǰ�ַ�λ�ڵ� pos �С�
            2.һ�� tab ��Ҫ���� ��һ�� width ������λ�á�
            �����������ǰ pos = 5��width = 4����һ�� tab ͣ������ 8��
            ������Ҫ�� 3 ���ո�8 - 5 = 3
			*/
			for (; num > 0; num--) {
				fputc(' ', dest);
				pos++;
			}
			
			break;
		case '\n':
			fputc(ch, dest);
			pos = 1;
			break;
		default:
			fputc(ch, dest);
			pos++;
			break;
		}
		
	}

}

int main_9_3(int argc,char* argv[]) {
	FILE* fp;
	int width = 8;
	if (argc<2) {
		copy(stdin, stdout,width);
	}
	else {

		while (--argc>0) {
			// �õ�"-t2"�ַ���
			//1.++argv==ָ���Ƶ��ڶ����ַ���
			//2.*++argv==�����ã���õڶ����ַ���("-t2"���׵�ַ,str[])
			//3.**++argv==�����ã���õڶ����ַ����еĵ�һ���ַ�('-',str[][0])
			if (**++argv=='-') {
				//1.*argv==�����ã���õڶ����ַ���("-t2"���׵�ַ,str[])
				//2.++(*argv)==,ָ��ǰ��,��û�õڶ����ַ����еĵڶ����ַ�('t',str[][1])
				if ((*++(*argv))=='t') {
					width = atoi(++(*argv));//���治֪���ж��ٸ��ַ���ʹ��atoiֱ�Ӷ�תstring->int
					//ֱ���û�û�õڶ����ַ����еĵ������ַ��ĵ�ַ(Ҳ�����׵�ַ)
				}
				else {
					fputs("��������ȷ\n", stderr);
					return 1;
				}
			}
			else if ((fp = fopen(*argv, "r")) == NULL) {
					fprintf(stderr, "�ļ�%s�޷���ȷ�� \n", *argv);
					return 1;
				}
				else {
					copy(fp, stdout, width);
					fclose(fp);
				}
			}

			
		
	}

	return 0;
}

/*

E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe a.txt
a               b               c
d               e               f
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe -t4 a.txt
a       b       c
d       e       f
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe -t2 a.txt
a   b   c
d   e   f
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe -t0 a.txt
a
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe -t1 a.txt
a  b  c
d  e  f
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>C_Studing_Medium.exe -t12 a.txt
a                       b                       c
d                       e                       f
E:\MyIDE\myRepository\Liust1918\C_Studing_Medium\x64\Debug>

*/
