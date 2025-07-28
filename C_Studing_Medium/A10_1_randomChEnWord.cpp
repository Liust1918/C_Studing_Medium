/*英语单词学习软件*/
/*
1.循环继续(是否再来一次)
2.不连续出同一个单词
3.出中文，回答英文，出英文，回答中，选项有4个,选项不重复
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_WORDS 12
#define SELECT_MAX_NUM 4


char* chinese_words[] = {
        (char*)"苹果", (char*)"电脑", (char*)"老师", (char*)"学生",
        (char*)"学校", (char*)"天气", (char*)"电话", (char*)"音乐",
        (char*)"快乐", (char*)"桌子", (char*)"椅子", (char*)"汉语"
};
char* english_words[] = {
        (char*)"apple", (char*)"computer", (char*)"teacher", (char*)"student",
        (char*)"school", (char*)"weather", (char*)"phone", (char*)"music",
        (char*)"happy", (char*)"table", (char*)"chair", (char*)"chinese"
};

//生成选项并返回正确答案的下标,n为正确答案的下标,c保存下标
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

//打印选项
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
    int currentKey= rand() % MAX_WORDS, preKey;//前面一个下标，后面一个下标不能相同
    int c_or_e;//0==中文，1==英语
    int c[SELECT_MAX_NUM];//选项的下标
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
                puts("回答错误");
            }
            else {
                puts("正确");
            }
        } while (c_answer != input);


        printf_s("是否再来一次？ 继续==0，结束==1 \n");
        scanf_s("%d", &entry);
    } while (entry==0);


    return 0;
}