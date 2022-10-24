#pragma once //仅编译一次
#ifndef _ONCE
    #define _ONCE
    

    //头文件列表
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <conio.h> //getch() 原型
    #include <time.h>  //时间函数头文件
    #include <io.h>    //chdir() 原型   创建文件 更改打开文件路径函数头文件
    #include <direct.h>

    //常量列表
    #define ZERO 0
    #define NUM 50
    #define SIZE 128
    #define SIZE1 256
    #define BUFFER 80

    //引用全局变量、指针
    extern bool b;
    extern int a, ch, _dir, _scf, number;
    extern char content;
    extern char line[SIZE1], name[SIZE], pws[SIZE], name_1[SIZE], pws_1[SIZE], UserAccount[SIZE], PassWords[SIZE]; 
    extern char time_str[BUFFER], time_str_1[BUFFER], diary_user[SIZE1 + SIZE1];
    FILE *fp, *fp1;        //文件指针
    time_t now_time; //声明 time_t 类型变量
    struct tm *info; // tm 结构指针
    size_t se;	//sizeof()返回值

    //函数声明列表
    void border(void);        //边框
    void welcome(void);       //启动界面
    void end_exit(void);      //结束界面
    void illegal_input(void); //非法输入
    void menu(void);          //菜单界面：账号注册、账号登陆、退出
    void menu_1(void);        //菜单界面：密码修改、功能选择、退出、返回
    void Exit_menu(void);     //是否退出菜单
    void CLS(void);           //暂停、清屏
    void progress_bar(void);  //进度条

    char hidden_number(char number[SIZE]); //获取输入的内容显示为 *

    int login_screen(void);    //登陆、注册 界面
    int personal_center(void); //密码修改、进入日记、返回、退出
    int diary_system(void);    //日记系统
    void diary_menu(void);     //日记软件菜单
    void write_diary(void);    //写日记
    void diary_menu_1(void);   // write_diary()菜单
    void consult_diary(void);  //查阅日记
    void read_file_name(void); //文件名读取
    void delete_diary(void);   //删除日记
    void whether_delete(void); //是否删除
    void import_diary(void);   //导入日记
    void export_diary(void);   //导出日记

#endif