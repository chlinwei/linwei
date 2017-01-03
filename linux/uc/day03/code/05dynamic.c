//共享库的动态加载
#include <stdio.h>
#include <dlfcn.h>

int main(void)
{
	//1.加载共享库，使用dlopen函数
	void* handle = dlopen("./add_shared/libadd.so",RTLD_NOW);
	//2.判断加载是否失败，打印失败原因
	// if(2 == num)
	if(NULL == handle)
	{
		printf("dlopen:%s\n",dlerror());
		return -1;//结束当前函数
	}
	//3.获取共享库中指定函数的地址
	int (*p_add_int)(int,int);
	p_add_int = dlsym(handle,"add_int");
	//4.判断获取是否失败，打印失败原因
	if(NULL == p_add_int)
	{
		printf("dlsym:%s\n",dlerror());
		return -1;
	}
	//5.调用函数
	int res = p_add_int(50,30);
	printf("res = %d\n",res);
	//6.卸载共享库，使用dlclose函数
	res = dlclose(handle);
	//7.判断卸载是否失败，打印失败原因
	if(0 != res)
	{
		printf("dlclose:%s\n",dlerror());
		return -1;
	}
	return 0;
}








