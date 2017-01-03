//递归打印目录中的所有内容
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

//递归打印的功能函数
void print(char* path)
{
	//1.打开目录
	DIR* dir = opendir(path);
	if(NULL == dir)
	{
		//perror(),exit();
		return;//结束当前函数
	}
	//2.循环读取目录中的内容
	struct dirent* ent;
	while(ent = readdir(dir))
	{
		//2.1 如果读取到的是目录,打印,递归
		if(4 == ent->d_type)
		{
			printf("[%s]\n",ent->d_name);
			//跳过特殊目录 . 和 ..
			if(!strcmp(ent->d_name,".") || !strcmp(ent->d_name,".."))
			{
				continue;//读取下一个
			}
			//拼接子目录的路径
			char buf[100] = {0};
			sprintf(buf,"%s/%s",path,ent->d_name);
			//调用递归函数
			print(buf);
		}
		//2.2 如果读取到的是文件，打印即可
		if(8 == ent->d_type)
		{
			printf("%s\n",ent->d_name);
		}
	}
	//3.关闭目录
	int res = closedir(dir);
	if(-1 == res)
	{
		return;//结束当前函数
	}
}

int main(void)
{
	print("../../day03/code");
	return 0;
}






