#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int SElemtype;
typedef struct Node{
    SElemtype data;
    struct Node *next;
}StackNode,*LinkStack;

//初始化栈
int InitStack(LinkStack &S){
    S = new StackNode;
    S->next = NULL;
    return OK;
}

int DestroyStack(LinkStack &S){
    LinkStack p;
    while(S){
        p = S;
        S = S->next;
        delete p;
    }
    return OK;
}

//清空栈
void ClearStack(LinkStack S){
    LinkStack p,q;
    p = S->next;
    while(p){
        q = p->next;
        delete p;
        p = q;
    }
    S->next = NULL;//头指针指针域为空，空栈
}

//判断链栈是否为空
int StackEmply(LinkStack S){
    return(S->next==NULL);
}
//入栈操作
void PushStack(LinkStack S,SElemtype e){
    LinkStack p;
    p = new StackNode;
    p->data = e;
    p->next = S->next;
    S->next = p;
}

//出栈操作
int PopStack(LinkStack S,SElemtype &e){
    LinkStack p;
    if(StackEmply(S))
     return ERROR;
    p = S->next;
    e = p->data;
    S->next = p->next;
    delete p;
    return OK;
}

//取栈顶元素
int GetTop(LinkStack S,SElemtype e){
    LinkStack p;
    if(StackEmply(S))
        return ERROR;
    p = S->next;
    e = p->data;
    return OK;
}

//输出链栈
void DispStack(LinkStack S){
    LinkStack p = S->next;
    printf("链栈为：");
    if(StackEmply(S)){
        printf("栈空!\n");
        return;
    }
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

//显示菜单
void Showmenu(){
    printf("\n      ---链栈基本操作---     \n");
    printf("*******************************\n");
    printf("*       1、初始化链栈          *\n");
    printf("*       2、创建链栈            *\n");
    printf("*       3、入栈操作            *\n");
    printf("*       4、出栈操作            *\n");
    printf("*       5、取栈顶元素          *\n");
    printf("*       0、退出程序            *\n");
    printf("*******************************\n");
    printf("请选择菜单(0-5):");
}

void Stack(){
    int choice,m,e;
    SElemtype item;
    LinkStack S;
    int flag = 0;
    while(choice){
        Showmenu();
        scanf("%d",&choice);
        switch(c