#include "circle.h"

int main(void)
{
	int it = 0;
	printf("请输入一个半径：\n");
	scanf("%d",&it);
	printf("圆形的周长是：%lf,面积是：%lf\n",circle_length(it),circle_area(it));

	return 0;
}
