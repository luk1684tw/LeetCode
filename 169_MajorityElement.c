#include <stdio.h>

void swap(int* a, int *b)
{
    if (*a > *b) 
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    return;
}

void merge(int array[], int l, int m, int r)
{
    int L[m - l + 1], R[r - m];
    int x = m - l + 1, y = r - m;
    int i , j , k;
    for (i = 0; i < x; i++)
    {
        L[i] = array[l + i];
    }
    for (i = 0; i < y; i++) {
        R[i] = array[m + 1 + i];
    }
    i = 0, j = 0, k = l;
    while (i < x && j < y)
    {
        if (L[i] < R[j])
        {
            array[k++] = L[i++];
        }
        else
        {
            array[k++] = R[j++];
        }
    }
    while (i < x)
    {
        array[k++] = L[i++];
    }

    while (j < y)
    {
        array[k++] = R[j++];
    }
    return;
}

void printArray(int* nums, int numSize)
{
    for (int i = 0; i < numSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return;
}

void mergeSort(int array[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        merge(array, l, m, r);
    }
}

int majorityElement(int* nums, int numsSize)
{
    mergeSort(nums, 0, numsSize - 1);
    int num = nums[0], count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (num == nums[i])
        {
            count++;
        }
        else
        {
            if (count > numsSize / 2)
            {
                return num;
            }
            else
            {
                num = nums[i];
                count = 1;
            }
        }
    }
    return num;
}

int main(void) 
{
    int ans;
    int data[11] = {2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2};
    int numSize = 11;
    ans = majorityElement(data, numSize);

    printf("%d\n", ans);
    return 0;
}