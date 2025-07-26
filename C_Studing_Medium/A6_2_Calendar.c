//��ӡ����

#include <stdio.h>
#include <time.h>

//�·�
int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };// 31 28   [31 30 31 30][31,31] [30,31,30,31]

//�Ƿ�������
int is_leap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//ͨ��������������
int dayOfweek(int year, int month, int day) {
	struct tm t = { 0 };
	t.tm_mday = day;
	t.tm_mon = month - 1;
	t.tm_year = year - 1900;
	if (mktime(&t)==-1) {
		return -1;
	}
	return t.tm_wday;
}

void put_calendar(int year, int month) {
	int i;
	//��������
	int mday= mon[month - 1];
	if (month ==2&&is_leap(year)) {
		mday++;
	}
	
	//���һ������
	int week=dayOfweek(year, month, 1);
	if (week == -1) {
		week = 0;  // Ĭ������
	}

	//��ʾ
	puts("�� һ �� �� �� �� ��");
	puts("������������������������������������");
	printf_s("%*s", 3 * week,"");
	for ( i = 0; i < mday; i++){
		printf_s("%2d ", i + 1);
		if ((++week % 7) == 0) {
			putchar('\n');
		}
	}
	if (week%7!=0) {
		putchar('\n');
	}

}

int main_6_2(void) {
	int year;
	int month;
	puts("��ʾ����");
	printf_s("������=="); scanf_s("%d", &year);
	printf_s("������=="); scanf_s("%d", &month);
	put_calendar(year,month);

	return 0;
}