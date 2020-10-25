int findZero(int* nums, int numSize, int start)
{
    for (int i = start; i < numSize; i++)
    {
        if (nums[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

void printArr(int* nums, int numSize)
{
    for (int i = 0; i < numSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return;
}


void moveZeroes(int* nums, int numsSize)
{
    if (numsSize == 0) return;
    int idx = findZero(nums, numsSize, 0);
    
    if (idx == -1) return;
    for (int i = idx + 1; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[idx] = nums[i];
            nums[i] = 0;
            idx = findZero(nums, numsSize, idx + 1);
        }
        if (idx == -1)
            break;
    }
    return;
}