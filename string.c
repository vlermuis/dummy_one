#include <stdio.h>

#define MAX_STR_SIZE    (64)

void bublesort(char* nums, char numSize)
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
                char temp  = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;
                bIsNotEnough = 1;
            }
        }
    }   
}



int main()
{
    char* s0 = (char*)malloc(sizeof(char)*MAX_STR_SIZE);
    char* ps0 = NULL;

    sprintf(s0, "sawefjirokal");
    ps0 = s0;
    char c = ps0[5];
    int dc = c;
    printf("%c:%d\n", c, c);
    printf("dc : %d\n", dc);
    int sl = strlen(s0);
    printf("sl :%d\n", sl);
    printf("%s\n", s0);
/*_________________________________________*/
    bublesort(s0, sl);
    printf("%s\n", s0);
    
    free(s0);
    return 0;
}