#include <stdio.h>
/*选择排序的基本逻辑:定义第一个元素为变量min，从第一个元素开始向后查找，若有元素小于
                  min，则此元素赋值给变量min，并记住此元素的位置，当第一轮查找完
                  后，将值为min的元素与第一个交换，再从第二个元素开始同样的查找，
                  最后得到一个升幂排序的数列. 
*/

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}  
//————基础选择排序(迭代思路)—————
void selectSortIterative(int *arr, unsigned int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_pos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_pos]) {
                min_pos = j;
            }
        }
        if (min_pos != i) {
            swap(&arr[i], &arr[min_pos]);
        }
    }
}
//————基础查找排序(递归思路)————
void selectSortRecursion(int *arr,unsigned int n){
    // 递归终止条件：当数组长度小于等于1时不需要排序
    if (n <= 1) {
        return;
    }

    int min_pos = 0;
    for (int i = 1 ; i < n ; i++){ //找出更小的的元素，并记住他们的位置
        if (arr[i] < arr[min_pos]) min_pos = i;
    }
    //如果这一轮的查找得到的最小元素，不是起始位置的元素，则交换他们的位置
    if (min_pos != 0) swap(&arr[0],&arr[min_pos]);

    selectSortRecursion(arr+1,--n);
}           
//————主函数(测试)————
int main(){
    int arr[5] = {2,10,4,15,1};
    selectSortRecursion(arr,5);
    int brr[4] = {1,10,2,19};
    selectSortIterative(brr,4);

    for (int i = 0 ; i < 5 ; i++){
        printf ("%d ",arr[i]);    
    }
    printf ("\n");
    for (int i = 0 ; i < 4 ; i++){
        printf ("%d ",brr[i]);
    }
    return 0;
}
