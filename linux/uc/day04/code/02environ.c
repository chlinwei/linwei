//遍历当前进程整个环境表的所有信息
#include <stdio.h>
#include <string.h>

int main(void)
{
	//对全局变量做一个外部声明
	extern char** environ;
	//指定替身去遍历环境表
	char** ppc = environ;
	while(*ppc != NULL)
	{
		printf("%s\n",*ppc);
		//指向下一个环境变量
		ppc++;
	}
	
	printf("----------------------\n");
	//练习:找出环境变量SHELL的值存放在自定义数组buf中，打印数组中的内容
	ppc = environ;
	char buf[100] = {0};
	while(*ppc != NULL)
	{
		if(!strncmp(*ppc,"SHELL",5))
		{
			strcpy(buf,*ppc+6);
			break;
		}
		//指向下一个
		ppc++;
	}
	printf("SHELL=%s\n",buf);
	return 0;
}











