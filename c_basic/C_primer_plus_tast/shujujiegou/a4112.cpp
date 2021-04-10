#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 typedef struct{
 	int weight;
 	int parent,lchild,rchild;
 }HTNode,*HuffmanTree;
 
void Select(HuffmanTree HT,int m,int &s1,int &s2) //����m�������ѡ����С��2��//�ѵ�һ�����б�Ǿ�ok
{ int i;                                           //���±�Ϊ1��λ�ÿ�ʼ����
  //int min=HT[1].weight;����ֱ�Ӹ�ֵ�����������һ���Ǹ�1������С��ѡѡ�У���ô��2�λ��Ǳ�ѡ��
  int min1=1000;                                  
  int min2=1000;                                 //�涨һ���ر�����

for(i=1;i<=m;i++)
 { if(HT[i].parent==0 && min1>HT[i].weight)
  { min1=HT[i].weight;
    s1=i;
  }
 }
 
for(i=1;i<=m;i++)                            //ע�����i!=s1���min
 { if(i!=s1 && HT[i].parent==0)
  if(HT[i].weight<min2)
  { min2=HT[i].weight;
    s2=i;
  }
 }
}

void CreateHuffmanTree(HuffmanTree &HT,int n)   //����������� 
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

int Print(HuffmanTree HT,int m)    //��� 
{  int i;
   printf("HuffmanTree:\n");
   printf("\n���i weight parent lchild rchild\n");
for(i=1;i<=m;i++)
   {printf("%d	%d	%d	%d	%d\n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
   }
}

int main()
{ int n;
  HTNode*HT=(HTNode*)malloc((2*n-1)*sizeof(HTNode));
  printf("����Ҷ�ӽ�����Ϊ:");
  scanf("%d",&n);
  printf("����Ҷ�ӽ���Ȩֵ:\n"); 
  CreateHuffmanTree(HT,n);
  printf("\n");
  Print(HT,2*n-1);
  printf("\n");
  return 0;
 }
 
 
