//链栈基本运算算法
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct linknode
{	
	ElemType data;				//数据域
	struct linknode *next;		//指针域
} LinkStNode;					//链栈类型
void InitStack(LinkStNode *&s)  //初始化栈
{
	s=(LinkStNode *)malloc(sizeof(LinkStNode));
	s->next=NULL;
}
void DestroyStack(LinkStNode *&s)  //销毁
{
	LinkStNode *p=s->next;
	while (p!=NULL)
	{	
		free(s);
		s=p;
		p=p->next;
	}
	free(s);	//s指向尾结点,释放其空间
}
bool StackEmpty(LinkStNode *s)  //判断栈空
{
	return(s->next==NULL);
}
void Push(LinkStNode *&s,ElemType e)  //入栈
{	LinkStNode *p;
	p=(LinkStNode *)malloc(sizeof(LinkStNode));
	p->data=e;				//新建元素e对应的结点p
	p->next=s->next;		//插入p结点作为开始结点
	s->next=p;
}
bool Pop(LinkStNode *&s,ElemType e)  //出栈
{	LinkStNode *p;
	if (s->next==NULL)		//栈空的情况
		return false;
	p=s->next;				//p指向开始结点
	e=p->data;
	s->next=p->next;		//删除p结点
	free(p);				//释放p结点
	return true;
}
bool GetTop(LinkStNode *s,ElemType e)    //获取栈顶
{	if (s->next==NULL)		//栈空的情况
		return false;
	e=s->next->data;
	return true;
}

int main()
{
	// 初始化栈
	LinkStNode *s;
	InitStack(*&s);
	printf("初始化链栈成功！\n\n");

	// 入栈操作 
	for (int j = 1; j <= 10; j++)
		Push(s, j);
	printf("入栈操作（0-10）!\n\n");

	// 出栈操作 
	ElemType e;
	Pop(s, e);
	printf("弹出的栈顶元素e=%d\n\n", e);

	// 获得栈顶元素
	GetTop(s, e);
	printf("栈顶元素 e=%d \n");

	// 判断是否为空栈
	printf("栈空否：%d(1:空 0:否)\n\n", StackEmpty(s));

	// 清空栈
	DestroyStack(s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n\n", StackEmpty(s));

	return 0;
}