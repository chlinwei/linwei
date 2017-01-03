/*
   字符串演示
   */
#include <stdio.h>
#include <string.h>
int main() {
	char str[10] = {0};
	printf("请输入一个字符串：");
	//scanf("%s", str);
	fgets(str, 10, stdin);
	printf("%s\n", str);
	if (strlen(str) == 9 && str[8] != '\n') {
	    scanf("%*[^\n]");
	    scanf("%*c");
	}
	printf("请输入一个字符串：");
	//scanf("%s", str);
	fgets(str, 10, stdin);
	printf("%s\n", str);
	return 0;
}



