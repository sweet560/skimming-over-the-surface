/**
 * @file   <������Ӱ> Window 10 Cmd���� ģʽ������
 * @author ��������(437830488@qq.com)
 * @brief  �������¼�µ��εΣ������յ����������Ϧ��������Ӱ����������
 * @date  2022-08-18
 * @version  V1.08.18-alpha
 * @copyright Copyright (c) 2022 �������乤����
 */
#include "head.h"

//����ȫ�ֱ���
int a = ZERO, ch = ZERO, _dir = ZERO, _scf = ZERO, number = ZERO;
bool b = true;                                             //�� true  �� false
char content = ZERO;                                       //�ļ�����
char line[SIZE1] = {ZERO};                                 // line[] һ��
char name[SIZE] = {ZERO}, pws[SIZE] = {ZERO};              // name[] pws[]�ļ��е��˻�������
char name_1[SIZE] = { ZERO }, pws_1[SIZE] = { ZERO };		   //���ڶԱ�����
char UserAccount[SIZE] = {ZERO}, PassWords[SIZE] = {ZERO}; // UserAccount[] PassWords[]������˻�������
char time_str[BUFFER] = {ZERO};                            //��ʾ���ص�ʱ����ַ���
char time_str_1[BUFFER] = {ZERO};                          //��ʾ���ص�ʱ����ַ���
char diary_user[SIZE1 + SIZE1] = {ZERO};                   //���ڴ����ռ�����