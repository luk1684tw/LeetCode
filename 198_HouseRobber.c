#include <stdio.h>


#define bigger(a, b) ((a) > (b))

void swap(int*s ,int i, int j)
{
    if (i != j)
    {
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];   
    }
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

void qSort(int* nums, int start, int end)
{
    if(start < end)
    {
        int pivot = nums[start];
        int idx = start + 1;
        for (int i = start + 1; i <= end; i++)
        {
            if (!bigger(nums[i], pivot))
            {
                swap(nums, i, idx++);
            }
        }
        swap(nums, start, --idx);
        qSort(nums, start, idx - 1);
        qSort(nums, idx + 1, end);
    }
    return;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    qSort(nums1, 0, nums1Size - 1); 
    qSort(nums2, 0, nums2Size - 1);

    int len = (nums1Size > nums2Size)? nums2Size: nums1Size;

    int* ans = (int*) malloc(sizeof(int) * len);
    *returnSize = 0;
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] > nums2[j])
        {
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            ans[*returnSize] = nums1[i++];
            *returnSize += 1;
            j++;
        }
    }
    return ans;
}