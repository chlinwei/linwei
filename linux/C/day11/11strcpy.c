/*
   字符串练习
   */
#include <stdio.h>
char *mystrcpy(char *p_dest, const char *p_src) {
	char *p_dest1 = p_dest;
	const char *p_src1 = p_src;
	while (*p_src1) {
        *p_dest1 = *p_src1;
		p_src1++;
		p_dest1++;
	}
	*p_dest1 = 0;
	return p_dest;
}
int main() {
	char str[10] = {0};
	printf("%s\n", mystrcpy(str, "abcdefx"));
	printf("%s\n", str);
	return 0;
}




