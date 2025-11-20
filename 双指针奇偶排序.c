#include <stdio.h>
#include <stdlib.h>
void swap (int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int left = 0;//左指针
    int right = numsSize - 1;//右指针
    
    while (left < right) {
        if (nums[left] % 2 == 1 && nums[right] % 2 == 0){
            swap(&nums[left], &nums[right]);
            left++;
            right--;
        } 
        else if (nums[left] % 2 == 0){
            left++;
        } 
        else if (nums[right] % 2 == 1){
            right--;
        }
    }
    
    *returnSize = numsSize;
    return nums;
}
//主函数(测试函数)
int main() {
    int numsSize;
    scanf ("%d",&numsSize);
    int nums[numsSize];
    for (int i = 0 ; i < numsSize ; i++){
        scanf ("%d",&nums[i]);
    }
    int returnSize;
    
    int* result = sortArrayByParity(nums, numsSize, &returnSize);
    
    printf("排序结果: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    return 0;
}