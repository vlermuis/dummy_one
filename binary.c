#include <stdio.h>
/*
Implementing binary search with recursion
*/


int sub_search(int* nums, int start, int end, int target)
{
    int cur;
    if (start <= end)
    {
        cur = (end - start)/2 + start;
        if (nums[cur] == target)
        {
            return cur;
        }
        else
        {
            if (nums[cur] > target)
            {/* looking in the left */

                return sub_search(nums, start, cur - 1, target);
            }
            else
            {/* looking in the right */
                return sub_search(nums, cur + 1, end, target);
            }
            
        }
    }
    
    return -1;
}

int binary_search(int* nums, int size, int target)
{
    int start = 0;
    int end = size;

    return sub_search(nums, start, end, target);
}

int test_case0[] = {2, 5, 9, 13, 27, 68, 99};

int main( int argc, char *argv[] )
{
    int p = atoi(argv[1]);
    printf("Searching for %d\n", p);
    int result = binary_search(test_case0, 7, p);
    printf ("result : %d\n", result);
    return 0;
}