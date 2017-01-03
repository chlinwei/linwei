/*
   打地鼠游戏练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int times = 0/*游戏次数*/, mousey = 0/*老鼠所在行号*/, mousex = 0/*老鼠所在列号*/, posy = 0/*锤子所在行号*/, posx = 0/*锤子所在列号*/, hits = 0/*打中次数*/, missed = 0/*错过次数*/;
	int num = 0, row = 0, col = 0;
	srand(time(0));
	//获得游戏次数
	printf("请输入次数：");
	scanf("%d", &times);
	//打印地图
	printf("***\n***\n***\n");
	//游戏过程
	for (num = 1;num <= times;num++) {
		//获得老鼠和锤子的位置
        mousey = rand() % 3 + 1;
		mousex = rand() % 3 + 1;
		do {
		    printf("请输入锤子所在的位置：");
		    scanf("%d %d", &posy, &posx);
		} while (posy < 1 || posy > 3 || posx < 1 || posx > 3);
		//修改打中和错过的个数
		if (mousey == posy && mousex == posx) {
			hits++;
		}
		else {
			missed++;
		}
		//打印地图
        for (row = 1;row <= 3;row++) {
			for (col = 1;col <= 3;col++) {
				if (row == posy && col == posx) {
					printf("O");
				}
				else if (row == mousey && col == mousex) {
					printf("X");
				}
				else {
					printf("*");
				}
			}
			printf("\n");
		}
		//提示是否打中
		if (mousey == posy && mousex == posx) {
			printf("打中了\n");
		}
		else {
			printf("没打中\n");
		}
		//打印总成绩
		printf("打中%d次，错过%d次\n", hits, missed);
	}
	return 0;
}





