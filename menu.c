#include "head.h"

void menu(void) //菜单界面：账号注册、账号登陆
{
	system("cls"); //清屏
	border();
	printf("\n\t1)登陆账户\t2)注册账户\n");
	printf("\t3)退出程序\n");
	border();
	printf("请输入数字(1~3):");
}

void menu_1(void) //菜单界面：密码修改、功能选择
{
	system("cls"); //清屏
	border();
	printf("\n\t1)修改密码\t2)日记系统\n");
	printf("\t3)注销登陆\t4)退出程序\n");
	border();
	printf("请输入数字(1~4):");
}

void Exit_menu(void) //是否退出菜单
{
	border(); //横线
	printf("\n\t----------------------------\n");
	printf("\t--    是否确认退出登陆    --\n");
	printf("\t-- 确认输入 Y 取消输入 N --\n");
	printf("\t----------------------------\n\n");
	border(); //横线
	printf("请输入: ");
}

void diary_menu(void) //日记软件菜单
{
	system("cls");
	border();
	printf("\n\t1)写日记\t2)查阅日记\n");
	printf("\t3)删除日记\t4)导入日记\n");
	printf("\t5)导出日记\t6)个人中心\n");
	printf("\t7)退出程序\n");
	border();
	printf("请输入数字(1~7):");
}

void diary_menu_1(void) // write_diary()菜单
{
	printf("\t--- 创建日记 ---\n");
	printf("1)自定义日记名称\t2)智能日记名称\n");
	printf("请选择: ");
}