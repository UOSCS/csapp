#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if((exp == 0xFF) && (frac != 0))
        return f;
    else
        return (exp << 23) | frac;
}

int main(void)
{
    for(float_bits f = 0, tmp; f <= 0xFFFFFFFF; f++)
    {
        tmp = float_absval(f);
        if(fabs(*(float *)&f) != *(float *)&tmp)
        {
            // When f is 0x7F800001 (0 11111111 00000000000000000000001)
            printf("%#x\n", f);
            break;
        }
    }
    
    return 0;
}