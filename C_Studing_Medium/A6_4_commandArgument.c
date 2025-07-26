/* 命令行参数
作用：当我们打开程序的时候，希望加载一些默认文件,
     启动的时候,通过命令行参数把参数传进来

*/
/*argc:argument count  参数个数 */
/*argv:argument vector 每个参数元素==字符串  */

/*
验证：你需要先找到项目名.exe,再路径cmd,输入参数(项目名.exe 参数1 参数2 ...)
例如:在路径...\项目名\x64\Debug
    cmd:...\Debug\C_Studing_Medium.exe abc 123
	输出:C_Studing_Medium.exeabc123
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