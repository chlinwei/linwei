#include <stdio.h>
int main(void){
    int a[10] = {1,2,34,232,54,56,32,4,565,10};
    for(int i=0;i<10;++i){
        int min = i;
        for(int j=i+1;j<10;++j){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if(min != i){
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
    for(int i=0;i<10;++i){
        printf("%d,",a[i]);
    }
    return 0;
}
