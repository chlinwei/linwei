//打印目录中的所有内容
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main(void)
{
	//1.打开目录
	DIR* dir = opendir("../code");
	if(NULL == dir)
	{
		perror("opendir"),exit(-1);
	}
	printf("打开目录成功\n");
	//2.遍历读取目录中的所有内容
	struct dirent* ent;// = readdir(dir);
	//while(ent != NULL)
	while(ent = readdir(dir))
	{
		printf("文件的类型是：%d,文件名是：%s\n",ent->d_type,ent->d_name);
		//读取下一个内容
		//ent = readdir(dir);
	}
	//3.关闭目录
	int res = closedir(dir);
	if(-1 == res)
	{
		perror("closedir"),exit(-1);
	}
	printf("成功关闭目录\n");
	return 0;
}









