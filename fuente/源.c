#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <io.h>

void diary_menu_1(void);

int main(void)
{
    FILE *fp;
    time_t now_time;   //声明 time_t 类型变量
    struct tm *info;   // tm 结构指针
    char time_str[80]; //表示返回的时间字符串
    char ch[80];
    int a, _dir, _scf;
    char diary_user[512];

    time(&now_time);             //获取机器时间 是一串整数
    info = localtime(&now_time); //获取当地时间和日期,返回 tm 结构数据
    // strftime(); 格式化时间函数,让获取到的时间日期信息按照指定格式显示
    strftime(time_str, 80, "%Y-%m", info);
    // printf("格式化的日期和时间 : %s \n", time_str);
    //判断是否是每月1日,是的话新建月份文件夹并将路径转到该文件夹
    if (_access("admin", 0) == -1) // 0 — — 只检查文件是否存在 2 — — 写权限 4 — — 读权限 6 — — 读写权限
        mkdir("admin");
    chdir("admin");
    if (info->tm_mday == 10)
    {
        if (_access(time_str, 0) == -1) // 0 — — 只检查文件是否存在 2 — — 写权限 4 — — 读权限 6 — — 读写权限
            mkdir(time_str);
        _dir = chdir(time_str); //转到指定文件夹路径
    }
    if (_dir == 0)
    {
        while (1)
        {
            //创建日记
            diary_menu_1(); // write_diary()菜单
            _scf = scanf("%d", &a);
            if (_scf == EOF) //非整数
            {
                printf("错误！\n");
            }
            else
            {
                if (a == 1)
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
                        char *diary_name = (char *)malloc(strlen("start ") + strlen(diary_user)); //分配动态内存
                        strcpy(diary_name, "start ");                                             //将str2 的内容复制到 str1
                        strcat(diary_name, diary_user);                                           //在str1 后面添加 str2 的内容
                        system(diary_name);                                                       //使用window cmd 命令打开指定文件
                        free(diary_name);                                                         //释放已分配的动态内存
                    }
                    break;
                }
                else if (a == 2)
                {
                    strftime(time_str, 80, "%Y%m%d", info);
                    strcat(time_str, ".txt");
                    if ((fp = fopen(time_str, "a+")) == NULL)
                    {
                        printf("创建失败!\n");
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        fclose(fp);
                        char *diary_name = (char *)malloc(strlen("start  ") + strlen(time_str));
                        strcpy(diary_name, "start  ");
                        strcat(diary_name, time_str);
                        system(diary_name);
                        free(diary_name);
                    }
                }
                break;
            }
        }
    }
    if (_dir == -1)
    {
        printf("--- 程序启动故障 ---\n");
        printf("--- 请重新启动 ---\n");
        exit(EXIT_FAILURE);
    }
}

void diary_menu_1(void) // write_diary()菜单
{
    printf("\t--- 创建日记 ---\n");
    printf("1)自定义日记名称\t2)智能日记名称\n");
    printf("请选择: ");
}