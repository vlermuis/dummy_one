#include <stdio.h>
/*
count a number of all bits
count a number of '1' bits
*/


int number_of_all_bits(int param)
{
    int result = 0;
    while(param)
    {
        result++;
        param = param >> 1;
    }
    return result;
}

int number_of_one_bits(int param, int num_of_bits)
{
    int result = 0;
    int mask = 0;
    int i = 0;
    for (i = 0; i < num_of_bits; i++)
    {
        mask = 1 << i;
        if ((param & mask) == mask)
        {
            result++;
        }
    }
    return result;
}

int main()
{
    int p0 = 5; // 0101b
    int p1 = 717; //‭001011001101‬b
    
    printf("%d : %d\n",p0, number_of_one_bits(p0, number_of_all_bits(p0)));
    printf("%d : %d\n",p1, number_of_one_bits(p1, number_of_all_bits(p1)));
    return 0;
}
