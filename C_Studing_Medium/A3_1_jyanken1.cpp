/*����ʯͷ��*/

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
			puts("���  ʯͷ��0�� ����[1]  ��[2]");
			scanf_s("%d", &human);
		} while (human<0&&human>=3);

		jugde = (comp - human + 3) % 3;
		//ʯͷ - ʯͷ  0 - 0 =0  0
		//ʯͷ - ����  0 - 1 =-1 1
		//ʯͷ - ��    0 - 2 =-2 -1
		//���� - ʯͷ  1 - 0 =1  -1
		//���� - ����  1 - 1 =0  0
		//���� - ��    1 - 2 =-1 1
		//�� - ʯͷ    1 - 0 = 1 1
 		//�� - ����    1 - 2 =-1 -1
		//�� - ��      2 - 2 =0  0
		switch (jugde) {
		case 0:  reply =(char*) "ƽ��";   break;
		case 1: reply = (char*)"ʤ��"; break;
		case 2: reply = (char*)"ʧ��"; break;
		default: 
			break;
		}
		switch (human) {
		case 0:  huamn_reply = (char*)"ʯͷ";   break;
		case 1: huamn_reply = (char*)"����"; break;
		case 2: huamn_reply = (char*)"��"; break;
		default:
			break;
		}
		switch (comp) {
		case 0:  comp_reply = (char*)"ʯͷ";   break;
		case 1: comp_reply = (char*)"����"; break;
		case 2: comp_reply = (char*)"��"; break;
		default:
			break;
		}
		printf_s("�����%s ,���Գ���%s \n",huamn_reply,comp_reply );
		printf_s("%s \n", reply);

		puts("�Ƿ���н��� ����[0] ������[1]");
		scanf_s("%d", &retry);
	} while (retry==0);

	return 0;
}