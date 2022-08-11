#include "head.h"

int diary_system(void) //日记系统
{
    border();
    //进入日记文件夹
    chdir("diary");
    if (_access(UserAccount, 0) == -1)
        mkdir(UserAccount);
    chdir(UserAccount);
    diary_menu(); //日记菜单
    while (scanf("%d", &a) != EOF)
    {
        system("cls"); //清屏
        if (a == 1)    //写日记
            write_diary();
        else if (a == 2) //查阅日记
            consult_diary();
        else if (a == 3) //删除日记
            delete_diary();
        else if (a == 4) //导入日记
            import_diary();
        else if (a == 5) //导出日记
            export_diary();
        else if (a == 6) //个人中心
            return 1;
        else if (a == 7) //退出程序
            return 3;
        else //非法输入
            illegal_input();
        diary_menu(); //日记菜单
    }
}