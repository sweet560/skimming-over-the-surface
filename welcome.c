#include "head.h"

void welcome(void) //��������
{
    border();
    printf("\n\n\t\t������Ӱ\n\n");
    printf("\t\t     ");
    system("date/T");
    border();
    progress_bar();
}

void end_exit(void) //��������
{
    system("cls");
    border();
    printf("\n\n\t      ������Ӱ\n\n");
    printf("\t\t\t-- ��������\n");
    border();
}