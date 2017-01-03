/*
   字符串演示
   */
#include <stdio.h>
#include <string.h>
int main() {
	char str[20] = "abc";
	printf("有效字符个数是%d\n", strlen(str));
	printf("%s\n", strcat(str, "xyz"));
	printf("%s\n", str);
	printf("比较结果是%d\n", strcmp("abc", "abd"));
    printf("%s\n", strcpy(str, "abcdefxyz"));
	printf("%s\n", str);
	memset(str, 't', 10);
	printf("%s\n", str);
	printf("%s\n", strstr("abcdefxyz", "cde"));
	return 0;




}
