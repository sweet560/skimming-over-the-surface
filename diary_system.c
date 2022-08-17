#include "head.h"

int diary_system(void) //�ռ�ϵͳ
{
    border();
    //�����ռ��ļ���
    chdir("diary");
    if (_access(UserAccount, 0) == -1)
        mkdir(UserAccount);
    chdir(UserAccount);

    //������־.txt ���ڶ�ȡ �ļ��С��ļ� ����
    if ((fp = fopen("log.txt", "a+")) == NULL) //�����Ƿ񴴽��ɹ�
    {
        printf("����ʧ��!\n");
        exit(EXIT_FAILURE);
    }

    //��ȡ����������
    time(&now_time);             //��ȡ����ʱ�� ��һ������
    info = localtime(&now_time); //��ȡ����ʱ�������,���� tm �ṹ����
    strftime(time_str, BUFFER, "%Y-%m", info); // time_str ����������ʱ�� ��:2022-08

    //�ж��Ƿ���ÿ��1��,�ǵĻ��½��·��ļ��в���·��ת�����ļ���
    if (info->tm_mday == 1)    //����ʱ��Ϊ��ǰ���ڣ���ʽ����ǰ ���Ϊ ÿ��1��
    {
        if (_access(time_str, 0) == -1) // 0 �� �� ֻ����ļ��Ƿ���� 2 �� �� дȨ�� 4 �� �� ��Ȩ�� 6 �� �� ��дȨ��
            mkdir(time_str);
        fprintf(fp,"%s\n",time_str);    //���ļ�������д��  ��־.txt
    }
    fclose(fp); //�ر� log.txt
    
    //����ѡ��
    diary_menu(); //�ռǲ˵�
    while ((_scf = (scanf("%d", &a))) == 1)
    {
        system("cls"); //����
        if (_scf == 0 || a > 7 || a < 1) //�Ƿ�����
            illegal_input();
        switch (a)
        {
            case 1:     //д�ռ�
            {
                write_diary();
                break;
            }
            case 2:     //�����ռ�
            {
                consult_diary();
                break;
            }
            case 3:     //ɾ���ռ�
            {
                delete_diary();
                break;
            }
            case 4:     //�����ռ�
            {
                import_diary();
                break;
            }
            case 5:     //�����ռ�
            {
                export_diary();
                break;
            }
            case 6:     //��������
                return 1;
            case 7:     //�˳�����
                return 3;
        }
        diary_menu(); //�ռǲ˵�
    }
}