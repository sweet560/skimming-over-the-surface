#include "head.h"

int diary_system(void) //�ռ�ϵͳ
{
    border();
    //�����ռ��ļ���
    chdir("diary");
    if (_access(UserAccount, 0) == -1)
        mkdir(UserAccount);
    chdir(UserAccount);
    diary_menu(); //�ռǲ˵�
    while (scanf("%d", &a) != EOF)
    {
        system("cls"); //����
        if (a == 1)    //д�ռ�
            write_diary();
        else if (a == 2) //�����ռ�
            consult_diary();
        else if (a == 3) //ɾ���ռ�
            delete_diary();
        else if (a == 4) //�����ռ�
            import_diary();
        else if (a == 5) //�����ռ�
            export_diary();
        else if (a == 6) //��������
            return 1;
        else if (a == 7) //�˳�����
            return 3;
        else //�Ƿ�����
            illegal_input();
        diary_menu(); //�ռǲ˵�
    }
}