#include<stdio.h>

typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum);

int main(){
    char testData[100];
    //scanf("%c", &testData);
    //scanf("%s", &testData);
    printf("%x\n", xbyte(0xA1A10101, 0));
    printf("%x\n", xbyte(0xA1A10101, 1));
    printf("%x\n", xbyte(0xA1A10101, 2));
    printf("%x\n", xbyte(0xA1A10101, 3));
    
    return 0;
}

int xbyte(packed_t word, int bytenum){
    int temp = (word << ((3 - bytenum) << 3));
    //printf("%x\n", temp);
    return temp >> 24;
}
