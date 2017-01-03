/*
   字符串函数演示
   */
#include <stdio.h>
#include <stdlib.h>
int main() {
	char str[20] = {0};
	char ch = 0;
	int num = 0;
	float fnum = 0.0f;
	//printf("%d %c %g", 34, 'u', 4.2f);
	sprintf(str, "%d %c %g", 34, 'u', 4.2f);
	printf("%s\n", str);
	sscanf(str, "%d %c %g", &num, &ch, &fnum);
	printf("ch是%c,num是%d,fnum是%g\n", ch, num, fnum);
	printf("%d\n", atoi("34sdg214"));
	printf("%lg\n", atof("34.23asd34"));
	return 0;
}




