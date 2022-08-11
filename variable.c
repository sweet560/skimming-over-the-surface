/**
 * @file <浮光掠影> Window 10 Cmd窗口 模式下运行
 * @author 伍悦匿匿 (437830488@qq.com)
 * @brief 在这里记录下点点滴滴，让往日的岁月犹如今夕：浮光掠影，岁月如梭
 * @version 1.1.1.2022.08.10_base
 * @date 2022-08-10 16:08:99
 *
 * @copyright Copyright (c) 2022 伍悦匿匿工作室
 *
 */
#include "head.h"

//定义全局变量
int a = ZERO, ch = ZERO, _dir = ZERO, _scf = ZERO;
bool b = true;                                             //真 true  假 false
char line[SIZE1] = {ZERO};                                 // line[] 一行
char name[SIZE] = {ZERO}, pws[SIZE] = {ZERO};              // name[] pws[]文件中的账户及密码
char UserAccount[SIZE] = {ZERO}, PassWords[SIZE] = {ZERO}; // UserAccount[] PassWords[]输入的账户及密码
char time_str[BUFFER] = {ZERO};                            //表示返回的时间的字符串
char diary_user[SIZE1+SIZE1] = {ZERO};                           //用于储存日记名字