/**
 * @file <������Ӱ> Window 10 Cmd���� ģʽ������
 * @author �������� (437830488@qq.com)
 * @brief �������¼�µ��εΣ������յ����������Ϧ��������Ӱ����������
 * @version 1.1.1.2022.08.10_base
 * @date 2022-08-10 16:08:99
 *
 * @copyright Copyright (c) 2022 �������乤����
 *
 */
#include "head.h"

//����ȫ�ֱ���
int a = ZERO, ch = ZERO, _dir = ZERO, _scf = ZERO;
bool b = true;                                             //�� true  �� false
char line[SIZE1] = {ZERO};                                 // line[] һ��
char name[SIZE] = {ZERO}, pws[SIZE] = {ZERO};              // name[] pws[]�ļ��е��˻�������
char UserAccount[SIZE] = {ZERO}, PassWords[SIZE] = {ZERO}; // UserAccount[] PassWords[]������˻�������
char time_str[BUFFER] = {ZERO};                            //��ʾ���ص�ʱ����ַ���
char diary_user[SIZE1+SIZE1] = {ZERO};                           //���ڴ����ռ�����