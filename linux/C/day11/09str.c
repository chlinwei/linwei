/*
   字符指针数组演示
   */
#include <stdio.h>
int main() {
	char *strs[] = {"China", 
		"Russia", "England", 
		"France", "America"};
	int num = 0;
	for (num = 0;num <= 4;num++) {
		printf("%s\n", strs[num]);
	}
	return 0;
}




