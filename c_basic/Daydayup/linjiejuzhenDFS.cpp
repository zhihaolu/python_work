#include<stdio.h>
#include<stdlib.h>
#define  OK 1
#define ERROR 0

//ͼ���ڽӾ���洢��ʾ
#define MaxInt 32767             //��ʾ����ֵ�������� 
#define MVNum 100                //��󶥵���
typedef char VerTexType;         //���趥�����������Ϊ�ַ���
typedef int ArcType;             //����ߵ�Ȩֵ����Ϊ���� 
typedef int Status;
typedef struct             
{ VerTexType vexs[MVNum];           //����� 
  ArcType arcs[MVNum][MVNum];      //�ڽӾ��� 
  int vexnum,arcnum;               //ͼ�ĵ�ǰ�����ͱ��� 
}AMGraph;

int LocateVexx(AMGraph G,VerTexType u)      //�����򷵻�u�ڶ�����е��±�;���򷵻�-1
{  int i;
   for(i=0;i<G.vexnum;++i)
     if(u==G.vexs[i])
       return i;
   return -1;
 }

Status CreateUDN(AMGraph &G)            //�����ڽӾ����ʾ������������ͼ G 
{ int i,j,k,w;
  char v1,v2;
  printf("�����ܽ�������ܱ�����\n");
  scanf("%c %c",G.vexnum,G.arcnum);    //�����ܽ�������ܱ��� 
  for(i=0;i<G.vexnum;++i)
   {printf("������������Ϣ��\n");
    scanf("%c",G.vexs[i]); }          //������������Ϣ 
  for(i=0;i<G.vexnum;++i)            //��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt 
  
    for(j=0;j<G.vexnum;++j)
       {G.arcs[i][j]=MaxInt;
	   }
 printf("����һ���������Ķ��㼰Ȩֵ��\n");   
  for(k=0;k<G.arcnum;++k)                       //�����ڽӾ���  
   { scanf("%d %d %d",v1,v2,w);                //����һ���������Ķ��㼰Ȩֵ 
     i=LocateVexx(G,v1);  j=LocateVexx(G,v2);  //ȷ��v1��v2��G�е�λ�ã�������������±� 
     G.arcs[i][j]=w;                           //�� <v1,v2> ��Ȩֵ��Ϊ w 
     G.arcs[j][i]=G.arcs[i][j];                //�� <v1,v2> �ĶԳƱ� <v2,v1> ��ȨֵΪ w  
   }
	return OK;
}

bool visited[MVNum];                     //���ʱ�־���飬���ֵΪ��false" 
void DFS(AMGraph G, int v){        		//ͼGΪ�ڽӾ������� 
  int w;
  printf("%d",v);  
  visited[v] = true;  		//���ʵ�v������,���÷��ʱ�־������Ӧ����ֵΪtrue 
  for(w = 0; w< G.vexnum; w++)         	//���μ���ڽӾ���v���ڵ���  
        if((G.arcs[v][w]!=0) && (!visited[w]))  
            DFS(G, w);                         //w��v���ڽӵ㣬���wδ���ʣ���ݹ����DFS 
} 

int main()
{  int v;
   AMGraph G;
   CreateUDN(G);
   DFS(G, v);
   printf("�����\n");
   return 0;
 } 
