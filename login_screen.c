#include "head.h"

int login_screen(void) //��½��ע�� ����
{
    fp = fopen("users/user.txt", "a+"); //���˻������ļ� txt

    if (fp == NULL) // a+ �ɶ���д�� д��ʱ���λ���ļ�ĩβ
    {               //��֤�Ƿ���ȷ��
        printf("���ļ�ʧ��!\n");
        exit(EXIT_FAILURE); //ԭ���� stdlib.h ��
    }
    else //ѡ���½��ע��
    {
        menu();                          //�˵����棺�˺�ע�ᡢ�˺ŵ�½
        while ((scanf("%d", &a)) != EOF) //�ж���Ч����
        {
            system("cls"); //����
            border();      //����
            if (a == 1)
            {
                while (b) //�����½�˺ż�����
                {
                    printf("�������˻�:");
                    scanf("%s", UserAccount);
                    printf("����������:");
                    hidden_number(PassWords); //��ȡ���벢��ʾΪ * ��
                    while (b)                 //��ȡ�ļ����˻�������
                    {
                        if ((fgets(line, sizeof(line), fp)) != NULL)                   // fgets ��ȡһ�У������ж��Ƿ��ȡ���ĵ�ĩβ
                        {                                                              //�����ȡ���ĵ�ĩβ���ʾ�˻�����ƥ�����
                            sscanf(line, "%s %s", name, pws);                          // sscanf ��һ���ַ��������ȡ����
                            if (!strcmp(UserAccount, name) && !strcmp(PassWords, pws)) // strcmp(str1,str2) �Ա��ַ���1���ַ���2
                            {
                                printf("��½�ɹ�!");
                                border();   //����
                                fclose(fp); //�ر��ļ�
                                CLS();      //��������ͣ
                                return 1;   //��������
                            }
                        }
                        else //�������
                        {
                            printf("�˻������������");
                            border();   //����
                            CLS();      //��������ͣ
                            border();   //����
                            rewind(fp); //��ָ��ص��ͷλ�ã�Ҫ��һ�α����˺ź���������ʲô������ʾû�д��˺š�
                            break;
                        }
                    }
                }
            }
            else if (a == 2) //ע���˻�������
            {
                printf("\n\t----ע���˻�----\n\n");
                printf("�����˻�:");
                scanf("%s", name);
                printf("��������:");
                hidden_number(pws); //��ȡ���벢��ʾΪ * ��
                fprintf(fp, "%s %s\n", name, pws);
                printf("\n\t----ע��ɹ�----\n");
                fclose(fp);     //�ر��ļ�
                border();       //����
                CLS();          //��ͣ������
                if (fp == NULL) // a+ �ɶ���д�� д��ʱ���λ���ļ�ĩβ
                {               //��֤�Ƿ���ȷ��
                    printf("���ļ�ʧ��!\n");
                    exit(EXIT_FAILURE); //ԭ���� stdlib.h �� �� exit(1) ��ͬ
                    break;
                }
            }
            else if (a == 3) //��������
                return 3;
            else //�Ƿ�����
                illegal_input();
            menu(); //�˵����棺�˺�ע�ᡢ�˺ŵ�½
        }
    }
    fclose(fp); //�ر��ļ�
}