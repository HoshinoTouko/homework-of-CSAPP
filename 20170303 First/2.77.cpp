#include<stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    
    int a[4];
    a[0] = (x << 4) + x;
    a[1] = x - (x << 3);
    a[2] = (x << 6) - (x << 2);
    a[3] = (x << 4) - (x << 7);
    for (int i = 0; i < 4; i++){
        printf("%d\n", a[i]);
    }
    
    return 0;
}
