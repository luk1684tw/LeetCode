#include <math.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = (int)pow(2, numsSize);
    int** ans = (int**) malloc(*returnSize * sizeof(int*));
    *returnColumnSizes = (int*) malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        int size = 0;
        ans[i] = (int*) malloc(numsSize * sizeof(int));
        int j = i, index = 0;
        while (j != 0) {
            if (j % 2 == 1) {
                ans[i][size++] = nums[index];
            }
            index++;
            j >>= 1;       
        }
        (*returnColumnSizes)[i] = size;
    }
    return ans;
}