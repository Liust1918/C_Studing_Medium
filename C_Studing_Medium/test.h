#include <stdio.h>
#ifndef ABC
#define ABC
    #undef putchar
    int __putchar(int ch) {
        putchar('#');
      return  putchar(ch);
    }
    #define putchar __putchar

#endif