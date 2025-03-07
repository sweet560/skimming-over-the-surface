#include "head.h"

int personal_center(void) //密码修改、进入日记、返回、退出
{
    char tpy_pws[SIZE];   // temporary_passwords 临时密码
    char tpy_pws_1[SIZE]; // 临时密码2
    char tpy_name[SIZE];  //临时账户
    char temporary[SIZE]; //临时
    fp = fopen("users/user.txt", "r+");

    menu_1();                        //密码修改、进入日记、返回、退出
    while ((scanf("%d", &a)) != EOF) //判断输入是否正确并跳转对应的选项
    {
        system("cls"); //清屏
        if (a == 1)    //密码修改
        {
            if (fp == NULL) // r+  可读可写, 必须存在, 可在任意位置读写, 读与写共用同一个指针
            {
                printf("文件打开失败!\n");
                exit(EXIT_FAILURE);
            }
            else //修改密码
            {
                do
                {
                    //验证密码
                    if ((fgets(line, sizeof(line), fp)) != NULL)                // fgets 读取一行，进行判断是否读取到文档末尾
                    {                                                           //如果读取到文档末尾则表示账户密码匹配错误
                        sscanf(line, "%s %s", tpy_name, temporary);             // sscanf 从一个字符串里面读取东西
                        if (!strcmp(tpy_name, name) && !strcmp(temporary, pws)) // strcmp(str1,str2) 对比字符串1和字符串2
                        {
                            border(); //横线
                            printf("\n--- 验证登陆密码 ---\n\n");
                            printf("请先输入密码: ");
                            hidden_number(PassWords);    //获取输入并显示为 * 号
                            if (!strcmp(PassWords, pws)) //验证密码是否正确
                            {
                                printf("--- 验证成功 ---\n");
                                border(); //横线
                                //更改密码
                                printf("\n--- 修改密码 ---\n\n");
                                printf("请输入新密码: ");
                                hidden_number(tpy_pws); //获取输入并显示为 * 号
                                printf("请再次输入新密码: ");
                                hidden_number(tpy_pws_1); //获取输入并显示为 * 号
                                //将原来的密码覆盖掉
                                if (!strcmp(tpy_pws, tpy_pws_1)) //两次密码相等
                                {
                                    fseek(fp, -8, SEEK_CUR); //将文件流调回到要修改的密码的位置  SEEK_CUR 当前位置
                                    //后续需针对密码大小做出限制及密码类型做出限制
                                    fprintf(fp, "%s\n", tpy_pws); //覆盖原来的密码
                                    printf("密码修改成功,请登录!\n");
                                    border();   //横线
                                    Sleep(500); //暂停0.5秒
                                    b = false;
                                    fclose(fp);
                                }
                            }
                            else
                                illegal_input(); //非法输入
                        }
                    }
                } while (b);
                b = true;
                return 0; //登录、注册界面
            }
        }
        else if (a == 2) //进入日记
            return 2;
        else if (a == 3) //退出登陆
        {
            getchar();                      //释放缓冲区
            Exit_menu();                    //是否退出菜单
            while ((ch = getchar()) != EOF) //确认退出登陆 或 继续使用
            {
                if (ch == 'Y' || ch == 'y') //返回 main.c
                    return 0;
                else if (ch == 'N' || ch == 'n') //继续运行菜单
                    break;
                else //非法输入
                {
                    illegal_input(); //非法输入
                    Exit_menu();     //是否退出菜单
                }
            }
        }
        else if (a == 4) //退出程序
            return 3;
        else                 //非法输入
            illegal_input(); //非法输入
        menu_1();            //密码修改、进入日记、返回、退出
    }
}