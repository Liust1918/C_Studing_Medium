/* �����в���
���ã������Ǵ򿪳����ʱ��ϣ������һЩĬ���ļ�,
     ������ʱ��,ͨ�������в����Ѳ���������

*/
/*argc:argument count  �������� */
/*argv:argument vector ÿ������Ԫ��==�ַ���  */

/*
��֤������Ҫ���ҵ���Ŀ��.exe,��·��cmd,�������(��Ŀ��.exe ����1 ����2 ...)
����:��·��...\��Ŀ��\x64\Debug
    cmd:...\Debug\C_Studing_Medium.exe abc 123
	���:C_Studing_Medium.exeabc123
*/

#include <stdio.h>

//int main(int argc, char* argv[]) {
//
//    int i;
//	for (i = 0; i < argc; i++){
//		printf_s("%s \n", argv[i]);
//	}
//	return 0;
//}

int main_6_4(int argc, char** argv) {
    int i;
    while (argc-->0) {
        printf_s("%s \n", *argv++);
    }
    return 0;
}