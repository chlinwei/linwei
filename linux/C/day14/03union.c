/*
   联合演示
   */
#include <stdio.h>
union un {
	char buf[2];
	int num;
	float fnum;
};
int main() {
	union un un1 = {0};
	un1.fnum = 1.0f;
	printf("1.0是0x%x\n", un1.num);
	printf("sizeof(un1)是%d\n", sizeof(un1));
	return 0;
}




