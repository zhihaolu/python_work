#include <stdio.h>

#define QueueSize 20
//typedef int DataType ;
#define DataType int
typedef struct {
    DataType data[QueueSize];
    int front;
    int rear;
    int count;
}Queue;

//初始化队列
void InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    Q->count = 0;
}

//队列是否为空
int QueueEmpty(Queue *Q)
{
    return (Q->count == 0);
}

//队列是否满
int QueueFull(Queue *Q)
{
    return (Q->count == QueueSize);
}

//入队
void EnQueue(Queue *Q, DataType v)
{
    if(QueueFull(Q))
        printf("Error, the queue is full!");
    Q->data[Q->rear] = v;
    Q->rear = (Q->rear+1)%QueueSize; //循环，防止rear大于QueueSize；
    Q->count++;
}

//出队
DataType DeQueue(Queue *Q)
{
    DataType i;
    if(QueueEmpty(Q))
        printf("Error, the queue is empty");
    i = Q->data[Q->front];
    Q->front = (Q->front+1)%QueueSize; //循环
    Q->count--;
    return i;
}

//读队头元素，不改变对状态
DataType ReadQueue(Queue *Q)
{
    DataType i;
    if(QueueEmpty(Q))
        printf("Error, the queue is empty");
    i = Q->data[Q->front];
    return i;
}

int main()
{
    Queue Q, *Q1;
    int i = 1;
    InitQueue(&Q);
    while(i<=6)
    {
        EnQueue(&Q,i);
        i++;
    }

    printf("DeQueue: %d\n", DeQueue(&Q));
    printf("DeQueue: %d\n", DeQueue(&Q));
    printf("DeQueue: %d\n", ReadQueue(&Q));

    EnQueue(&Q,9);
    printf("The queue :");
    while(!QueueEmpty(&Q))
        printf("%d\t",DeQueue(&Q));

    Q1 = &Q;
    printf("\nThe length of the queue:5");

    return 0;
}
