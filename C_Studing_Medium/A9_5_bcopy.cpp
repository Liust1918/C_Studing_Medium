/*bcopy:�ļ��ķֿ鸴�� */
/*
1.���������У���a.txt�ļ�������(�ֿ鸴��)�������ļ���
����:��������������xx.exe a.txt b.txt
    ��ȡ16���ַ� д��16���ַ�
    ��ȡ13���ַ� д��13���ַ�
*/

/*
1.�������ָ��,FILE* src, *dest; �������Ҳ��*
2.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BSIZE 16 //ÿ���ȡ/д��16���ַ�

int main_9_5(int argc, char* argv[]) {


    FILE* src, * dest;
    unsigned char buf[BSIZE];//һ�黺����
    int n;//ÿ�ζ�ȡ�ɹ����ַ�����

    if (argc!= 3) {
        fprintf(stderr, "��������ȷ\n");
        return 1;
    }
    if ((src = fopen(*++argv, "rb")) == NULL) {
        fprintf(stderr, "�ļ�%s�޷�������\n", *argv);
        return 1;
    }
    if ((dest = fopen(*++argv, "wb")) == NULL) {
        fprintf(stderr, "�ļ�%s�޷�������\n", *argv);
        fclose(src);
        return 1;
    }
    while ((n = fread(buf, sizeof(char), BSIZE, src))>0){
        fprintf(stderr, "��ȡ��%d���ַ� ", n);
        n=fwrite(buf, sizeof(char), n, dest);
        fprintf(stderr, "д����%d���ַ� \n", n);
    }


    fclose(dest);
    fclose(src);
    

	return 0;
}