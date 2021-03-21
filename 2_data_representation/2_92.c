#include <stdio.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if((exp == 0xFF) && (frac != 0))
        return f;
    else
    {
        sign ^= 1;
        return (sign << 31) | (exp << 23) | frac;
    }
}

int main(void)
{
    for(long f = 0, tmp; f <= 0xFFFFFFFF; f++)
    {
        tmp = float_negate((float_bits)f);
        if(-*(float *)&f != *(float *)&tmp)
        {
            // When f is 0x7F800001 (0 11111111 00000000000000000000001)
            printf("%#x\n", f);
            break;
        }
    }
    
    return 0;
}