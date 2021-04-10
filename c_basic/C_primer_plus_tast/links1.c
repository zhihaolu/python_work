//1.单链表 
#include <stdio.h>  
#include <stdlib.h>  

typedef struct LNode 
{
    int data;
    struct LNode* next;
}LNode, * LinkList;

LinkList head, k;


void CreateHead(LinkList L)//头插法创建单链表 
{
    head = (LinkList)malloc(sizeof(LNode));  
    head->next = NULL;  
    head->data = NULL;  //建立一个带头结点的空链表
    LinkList p, t;
    int x;
    t = head;
    printf("请输入数值，以0结束\n");
    while (~scanf("%d", &x), x)
    {
        p = (LinkList)malloc(sizeof(LNode));  //生成新结点作为头结点，用头指针*p指向头结点
        p->data = x;
        p->next = t->next;
        t->next = p;    //将新结点*p插入到头结点之后
    }
}


void Show(LinkList t)//输出数据元素
{
    printf("当前链表元素为：");
    t = t->next;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int Insert(LinkList L, int i, int e)//插入 
{
    LinkList t, p;
    int j = 0;
    t = head;
    if (i < 1) { printf("插入错误\n"); return 0; }
    
    while (j < i - 1 && L)
    {
        t = t->next;
        j++;
        if (!t || j>i-1)  //i>n+1 或 i<1
        {
            printf("插入错误\n");
            return 0;
        }
    }
     
    p = (LinkList)malloc(sizeof(LNode)); //生成新结点
    p->data = e;  //将*p的数据域置为e
    p->next = t->next;  //将结点*p的指针域指向结点ai
    t->next = p;  //将结点*t的指针域指向结点*p
    printf("插入成功\n");
}

int Delete(LinkList L, int i)//删除 
{
    LinkList p, t;
    int j = 0;
    p = head;
    if (i < 1) { printf("删除失败\n"); return 0; } //位置不合法则删除失败
    while (j < i - 1 && L)
    {
        p = p->next;
        j++;  //查找第i-1个结点，p指向该节点
        if (p == NULL||j>i-1)  // i>n 或者 i<1,删除位置不合理
        {
            printf("删除失败\n");
            return 0;
        }
    }
    t = p->next;  //临时保存被删结点的地址以备释放
    p->next = t->next;  //改变删除结点前驱结点的指针域
    printf("删除成功\n");
    free(t);  //释放删除结点的空间
}

int Secrch(LinkList L, int i)//按位置查找
{
    LinkList p;
    int j = 0, e;
    p = head;
    if (i < 1) { printf("查找失败，该元素不存在\n"); return 0; }
    while (j < i && L)
    {
        p = p->next;  //p指向下一个结点
        j++;  //计数器j加1
        if (p == NULL||j>i)  //i值不合法
        {
            printf("查找失败，该元素不存在\n");
            return 0;
        }
    }
    e = p->data; //取第i个结点的数据域
    printf("查找成功，第%d个元素为%d\n", i, e);
}


    

int main()
{
    LinkList L;
    int select, i, e;
    while (1)
    {
        printf("1.头插法建表 \t2.插入 \t3.删除 \t4.查找 \n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            CreateHead(&L);
            Show(head);
            break;
        
        case 2:
            printf("输入位置和要插入的元素\n");
            scanf_s("%d%d", &i, &e);
            Insert(&L, i, e);
            Show(head);
            break;
        case 3:
            printf("输入要删除的元素的位置\n");
            scanf_s("%d", &i);
            Delete(&L, i);
            Show(head);
            break;
        case 4:
            printf("输入要查找的元素的位置\n");
            scanf_s("%d", &i);
            Secrch(&L, i);
            break;      
        }
    }
    return 0;
}