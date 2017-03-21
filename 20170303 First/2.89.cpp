#include<stdio.h>
#include<stdlib.h>

int main(){
    int x = rand();
    int y = rand();
    int z = rand();
    
    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;
    
    int a = (float)x == (float)dx;
    int b = ((dx-dy) == (double)(x-y));
    int c = (((dx+dy) + dz) == (dx + (dy+dz)));
    int d = ((dx*dy) * dz) == (dx * (dy*dz));
    int e = dx/dx == dz/dz;
    
    printf("%d %d %d %d %d", a, b, c, d, e);
    
    return 0;
}
