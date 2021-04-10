#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 typedef struct{
 	int weight;
 	int parent,lchild,rchild;
 }HTNode,*HuffmanTree;
 
void Select(HuffmanTree HT,int m,int &s1,int &s2) //从这m个数里边选择最小的2个//把第一个进行标记就ok
{ int i;                                           //从下标为1的位置开始计数
  //int min=HT[1].weight;这里直接赋值不合理，假如第一次那个1就是最小被选选中，那么第2次还是被选中
  int min1=1000;                                  
  int min2=1000;                                 //规定一个特别大的数

for(i=1;i<=m;i++)
 { if(HT[i].parent==0 && min1>HT[i].weight)
  { min1=HT[i].weight;
    s1=i;
  }
 }
 
for(i=1;i<=m;i++)                            //注意这个i!=s1标记min
 { if(i!=s1 && HT[i].parent==0)
  if(HT[i].weight<min2)
  { min2=HT[i].weight;
    s2=i;
  }
 }
}

void CreateHuffmanTree(HuffmanTree &HT,int n)   //构造哈夫曼树 
 { if(n<=1)
   return;
   int m,i;
   m=2*n-1;
   HT=new HTNode[m+1];
   for(i=1;i<=m;++i)
  { HT[i].parent=0;HT[i].lchild=0;HT[i].rchild=0;}
for(i=1;i<=n;++i)
 { scanf("%d",&HT[i].weight);}
 
for(i=n+1;i<=m;++i)
 { int s1,s2;
   Select(HT,i-1, s1, s2);
   HT[s1].parent=i;  HT[s2].parent=i;
   HT[i].lchild=s1;  HT[i].rchild=s2;
   HT[i].weight=HT[s1].weight+HT[s2].weight; 
 }
}

int Print(HuffmanTree HT,int m)    //输出 
{  int i;
   printf("HuffmanTree:\n");
   printf("\n结点i weight parent lchild rchild\n");
for(i=1;i<=m;i++)
   {printf("%d	%d	%d	%d	%d\n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
   }
}

int main()
{ int n;
  HTNode*HT=(HTNode*)malloc((2*n-1)*sizeof(HTNode));
  printf("输入叶子结点个数为:");
  scanf("%d",&n);
  printf("输入叶子结点的权值:\n"); 
  CreateHuffmanTree(HT,n);
  printf("\n");
  Print(HT,2*n-1);
  printf("\n");
  return 0;
 }
 
 
