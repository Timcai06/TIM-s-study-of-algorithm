#include <stdio.h>
#include <stdlib.h>
/*插入排序的基本逻辑:通过构建有序序列，对于未排序的数据，在已排序的
                  序列中，从后向前扫描，找到相应的位置，并插入.
*/

//————插入排序————
void insertSortBasic (int *arr,unsigned int n){
    if (n < 2) return;
   
    int itmp; //当前需要排序的元素的值
    
    for (int i = 1 ; i < n ; i++){
        itmp =  arr[i]; //对元素i进行排序，也即插入到已经建立的有序数列里
        int j = i-1; //插入使需要后移元素的计数器
        
        //从有序数列的最右边开始，与元素i进行比较，对大于元素i的元素向后移一位
        while (j >= 0 && arr[j] > itmp) {
            arr[j + 1] = arr[j];  // 将大于itmp的元素后移
            j--;
        }
        
        arr[j+1] = itmp;
    }
}
//————二分查找优化版插入排序————
int binarySearch(int arr[], int key, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid + 1;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
void insertSortBinary(int *arr, unsigned int n) {
    if (n < 2) return;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int pos = binarySearch(arr, key, 0, i - 1);
        
        // 移动元素
        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = key;
    }
}
//————主函数(测试)————
int main (){
    /*
    int arr[5] = {1,10,4,8,19};
    insertSortBasic (arr,5);
    for (int i = 0 ; i < 5 ; i++){
        printf ("%d ",arr[i]);
    }
    */
    int n = 0;
    scanf ("%d",&n);
    int brr[n];
    for (int i = 0 ; i < n ; i++){
        scanf ("%d",&brr[i]);
    }
    insertSortBinary(brr,n);
    for (int i = 0 ; i < n ; i++){
        printf ("%d ",brr[i]);
    }

    return 0;
}