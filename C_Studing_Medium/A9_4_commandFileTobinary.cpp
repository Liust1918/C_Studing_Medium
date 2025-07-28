/*�ļ���ת��(������)*/
/*
1.��������������xx.exe  a.txt ,��a.txt�ڵ�16���Ƶ�ַ,ÿ���ַ���16������,�����������Ļ����

*/

/*
�����ݴ�ӡ����������Ļ,������fprintf()
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <climits>
#include <ctype.h>



void hdump(FILE* src, FILE* dest) {
	unsigned char buf[16];//�ַ�������
	unsigned long count=0; //�����ַ�������������ļ�����ڼ����ַ�
	int n;//����ɹ���ȡ����
	int i;
	while ((n=fread(buf,sizeof(char), 16, src))>0) {
		//1.��ӡ��ַcount
		fprintf(dest, "%08lX ", count);//lX==16����,8λ0����
		//2.��ӡÿ���ַ�����
		for ( i = 0; i < n; i++){
			fprintf(dest, "%0*X ",(CHAR_BIT+3)/4, buf[i]);			
		}
		//3.���ո�
		if (n<16) {
			for ( i = n; i < 16; i++){
				fprintf(dest, "%*s ", (CHAR_BIT + 3) / 4, "");
			}
		}
		//4.��ӡ����
		for ( i = 0; i < 16; i++){
			if (isprint(buf[i])) {
				fputc(buf[i], dest);
			}
			else {
				fputc('.', dest);
			}
		}

		fputc('\n',dest);
		count += 16;
	}

}

int main_9_4(int argc, char* argv[]) {

	FILE* fp;

		while (--argc>0) {
			if ((fp=fopen(*++argv,"rb")) == NULL) {
				fprintf(stderr, "�ļ�%s�޷���ȷ��\n", *argv);
				//�����ʹ��stderr,���еĴ�������Ҳ�ܸ��ǵ�����һ���ļ�.
			}
			else {
				hdump(fp, stdout);
				fclose(fp);
			}
			puts("");
		}
	


	return 0;
}