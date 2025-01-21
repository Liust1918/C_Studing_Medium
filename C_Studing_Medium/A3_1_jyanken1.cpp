/*剪刀石头布*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main_10(void) {

	int human;
	int comp;
	int jugde;
	int retry;
	char* reply=NULL;
	char* huamn_reply=NULL;
	char* comp_reply=NULL;
	srand((unsigned)time(NULL));

	do{
		int comp = rand() % 3;
		do{
			puts("请出  石头【0】 剪刀[1]  布[2]");
			scanf_s("%d", &human);
		} while (human<0&&human>=3);

		jugde = (comp - human + 3) % 3;
		//石头 - 石头  0 - 0 =0  0
		//石头 - 剪刀  0 - 1 =-1 1
		//石头 - 布    0 - 2 =-2 -1
		//剪刀 - 石头  1 - 0 =1  -1
		//剪刀 - 剪刀  1 - 1 =0  0
		//剪刀 - 布    1 - 2 =-1 1
		//布 - 石头    1 - 0 = 1 1
 		//布 - 剪刀    1 - 2 =-1 -1
		//布 - 布      2 - 2 =0  0
		switch (jugde) {
		case 0:  reply =(char*) "平局";   break;
		case 1: reply = (char*)"胜利"; break;
		case 2: reply = (char*)"失败"; break;
		default: 
			break;
		}
		switch (human) {
		case 0:  huamn_reply = (char*)"石头";   break;
		case 1: huamn_reply = (char*)"剪刀"; break;
		case 2: huamn_reply = (char*)"布"; break;
		default:
			break;
		}
		switch (comp) {
		case 0:  comp_reply = (char*)"石头";   break;
		case 1: comp_reply = (char*)"剪刀"; break;
		case 2: comp_reply = (char*)"布"; break;
		default:
			break;
		}
		printf_s("你出了%s ,电脑出了%s \n",huamn_reply,comp_reply );
		printf_s("%s \n", reply);

		puts("是否进行进行 继续[0] 不继续[1]");
		scanf_s("%d", &retry);
	} while (retry==0);

	return 0;
}