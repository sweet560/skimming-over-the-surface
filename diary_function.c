#include "head.h"

void write_diary(void) //д�ռ�
{
    _dir = chdir(time_str); //ת��ָ���ļ���·��
    if (_dir == 0) //��֤�Ƿ��Ѿ�����ָ���ļ���·����
    {
        while (b)//�����ռ�
        {
            border();
            diary_menu_1(); // write_diary()�˵�
            _scf = scanf("%d", &a); //scanf() ��ȡʧ�ܣ� ����0
            border();
            if (_scf == 0 || a > 2 || a < 1) //�������
                illegal_input();
            else
            {
                //���䶯̬�ڴ� ���ȸ��� "start "
                char* diary_name = (char*)malloc(strlen("start ") + strlen(diary_user)); //���䶯̬�ڴ�
                strcpy(diary_name, "start ");                                             //��str2 �����ݸ��Ƶ� str1

                if (a == 1) //�Զ����ռ�����
                {
                    //getchar();
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
                    strftime(time_str_1, BUFFER, "%Y%m%d-%H%M%S", info);
                    strcat(time_str_1, ".txt");
                    if ((fp = fopen(time_str_1, "a+")) == NULL)
                    {
                        printf("����ʧ��!\n");
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        fclose(fp);
                        strcat(diary_name, time_str_1);
                        system(diary_name);
                    }
                    break;
                }
                free(diary_name); // ����̫���ͷŶ�̬�ڴ棬�������� �����ڴ�й©������ �ر��˶�̬�ڴ���������д���ڴ�
            }
        }
        chdir("..");
        return;
    }
    if (_dir == -1)//�������
    {
        border();
        printf("--- ������������ ---\n");
        printf("--- ���������� ---\n");
        exit(EXIT_FAILURE);
        border();
        CLS();
    }
}
void consult_diary(void) //�����ռ�
{
    char content;
    int inpt = ZERO;
    char num[SIZE];

    border();
    if ((fp = fopen("log.txt", "r")) == NULL)   //  "r"  ֻ��
    {
        printf("��ȡʧ��!\n");
        exit(EXIT_FAILURE);
    }
    while ((content = fgetc(fp)) != EOF)
    {
        putchar(content);
        printf("%d\n", inpt);
        num[inpt++] = content;
        printf("%d %s\n", inpt, num[inpt]);
    }
    border();
    printf("����Ҫ�鿴���·�:");
    while ((scanf("%d", &number)) == 1)
    {
        printf("%d %s\n", number, num[number]);
        char* diary_name = (char*)malloc(strlen("start ") + strlen(num[number]));

        strcpy(diary_name, "start ");
        strcat(diary_name, num[number]);

        printf("����Ҫ�鿴���·�:");
        free(diary_name);
    }
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