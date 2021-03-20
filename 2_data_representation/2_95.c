#include <stdio.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if(exp == 0xFF)
        return f;
    else
    {
        if(exp <= 1)
        {
            int tmp = sign << 31;

            if((frac & 3) == 3)
                tmp |= (frac >> 1) + 1;
            else
                tmp |= frac >> 1;
            
            if(exp)
            {
                if(frac == 0x7FFFFF)
                    return tmp << 1;
                else
                    return tmp | 0x400000;
            }
            else
                return tmp;
        }
        else
            return (sign << 31) | ((--exp) << 23) | frac;
    }
}

int main(void)
{
    for(float_bits f = 0, tmp; f <= 0xFFFFFFFF; f++)
    {
        tmp = float_half(f);
        if(((*(float *)&f) / 2.0F) != *(float *)&tmp)
        {
            // When f is 0x7F800001 (0 11111111 00000000000000000000001)
            printf("%#x\n", f);
            break;
        }
    }
    
    return 0;
}