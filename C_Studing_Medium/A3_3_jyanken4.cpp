/*��ȭ��Ϸ ������(�ָ��/��ʾ�ɼ�)*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int human;
int computer;
int win_no;
int lost_no;
int draw_no;
char* ch[] = {(char*)"ʯͷ", (char*)"����",(char*)"��"};

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
	
	printf_s("��ĳɼ�Ϊ==\n ʤ��:%d \n ʧ��:%d \n ƽ��:%d \n", win_no, lost_no, draw_no);

	return 0;
}

//��ʼ��
void initilize() {
	human = 0;
	computer = 0;
	win_no = 0;
	lost_no = 0;
	draw_no = 0;
}

//˫����ȭ
void play() {
	computer = rand() % 3;
	do{
		printf_s("[0]:%s [1]:%s [2]:%s \n", ch[0], ch[1], ch[2]);
		scanf_s("%d", &human);
	} while (human<0&&human>=3);
}

//��ӡ���ֽ��
void printResult(int judge) {
	printf_s("������� %s, ���Գ�%s \n", ch[human],ch[computer]);
	switch (judge){
	case 0: printf_s("����ƽ�� \n");  break;
	case 1: printf_s("����ʤ�� \n");  break;
	case 2: printf_s("����ʧ�� \n");  break;
	default:
		break;
	}

}

//�������
void countNo(int judge) {
	switch (judge) {
	case 0:  draw_no++; break;
	case 1:  win_no++; break;
	case 2:  lost_no++; break;
	default:
		break;
	}
}

//�Ƿ����
int isRetry() {
	puts("�Ƿ���� [0]���� [1]������");
	int input;
	scanf_s("%d", &input);
    return input==0?0:1;
	
}