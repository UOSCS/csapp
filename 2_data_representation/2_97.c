#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef unsigned float_bits;

int get_bit_length(int i)
{
    int length = 32;
    for(unsigned j = 0x80000000; j > 0; j >>= 1, length--)
        if(i & j)
            break;
    return length;
}

float_bits float_i2f(int i)
{
    unsigned sign = 0;
    unsigned exp = 0;
    unsigned bias = 127;
    int bit_len = 0;
    int tmp = 0, tmp_is_not_plus = 0;

    if(!i)
        return 0;
    if(i == INT_MIN)
    {
        sign = 1;
        exp = bias + 31;
        int frac = 0;
        return sign << 31 | exp << 23 | frac;
    }

    if((unsigned)i >> 31)
    {
        sign = 1;
        i = ~i + 1;
    }

    tmp = (bit_len = get_bit_length(i)) - 23;
    tmp <= 0 ? tmp_is_not_plus = 1 : tmp_is_not_plus;
    if(tmp_is_not_plus)
    {
        int bit_shift = abs(tmp) + 1;
        i <<= bit_shift;
        exp = bias + 23 - bit_shift;
    }
    else
    {
        int bit_shift = tmp - 1, flag = 0;
        if((((1 << bit_shift) & i) && (((1 << bit_shift) >> 1) & i)) || 
           (!((1 << bit_shift) & i) && ((1 << bit_shift) >> 1) < (i % (1 << bit_shift))))
            flag = 1;
        i >>= bit_shift;
        if(flag)
            i++;
        if(i & 0x1000000)
            bit_shift++;
        exp = bias + 23 + bit_shift;
    }
    i &= 0x7FFFFF;

    return sign << 31 | exp << 23 | i;
}

int main(void)
{
    for(long i = 0; i <= 0xFFFFFFFF; i++)
    {
        float_bits tmp = float_i2f((int)i);
        if((float)(int)i != *(float *)&tmp)
        {
            printf("%#x\n", i);
            return 0;
        }
    }
    printf("success!\n");
    
    return 0;
}