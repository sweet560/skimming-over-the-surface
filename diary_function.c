#include "head.h"

void write_diary(void) //写日记
{
    _dir = chdir(time_str); //转到指定文件夹路径
    if (_dir == 0) //验证是否已经到达指定文件夹路径内
    {
        while (b)//创建日记
        {
            border();
            diary_menu_1(); // write_diary()菜单
            _scf = scanf("%d", &a); //scanf() 获取失败， 返回0
            border();
            if (_scf == 0 || a > 2 || a < 1) //输入错误
                illegal_input();
            else
            {
                //分配动态内存 并先赋予 "start "
                char* diary_name = (char*)malloc(strlen("start ") + strlen(diary_user)); //分配动态内存
                strcpy(diary_name, "start ");                                             //将str2 的内容复制到 str1

                if (a == 1) //自定义日记名称
                {
                    //getchar();
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

                        //生成log.bat 
                        if ((fp = fopen("log.bat", "a+")) == NULL)
                        {
                            printf("创建失败!\n");
                            exit(EXIT_FAILURE);
                        }
                        fprintf(fp, "%s\n", diary_user);    //将文件夹名称写入 log.bat
                        fclose(fp); //关闭 log.bat
                    }
                    break;
                }
                else if (a == 2) //以日期及时间自动命名
                {
                    strftime(time_str_1, BUFFER, "%Y%m%d-%H%M%S", info);
                    strcat(time_str_1, ".txt");
                    if ((fp = fopen(time_str_1, "a+")) == NULL)
                    {
                        printf("创建失败!\n");
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        fclose(fp);
                        strcat(diary_name, time_str_1);
                        system(diary_name);

                        //生成log.bat 
                        if ((fp = fopen("log.bat", "a+")) == NULL)
                        {
                            printf("创建失败!\n");
                            exit(EXIT_FAILURE);
                        }
                        fprintf(fp, "%s\n", time_str_1);    //将文件夹名称写入 log.bat
                        fclose(fp); //关闭 log.bat
                    }
                    break;
                }
                free(diary_name); // 不宜太早释放动态内存，否则会出现 堆损坏内存泄漏或者是 关闭了动态内存仍有数据写入内存
            }
        }
        chdir("..");
        return;
    }
    if (_dir == -1)//程序错误
    {
        border();
        printf("--- 程序启动故障 ---\n");
        printf("--- 请重新启动 ---\n");
        exit(EXIT_FAILURE);
        border();
        CLS();
    }
}
void consult_diary(void) //查阅日记
{
    char* diary_name = (char*)malloc(strlen("start ") + strlen(name));
    strcpy(diary_name, "start ");

    while (b)
    {
        read_file_name();   //读取文件内容
        printf("输入要查看的月份: ");
        scanf("%s", name);
        _dir = chdir(name);
        if (_dir == 0)
        {
            while (b)
            {
                if (_dir == 0)
                {
                    CLS();
                    read_file_name();   //读取文件内容
                    printf("输入要查阅的日记: ");
                    scanf("%s", name);
                    fp = fopen("log.bat", "r");
                    while (b)
                    {
                        //输入文件名错误
                        if ((fgets(line, sizeof(line), fp)) != NULL)
                        {
                            sscanf(line, "%s", name_1);
                            if (!strcmp(name_1, name))
                            {
                                //打开指定文件
                                strcat(diary_name, name);
                                system(diary_name);
                                strcpy(diary_name, "start ");
                                while ((getchar()) != '\n');
                                break;
                            }
                        }
                        else
                        {
                            border();
                            printf("输入错误!\n");
                            printf("输入要查阅的日记: ");
                            scanf("%s", name);
                            rewind(fp);
                        }
                    }
                    fclose(fp);
                }
                border();
                printf("是否继续查阅其他日记( Y / N ): ");
                while ((ch = getchar()) != EOF)
                {
                    if (ch == 'Y' || ch == 'y')
                        break;
                    else if (ch == 'N' || ch == 'n')    //返回日记系统主菜单
                    {
                        chdir("..");
                        return 0;
                    }
                    else
                    {
                        illegal_input();
                        border();
                        printf("是否继续查阅其他日记( Y / N ): ");
                    }
                }
            }
        }
        else  //输入错误
            illegal_input();
    }
    free(diary_name);
}
void delete_diary(void) //删除日记
{/*
    remove(); 用于删除文件
 */
    while (b)
    {
        read_file_name();   //位于 用户名 文件
        whether_delete();
        printf("输入要查看的内容: ");
        scanf("%s", name);
        _dir = chdir(name);
        if (_dir == 0)
        {
            read_file_name();   //位于 月份名 文件
            whether_delete();
            chdir("..");
        }
        else
            illegal_input();
    }
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