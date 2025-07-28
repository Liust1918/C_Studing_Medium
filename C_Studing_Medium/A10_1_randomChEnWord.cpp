/*Ӣ�ﵥ��ѧϰ���*/
/*
1.ѭ������(�Ƿ�����һ��)
2.��������ͬһ������
3.�����ģ��ش�Ӣ�ģ���Ӣ�ģ��ش��У�ѡ����4��,ѡ��ظ�
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_WORDS 12
#define SELECT_MAX_NUM 4


char* chinese_words[] = {
        (char*)"ƻ��", (char*)"����", (char*)"��ʦ", (char*)"ѧ��",
        (char*)"ѧУ", (char*)"����", (char*)"�绰", (char*)"����",
        (char*)"����", (char*)"����", (char*)"����", (char*)"����"
};
char* english_words[] = {
        (char*)"apple", (char*)"computer", (char*)"teacher", (char*)"student",
        (char*)"school", (char*)"weather", (char*)"phone", (char*)"music",
        (char*)"happy", (char*)"table", (char*)"chair", (char*)"chinese"
};

//����ѡ�������ȷ�𰸵��±�,nΪ��ȷ�𰸵��±�,c�����±�
int make_cand(int c[], int n) {
    int i,j;
    int x;
    c[0] = n;
    for ( i = 1; i < SELECT_MAX_NUM; i++){
        do{
            x = rand() % MAX_WORDS;
            for ( j = 0; j < i; j++){
                if (c[j]==x) {
                    break;
                }
            }
        } while (j!=i);
        c[i] = x;
    }
    int z = rand() % SELECT_MAX_NUM;
    if (z!=0) {
        int temp = c[0];
        c[0] = c[z];
        c[z] = temp;
    }
    return z;
}

//��ӡѡ��
void print_cand(const int c[], int c_or_e) {
    int i;
    for ( i = 0; i < SELECT_MAX_NUM; i++) {
        printf_s("[%d].%s ", i, c_or_e ? english_words[c[i]] : chinese_words[c[i]]);
    }
    putchar('\n'); 
}

int main_10_1(void) {
    srand((unsigned)time(NULL));
    int entry;
    int currentKey= rand() % MAX_WORDS, preKey;//ǰ��һ���±꣬����һ���±겻����ͬ
    int c_or_e;//0==���ģ�1==Ӣ��
    int c[SELECT_MAX_NUM];//ѡ����±�
    int c_answer;
    int input;

    do{
        c_or_e = rand() % 2;
        do{
            preKey = rand() % MAX_WORDS;
        } while (currentKey==preKey);
        currentKey = preKey;
        printf_s("%s \n", c_or_e ? chinese_words[currentKey] : english_words[currentKey]);
        c_answer=make_cand(c, currentKey);
        print_cand(c, c_or_e);
        do{
            scanf_s("%d", &input);
            if (c_answer != input) {
                puts("�ش����");
            }
            else {
                puts("��ȷ");
            }
        } while (c_answer != input);


        printf_s("�Ƿ�����һ�Σ� ����==0������==1 \n");
        scanf_s("%d", &entry);
    } while (entry==0);


    return 0;
}