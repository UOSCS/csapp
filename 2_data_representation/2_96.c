#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

int float_f2i(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned bias = 127;

    if(exp < bias)
        return 0;
    else if(exp > bias + 30)
        return 0x80000000;
    else
    {
        int tmp = exp - bias - 23;
        frac |= 0x800000;
        if(!sign)
            return (tmp < 0 ? frac >> abs(tmp) : frac << tmp);
        else
        {
            tmp < 0 ? (frac >>= abs(tmp)) + 1 : (frac <<= tmp);
            return ~(frac) + 1;
        }
    }
}

int main(void)
{
    for(float_bits f = 0; f <= 0xFF800001; f++)
    {
        int tmp = float_f2i(f);
        if((int)*(float *)&f != tmp)
        {
            printf("%#x\n", f);
            return 0;
        }
    }
    printf("success!\n");
    
    return 0;
}