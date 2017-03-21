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
- 2.88
- 2.89
- 2.90

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

### 2.88

|               |          |               |          |
| :----------   | :------- | :------------ | :------- |  
| 1 01110 001   | -9/16    | 1 0110 0010   | -9/16    |  
| 0 10110 101   | 208      | 1 1110 1010   | 208      |  
| 1 00111 110   | -7/1024  | 1 0000 0111   | -7/1024  |   
| 0 00000 101   | 3/2^16   | 1 1111 0000   | 0        |  
| 1 11011 000   | -4096    | 1 1111 0000   | -inf     |  
| 0 11000 100   | 768      | 0 1111 0000   | inf      |  
 

### 2.89

#### A.  

False.
Float变量不能表示TMax，而double可以。

#### B.  

False.
如果x-y越界，右边越界，左边不会越界

#### C.

True.
double足够表示2^63以内的整数，不会导致溢出

#### D.

False.
double只能表示2^63以内的整数，只要原数足够大，就会导致溢出

#### E.

False.
0.0/0.0 = NaN，C/0.0 = inf

### 2.90

#### Code is here.
```
float fpwr2(int x){
    unsigned exp, frac;
    unsigned u;
    
    if (x < -149){
        exp = 0;
        frac = 0;
    }
    else if (x < -125){
        exp = 0;
        frac = 1<<x+149;
    }
    else if (x < 127){
        exp = x + 127;
        frac = 0;
    }
    else {
        exp = 255;
        frac = 0;
    }
    
    u = exp<<23 | frac;
    return u2f(u);
}
```

#### 分析：

k=8, n=23  
bias = 2^7 - 1 = 127  
最小非规格化数（正数）
2^(1-n-bias) = 2^-149  
最小规格化数（正数）  
2^(0-bias) = 2^-126  
最大规格化数  
2^(256-2-bias) = 2^127  
所以x可以分成以下区块  

- TMin ~ -149
- -149 ~ -126
- -126 ~ 127
- 127 ~ TMax

