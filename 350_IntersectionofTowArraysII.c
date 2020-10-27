#include <stdio.h>

#define bigger (a, b) ((a) > (b))

void swap(int*s ,int i, int j)
{
    s[i] ^= s[j];
    s[j] ^= s[i];
    s[i] ^= s[j];
    return;
}

void printArr(int *nums, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return;
}

void qsort(int* nums, int start, int end)
{
    if(start < end)
    {
        int pivot = nums[start];
        int idx = start;
        for (int i = start + 1; i <= end; i++)
        {
            if (!bigger(nums[i], pivot))
            {
                swap(nums, i, idx++);
            }
        }
        swap(nums, start, idx);
        qsort(nums, start, idx - 1);
        qsort(nums, idx + 1, end);
    }
    return;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{

}