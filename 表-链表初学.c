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
    p->next = L->next;//把头节点的指针域(NULL/原本的下一个节点)赋予新节点
    L->next = p;//头节点的指针域指向新节点
    return 1;
}
//获取尾节点的地址
Node *get_tail(Node *L){
    Node *p = L;
    while (p->next != NULL){
        p = p->next;
    }
    return p;
}
//尾插法
Node *insertTail(Node *tail,ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p; 
}
//指定位置插入数据
int insertNode(Node *L,int pos,ElemType e){
    Node *p = L;
    int i = 0;
    while (i < pos-1){
        p = p->next;
        i++;
        if (p == NULL){
            return 0;
        }
    }
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}
//删除特定位置节点
int deleteNode(Node *L,int pos){
    Node *p = L;
    int i = 0;
    while (i < pos-1){
        p = p->next;
        i++;
        if (p == NULL){
            return 0;
        }
    }
    if (p->next == NULL){
        printf ("要删除的位置错误\n");
        return 0;
    }

    Node *q = p->next;
    p->next = q->next;
    free(q);
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
    //头插法函数检验
    insertHead(list,10);
    listNode(list);
    insertHead(list,20);
    listNode(list);
    insertHead(list,30);
    listNode(list);
    //尾插法函数检验
    Node *tail = get_tail(list);
    tail = insertTail(tail,10);
    listNode(list);
    //指定位置插入函数检验
    insertNode(list,2,33);
    listNode(list);
    //删除节点函数检验
    deleteNode(list,3);
    listNode(list);

    return 0;
}
