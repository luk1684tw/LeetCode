#include <math.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = pow(2, numsSize);
    int** ans = (int**) malloc(*returnSize * sizeof(int*));
    returnColumnSizes = (int**) malloc(*returnSize * sizeof(int*));
    for (int i = 0; i < *returnSize; i++) {
        printf("%d\n", i);
        int size = 0;
        ans[i] = (int*) malloc(numsSize * sizeof(int));
        int j = i, index = 0;
        while (j != 0) {
            if (j % 2) {
                ans[i][size++] = nums[index];
            }
            index++;
            j >>= 1;       
        }
        returnColumnSizes[i] = (int*) malloc(sizeof(int));
        returnColumnSizes[i][0] = size;
        if (size == 0) {
            free(ans[i]);
            ans[i] = NULL;
        }
    }

    for (int i = 0; i < *returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i][0]; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return ans;
}