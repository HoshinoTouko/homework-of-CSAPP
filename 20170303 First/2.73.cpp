#include<stdio.h>

int saturating_add(int x, int y);
int w = 8*sizeof(int);
const int TMAX = (1 << w-1 >> w-1) ^ (1 << w-1);
const int TMIN = 1 << w-1;

int main(){
    int a, b;
    while(1){
        scanf("%d%d", &a, &b);
        printf("%d\n", saturating_add(a, b));
    } 

    return 0;
}

int saturating_add(int x, int y){
    unsigned xx = (unsigned) x;
    unsigned yy = (unsigned) y;
    unsigned temp = xx + yy;
    printf("%x, %x\n", (xx >> (w-1)), (yy >> (w-1)));
    if ((xx >> (w-1)) ^ (yy >> (w-1))){
        return (int)temp;
    }
    else if ((xx >> (w-1)) & (yy >> (w-1))){
        printf("%d\n", (temp >> (w-1)) ^ 1 );
        if ((temp >> (w-1)) ^ 1){
            //printf("TMIN: ");
            return TMIN;
        }
    }
    else{
        if (temp >> (w-1)){
            //printf("TMAX: ");
            return TMAX;
        }
    }
    return (int)temp;
    
}
