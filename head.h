#pragma once //������һ��
#ifndef _ONCE
    #define _ONCE
    

    //ͷ�ļ��б�
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <conio.h> //getch() ԭ��
    #include <time.h>  //ʱ�亯��ͷ�ļ�
    #include <io.h>    //chdir() ԭ��   �����ļ� ���Ĵ��ļ�·������ͷ�ļ�
    #include <direct.h>

    //�����б�
    #define ZERO 0
    #define NUM 50
    #define SIZE 128
    #define SIZE1 256
    #define BUFFER 80

    //����ȫ�ֱ�����ָ��
    extern bool b;
    extern int a, ch, _dir, _scf, number;
    extern char content;
    extern char line[SIZE1], name[SIZE], pws[SIZE], name_1[SIZE], pws_1[SIZE], UserAccount[SIZE], PassWords[SIZE]; 
    extern char time_str[BUFFER], time_str_1[BUFFER], diary_user[SIZE1 + SIZE1];
    FILE *fp, *fp1;        //�ļ�ָ��
    time_t now_time; //���� time_t ���ͱ���
    struct tm *info; // tm �ṹָ��
    size_t se;	//sizeof()����ֵ

    //���������б�
    void border(void);        //�߿�
    void welcome(void);       //��������
    void end_exit(void);      //��������
    void illegal_input(void); //�Ƿ�����
    void menu(void);          //�˵����棺�˺�ע�ᡢ�˺ŵ�½���˳�
    void menu_1(void);        //�˵����棺�����޸ġ�����ѡ���˳�������
    void Exit_menu(void);     //�Ƿ��˳��˵�
    void CLS(void);           //��ͣ������
    void progress_bar(void);  //������

    char hidden_number(char number[SIZE]); //��ȡ�����������ʾΪ *

    int login_screen(void);    //��½��ע�� ����
    int personal_center(void); //�����޸ġ������ռǡ����ء��˳�
    int diary_system(void);    //�ռ�ϵͳ
    void diary_menu(void);     //�ռ�����˵�
    void write_diary(void);    //д�ռ�
    void diary_menu_1(void);   // write_diary()�˵�
    void consult_diary(void);  //�����ռ�
    void read_file_name(void); //�ļ�����ȡ
    void delete_diary(void);   //ɾ���ռ�
    void whether_delete(void); //�Ƿ�ɾ��
    void import_diary(void);   //�����ռ�
    void export_diary(void);   //�����ռ�

#endif