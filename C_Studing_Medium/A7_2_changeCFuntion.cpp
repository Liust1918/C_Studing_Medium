/*改变标准C函数行为*/
/*
改变原来C标准库中putchar函数输出
*/

/*
undefine

#undef C语言标准库函数
修改后函数
#define C语言标准库函数  修改后函数

例如:  
#undef putchar
int __putchar(int ch){}
#define putchar __putchar

*/

/*
创建头文件 xxx.h
引入头文件 #include "xxx.h"

可能存在头文件中函数/宏重复定义
解决方法：在其中一个引入的头文件内
#ifndef 宏名(大写)
#define 宏名(大写)
.....

#endif

作用：如果没有定义该宏，则定义它，并编译下面的内容；
     如果已经定义过该宏，则跳过整个内容，不再重复编译。
*/

//#include <stdio.h>
//#undef putchar
//int __putchar(int ch) {
//    putchar('#');
//  return  putchar(ch);
//}
//#define putchar __putchar

#include "test.h"
#include "test.h"

int main_7_2(void) {
    putchar('5');
    return 0;
}

