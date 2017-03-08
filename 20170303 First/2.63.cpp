#include<stdio.h>

unsigned srl(unsigned x, int k);
int sra(int x, int k);
int main(){
    int a;
    scanf("%d", &a);
    int b = a;
    
    printf("Arithmetically(but logically) %x, %x\n", srl(a, 2), (unsigned)b>>2);
    printf("Logically(but arithmetically) %x, %x\n", sra(a, 2), (int) b>>2);
    
    return 0;
}

unsigned srl(unsigned x, int k){
    unsigned xsra = (int) x >> k;
    
    //Additional code
    int temp = 1 << (8*sizeof(int) - k - 1);
    if (temp & xsra){
        int i;
        for (i = 0; i < k; i++){
            temp <<= 1;
            xsra ^= temp;
        }
    }
    return xsra; 
}

int sra(int x, int k){
    int xsrl = (unsigned) x >> k;
    
    //Additional code
    int temp = 1 << (8*sizeof(int) - k - 1);
    if (temp & xsrl){
        int i;
        for (i = 0; i < k; i++){
            temp <<= 1;
            xsrl |= temp;
        }
    }
    return xsrl;    
}
