#include "head.h"

void welcome(void) //启动界面
{
    border();
	printf("\n\n\t\t浮光掠影\n\n"); //标题
    printf("\t\t     ");    
	system("date/T");   //显示日期
    border();
	progress_bar(); //进度条
}

void end_exit(void) //结束界面
{
    system("cls");
    border();
    printf("\n\n\t      浮光掠影\n\n");
    printf("\t\t\t-- 伍悦匿匿\n");
    border();
}