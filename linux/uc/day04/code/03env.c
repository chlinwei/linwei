//环境表的基本操作
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//获取环境变量SHELL的变量值
	char* pc = getenv("SHELL");
	if(NULL == pc)
	{
		printf("该环境变量不存在\n");
		//return -1;
		exit(-1);
	}
	printf("SHELL = %s\n",pc);// /bin/bash

	printf("-------------------------\n");
	//增加环境变量到环境表中
	int res = setenv("MARK","marz",0);
	if(-1 == res)
	{
		perror("setenv"),exit(-1);
	}
	// marz
	printf("MARK = %s\n",getenv("MARK"));
	
	//修改环境变量的值，不允许修改
	res = setenv("SHELL","abcd",0);
	if(-1 == res)
	{
		perror("setenv"),exit(-1);
	}
	// /bin/bash
	printf("SHELL = %s\n",getenv("SHELL"));
	
	//修改环境变量的值，允许修改
	res = setenv("SHELL","abcd",1);
	if(-1 == res)
	{
		perror("setenv"),exit(-1);
	}
	// abcd
	printf("SHELL = %s\n",getenv("SHELL"));
	
	printf("-------------------------\n");
	//删除环境变量 MARK
	res = unsetenv("MARK");
	if(-1 == res)
	{
		perror("unsetenv"),exit(-1);
	}
	// (null)  段错误
	printf("MARK = %s\n",getenv("MARK"));

	printf("------------------------\n");
	//使用putenv函数增加环境变量
	res = putenv("MARK=xiaomage");
	if(0 != res)
	{
		perror("putenv"),exit(-1);
	}
	// xiaomage
	printf("MARK = %s\n",getenv("MARK"));


	//使用putenv函数修改SHELL为/bin/bash
	res = putenv("SHELL=/bin/bash");
	if(0 != res)
	{
		perror("putenv"),exit(-1);
	}
	// /bin/bash
	printf("SHELL = %s\n",getenv("SHELL"));
	
	printf("-------------------------\n");
	// 清空整个环境表中的所有环境变量
	res = clearenv();
	if(0 != res)
	{
		perror("clearenv"),exit(-1);
	}
	//  (null)  段错误
	printf("PATH = %s\n",getenv("PATH"));
	//声明外部的全局变量
	extern char** environ;
	// (nil)
	printf("environ = %p\n",environ);
	
	while(1);
	return 0;
}













