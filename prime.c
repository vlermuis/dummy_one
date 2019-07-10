#include <stdio.h>

int is_it_prime_number(int num)
{
    int result = 1;
    int i = 0;
    for (i = 2; i < num; i++)
    {
        if ((num % i) == 0)
        {
            result = 0;
            break;
        }
    }
    return result;
}

void find_all_prime_numbers(int mnum)
{
    int i = 0;
    for (i = 2; i < mnum; i++)
    {
        if (is_it_prime_number(i))
        {
            printf("%d ,", i);
        }
    }
}
int main()
{
    printf(" is 6 prime number : %d\n", is_it_prime_number(6));
    printf("All prime numbers 1..9 : ");
    find_all_prime_numbers(9);
    printf("\n");
    return 0;
}