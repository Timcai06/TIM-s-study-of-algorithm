#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct node{
    ElemType data;//数据域
    struct node *next;//指针域
}Node;
//初始化链表
Node *initList(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;//初始化为一个带头节点的单链表，初始指针域直接指向NULL
    return head;
}
//头插法
int insertHead(Node *L,ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));//动态分配内存
    p->data = e;
    p->next = L->next;//把头节点的指针域(NULL)赋予新节点
    L->next = p;//头节点的指针域指向新节点
    return 1;
}
//遍历链表并输出元素
void listNode(Node *L){
    Node *p = L->next;
    while (p != NULL){
        printf ("%d ",p->data);
        p = p->next;
    }
    printf ("\n");
}
int main (){
    Node *list = initList();
    insertHead(list,10);
    listNode(list);

    insertHead(list,20);
    listNode(list);

    insertHead(list,30);
    listNode(list);
    return 0;
}
