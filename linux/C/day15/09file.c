/*
   文件练习
   */
#include <stdio.h>
typedef struct {
	int id;
	float salary;
	char name[10];
} person;
int main() {
	person prn = {0};
	FILE *p_file = fopen("person.bin", "rb");
	if (p_file) {
		while (1) {
			if (!fread(&prn ,sizeof(person), 1, p_file)) {
				break;
			}
			printf("id是%d\n", prn.id);
			printf("工资是%g\n", prn.salary);
			printf("姓名是%s\n", prn.name);
		}
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}





