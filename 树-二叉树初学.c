#include <stdio.h>
#include <stdlib.h>
typedef char Elemtype;
typedef struct TreeNode{
    Elemtype data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;
typedef TreeNode* BiTree;
//前序遍历
void preOrder(BiTree T){
    if (T == NULL) return;
    printf("%c",T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}
//中序遍历
void inOrder(BiTree T){
    if (T == NULL) return;
    inOrder(T->lchild);
    printf("%c",T->data);
    inOrder(T->rchild);
}
//后序遍历
void postOrder(BiTree T){
    if (T == NULL) return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c",T->data);
}

//创建二叉树（从前序和中序序列）
BiTree createTree(char* pre, char* in, int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return NULL;
    BiTree root = (BiTree)malloc(sizeof(TreeNode));
    root->data = pre[preStart];
    root->lchild = root->rchild = NULL;
    int rootIndex = inStart;
    while (in[rootIndex] != pre[preStart]) rootIndex++;
    int leftLen = rootIndex - inStart;
    root->lchild = createTree(pre, in, preStart + 1, preStart + leftLen, inStart, rootIndex - 1);
    root->rchild = createTree(pre, in, preStart + leftLen + 1, preEnd, rootIndex + 1, inEnd);
    return root;
}
int main (){

    char pre[] = "ABDECFG";
    char in[] = "DBEAFGC";
    BiTree T = createTree(pre, in, 0, 6, 0, 6);
    printf("前序遍历: ");
    preOrder(T);
    printf("\n");
    printf("中序遍历: ");
    inOrder(T);
    printf("\n");
    printf("后序遍历: ");
    postOrder(T);
    printf("\n");
    return 0;
}
