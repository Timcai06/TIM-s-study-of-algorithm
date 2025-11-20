#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node *next;
} Node;

Node *initList(void) {
    Node *h = malloc(sizeof *h);
    if (!h) return NULL;
    h->data = 0;
    h->next = NULL;
    return h;
}

Node *get_tail(Node *L) {
    Node *p = L;
    while (p->next) p = p->next;
    return p;
}

Node *insertTail(Node *tail, ElemType e) {
    if (!tail) return NULL;
    Node *p = malloc(sizeof *p);
    if (!p) return NULL;
    p->data = e;
    p->next = NULL;
    tail->next = p;
    return p;
}

void listNode(Node *L) {
    for (Node *p = L->next; p != NULL; p = p->next) printf("%d ", p->data);
    printf("\n");
}

// 查找倒数第 k 个节点（k 从 1 开始），返回节点指针，找不到返回 NULL
Node *find_kth_from_end(Node *head, int k) {
    if (!head || k <= 0) return NULL;
    Node *fast = head->next;
    Node *slow = head->next;
    for (int i = 0; i < k; ++i) {
        if (fast == NULL) return NULL; // k 大于长度
        fast = fast->next;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(void) {
    Node *list = initList();
    if (!list) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    int n = 0;
    printf("请输入要读入的数据个数 n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "无效的 n\n");
        return 1;
    }
    int ch = getchar(); while (ch != '\n' && ch != EOF) ch = getchar();

    Node *tail = get_tail(list);
    printf("请输入 %d 个整数（可以多行输入，每个用空格或换行分隔）：\n", n);
    for (int i = 0; i < n; ++i) {
        int v;
        if (scanf("%d", &v) != 1) {
            fprintf(stderr, "输入不足或格式错误\n");
            return 1;
        }
        Node *newtail = insertTail(tail, v);
        if (newtail) tail = newtail;
    }

    listNode(list);

    int k = 0;
    printf("请输入 k（查找倒数第 k 个元素，k 从 1 开始）: ");
    if (scanf("%d", &k) != 1) {
        fprintf(stderr, "读取 k 失败\n");
        return 1;
    }
    Node *res = find_kth_from_end(list, k);
    if (!res) {
        printf("无效的 k（超过链表长度或 k<=0）\n");
    } else {
        printf("倒数第 %d 个元素是: %d\n", k, res->data);
    }

    return 0;
}
