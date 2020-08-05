#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    
    returnSize[0] = 1;
    returnSize[1] = 2;

    return NULL;
}

int main(void){
    int *test = (int*) malloc(sizeof(int) * 4), *ans;
    int target = 9;

    test[0] = 2;
    test[1] = 7;
    test[2] = 11;
    test[3] = 15;
    printf("aaa");
    twoSum(test, 4, target, ans);

    printf("fuck");
    printf("%d, %d", ans[0], ans[1]);
    free(ans);

    return 0;
}