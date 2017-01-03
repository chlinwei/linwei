//修改文件的权限和大小信息
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
	//1.获取文件a.txt的权限和大小，打印
	struct stat st = {};
	int res = stat("a.txt",&st);
	if(-1 == res)
	{
		perror("stat"),exit(-1);
	}
	printf("文件的权限是：%o,文件的大小是：%ld\n",st.st_mode&0777,st.st_size);
	//2.修改文件的权限和大小
	res = chmod("a.txt",0600);
	if(-1 == res)
	{
		perror("chmod"),exit(-1);
	}
	printf("修改文件的权限成功\n");
	res = truncate("a.txt",100);
	if(-1 == res)
	{
		perror("truncate"),exit(-1);
	}
	printf("修改文件的大小成功\n");
	//3.获取修改之后的权限和大小，打印
	res = stat("a.txt",&st);
	if(-1 == res)
	{
		perror("stat"),exit(-1);
	}
	printf("修改之后的文件权限是：%o,文件大小是：%ld\n",st.st_mode&0777,st.st_size);
	return 0;
}










