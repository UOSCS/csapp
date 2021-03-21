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
        tmp < 0 ? frac >>= abs(tmp) : (frac <<= tmp);

        return sign ? ~(frac) + 1 : frac;
    }
}

int main(void)
{
    for(long f = 0; f <= 0xFFFFFFFF; f++)
    {
        int tmp = float_f2i((float_bits)f);
        if((int)*(float *)&f != tmp)
        {
            printf("%#x\n", f);
            return 0;
        }
    }
    printf("success!\n");
    
    return 0;
}