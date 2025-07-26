/* ͨ�������� �������� ����һ:����mktime������ */
/*
����ԭ�ͣ�time_t mktime(struct tm* timeptr);
����:    ����struct tm�ṹ���е�tm_wday��tm_ydayԪ�ص�ֵ
         ����time�����ķ���ֵ. (��localtime�����෴)
����ֵ����ָ���ķֽ�ʱ��ת����time_t�͵�ֵ������.
       �޷�������ʱ���ʾʱ,��������-1

*/

/*

struct tm
{
    int tm_sec;   // seconds after the minute - [0, 60] including leap second
    int tm_min;   // minutes after the hour - [0, 59]
    int tm_hour;  // hours since midnight - [0, 23]
    int tm_mday;  // day of the month - [1, 31]
    int tm_mon;   // months since January - [0, 11]
    int tm_year;  // years since 1900
    int tm_wday;  // days since Sunday - [0, 6]
    int tm_yday;  // days since January 1 - [0, 365]
    int tm_isdst; // daylight savings time flag
};

*/

#include <stdio.h>
#include <time.h>

/*��year��month��day�������ڼ�*/
int dayofweek(int year, int month, int day) {
    struct tm t;
    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_mday = day;
    t.tm_mon = month-1;
    t.tm_year = year-1900;


    if (mktime(&t)==-1) {
        return -1;
    }

    return t.tm_wday;
}

/*
ͨ�������� �������ڡ�������(Zeller)��ʽ  �˽⼴��\

*/
int dayofweek_Zeller(int year, int month, int day) {
    if (month==1||month==2) {
        year--;
        month += 12;
    }

    return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}


int main_6_1(void) {
    int i;
    int year;
    int mon;
    int day;
    char* week[] = { "��","һ","��","��","��","��","��"};
    puts("������");
    printf_s("������=="); scanf_s("%d", &year);
    printf_s("\n�����·�=="); scanf_s("%d", &mon);
    printf_s("\n��������=="); scanf_s("%d", &day);
    i=dayofweek(year, mon, day);
    if (i==-1) {
        puts("���ʧ��");
    }
    else {
        printf_s("����%s", week[i]);
    }

    i = dayofweek_Zeller(year, mon, day);
    if (i == -1) {
        puts("���ʧ��");
    }
    else {
        printf_s("����%s", week[i]);
    }

    return 0;
}

