
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 
#define MAX_VERTEX 100
#define inf 65535  //表示两点之间没有边相连
 
int visit[MAX_VERTEX];   //标记顶点是否被访问
 
/**图的邻接矩阵的建立**/
//邻接矩阵数据结构定义
typedef struct Martrix_Graph
{
    char vertex[MAX_VERTEX]; //存储顶点信息
    int edge[MAX_VERTEX][MAX_VERTEX]; //存储边信息
    int vertex_number,edge_number;//存储顶点数和边数
}Martrix_Graph;
 
void Create_non_direction_martrix_Graph( Martrix_Graph *G )
{
    int i,j,k,m;
    printf("请输入构造的无向图的顶点数和边数：\n");
    scanf("%d %d",&G->vertex_number,&G->edge_number);
 
    printf("请输入无向图顶点信息（如ABCDEF....）：\n");
    char ch;
    while( ( ch = getchar() != '\n' ) );  //过滤掉前面的\n，防止\n被scanf进去
    for(i=0;i<G->vertex_number;i++)
        scanf("%c",&G->vertex[i]);
 
    //不相连的顶点之间的权值设为inf，包括顶点自身
    //初始化邻接矩阵
    for(i=0;i<G->vertex_number;i++)
        for(j=0;j<G->vertex_number;j++)
            G->edge[i][j] = inf;
 
    //更新无向图边信息
    printf("请输入无向图邻接矩阵相连的边信息，相连标记为1\n");
    for(k=0;k<G->edge_number;k++)
    {
        scanf("%d %d %d",&i,&j,&m);
        G->edge[i][j] = m;
        G->edge[j][i] = G->edge[i][j];//无向图是对称阵
    }
 
 
    //打印邻接矩阵存储信息，检查正确性
    printf("---------------------构造出来的无向图邻接矩阵如下---------------------\n");
    for(i=0;i<G->vertex_number;i++)
    {
        for(j=0;j<G->vertex_number;j++)
            printf("%d\t",G->edge[i][j]);
        printf("\n");
    }
}
/**BFS会用到队列这个数据结构**/
/**循环队列**/
typedef struct
{
    char data[MAX_VERTEX];
    int front;  //头指针
    int rear;   //尾指针，队列非空则指向队尾最后一个元素后一个位置
}SqQueue;
 
//队列初始化
void InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}
//入队
bool EnQueue(SqQueue *Q, char e)
{
    //判断队列是否满
    if( ( Q->rear+1 ) % MAX_VERTEX == Q->front )
        return false;
    Q->data[Q->rear]=e;
    Q->rear = (Q->rear+1)%MAX_VERTEX;
    return true;
}
//出队---删除队首元素，并赋给e
char* DeQueue(SqQueue *Q, char *e)
{
    //判断队列是否为空
    if( Q->front == Q->rear )
        return NULL;
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAX_VERTEX;
    return e;
}
//队列判空
bool isEmptyQueue(SqQueue *Q)
{
    return Q->front == Q->rear?true:false;
}
 
//无向图邻接矩阵BFS
void BFS_Travel(Martrix_Graph G)
{
//    int layerNumer = 0;
    SqQueue Q;
    int i,j,mark;
    char data;
    //初始化visit数组
    for(i=0;i<G.vertex_number;i++)
        visit[i] = false;
    //初始化队列
    InitQueue(&Q);
 
    //开始遍历整个图的顶点--默认从第一个顶点开始
    printf("此邻接矩阵无向图BFS的结果为：\n");
    for(i=0;i<G.vertex_number;i++)
    {
        //对未访问的顶点做BFS
        if(!visit[i])
        {
            visit[i] = true;
 
            //将此顶点入队
            EnQueue(&Q,G.vertex[i]);
//            layerNumer++;
 
            while(!isEmptyQueue(&Q))
            {
                DeQueue(&Q,&data);  //队首顶点出队，并赋值给data
                printf("%c ",data);
 
                //找所删除顶点的下标，更新该下标值，以便正确找到与出队元素相连的其他顶点
                for( j = 0;j<G.vertex_number;j++)
                    if(G.vertex[j] == data )
                        mark = j ;
                //找寻与此顶点相连且未被访问的顶点，逐次标记、打印，并入队
                for(j=0;j<G.vertex_number;j++)
                {
                    if(G.edge[mark][j]==1 && !visit[j])
                    {
 
                        visit[j] = true;
//                        printf("%c ",G.vertex[j]);
                        EnQueue(&Q,G.vertex[j]);
                    }
                }
            }
        }
 
    }
} 

int main()
{
    printf("测试代码\n");
    Martrix_Graph G;
    Create_non_direction_martrix_Graph(&G);
    BFS_Travel(G);
    return 0;
}