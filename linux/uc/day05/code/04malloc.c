//使用malloc函数申请动态内存的注意事项
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// 指针指向堆区   指针本身在栈区
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	int* p3 = (int*)malloc(sizeof(int));
	int* p4 = (int*)malloc(sizeof(int));
	int* p5 = (int*)malloc(sizeof(int));
	printf("p1 = %p, p2 = %p, p3 = %p, p4 = %p, p5 = %p\n",p1,p2,p3,p4,p5);

	printf("--------------------------\n");
	*p1 = 1;
	//*(p1+1) = 2;
	//*(p1+2) = 3;
	//*(p1+3) = 4;
	*(p1+4) = 5;
	printf("*p1 = %d\n",*p1); // 1
	//释放第一块动态内存
	free(p1);
	printf("*p2 = %d\n",*p2); // 5
	return 0;
}











