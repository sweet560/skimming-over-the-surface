#include "head.h"

int diary_system(void) //日记系统
{
    //获取创建的日期
    time(&now_time);             //获取机器时间 是一串整数
    info = localtime(&now_time); //获取当地时间和日期,返回 tm 结构数据
    strftime(time_str, BUFFER, "%Y-%m", info); // time_str 储存了日期时间 如:2022-08

    border();
    //进入日记文件夹
    chdir("diary");
    if (_access(UserAccount, 0) == -1)
        mkdir(UserAccount);
    chdir(UserAccount);

    //判断是否是每月1日,是的话新建月份文件夹并将路径转到该文件夹
    if (info->tm_mday == 1)    //测试时改为当前日期，正式发布前 徐改为 每月1日
    {
        if (_access(time_str, 0) == -1) // 0 — — 只检查文件是否存在 2 — — 写权限 4 — — 读权限 6 — — 读写权限
            mkdir(time_str);

        //生成log.bat 用于读取 文件夹、文件 名称
        if ((fp = fopen("log.bat", "a+")) == NULL) //检验是否创建成功
        {
            printf("创建失败!\n");
            exit(EXIT_FAILURE);
        }
        fprintf(fp, "%s\n", time_str);    //将文件夹名称写入 log.bat
        fclose(fp); //关闭 log.bat
    }

    //功能选择
    diary_menu(); //日记菜单
    while ((_scf = (scanf("%d", &a))) == 1)
    {
        system("cls"); //清屏
        if (_scf == 0 || a > 7 || a < 1) //非法输入
            illegal_input();
        switch (a)
        {
        case 1:     //写日记
        {
            write_diary();
            break;
        }
        case 2:     //查阅日记
        {
            consult_diary();
            break;
        }
        case 3:     //删除日记
        {
            delete_diary();
            break;
        }
        case 4:     //导入日记
        {
            import_diary();
            break;
        }
        case 5:     //导出日记
        {
            export_diary();
            break;
        }
        case 6:     //个人中心
            return 1;
        case 7:     //退出程序
            return 3;
        }
        diary_menu(); //日记菜单
    }
}