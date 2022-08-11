#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <io.h>

void diary_menu_1(void);

int main(void)
{
    FILE *fp;
    time_t now_time;   //���� time_t ���ͱ���
    struct tm *info;   // tm �ṹָ��
    char time_str[80]; //��ʾ���ص�ʱ���ַ���
    char ch[80];
    int a, _dir, _scf;
    char diary_user[512];

    time(&now_time);             //��ȡ����ʱ�� ��һ������
    info = localtime(&now_time); //��ȡ����ʱ�������,���� tm �ṹ����
    // strftime(); ��ʽ��ʱ�亯��,�û�ȡ����ʱ��������Ϣ����ָ����ʽ��ʾ
    strftime(time_str, 80, "%Y-%m", info);
    // printf("��ʽ�������ں�ʱ�� : %s \n", time_str);
    //�ж��Ƿ���ÿ��1��,�ǵĻ��½��·��ļ��в���·��ת�����ļ���
    if (_access("admin", 0) == -1) // 0 �� �� ֻ����ļ��Ƿ���� 2 �� �� дȨ�� 4 �� �� ��Ȩ�� 6 �� �� ��дȨ��
        mkdir("admin");
    chdir("admin");
    if (info->tm_mday == 10)
    {
        if (_access(time_str, 0) == -1) // 0 �� �� ֻ����ļ��Ƿ���� 2 �� �� дȨ�� 4 �� �� ��Ȩ�� 6 �� �� ��дȨ��
            mkdir(time_str);
        _dir = chdir(time_str); //ת��ָ���ļ���·��
    }
    if (_dir == 0)
    {
        while (1)
        {
            //�����ռ�
            diary_menu_1(); // write_diary()�˵�
            _scf = scanf("%d", &a);
            if (_scf == EOF) //������
            {
                printf("����\n");
            }
            else
            {
                if (a == 1)
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
                        char *diary_name = (char *)malloc(strlen("start ") + strlen(diary_user)); //���䶯̬�ڴ�
                        strcpy(diary_name, "start ");                                             //��str2 �����ݸ��Ƶ� str1
                        strcat(diary_name, diary_user);                                           //��str1 ������� str2 ������
                        system(diary_name);                                                       //ʹ��window cmd �����ָ���ļ�
                        free(diary_name);                                                         //�ͷ��ѷ���Ķ�̬�ڴ�
                    }
                    break;
                }
                else if (a == 2)
                {
                    strftime(time_str, 80, "%Y%m%d", info);
                    strcat(time_str, ".txt");
                    if ((fp = fopen(time_str, "a+")) == NULL)
                    {
                        printf("����ʧ��!\n");
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
        printf("--- ������������ ---\n");
        printf("--- ���������� ---\n");
        exit(EXIT_FAILURE);
    }
}

void diary_menu_1(void) // write_diary()�˵�
{
    printf("\t--- �����ռ� ---\n");
    printf("1)�Զ����ռ�����\t2)�����ռ�����\n");
    printf("��ѡ��: ");
}