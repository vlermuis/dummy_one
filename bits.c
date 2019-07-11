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

/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method
to insert Minto N such that M starts at bit j and ends at bit i. You can assume that the bits j through
i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5
bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully
fit between bit 3 and bit 2.
EXAMPLE
Input: N
Output: N
SOLUTION
10000000000, M
10001001100
10011, i = 2, j = 6
*/

int insert_to(int dest, int insert, int i, int j)
{
    
    int allones = ~0;
    int left = allones << (j+1);

    int right = ((1 << i) - 1);

    int mask = left | right;

    insert = insert << i;

    mask = mask | insert;

    dest = dest & mask;
    dest = dest | insert;

    return dest;
}

/*
 reverse bits
 10111001 into 10111001
*/
int reverse_bits(int c)
{
    int result = 1;
    int mask = 0;
    int mask2 = 0;
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        mask = (c & (1 << i)); 
        mask = 1 << i;
        if (c & mask)
        {/*1*/
            mask2 = (1 << 7 - i);
            result |= mask2;
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


    printf(" Insert result : %d\n", insert_to(1024, 19, 2, 6));

    printf("reverse bits from 157 is : %d\n", reverse_bits(157));

    return 0;
}
