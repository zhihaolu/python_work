#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 30
 
typedef char ElemType;
typedef struct TNode *BiTree;
 
 
 
struct TNode {
	char data;
	BiTree lchild; 
	BiTree rchild;
};
 
 
int IsEmpty_BiTree(BiTree *T) {
	if(*T == NULL)
	return 1;
	else
	return 0;
}
 
void Create_BiTree(BiTree *T){
    char ch;
    ch = getchar();
    //当输入的是"#"时，认为该子树为空
    if(ch == '#')
        *T = NULL;
    //创建树结点
    else{
        *T = (BiTree)malloc(sizeof(struct TNode));
        (*T)->data = ch; //生成树结点
        //生成左子树
        Create_BiTree(&(*T)->lchild);
        //生成右子树
        Create_BiTree(&(*T)->rchild);
    }
}
 
void TraverseBiTree(BiTree T) {	//先序遍历 
	if(T == NULL)
	return; 
	else {
		printf("%c ",T->data);
		TraverseBiTree(T->lchild);
		TraverseBiTree(T->rchild);
	}
	
}
 
void InOrderBiTree(BiTree T) {		//中序遍历 
	if(NULL == T)
	return;
	else {
		InOrderBiTree(T->lchild);
		printf("%c ",T->data);
		InOrderBiTree(T->rchild);	
	}
}
 
void PostOrderBiTree(BiTree T) {
	if(NULL == T)
	return;
	else {
		InOrderBiTree(T->lchild);
		InOrderBiTree(T->rchild);
		printf("%c ",T->data);
	}
	
} 
 
int TreeDeep(BiTree T) {
	int deep = 0;
	if(T)
	{
		int leftdeep = TreeDeep(T->lchild);
		int rightdeep = TreeDeep(T->rchild);
		deep = leftdeep+1 > rightdeep+1 ? leftdeep+1 : rightdeep+1; 
	}
	return deep;
}
 
int Leafcount(BiTree T, int &num) {
	if(T)
	{
		if(T->lchild ==NULL && T->rchild==NULL)	
		{
			num++;
			printf("%c ",T->data);
		}			
		Leafcount(T->lchild,num);
		Leafcount(T->rchild,num);
 
	}
	return num;
}

 
int main(void)
{
    printf("请输入二叉树：");
	BiTree T;
	BiTree *p = (BiTree*)malloc(sizeof(BiTree));
	int deepth,num=0 ;
	Create_BiTree(&T);
	printf("先序遍历二叉树:\n");
	TraverseBiTree(T);
	printf("\n");
	printf("中序遍历二叉树:\n");
	InOrderBiTree(T);
	printf("\n");
	printf("后序遍历二叉树:\n");
	PostOrderBiTree(T);
	deepth=TreeDeep(T);
	printf("树的深度为:%d",deepth);
	printf("\n");
	printf("树的叶子结点为:");
	Leafcount(T,num);
	printf("\\n树的叶子结点个数为:%d",num);
	return 0;
}
