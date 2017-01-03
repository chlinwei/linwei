//errno的使用
#include <stdio.h>
#include <errno.h>

int main(void)
{
	printf("出错之前：errno = %d\n",errno);
	//1.打开文件/etc/passwd，使用fopen函数
	FILE* fp = fopen("/etc/passwdd","rb");
	//2.判断打开文件是否失败
	if(NULL == fp)
	{
		printf("打开文件失败\n");
		printf("出错之后：errno = %d\n",errno);
		return -1;
	}
	//3.关闭文件，使用fclose函数
	fclose(fp);
	return 0;
}











