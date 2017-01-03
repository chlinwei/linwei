//使用errno来获取具体的错误原因
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	printf("出错之前：errno = %d\n",errno);
	printf("%s\n",strerror(errno));
	perror("出错之前");
	printf("%m\n");
	printf("---------------------\n");

	//1.打开文件
	FILE* fp = fopen("/etc/passwdd","rb");
	//2.判断文件是否打开失败
	if(NULL == fp)
	{
		//printf("打开文件失败\n");
		printf("出错之后：errno = %d\n",errno);
		printf("fopen:%s\n",strerror(errno));
		perror("fopen");
		printf("%m\n");
		//return -1;
	}

	printf("----------------------\n");
	//练习：要求以"wb"的方式打开文件/etc/passwd,判断打开是否失败，若失败，使用三种方法打印错误信息
	//fp = fopen("/etc/passwd","wb");
	fp = fopen("/etc/passwd","rb");
	//if(NULL == fp)
	if(errno)
	{
		printf("errno = %d\n",errno);
		printf("fopen: %s\n",strerror(errno));
		perror("fopen");
		printf("fopen: %m\n");
		return -1;
	}
	return 0;
}











