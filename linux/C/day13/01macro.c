/*
   宏作业
   */
#include <stdio.h>
#define   CHR(ch)    ((ch) >= 'a' && (ch) <= 'z' ? (ch) - 'a' + 'A' : (ch) - 'A' + 'a')
int main() {
	char chr = 0;
	printf("请输入一个字符：");
	scanf("%c", &chr);
	printf("转换结果是%c\n", CHR(chr));
	return 0;
}




