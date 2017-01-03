/*
   动态分配内存作业
   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int id;
	char name[10];
	char date[10];
} student;
student *read(void) {
	student *p_student = malloc(sizeof(student));
	if (p_student) {
        printf("请输入编号：");
		scanf("%d", &(p_student->id));
		scanf("%*[^\n]");
		scanf("%*c");
		printf("请输入姓名：");
		fgets(p_student->name, 10, stdin);
		if (strlen(p_student->name) == 9 && p_student->name[8] != '\n') {
		    scanf("%*[^\n]");
		    scanf("%*c");
		}
		printf("请输入入学日期：");
		fgets(p_student->date, 10, stdin);
		if (strlen(p_student->date) == 9 && p_student->date[8] != '\n') {
		    scanf("%*[^\n]");
		    scanf("%*c");
		}
	}
	return p_student;
}
int main() {
    student *p_student = read();
	if (p_student) {
		printf("编号是%d\n", p_student->id);
		printf("姓名是%s\n", p_student->name);
		printf("入学日期是%s\n", p_student->date);
		free(p_student);
		p_student = NULL;
	}
	return 0;
}






