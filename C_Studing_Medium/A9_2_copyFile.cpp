/*�ļ��ĸ���*/

/*
1.�û��ύ���ļ�������ϣ�����ļ����������ȫ����ʾ����Ļ����

*/

#include <stdio.h>


int main(int argc,char* argv[]) {

	int ch;
	//��׼������
	while ((ch=fgetc(stdin))!=EOF) {
		//��׼�����
		fputc(ch, stdout);
	}

	return 0;
}