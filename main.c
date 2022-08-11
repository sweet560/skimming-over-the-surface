#include "head.h"

int main(void)
{
	//界面设置
	system("title 浮光掠影"); //使用system 调用DOS 命令  title为标题命令
	system("color 0F");		  // color 由2位数控制颜色,第一个为背景，第二个则为前景
							  /*
								color 颜色设置
								  0 = 黑色       8 = 灰色
								  1 = 蓝色       9 = 淡蓝色
								  2 = 绿色       A = 淡绿色
								  3 = 湖蓝色     B = 淡浅绿色
								  4 = 红色       C = 淡红色
								  5 = 紫色       D = 淡紫色
								  6 = 黄色       E = 淡黄色
								  7 = 白色       F = 亮白色
							  */
	//程序开始执行
	welcome(); //启动界面

	while (b) //界面交互
	{
		if (a == 0) //登录、注册界面
			a = login_screen();
		else if (a == 1) //个人中心
			a = personal_center();
		else if (a == 2) //日记系统
			a = diary_system();
		else if (a == 3) //结束界面
		{
			end_exit();
			return 0; //结束循环
		}
	}
	return 0;
}