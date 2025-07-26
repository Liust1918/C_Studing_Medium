/* 通过年月日 ，求星期 （其一:利用mktime函数） */
/*
函数原型：time_t mktime(struct tm* timeptr);
功能:    忽略struct tm结构体中的tm_wday和tm_yday元素的值
         返回time函数的返回值. (与localtime函数相反)
返回值：把指定的分解时间转换成time_t型的值并返回.
       无法用日历时间表示时,函数返回-1

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

/*求year年month月day日是星期几*/
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
通过年月日 ，求星期——蔡勒(Zeller)公式  了解即可\

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
    char* week[] = { "日","一","二","三","四","五","六"};
    puts("求星期");
    printf_s("输入年=="); scanf_s("%d", &year);
    printf_s("\n输入月份=="); scanf_s("%d", &mon);
    printf_s("\n输入日期=="); scanf_s("%d", &day);
    i=dayofweek(year, mon, day);
    if (i==-1) {
        puts("输出失败");
    }
    else {
        printf_s("星期%s", week[i]);
    }

    i = dayofweek_Zeller(year, mon, day);
    if (i == -1) {
        puts("输出失败");
    }
    else {
        printf_s("星期%s", week[i]);
    }

    return 0;
}

