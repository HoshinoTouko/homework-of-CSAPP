#include<stdio.h>

int main(){
    int j = 1;
    int k = 1;
    int a = ~((1 << k) - 1);
    int b = ((1 << k) - 1) << j;
    
    
    return 0;
}
