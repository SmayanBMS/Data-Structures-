#include<stdio.h>
#include<stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            if (result[0] == -1) {
                result[0] = i;
            }
            result[1] = i;
        }
    }

    *returnSize = 2; 
    return result;
}

int main() {
    int a[] = {1, 2, 3, 3, 4};
    int b;
    int* result = searchRange(a, 5, 3, &b); 
    int i = 0;

    while (i < b) { 
        printf("%d ", result[i]);
        i++;
    }

    free(result); 
    return 0;
}
