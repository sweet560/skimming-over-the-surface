#include "head.h"

int login_screen(void) //登陆、注册 界面
{
   fp = fopen("users/user.txt", "a+"); //打开账户密码文件 txt

   if (fp == NULL) // a+ 可读可写， 写入时光标位于文件末尾
   {               //验证是否正确打开
       printf("打开文件失败!\n");
       exit(EXIT_FAILURE); //原型在 stdlib.h 中
   }
   else //选择登陆或注册
   {
       menu();                          //菜单界面：账号注册、账号登陆
       while ((scanf("%d", &a)) != EOF) //判断有效输入
       {
           system("cls"); //清屏
           border();      //横线
           if (a == 1)
           {
               while (b) //输入登陆账号及密码
               {
                   printf("请输入账户:");
                   if (scanf("%s", UserAccount) != 1) {
                       printf("输入错误，请重试。\n");
                       continue;
                   }
                   printf("请输入密码:");
                   hidden_number(PassWords); //获取输入并显示为 * 号
                   while (b)                 //读取文件中账户及密码
                   {
                       if ((fgets(line, sizeof(line), fp)) != NULL)                   // fgets 读取一行，进行判断是否读取到文档末尾
                       {                                                              //如果读取到文档末尾则表示账户密码匹配错误
                           if (sscanf(line, "%s %s", name, pws) != 2) {               // sscanf 从一个字符串里面读取东西
                               printf("读取账户信息失败，请重试。\n");
                               continue;
                           }
                           if (!strcmp(UserAccount, name) && !strcmp(PassWords, pws)) // strcmp(str1,str2) 对比字符串1和字符串2
                           {
                               printf("登陆成功!");
                               border();   //横线
                               fclose(fp); //关闭文件
                               CLS();      //清屏、暂停
                               return 1;   //个人中心
                           }
                       }
                       else //密码错误
                       {
                           printf("账户密码输入错误");
                           border();   //横线
                           CLS();      //清屏、暂停
                           border();   //横线
                           rewind(fp); //将指针回到最开头位置，要不一次遍历账号后，无论输入什么都会显示没有此账号。
                           break;
                       }
                   }
               }
           }
           else if (a == 2) //注册账户及密码
           {
               printf("\n\t----注册账户----\n\n");
               printf("输入账户:");
               if (scanf("%s", name) != 1) {
                   printf("输入错误，请重试。\n");
                   continue;
               }
               printf("输入密码:");
               hidden_number(pws); //获取输入并显示为 * 号
               fprintf(fp, "%s %s\n", name, pws);
               printf("\n\t----注册成功----\n");
               fclose(fp);     //关闭文件
               border();       //横线
               CLS();          //暂停、清屏
               if (fp == NULL) // a+ 可读可写， 写入时光标位于文件末尾
               {               //验证是否正确打开
                   printf("打开文件失败!\n");
                   exit(EXIT_FAILURE); //原型在 stdlib.h 中 与 exit(1) 等同
                   break;
               }
           }
           else if (a == 3) //结束程序
               return 3;
           else //非法输入
               illegal_input();
           menu(); //菜单界面：账号注册、账号登陆
       }
   }
   fclose(fp); //关闭文件
}