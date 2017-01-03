#include <string.h>
#include <stdio.h>

int main(void){
	char str[] = "a,b,c,d*e";
	const char* split = ",*";
	char* p;
	p = strtok(str,split);
	while(p!=NULL){
		printf("%s\n",p);
		p = strtok(NULL,split);
	}
	return 0;
}
