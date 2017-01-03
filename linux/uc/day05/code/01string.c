//存放常量字符串的不同形式之间的比较
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	// pc指向只读常量区 pc本身在栈区
	char* pc = "hello";
	// pc指向栈区   ps本身在栈区 
	char ps[] = "hello";
	
	printf("pc = %p,&pc = %p\n",pc,&pc);
	printf("ps = %p,&ps = %p\n",ps,&ps);	
	printf("-------------------------\n");
	// 试图改变指向
	pc = "word";
	// 数组名是个常量，不可改变
	//ps = "word";  error

	//试图改变指向的内容
	//strcpy(pc,"1234"); error
	strcpy(ps,"1234");

	printf("-------------------------\n");
	pc = (char*)malloc(sizeof(char)*10);
	// 改变指针指向的内容
	strcpy(pc,"hello");
	char* pt = pc;
	// 改变指针的指向
	pc = "1234";
	free(pt);
	pt = NULL;
	return 0;
}












