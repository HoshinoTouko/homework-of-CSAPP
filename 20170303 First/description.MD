# The First Homework

by Touko (080)  
The source codes are under this folder.  
Thank you for checking my homework.  

## Questions:

### p89

- 2.63
- 2.71
- 2.72
- 2.73
- 2.77
- 2.81

## Answers:

### 2.63

#### Code is here:

```
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
```

### 2.71

#### A. Wrong:

如果byte变量的第一位为1，扩展成int类型的时候无法自动将前面的1补全使这个数为负数。

#### B. Code is here:

```
int xbyte(packed_t word, int bytenum){
    int temp = (word << ((3 - bytenum) << 3));
    return temp >> 24;
}
```

### 2.72

#### A. Wrong:

size_t本身是一个无符号变量，在进行比较运算的时候，会将maxbytes转换为无符号变量进行处理，并且以无符号变量的方式进行对比，这样会导致当size_t很小的时候，左式永远比右式大。

#### B. Code is here:

```
void copy_int(int val, void *buf, int maxbytes){
    if (maxbytes > 0 && maxbytes >= sizeof(val)){
        memcpy (buf, (void *) &val, sizeof(val));
    }
} 
```

### 2.73

#### Code is here:

```
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
```

### 2.77

#### Code is here:

```
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
```

### 2.81

#### A. Code is here:

```
int a = ~((1 << k) - 1);
```

#### B. Code is here:

```
int b = ((1 << k) - 1) << j;
```
