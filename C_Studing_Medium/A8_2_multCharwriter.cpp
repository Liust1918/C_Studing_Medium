/*多字符串打字训练 */
/*
1.显示一个英文单词，英文单词随机显示(打乱字符串数组的顺序)
2.输入正确字符就消掉改字符
例如 video->ideo->deo-eo-o-下一个单词
关键：在for循环中printf_s("%s \r",&str[i][j])
     while(_getch()!=str[i][j])
*/

/*
打乱数组顺序的经典算法（Knuth 洗牌 ） 等概率洗牌算法
1.存在数组arr[0..n-1],i=>(0,n-1)
2.从最后一个元素开始，依次向前
3.在[0,i]中随机选一个索引j.
4.交换 arr[i] 和 arr[j]
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

#define MAX_STAGE 10
#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)


int main_8_2(void) {

    char* str[] = {
    (char*)"apple",
    (char*)"book",
    (char*)"cat",
    (char*)"dog",
    (char*)"egg",
    (char*)"fish",
    (char*)"hat",
    (char*)"ice",
    (char*)"jam",
    (char*)"key"
    };
    int i;
    int stage;
    int len;
    srand((unsigned)time(NULL));

    //打乱
    for (i = MAX_STAGE-1; i >0; i--){
        int j = rand() % (i + 1);
        swap(char*, str[i], str[j]);
    }

    for (stage = 0; stage < MAX_STAGE; stage++){
        len = strlen(str[stage]);
        for ( i = 0; i < len; i++){
            printf_s("%s \r",&str[stage][i]);
            while (_getch()!=str[stage][i]) {
                ;
            }
        }
    }



    return 0;
}