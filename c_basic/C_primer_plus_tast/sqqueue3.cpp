#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define OK 1
 int yes=0;
 typedef struct node
 {
     char data;
     struct node *next;
 }node,*queueptr;
 typedef struct
 {
     queueptr front;
     queueptr rear;
 }linkqueue;

void initqueue(linkqueue *q)  //初始化操作，建立一个空队列 
 {
     q->front=q->rear=(queueptr)malloc(sizeof(node));
     if(!(q->front))
         exit(1);
     q->front->next=0;
 }
 void enqueue(linkqueue *q,char e)  //插入新元素e到队列中并成为队尾元素 
 {
     queueptr p;
     p=(queueptr)malloc(sizeof(node));
     if(!p)exit(1);
     p->data=e;
     p->next=0;
     q->rear->next=p;
     q->rear=p;
 }
 void creatqueue(linkqueue *q) //创建一个长度由自己决定的队列并初始化 
 {
     int i,length;
     int num;
     queueptr p;
     printf("请输入队列长度:\n");
     scanf("%d",&length);
     printf("请输入队列的元素:\n");
     for(i=0;i<length;i++)
     {
         p=(queueptr)malloc(sizeof(node));
         if(!p)exit(1);
         scanf("%d",&num);
         
             p->data=num;
             p->next=0;
             q->rear->next=p;
             q->rear=p;
     }
     yes=1;
 }
 void destroyqueue(linkqueue *q)  //若队列存在，则销毁它 
 {
     if(!q)
     {
         printf("链队列已经是空队列!\n");
         exit(1);
     }
     while(q->front)
     {
         q->rear=q->front->next;
         free((q->front));
         q->front=q->rear;
         if(!q->rear)
             free(q->rear);
     }
     free(q->front);
 }
     
     void disqueue(linkqueue *q)  //输出队列元素 
     {
         node *r=q->front->next;
         printf("此时的链队列输出:\n");
         while(r)
         {
             printf("%d  ",r->data);
             r=r->next;
         }
         printf("\n");
     }
     void lenqueue(linkqueue *q)  //求队列长度 
     {
         node *r=q->front->next;
         int s=0;
         printf("此时的链队列长度为:\n");
         while(r)
         {
             r=r->next;
             s++;
         }
         printf("%d\n",s);
     }
     char dequeue(linkqueue *q,int e)  //删除队列中队头元素，并用e返回其值 
     {
         node *p;
         if(q->front==q->rear)
             return -1;
         p=q->front->next;
         e=p->data;
         q->front->next=p->next;
         if(q->rear==p)
             q->rear=q->front;
         free(p);
         return e;
     }
     int queueempty(linkqueue *q) // 判断队列是否为空 
     {
         if(q->front==q->rear)
             return 1;
         else
             return 0;
     }
     void menu()  //菜单 
     {
         printf("           链队列试验统一界面               \n");
         printf("********************************************\n");
         printf("1 创建链队列                                *\n");
         printf("2 入队                                     *\n");
         printf("3 出队                                     *\n");
         printf("4 求队列长度                                *\n");
         printf("5 判断队列是否为空                          *\n");
         printf("6 输出队列                                 *\n");
         printf("7 销毁队列                                 *\n");
         printf("0 退出                                     *\n");
         printf("********************************************\n");
     }

int main(void)
     {
         linkqueue ptr;
         int sel;
         int num;
         initqueue(&ptr);
         while(1)
         {
             menu();
             printf("please input command:\n");
             scanf("%d",&sel);
             switch(sel)
             {
             case 1:if(yes==1)
                    {
                        printf("此时表已创建!不能再次创建!\n");
                        break;
                    }
                 else
                     creatqueue(&ptr);break;
             case 2:if(yes==0)
                    {
                        printf("此时表未创建!不能入队!\n");
                        break;
                    }
                 else
                 {
                     printf("请输入队的元素值:");
                     scanf("%d",&num);
                         enqueue(&ptr,num);
                     break;
                 }
             case 3:if(yes==0)
                    {
                        printf("此时表为创建!不能出队!\n");
                        break;
                    }
                 else
                 {
                     num=dequeue(&ptr,num);
                     printf("目前出队的元素是%d",num);
                     break;
                 }
             case 4:if(yes==0)
                    {
                        printf("此时链队列未创建!不能求其长度!\n");
                        break;
                    }
                 lenqueue(&ptr);
                 break;
             case 5:if(yes==0)
                    {
                        printf("此时表未创建!不能判断是否为空!\n");
                        break;
                    }
                 else
                 {
                     if(queueempty(&ptr))
                         printf("此时队列为空队列!\n");
                     else
 
                         printf("此时队列为非空队列!\n");
 
                     break;
                 }
             case 6:if(yes==0)
                    {
                        printf("此时链队列未创建!不能输出!\n");
                        break;
                    }
                            disqueue(&ptr);
                            break;
             case 7:if(yes==0)
                    {
                        printf("此时链队列未创建!不能销毁!\n");
                        break;
                    }
                 destroyqueue(&ptr);
                 printf("销毁成功\n");
                 break;
             case 0:exit(1);break;
             default:printf("输入命令错误!请重新输入:\n");
                 break;
             }
         }
         return OK;
     }

