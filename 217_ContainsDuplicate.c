// void swap(int* nums, int i, int j)
// {
//     nums[i] ^= nums[j];
//     nums[j] ^= nums[i];
//     nums[i] ^= nums[j];
//     return;
// }

// void printArr(int *nums, int numSize)
// {
//     for (int i = 0; i < numSize; i++)
//     {
//         printf("%d ", nums[i]);
//     }
//     return;
// }

// int swapHeap(int* nums, int numSize, int i)
// {
//     int left, right;
//     if (2 * i + 1 < numSize)
//         left = nums[2 * i + 1];
//     else
//         left = nums[i];
    
//     if (2 * i + 2 < numSize)
//         right = nums[2 * i + 2];
//     else
//         right = nums[i];

//     if (nums[i] < left || nums[i] < right)
//     {
//         if (left >= right)
//         {
//             swap(nums, i, 2 * i + 1);
//             return 1;
//         }
//         else
//         {
//             swap(nums, i, 2 * i + 2);
//             return 2;
//         }
//     }
//     return 0;
// }


// void heapify(int* nums, int numSize)
// {
//     for (int i = numSize / 2 - 1; i >= 0; i--)
//     {
//         int tmp = swapHeap(nums, numSize, i);
//     }
//     return;
// }


// void heapSort(int* nums, int numSize)
// {
//     heapify(nums, numSize);
//     for (int i = 0; i < numSize - 1; i++)
//     {
//         swap(nums, 0, numSize - 1 - i);
//         int index = 0;
//         int result = swapHeap(nums, numSize - 1 - i, index);
//         while(result)
//         {
//             index = index * 2 + result;
//             result = swapHeap(nums, numSize - 1 - i, index);
//         }
//         printArr(nums, numSize);
//         printf("\n");
//     }
//     return;
// }

// TLE with HeapSort

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

bool containsDuplicate(int* nums, int numsSize)
{
    mergeSort(nums, 0, numsSize - 1);
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i - 1] == nums[i])
            return true;
    }
    return false;
}