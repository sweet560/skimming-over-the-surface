#include "head.h"

void menu(void) //�˵����棺�˺�ע�ᡢ�˺ŵ�½
{
	system("cls"); //����
	border();
	printf("\n\t1)��½�˻�\t2)ע���˻�\n");
	printf("\t3)�˳�����\n");
	border();
	printf("����������(1~3):");
}

void menu_1(void) //�˵����棺�����޸ġ�����ѡ��
{
	system("cls"); //����
	border();
	printf("\n\t1)�޸�����\t2)�ռ�ϵͳ\n");
	printf("\t3)ע����½\t4)�˳�����\n");
	border();
	printf("����������(1~4):");
}

void Exit_menu(void) //�Ƿ��˳��˵�
{
	border(); //����
	printf("\n\t----------------------------\n");
	printf("\t--    �Ƿ�ȷ���˳���½    --\n");
	printf("\t-- ȷ������ Y ȡ������ N --\n");
	printf("\t----------------------------\n\n");
	border(); //����
	printf("������: ");
}

void diary_menu(void) //�ռ�����˵�
{
	system("cls");
	border();
	printf("\n\t1)д�ռ�\t2)�����ռ�\n");
	printf("\t3)ɾ���ռ�\t4)�����ռ�\n");
	printf("\t5)�����ռ�\t6)��������\n");
	printf("\t7)�˳�����\n");
	border();
	printf("����������(1~7):");
}

void diary_menu_1(void) // write_diary()�˵�
{
	printf("\t--- �����ռ� ---\n");
	printf("1)�Զ����ռ�����\t2)�����ռ�����\n");
	printf("��ѡ��: ");
}