/*�ļ��ĸ���*/
#define _CRT_SECURE_NO_WARNINGS

/*
ÿ��ʹ�ö�Ҫ�����±���
1.��������������  xx.exe���������������ʾ����Ļ����
2.�������������룬xx.exe �ļ���1 �ļ���2... ���ļ����ݶ���ʾ����Ļ����
3.�������������룬xx.exe �ļ���1>�ļ���2,���ļ���1�����ݸ��Ƶ��ļ���2
*/

/*
�� <stdio.h> �У�ϵͳ�Ѿ�Ϊ�㶨�����������׼�ļ�ָ�룺
extern FILE *stdin;   // ��׼���루ͨ���Ǽ��̣�
extern FILE *stdout;  // ��׼�����ͨ������Ļ��
extern FILE *stderr;  // ��׼���������ͨ������Ļ��

����������ʾ����ΪʲôҪ��fprintf(stderr,"�������",...);
fprintf(stderr,"�ļ�%s�޷���", *argv);
�����ʧ�ܣ�ʹ�� ��׼������� stderr ��ʾ������Ϣ����ֹ������Ϣ�������ļ������С�
�����ʹ��stderr,��ʹ��stdout,��Ѵ�������Ҳ�ܸ��ǵ�����һ���ļ�.

*/

#include <stdio.h>

void copy(FILE* src, FILE* dest) {
	int ch;
	//��׼������
	while ((ch = fgetc(src)) != EOF) {
		//��׼�����
		fputc(ch, dest);
	}
}

//��һ���ַ�����.exe�ļ����� 
int main_9_2(int argc,char* argv[]) {

	FILE* fp;
	//���argvֻ��һ������(.exe�ļ���),�Ͳ������ļ�
	if (argc<2) {
		copy(stdin, stdout);//��Ļ��������
		return 0;
	}
	//���argv�ж������
	while(--argc>0){
		//*++argv �ڶ����ļ������ַ���
		if ((fp = fopen(*++argv, "r")) == NULL) {
			//ǰ��argv�Ѿ�++������ֱ�ӽ�����
			fprintf(stderr,"�ļ�%s�޷���", *argv);
			//�����ʧ�ܣ�ʹ�� ��׼������� stderr ��ʾ������Ϣ����ֹ������Ϣ�������ļ������С�
			//�����ʹ��stderr,��ʹ��stdout,��Ѵ�������Ҳ�ܸ��ǵ�����һ���ļ�.
		}
		else {
			copy(fp, stdout);//a.txt>b.txt
			fclose(fp);
		}
		puts("");
	}
	
		
	

	return 0;
}