#include "head.h"

int personal_center(void) //�����޸ġ������ռǡ����ء��˳�
{
    char tpy_pws[SIZE];   // temporary_passwords ��ʱ����
    char tpy_pws_1[SIZE]; // ��ʱ����2
    char tpy_name[SIZE];  //��ʱ�˻�
    char temporary[SIZE]; //��ʱ
    fp = fopen("users/user.txt", "r+");

    menu_1();                        //�����޸ġ������ռǡ����ء��˳�
    while ((scanf("%d", &a)) != EOF) //�ж������Ƿ���ȷ����ת��Ӧ��ѡ��
    {
        system("cls"); //����
        if (a == 1)    //�����޸�
        {
            if (fp == NULL) // r+  �ɶ���д, �������, ��������λ�ö�д, ����д����ͬһ��ָ��
            {
                printf("�ļ���ʧ��!\n");
                exit(EXIT_FAILURE);
            }
            else //�޸�����
            {
                do
                {
                    //��֤����
                    if ((fgets(line, sizeof(line), fp)) != NULL)                // fgets ��ȡһ�У������ж��Ƿ��ȡ���ĵ�ĩβ
                    {                                                           //�����ȡ���ĵ�ĩβ���ʾ�˻�����ƥ�����
                        sscanf(line, "%s %s", tpy_name, temporary);             // sscanf ��һ���ַ��������ȡ����
                        if (!strcmp(tpy_name, name) && !strcmp(temporary, pws)) // strcmp(str1,str2) �Ա��ַ���1���ַ���2
                        {
                            border(); //����
                            printf("\n--- ��֤��½���� ---\n\n");
                            printf("������������: ");
                            hidden_number(PassWords);    //��ȡ���벢��ʾΪ * ��
                            if (!strcmp(PassWords, pws)) //��֤�����Ƿ���ȷ
                            {
                                printf("--- ��֤�ɹ� ---\n");
                                border(); //����
                                //��������
                                printf("\n--- �޸����� ---\n\n");
                                printf("������������: ");
                                hidden_number(tpy_pws); //��ȡ���벢��ʾΪ * ��
                                printf("���ٴ�����������: ");
                                hidden_number(tpy_pws_1); //��ȡ���벢��ʾΪ * ��
                                //��ԭ�������븲�ǵ�
                                if (!strcmp(tpy_pws, tpy_pws_1)) //�����������
                                {
                                    fseek(fp, -8, SEEK_CUR); //���ļ������ص�Ҫ�޸ĵ������λ��  SEEK_CUR ��ǰλ��
                                    //��������������С�������Ƽ�����������������
                                    fprintf(fp, "%s\n", tpy_pws); //����ԭ��������
                                    printf("�����޸ĳɹ�,���¼!\n");
                                    border();   //����
                                    Sleep(500); //��ͣ0.5��
                                    b = false;
                                    fclose(fp);
                                }
                            }
                            else
                                illegal_input(); //�Ƿ�����
                        }
                    }
                } while (b);
                b = true;
                return 0; //��¼��ע�����
            }
        }
        else if (a == 2) //�����ռ�
            return 2;
        else if (a == 3) //�˳���½
        {
            getchar();                      //�ͷŻ�����
            Exit_menu();                    //�Ƿ��˳��˵�
            while ((ch = getchar()) != EOF) //ȷ���˳���½ �� ����ʹ��
            {
                if (ch == 'Y' || ch == 'y') //���� main.c
                    return 0;
                else if (ch == 'N' || ch == 'n') //�������в˵�
                    break;
                else //�Ƿ�����
                {
                    illegal_input(); //�Ƿ�����
                    Exit_menu();     //�Ƿ��˳��˵�
                }
            }
        }
        else if (a == 4) //�˳�����
            return 3;
        else                 //�Ƿ�����
            illegal_input(); //�Ƿ�����
        menu_1();            //�����޸ġ������ռǡ����ء��˳�
    }
}