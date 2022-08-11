#include "head.h"

void welcome(void) //启动界面
{
    border();
    printf("\n\n\t\t浮光掠影\n\n");
    printf("\t\t     ");
    system("date/T");
    border();
    progress_bar();
}

void end_exit(void) //结束界面
{
    system("cls");
    border();
    printf("\n\n\t      浮光掠影\n\n");
    printf("\t\t\t-- 伍悦匿匿\n");
    border();
}