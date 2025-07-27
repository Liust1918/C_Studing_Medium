/* 三字母联想训练    */

/*
请输入连续的3个数字或英文字母中被隐去的字符.
例如：显示A?C:就请输入B
     显示45?:就请输入6
按下空格键开始.
*/

/*
#include <conio.h> 非C语言标准库。
int _getch()
char ch = _getch();
功能:
1.从键盘读取一个字符,不用进入缓冲区
2.不等待回车
3.不在控制台上回显输入字符（你按下去它就返回，但不会在屏幕上显示）
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


#define MAX_STAGE 5
void printInstruction() {
    puts("请输入连续的3个数字或英文字母中被隐去的字符.");
    puts("例如：显示A?C:就请输入B");
    puts("显示45?:就请输入6");
    puts("按下空格键开始.");
    while (_getch()!=' ') {
        ;
    } 

}

int main_7_4(void) {
    //计时
    //挑战次数
    //保存1-9 A-Z a-z
    //保存生成的随机字符串(连续的3个数字或英文字母)
    //随机
    //随机是数字，大写字母，还是小写字母
    //随机3个,最后两个不能取
    //随机从3个字符中屏蔽一个，填入字符？
    //用户输入完，不用回车(isprint判断输入字符)
    //统计正确次数
    printInstruction();

    clock_t startTime, endTime;
    int stage;
    char* str[3] = { (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ",(char*)"123456789",(char*)"abcdefghijklmnopqrstuvwxyz" };

    int startIndex = 0;
    int hideIndex = 0;
    srand((unsigned)time(NULL));
    int x;
    int i;
    int key;
    int win = 0;

    startTime = clock();
    for ( stage = 0; stage < MAX_STAGE; stage++){
        x = rand() % 3;//选择0 1 2 数字 大写字母 小写字母
        startIndex = rand()%(strlen(str[x])-2); //选择里面0-(len-2)随机一个开始
        hideIndex = rand() % 3;
        for ( i = 0; i < 3; i++){ //显示3个字符
            if (i==hideIndex) {
                putchar('?');
            }
            else {
                putchar(str[x][startIndex + i]);
            }
        }
        printf_s("==");
        do{
            key = _getch();
            if (isprint(key)) {
                putchar(key);
                putchar('\b');//返回     
               
            }
        } while (key != (str[x][startIndex + hideIndex]));
        win++;

        putchar('\n');
    }
    endTime = clock();

    printf_s("用时%.2lf 回答正确=%d", (double)(endTime - startTime) / CLOCKS_PER_SEC, win);

    return 0;
}