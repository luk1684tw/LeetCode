void swap(int* nums, int i, int j) {
    if (i != j) {
        nums[i] ^= nums[j];
        nums[j] ^= nums[i];
        nums[i] ^= nums[j];
    }
    return;
}

void sortColors(int* nums, int numsSize){
    if (numsSize == 1) return;

    for (int i = 1; i < numsSize; i++) {
        int j = i;
        while (j > 0 && nums[j - 1] > nums[j]) {
            swap(nums, j, j - 1);
            j--;
        }
    }
    return;
}