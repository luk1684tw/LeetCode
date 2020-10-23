#include <stdio.h>

#define max(a, b) (((a) > (b))? (a) : (b))

int rob(int* nums, int numsSize)
{
    if (numsSize == 0) return 0;
    else if (numsSize == 1)
    {
        return nums[0];
    } else if (numsSize == 2)
    {
        return max(nums[0], nums[1]);
    }
    int sols[100] = {0};
    sols[0] = nums[0];
    sols[1] = max(nums[0], nums[1]);

    for (int i = 2; i < numsSize; i++) 
    {
        sols[i] = max(sols[i - 1], sols[i - 2] + nums[i]);
    }
    return sols[numsSize - 1];
}
int main(void)
{

    return 0;
}