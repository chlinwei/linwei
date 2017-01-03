//使用stat函数获取文件的状态信息
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(void)
{
	//准备结构体变量
	struct stat st = {};
	//调用stat函数获取文件a.txt的信息
	int res = stat("a.txt",&st);
	if(-1 == res)
	{
		perror("stat"),exit(-1);
	}
	printf("st.st_mode = %o,st.st_size = %ld,st.st_mtime = %ld\n",st.st_mode,st.st_size,st.st_mtime);

	printf("-----------------------\n");
	if(S_ISREG(st.st_mode))
	{
		printf("普通文件\n");
	}
	if(S_ISDIR(st.st_mode))
	{
		printf("目录文件\n");
	}
	printf("文件的权限是：%o\n",st.st_mode & 0777);
	printf("文件的大小是：%ld\n",st.st_size);
	printf("文件的最后一次修改时间是：%s",ctime(&st.st_mtime));
	struct tm* pt =localtime(&st.st_mtime);
	printf("文件的最后一次修改时间是：%d-%d-%d %02d:%02d:%02d\n",pt->tm_year+1900,pt->tm_mon+1,pt->tm_mday,pt->tm_hour,pt->tm_min,pt->tm_sec);
	return 0;
}









