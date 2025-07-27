/*���ַ�������ѵ�� */
/*
1.��ʾһ��Ӣ�ĵ��ʣ�Ӣ�ĵ��������ʾ(�����ַ��������˳��)
2.������ȷ�ַ����������ַ�
���� video->ideo->deo-eo-o-��һ������
�ؼ�����forѭ����printf_s("%s \r",&str[i][j])
     while(_getch()!=str[i][j])
*/

/*
��������˳��ľ����㷨��Knuth ϴ�� �� �ȸ���ϴ���㷨
1.��������arr[0..n-1],i=>(0,n-1)
2.�����һ��Ԫ�ؿ�ʼ��������ǰ
3.��[0,i]�����ѡһ������j.
4.���� arr[i] �� arr[j]
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

    //����
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