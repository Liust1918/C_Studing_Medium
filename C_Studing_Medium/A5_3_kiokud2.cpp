//'a' - 'A' == 32
//����������� ASCII ����ʵ�ִ�Сдת����
//char lower = 'A' + 32;  // => 'a'
//char upper = 'z' - 32;  // => 'Z'

//5.3 �ַ�������ѵ��

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STAGE 5
#define MAX_LEVEL 30
#define MIN_LEVEL 3

int sleep_k2(unsigned long ms) {
	clock_t start = clock(), end;
	do{
		if((end=clock())==(clock_t)-1){
			return 0;
		}
	} while (1000.0*(end-start)/CLOCKS_PER_SEC < ms);
	return 1;
}

//һ����������char 'A'-'Z' 'a'-'z'
void getCharArray(char az[]) {
	int len = 26;
	int i;
	// 'A'-'Z'
	for (i = 0; i < len; i++){
		az[i] = 'A' + i;
	}
	//'a'-'z'
	for (i = 0; i < len; i++) {
		az[i+26] = 'a' + i;
	}
}

int main(void) {
	clock_t startTime, endTime;
	int winNum = 0;
	int stage = 0;
	int sLevel = 0;
	char az[32];
	srand((unsigned)time(NULL));
	do{
		printf("���� %d ~ %d LEVEL ѡ�� \n", MIN_LEVEL, MAX_LEVEL);
		scanf_s("%d", &sLevel);
	} while (sLevel>MAX_LEVEL||sLevel<MIN_LEVEL);

	getCharArray(az);

	do{
		//���
		


		//����


		//�ж�


	} while (++stage<MAX_STAGE);

}
