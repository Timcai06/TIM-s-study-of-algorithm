#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
// 顺序表结点定义
typedef struct ListNode {
    int length;
    ElemType data[MAXSIZE];
}List;
/*顺序表的特点:查找更快，但是数据的读写效率相较于链表更低
             利用length达到类似数组下标的作用
    */
//初始化顺序表长度
void initList(List *L){
    L->length = 0;
}
//链尾增加元素
int appendElem(List *L,ElemType e){
    if (L->length >= MAXSIZE){
        printf ("顺序表满");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}
//插入元素
int insertList (List *L,int pos,ElemType e){
    if (L->length >= MAXSIZE){
        printf ("顺序表满");
        return 0;
    }
    if (pos <= L->length){
        //插入元素位置后面的所有元素向后移动一位
        for (int i = L->length - 1 ; i >= pos-1 ; i--){
            L->data[i+1] = L->data[i];
        }

        L->data[pos-1] = e;
        L->length ++;
    }
    return 1;
}
//删除元素
int deleteList (List *L,int pos,ElemType *e){
    *e = L->data[pos-1];
    if (pos < L->length){
        for (int i = pos ; i < L->length ; i++){
            L->data[i-1] = L->data[i];
        }
    }
    L->length--;
    return 1;
}
//遍历顺序表并输出(检验操作)
void listElem(List *L){
    for (int i = 0 ; i < L->length ; i++){
        printf ("%d ",L->data[i]);
    }
    printf ("\n");
    printf ("占用长度%d\n\n",L->length);
}
//查找顺序表元素(通过元素查找)
int findElem (List *L,ElemType e){
    for (int i = 0 ; i < L->length ; i++){
        if (L->data[i] == e) 
            return i+1;
    }
    return 0;
}
//测试函数
int main (){
    //声明一个顺序表并初始化
    struct ListNode List;
    initList(&List);
    printf ("占用长度%d\n\n",List.length);

    appendElem (&List,88);
    appendElem (&List,99);
    appendElem (&List,77);
    listElem(&List);

    insertList (&List,3,1234);
    listElem(&List);
    
    ElemType delData;
    deleteList (&List,2,&delData);
    listElem(&List);

    int pos = findElem(&List,1234);
    if (pos != 0){
        printf ("这个元素在此链表当中的位置是:第%d位",pos);
    }else {
        printf ("链表中不存在这个元素");
    }
    
    return 0;
}
