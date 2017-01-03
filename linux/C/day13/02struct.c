/*
   结构体演示
   */
#include <stdio.h>
/*struct person {
	int age;
	float height;
	char name[10];
};
typedef struct person person;*/
typedef struct /*person*/ {
	int age;
	float height;
	char name[10];
} person;
int main() {
    //struct person prn;   //结构体变量声明语句
	person prn1 = {20, 1.74f, "abc"}, prn2 = {0}, *p_prn = NULL;
	printf("请输入年龄：");
	scanf("%d", &(prn1.age));
	printf("请输入身高：");
	scanf("%g", &(prn1.height));
	scanf("%*[^\n]");
	scanf("%*c");
	printf("请输入姓名：");
	fgets(prn1.name, 10, stdin);
	printf("年龄是%d\n", prn1.age);
	printf("身高是%g\n", prn1.height);
	printf("姓名是%s\n", prn1.name);
	prn2 = prn1;
	printf("年龄是%d\n", prn2.age);
	printf("身高是%g\n", prn2.height);
	printf("姓名是%s\n", prn2.name);
	p_prn = &prn1;
	printf("年龄是%d\n", p_prn->age);
	printf("身高是%g\n", p_prn->height);
	printf("姓名是%s\n", p_prn->name);
	return 0;
}






