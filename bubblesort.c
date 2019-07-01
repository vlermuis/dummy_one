#include <stdio.h>

void bublesort(int* nums, int numSize)
{
    int i = 0;
    int bIsNotEnough = 1;
    while (bIsNotEnough)
    {
        bIsNotEnough = 0;
        for (i = 1; i < numSize; i++)
        {
            if (nums[i-1] > nums[i])
            {
                int temp  = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;
                bIsNotEnough = 1;
            }
        }
    }   
}

void display_array(int* nums, int numSize)
{
    int i = 0;
    for (i = 0; i < numSize; i++)
    {
        printf("%d, ", nums[i]);
    }
}
int test_case0[] = {9, 3, 14, 90, 23, 45, 1, 17};

int main()
{
    printf("Initial array: ");
    display_array(test_case0, 8);
    printf("\nSorted array : ");
    bublesort(test_case0, 8);
    display_array(test_case0, 8);
    printf("\n");
    return 0;
}