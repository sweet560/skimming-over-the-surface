#include "head.h"

int main(void)
{
	//��������
	system("title ������Ӱ"); //ʹ��system ����DOS ����  titleΪ��������
	system("color 0F");		  // color ��2λ��������ɫ,��һ��Ϊ�������ڶ�����Ϊǰ��
							  /*
								color ��ɫ����
								  0 = ��ɫ       8 = ��ɫ
								  1 = ��ɫ       9 = ����ɫ
								  2 = ��ɫ       A = ����ɫ
								  3 = ����ɫ     B = ��ǳ��ɫ
								  4 = ��ɫ       C = ����ɫ
								  5 = ��ɫ       D = ����ɫ
								  6 = ��ɫ       E = ����ɫ
								  7 = ��ɫ       F = ����ɫ
							  */
	//����ʼִ��
	welcome(); //��������

	while (b) //���潻��
	{
		if (a == 0) //��¼��ע�����
			a = login_screen();
		else if (a == 1) //��������
			a = personal_center();
		else if (a == 2) //�ռ�ϵͳ
			a = diary_system();
		else if (a == 3) //��������
		{
			end_exit();
			return 0; //����ѭ��
		}
	}
	return 0;
}