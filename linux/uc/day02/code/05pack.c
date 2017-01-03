// #pragma pack 的使用
#include <stdio.h>

// 按照 2 的倍数进行对齐和补齐
//#pragma pack(2)  // 8  
// 按照 1 的倍数进行对齐和补齐
//#pragma pack(1)   // 6  
//#pragma pack(3) error   
//#pragma pack(4) 默认
//#pragma pack(8) 超过4按照4计算

int main(void)
{
	struct S
	{
		char c1;
		int i;
		char c2;
	};
	printf("sizeof(struct S) = %d\n",sizeof(struct S)); // 12 
	return 0;
}






