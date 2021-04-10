#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int *base;
    int *top;
    int stacksize;//栈可用的最大容量
}Sqstack;

void InitStack(Sqstack &s)//建立一个空栈
{
    s.base=new int[MAXSIZE];
    if(!s.base)
        {
            printf("空间开辟失败");
            exit(0);
        }
    s.top=s.base;
    s.stacksize=MAXSIZE;
    printf("已建立空栈\n");
}

void Push(Sqstack &s,int e)//入栈
{
    if(s.top-s.base==s.stacksize)
        printf("此栈以满");
    else
        *s.top++=e;//元素e压入栈顶，栈顶指针加一
}

void Pop(Sqstack &s,int &e)//出栈
{
    if(s.base==s.top)
        printf("此栈为空");
    else
        {
            e=*--s.top;
            printf("%d ",e);
        }
}

void Gettop(Sqstack s)//获取栈顶元素
{
    int e;
    if(s.top==s.base)
        printf("此栈为空栈");
    else
        {
            e=*(s.top-1);
            printf("栈顶元素为：%d\n",e);
        }
}

void Clear(Sqstack &s)//清空栈
{
    s.base==s.top;
    printf("此栈已清空");
}

void Destory(Sqstack &s)//销毁栈
{
    free(s.base);
    s.top=s.base=NULL;
    s.stacksize=0;
    printf("此栈已销毁");
}

int main()
{
    Sqstack s;
    int e,i,flag=1;
    while(flag){
    printf("\n\n\t*****栈的操作*****\n\n");
    printf("\t  1 构造空栈      \n");
    printf("\t  2 入栈          \n");
    printf("\t  3 出栈          \n");
    printf("\t  4 清空栈        \n");
    printf("\t  5 销毁栈        \n");
    printf("\t  6 获取栈顶元素  \n");
    printf("\t  0 退出          \n");
    printf("请输入你选择的操作序号:");
    scanf("%d",&flag);
    switch(flag)
    {
        case 0:flag=0;break;
        case 1:printf("构造空栈\n");InitStack(s);break;
        case 2:printf("入栈\n");
               printf("请输入数据个数:");
               scanf("%d",&i);
               printf("请输入数据：");
               while(i!=0)
              {
                  scanf("%d",&e);
                  Push(s,e);
                  i--;
              }
              break;
        case 3:printf("出栈\n");
               while(!(s.top-s.base==0))Pop(s,e);break;
        case 4:Clear(s);break;
        case 5:Destory(s);break;
        case 6:Gettop(s);break;
    }
    }
    return 0;
}