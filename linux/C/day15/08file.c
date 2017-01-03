/*
   文件练习
   */
#include <stdio.h>
#include <string.h>
typedef struct {
	int id;
	float salary;
	char name[10];
} person;
int main() {
	int choice = 0;
	person prn = {0};
	FILE *p_file = fopen("person.bin", "ab");
	if (p_file) {
		while (1) {
            printf("请输入id:");
			scanf("%d", &(prn.id));
			printf("请输入工资：");
			scanf("%g", &(prn.salary));
			scanf("%*[^\n]");
			scanf("%*c");
			printf("请输入姓名：");
			fgets(prn.name, 10, stdin);
			if (strlen(prn.name) == 9 && prn.name[8] != '\n') {
				scanf("%*[^\n]");
				scanf("%*c");
			}
			fwrite(&prn, sizeof(person), 1, p_file);
			printf("是否继续输入？0表示不输入，1表示输入");
			scanf("%d", &choice);
			if (!choice) {
				break;
			}
		}
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}





