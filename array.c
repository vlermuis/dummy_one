/*
You are given two sorted arrays, A and B, where A has a large enough buffer at the
end to hold B. Write a method to merge B into A in sorted order.
*/

#include <stdio.h>
/* 1 solution, append and sort the result array */
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
void insert_in_one(int* arr1, int arr1Size, int* arr2, int arr2Size)
{
    int i = 0;
    for (i = 0; i < arr2Size; i++)
    {
        arr1[i+arr1Size] = arr2[i];
    }
    bublesort(arr1, arr1Size + arr2Size);
}
/************************************************************/

/*  2 solution, take element from the end of second array and insert in first one */
/*
void shift_array(int* arr, int size, int start_idx)
{
    int i = 0;
    for (i = size-1; i >=start_idx; i--)
    {
        arr[i+1] = arr[i];
    }
}

int get_idx_to_insert(int* arr, int arrSize, int target)
{
    int position = 0;
    int i = 0;
    for (i = arrSize; i > 0; i--)
    {
        if (target > arr[i])
        {
            return i+1;
        }
    }
    return position;
}

void insert_in_one2(int* arr1, int arr1Size, int* arr2, int arr2Size)
{
    int i = 0;
    for (i = arr2Size; i > 0; i--)
    {
        int pos = (arr1, arr1Size, arr2[i]);
        shift_array(arr1, arr1Size, pos);
        arr1Size++;
        arr1[pos] = arr2[i];
    }
}
*/

/************************************************************/
void display_array(int* nums, int numSize)
{
    int i = 0;
    for (i = 0; i < numSize; i++)
    {
        printf("%d, ", nums[i]);
    }
}

int a[] = {3, 6, 9, 10, 24, 35, 66, 0, 0, 0, 0, 0, 0, 0};

int b[] = {5, 10, 11, 35, 45, 59, 69};

//int a2[] = {3, 6, 9, 10, 24, 35, 66, 0, 0, 0, 0, 0, 0, 0};

//int b2[] = {5, 10, 11, 35, 45, 59, 69};

int main()
{
    /* 1 solution */
    insert_in_one(a, 7, b, 7);
    printf("Solution 1\nResult : ");
    display_array(a, 14);
    printf("\n");

//    printf("Solution2\nResult : ");
//    insert_in_one2(a2, 7, b2, 7);
//    display_array(a2, 14);
//    printf("\n");
    return 0;
}