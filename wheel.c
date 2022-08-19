#include "head.h"
/* 
	释放输入缓冲区 几种方法：
	1. scanf("%*[^\n]%*c");
	2. while((getchar()) !='\n");
	3. gtechar();
	4. rewind(stdin);
	5. fflush(stdin);	在C++11 标准后，输入流被称为“未定义” 不建议使用
*/
void border(void) //横线
{
	int i;
	printf("\n");
	for (i = 0; i < NUM; i++)
		printf("*");
	printf("\n");
}

void CLS(void) //暂停清屏
{
	Sleep(500);	   // 1000毫秒 == 1秒 **注意 S 要大写 小写的不行**
	system("cls"); //清屏
}

char hidden_number(char number[SIZE]) //获取输入的内容显示为 *
{
	int i = 0, flag = 0;
	char input;
	while (1) //可以控制while循环次数，但这里写成了只能通过回车结束函数使用。
	{
		if ((input = getch()) != '\r') //结束条件
		{
			if (input != '\b')
			{
				*(number + i++) = input; //通过指针给数组赋值
				printf("*");			 //回显*号
				//fflush(stdin);
				scanf("%*[^\n]%*c");
				flag++;
			}
			if (input == '\b' && flag != 0) //为了不让\b \b也删除掉输入密码前的提示文字即判断flag是否为0
			{
				flag--; //如果用户想要backspace，那么flag自减
				i--;	//使指针向前移动一格
				printf("\b \b");
			}
		}
		else
		{
			*(number + i) = '\0'; //\0不能忘记
			//fflush(stdin);
			scanf("%*[^\n]%*c");
			printf("\n");
			return input; //函数调用结束
		}
	}
}

void illegal_input(void) //非法输入
{
	system("cls");
	border(); //横线
	printf("\n\t-------------------\n");
	printf("\t---  输入错误!  ---\n");
	printf("\t-------------------\n\n");
	border();  //横线
	//getchar();
	while ((getchar()) != '\n');
	CLS();	   //清屏、暂停
}

void progress_bar(void) //进度条
{
	int i = 0;
	char proc[101];
	memset(proc, 0, 101);
	while (i <= 48)
	{
		/* printf("[%-s] %d%% \r", proc, i * 2); //控制起始位置及打印 */
		printf("[%-s]\r", proc); //控制起始位置及打印
		proc[i] = '>';			 //打印进度条的形状
		fflush(stdout);			 //刷新缓冲区
		Sleep(100);				 //控制进度条的速度
		i++;
	}
	printf("\n");
}

void read_file_name(void)
{
	border();
	if ((fp = fopen("log.bat", "r")) == NULL)   //  "r"  只读
	{
		printf("读取失败!\n");
		exit(EXIT_FAILURE);
	}
	while ((content = fgetc(fp)) != EOF)    //读取文件内容显示到屏幕上
		putchar(content);
	fclose(fp);
	border();
}
