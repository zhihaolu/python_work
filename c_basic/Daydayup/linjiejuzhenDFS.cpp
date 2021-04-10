#include<stdio.h>
#include<stdlib.h>
#define  OK 1
#define ERROR 0

//图的邻接矩阵存储表示
#define MaxInt 32767             //表示极大值，即无穷 
#define MVNum 100                //最大顶点数
typedef char VerTexType;         //假设顶点的数据类型为字符型
typedef int ArcType;             //假设边的权值类型为整型 
typedef int Status;
typedef struct             
{ VerTexType vexs[MVNum];           //顶点表 
  ArcType arcs[MVNum][MVNum];      //邻接矩阵 
  int vexnum,arcnum;               //图的当前点数和边数 
}AMGraph;

int LocateVexx(AMGraph G,VerTexType u)      //存在则返回u在顶点表中的下标;否则返回-1
{  int i;
   for(i=0;i<G.vexnum;++i)
     if(u==G.vexs[i])
       return i;
   return -1;
 }

Status CreateUDN(AMGraph &G)            //采用邻接矩阵表示法，创建无向图 G 
{ int i,j,k,w;
  char v1,v2;
  printf("输入总结点数和总边数：\n");
  scanf("%c %c",G.vexnum,G.arcnum);    //输入总结点数和总边数 
  for(i=0;i<G.vexnum;++i)
   {printf("依次输入点的信息；\n");
    scanf("%c",G.vexs[i]); }          //依次输入点的信息 
  for(i=0;i<G.vexnum;++i)            //初始化邻接矩阵，边的权值均置为极大值MaxInt 
  
    for(j=0;j<G.vexnum;++j)
       {G.arcs[i][j]=MaxInt;
	   }
 printf("输入一条边依附的顶点及权值；\n");   
  for(k=0;k<G.arcnum;++k)                       //构造邻接矩阵  
   { scanf("%d %d %d",v1,v2,w);                //输入一条边依附的顶点及权值 
     i=LocateVexx(G,v1);  j=LocateVexx(G,v2);  //确定v1和v2在G中的位置，即顶点数组的下标 
     G.arcs[i][j]=w;                           //边 <v1,v2> 的权值置为 w 
     G.arcs[j][i]=G.arcs[i][j];                //置 <v1,v2> 的对称边 <v2,v1> 的权值为 w  
   }
	return OK;
}

bool visited[MVNum];                     //访问标志数组，其初值为“false" 
void DFS(AMGraph G, int v){        		//图G为邻接矩阵类型 
  int w;
  printf("%d",v);  
  visited[v] = true;  		//访问第v个顶点,并置访问标志数组相应分量值为true 
  for(w = 0; w< G.vexnum; w++)         	//依次检查邻接矩阵v所在的行  
        if((G.arcs[v][w]!=0) && (!visited[w]))  
            DFS(G, w);                         //w是v的邻接点，如果w未访问，则递归调用DFS 
} 

int main()
{  int v;
   AMGraph G;
   CreateUDN(G);
   DFS(G, v);
   printf("结果；\n");
   return 0;
 } 
