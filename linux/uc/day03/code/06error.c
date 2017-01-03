//C语言中的错误表现形式
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//返回1 ~ 10之间的随机数
int rand_num(void)
{
	//1.设置随机种子
	srand(time(0));
	//2.生成随机数
	int num = rand() % 10 + 1;
	//3.判断是否合法
	if(5 == num)
	{
		return -1;//表示错误
	}
	return num;//返回具体的随机数
	//return 5 == num ? -1 : num;
	//return 5 == rand()%10+1 ? -1 : num;
	//return 5 == (srand(time(0)),rand()%10+1) ? -1 : num;
}

//返回两个int类型参数的最大值
int max_num(int ia,int ib,int* pi)
{
	// int ia = -1, ib = -2;
	// int* pi = &res;
	// int* pi;  pi = &res;
	if(ia == ib)
	{
		return -1;//表示出错
	}
	//*pi = *(&res)  = res ;
	*pi = ia > ib ? ia : ib;
	return 0;//表示函数正常结束
}

// 判断传入的字符串是否为"error"
char* judge_str(char* pc)
{
	if(!strcmp(pc,"error"))
	{
		return NULL;//表示错误
	}
	return "ok";
}

//打印传入的字符串
void print(char* pc)
{
	printf("%s\n",pc);
}

int main(void)
{
	printf("生成的随机数是：%d\n",rand_num());
	
	int res = 0;
	if(0 == max_num(-1,-2,&res))
	{
		printf("最大值是：%d\n",res);
	}

	printf("%s\n",judge_str("GoodMorning"));
	
	print("Good Good Study,Day Day Up!");
	return 0;
}













