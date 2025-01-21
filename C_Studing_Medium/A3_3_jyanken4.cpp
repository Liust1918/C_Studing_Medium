/*猜拳游戏 函数版(分割函数/显示成绩)*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int human;
int computer;
int win_no;
int lost_no;
int draw_no;
char* ch[] = {(char*)"石头", (char*)"剪刀",(char*)"布"};

void initilize();
void play();
void printResult(int judge);
void countNo(int jugde);
int isRetry();

int main_12(void) {
	int retry, judge;
	initilize();
	srand((unsigned)time(NULL));
	do{
		play();
		judge = (computer - human + 3) % 3;
		printResult(judge);
		countNo(judge);

		retry = isRetry();
	} while (retry==0);
	
	printf_s("你的成绩为==\n 胜利:%d \n 失败:%d \n 平局:%d \n", win_no, lost_no, draw_no);

	return 0;
}

//初始化
void initilize() {
	human = 0;
	computer = 0;
	win_no = 0;
	lost_no = 0;
	draw_no = 0;
}

//双方出拳
void play() {
	computer = rand() % 3;
	do{
		printf_s("[0]:%s [1]:%s [2]:%s \n", ch[0], ch[1], ch[2]);
		scanf_s("%d", &human);
	} while (human<0&&human>=3);
}

//打印本轮结果
void printResult(int judge) {
	printf_s("本轮你出 %s, 电脑出%s \n", ch[human],ch[computer]);
	switch (judge){
	case 0: printf_s("本轮平局 \n");  break;
	case 1: printf_s("本轮胜利 \n");  break;
	case 2: printf_s("本轮失败 \n");  break;
	default:
		break;
	}

}

//结果计数
void countNo(int judge) {
	switch (judge) {
	case 0:  draw_no++; break;
	case 1:  win_no++; break;
	case 2:  lost_no++; break;
	default:
		break;
	}
}

//是否继续
int isRetry() {
	puts("是否继续 [0]继续 [1]不继续");
	int input;
	scanf_s("%d", &input);
    return input==0?0:1;
	
}