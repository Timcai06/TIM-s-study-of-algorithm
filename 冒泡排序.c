#include <stdio.h>
#include <stdbool.h>
/*冒泡排序基本逻辑:从第一个元素开始第一轮比较，若相邻的元素i大于元素i+1，则改变位置，
                反之，比较元素i+1和元素i+2，直到最后一个元素，接着从第二个元
                素开始第二轮比较，直到全部比较完毕 || 在一轮比较中没有出现任何
                元素位置的改变,排序结束.
*/

//————基础冒泡排序————
void bubbleSortBasic(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++){ //变量i指引需要比较的次数
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) { //变量j指引单次需要比较几个元素
            if (arr[j] > arr[j + 1]) {
                // 交换元素
                int temp = arr[j]; 
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // 如果本轮没有交换，说明数组已有序
        if (!swapped) break;
    }
}
//————递归版冒泡排序————
void bubbleSortRecursion(int *arr,unsigned int n){
    if (n < 2) return;
    int itmp;
    for (int i = 0 ; i < n-1 ; i++){
        if (arr[i] > arr[i+1]){
            itmp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = itmp;
        }
    }
    bubbleSortRecursion(arr,--n); //一轮排序后已经将最大/最小元素排在最后一个位置上
                               //所以无需加入排序队列
}
//————双向冒泡排序(鸡尾酒排序)————
void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    
    while (swapped) {
        swapped = false;
        
        // 从左到右扫描
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        end--;
        
        // 从右到左扫描
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        
        start++;
    }
}
//————主函数(测试)————
int main (){
    int arr[7] = {1,6,10,42,5,10002,2};
    cocktailSort(arr,7);
    for (int i = 0 ; i < 7 ; i++) printf("%d ",arr[i]);
    return 0;
}