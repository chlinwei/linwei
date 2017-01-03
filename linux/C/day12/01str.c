/*
   字符串作业
   */
#include <stdio.h>
#include <string.h>
int main() {
	int sum = 0;
	char str[20] = "10,20,30,40,50";
	char *p_rank = str;
	while (1) {
		sum += atoi(p_rank);
		p_rank = strstr(p_rank, ",");
        //char* strstr(str1,str2)函数用于判断字符串str是否是str1的子串
        //如果是,则返回str2在str1中首次出现的地址,否则返回空
		if (!p_rank) {
			break;
		}
		else {
			p_rank++;
		}
	}
	printf("总成绩是%d\n", sum);
	return 0;
}




