#include "head.h"
/* 
	�ͷ����뻺���� ���ַ�����
	1. scanf("%*[^\n]%*c");
	2. while((getchar()) !='\n");
	3. gtechar();
	4. rewind(stdin);
	5. fflush(stdin);	��C++11 ��׼������������Ϊ��δ���塱 ������ʹ��
*/
void border(void) //����
{
	int i;
	printf("\n");
	for (i = 0; i < NUM; i++)
		printf("*");
	printf("\n");
}

void CLS(void) //��ͣ����
{
	Sleep(500);	   // 1000���� == 1�� **ע�� S Ҫ��д Сд�Ĳ���**
	system("cls"); //����
}

char hidden_number(char number[SIZE]) //��ȡ�����������ʾΪ *
{
	int i = 0, flag = 0;
	char input;
	while (1) //���Կ���whileѭ��������������д����ֻ��ͨ���س���������ʹ�á�
	{
		if ((input = getch()) != '\r') //��������
		{
			if (input != '\b')
			{
				*(number + i++) = input; //ͨ��ָ������鸳ֵ
				printf("*");			 //����*��
				//fflush(stdin);
				scanf("%*[^\n]%*c");
				flag++;
			}
			if (input == '\b' && flag != 0) //Ϊ�˲���\b \bҲɾ������������ǰ����ʾ���ּ��ж�flag�Ƿ�Ϊ0
			{
				flag--; //����û���Ҫbackspace����ôflag�Լ�
				i--;	//ʹָ����ǰ�ƶ�һ��
				printf("\b \b");
			}
		}
		else
		{
			*(number + i) = '\0'; //\0��������
			//fflush(stdin);
			scanf("%*[^\n]%*c");
			printf("\n");
			return input; //�������ý���
		}
	}
}

void illegal_input(void) //�Ƿ�����
{
	system("cls");
	border(); //����
	printf("\n\t-------------------\n");
	printf("\t---  �������!  ---\n");
	printf("\t-------------------\n\n");
	border();  //����
	//getchar();
	while ((getchar()) != '\n');
	CLS();	   //��������ͣ
}

void progress_bar(void) //������
{
	int i = 0;
	char proc[101];
	memset(proc, 0, 101);
	while (i <= 48)
	{
		/* printf("[%-s] %d%% \r", proc, i * 2); //������ʼλ�ü���ӡ */
		printf("[%-s]\r", proc); //������ʼλ�ü���ӡ
		proc[i] = '>';			 //��ӡ����������״
		fflush(stdout);			 //ˢ�»�����
		Sleep(100);				 //���ƽ��������ٶ�
		i++;
	}
	printf("\n");
}

void read_file_name(void)
{
	border();
	if ((fp = fopen("log.bat", "r")) == NULL)   //  "r"  ֻ��
	{
		printf("��ȡʧ��!\n");
		exit(EXIT_FAILURE);
	}
	while ((content = fgetc(fp)) != EOF)    //��ȡ�ļ�������ʾ����Ļ��
		putchar(content);
	fclose(fp);
	border();
}
