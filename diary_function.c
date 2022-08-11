#include "head.h"

void write_diary(void) //д�ռ�
{
    time_t now_time; //���� time_t ���ͱ���
    struct tm *info; // tm �ṹָ��

    //��ȡ����������
    time(&now_time);             //��ȡ����ʱ�� ��һ������
    info = localtime(&now_time); //��ȡ����ʱ�������,���� tm �ṹ����
    // strftime(); ��ʽ��ʱ�亯��,�û�ȡ����ʱ��������Ϣ����ָ����ʽ��ʾ
    strftime(time_str, BUFFER, "%Y-%m", info); // time_str ����������ʱ�� ��:2022-08

    //�ж��Ƿ���ÿ��1��,�ǵĻ��½��·��ļ��в���·��ת�����ļ���
    if (info->tm_mday == 1)
    {
        if (_access(time_str, 0) == -1) // 0 �� �� ֻ����ļ��Ƿ���� 2 �� �� дȨ�� 4 �� �� ��Ȩ�� 6 �� �� ��дȨ��
            mkdir(time_str);
        _dir = chdir(time_str); //ת��ָ���ļ���·��
    }
    if (_dir == 0) //��֤�Ƿ��Ѿ�����ָ���ļ���·����
    {
        while (b) //�����ռ�
        {
            border();
            diary_menu_1(); // write_diary()�˵�
            _scf = scanf("%d", &a);
            border();
            if (_scf == EOF) //������ ��ʾ����
            {
                illegal_input();
            }
            else
            {
                //���䶯̬�ڴ� ���ȸ��� "start "
                char *diary_name = (char *)malloc(strlen("start ") + strlen(diary_user)); //���䶯̬�ڴ�
                strcpy(diary_name, "start ");                                             //��str2 �����ݸ��Ƶ� str1

                if (a == 1) //�Զ����ռ�����
                {
                    getchar();
                    printf("�����ռ�����: ");
                    scanf("%s", diary_user);
                    strcat(diary_user, ".txt");
                    if ((fp = fopen(diary_user, "a+")) == NULL) //�����Ƿ񴴽��ɹ�
                    {
                        printf("����ʧ��!\n");
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        fclose(fp);
                        strcat(diary_name, diary_user); //��str1 ������� str2 ������
                        system(diary_name);             //ʹ��window cmd �����ָ���ļ�
                    }
                    break;
                }
                else if (a == 2) //�����ڼ�ʱ���Զ�����
                {
                    strftime(time_str, BUFFER, "%Y%m%d-%H%M%S", info);
                    strcat(time_str, ".txt");
                    if ((fp = fopen(time_str, "a+")) == NULL)
                    {
                        printf("����ʧ��!\n");
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
                free(diary_name); // ����̫���ͷŶ�̬�ڴ棬�������� �����ڴ�й©������ �ر��˶�̬�ڴ���������д���ڴ�
            }
        }
    }
    if (_dir == -1) //�������
    {
        printf("--- ������������ ---\n");
        printf("--- ���������� ---\n");
        exit(EXIT_FAILURE);
        CLS();
    }
}
void consult_diary(void) //�����ռ�
{
    // mkdir("./cs");  //������Ŀ¼
    chdir("./cs"); //�л� �ļ�Ŀ¼

    char name_1[SIZE] = {"start account_password.txt"}; //���� ��Ҫ�򿪵��ռ���
    system(name_1);
    system("pause");
}
void delete_diary(void) //ɾ���ռ�
{
    char name_2[SIZE] = {"DEL cs.txt"}; //����ǰ���½�һ��  cs.txt �ļ�
    system("DEL cs.txt");
    system("pause");
}
void import_diary(void) //�����ռ�
{
    printf("--- ������ ---\n");
    CLS();
}
void export_diary(void) //�����ռ�
{
    printf("--- ������ ---\n");
    CLS();
}
/*
    chdir(f:\\test); ���ļ�\�ļ���
    mkdir(f:\\test); ������Ŀ¼
*/