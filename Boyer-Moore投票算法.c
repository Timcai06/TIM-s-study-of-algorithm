#include <stdio.h>
#include <stdbool.h>
/*核心思路:由于要找的元素是大于所有元素的一半的，碰到潜在的所求元素会count++
          反之count--，每次变换candidate也即从这一位元素开始向后判断
*/
int majorityElement(int *nums, int numsSize) {
    int candidate = nums[0];  // 候选元素
    int count = 1;           // 计数器
    
    // Boyer-Moore投票算法
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    return candidate;
}