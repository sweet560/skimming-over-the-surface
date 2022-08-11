#include "head.h"

void write_diary(void) //写日记
{
    time_t now_time; //声明 time_t 类型变量
    struct tm *info; // tm 结构指针

    //获取创建的日期
    time(&now_time);             //获取机器时间 是一串整数
    info = localtime(&now_time); //获取当地时间和日期,返回 tm 结构数据
    // strftime(); 格式化时间函数,让获取到的时间日期信息按照指定格式显示
    strftime(time_str, BUFFER, "%Y-%m", info); // time_str 储存了日期时间 如:2022-08

    //判断是否是每月1日,是的话新建月份文件夹并将路径转到该文件夹
    if (info->tm_mday == 1)
    {
        if (_access(time_str, 0) == -1) // 0 — — 只检查文件是否存在 2 — — 写权限 4 — — 读权限 6 — — 读写权限
            mkdir(time_str);
        _dir = chdir(time_str); //转到指定文件夹路径
    }
    if (_dir == 0) //验证是否已经到达指定文件夹路径内
    {
        while (b) //创建日记
        {
            border();
            diary_menu_1(); // write_diary()菜单
            _scf = scanf("%d", &a);
            border();
            if (_scf == EOF) //非整数 显示错误
            {
                illegal_input();
            }
            else
            {
                //分配动态内存 并先赋予 "start "
                char *diary_name = (char *)malloc(strlen("start ") + strlen(diary_user)); //分配动态内存
                strcpy(diary_name, "start ");                                             //将str2 的内容复制到 str1

                if (a == 1) //自定义日记名称
                {
                    getchar();
                    printf("输入日记名称: ");
                    scanf("%s", diary_user);
                    strcat(diary_user, ".txt");
                    if ((fp = fopen(diary_user, "a+")) == NULL) //检验是否创建成功
                    {
                        printf("创建失败!\n");
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        fclose(fp);
                        strcat(diary_name, diary_user); //在str1 后面添加 str2 的内容
                        system(diary_name);             //使用window cmd 命令打开指定文件
                    }
                    break;
                }
                else if (a == 2) //以日期及时间自动命名
                {
                    strftime(time_str, BUFFER, "%Y%m%d-%H%M%S", info);
                    strcat(time_str, ".txt");
                    if ((fp = fopen(time_str, "a+")) == NULL)
                    {
                        printf("创建失败!\n");
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        fclose(fp);
                        strcat(diary_name, time_str);
                        system(diary_name);
                    }
                    break;
                }
                free(diary_name); // 不宜太早释放动态内存，否则会出现 堆损坏内存泄漏或者是 关闭了动态内存仍有数据写入内存
            }
        }
    }
    if (_dir == -1) //程序错误
    {
        printf("--- 程序启动故障 ---\n");
        printf("--- 请重新启动 ---\n");
        exit(EXIT_FAILURE);
        CLS();
    }
}
void consult_diary(void) //查阅日记
{
    // mkdir("./cs");  //创建新目录
    chdir("./cs"); //切换 文件目录

    char name_1[SIZE] = {"start account_password.txt"}; //储存 需要打开的日记名
    system(name_1);
    system("pause");
}
void delete_diary(void) //删除日记
{
    char name_2[SIZE] = {"DEL cs.txt"}; //运行前先新建一个  cs.txt 文件
    system("DEL cs.txt");
    system("pause");
}
void import_diary(void) //导入日记
{
    printf("--- 待开发 ---\n");
    CLS();
}
void export_diary(void) //导出日记
{
    printf("--- 待开发 ---\n");
    CLS();
}
/*
    chdir(f:\\test); 打开文件\文件夹
    mkdir(f:\\test); 建立新目录
*/