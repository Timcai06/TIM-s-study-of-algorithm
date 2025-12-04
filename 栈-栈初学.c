#include <stdio.h>
#define MAXSIZE 100
typedef int Elemtype;

typedef struct {
    Elemtype data[MAXSIZE];
    int top;
}Stack;

void initStack(Stack *s){
    s->top = -1;
}
//判断是否为空
int isEmpty(Stack *s){
    if (s->top == -1){
        printf ("空的\n");
        return 1;
    }
    else {
        return 0;
    }
}
//进栈操作
int push(Stack *s,Elemtype e){
    if (s->top >= MAXSIZE-1){
        printf ("满了\n");
        return 0;
    }
    s->top++;//第一次入栈时s->top自增为0，后续可视为数组下标
    s->data[s->top] = e;
    return 1;
}
//出栈操作
Elemtype pop(Stack *s,Elemtype *e){
    if (s->top == -1){
        printf ("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}
//获取栈顶元素
int getTop(Stack *s,Elemtype *e){
    if (s->top == -1){
        printf ("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

int main (){
    Stack s;
    initStack(&s);
    push(&s,10);
    push(&s,20);
    Elemtype e;
    pop(&s,&e);
    printf("%d\n",e);
    getTop(&s,&e);
    printf("%d\n",e);

    push(&s,101);
    getTop(&s,&e);
    printf("%d\n",e);

    return 0;
}
