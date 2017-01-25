#ifndef ALGO_SHUFFLE_H
#define ALGO_SHUFFLE_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//把一个数组中的元素顺序打乱
namespace alg{
	template<typename T>
		static void shuffle(T* list,int len){
			srand(time(NULL));
			int i = len,j;
			T temp;
			if(i==0)return;
			while(--i){
				j = rand()%(i+1);
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
};
#endif
