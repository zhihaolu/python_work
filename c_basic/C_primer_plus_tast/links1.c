//1.������ 
#include <stdio.h>  
#include <stdlib.h>  

typedef struct LNode 
{
    int data;
    struct LNode* next;
}LNode, * LinkList;

LinkList head, k;


void CreateHead(LinkList L)//ͷ�巨���������� 
{
    head = (LinkList)malloc(sizeof(LNode));  
    head->next = NULL;  
    head->data = NULL;  //����һ����ͷ���Ŀ�����
    LinkList p, t;
    int x;
    t = head;
    printf("��������ֵ����0����\n");
    while (~scanf("%d", &x), x)
    {
        p = (LinkList)malloc(sizeof(LNode));  //�����½����Ϊͷ��㣬��ͷָ��*pָ��ͷ���
        p->data = x;
        p->next = t->next;
        t->next = p;    //���½��*p���뵽ͷ���֮��
    }
}


void Show(LinkList t)//�������Ԫ��
{
    printf("��ǰ����Ԫ��Ϊ��");
    t = t->next;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int Insert(LinkList L, int i, int e)//���� 
{
    LinkList t, p;
    int j = 0;
    t = head;
    if (i < 1) { printf("�������\n"); return 0; }
    
    while (j < i - 1 && L)
    {
        t = t->next;
        j++;
        if (!t || j>i-1)  //i>n+1 �� i<1
        {
            printf("�������\n");
            return 0;
        }
    }
     
    p = (LinkList)malloc(sizeof(LNode)); //�����½��
    p->data = e;  //��*p����������Ϊe
    p->next = t->next;  //�����*p��ָ����ָ����ai
    t->next = p;  //�����*t��ָ����ָ����*p
    printf("����ɹ�\n");
}

int Delete(LinkList L, int i)//ɾ�� 
{
    LinkList p, t;
    int j = 0;
    p = head;
    if (i < 1) { printf("ɾ��ʧ��\n"); return 0; } //λ�ò��Ϸ���ɾ��ʧ��
    while (j < i - 1 && L)
    {
        p = p->next;
        j++;  //���ҵ�i-1����㣬pָ��ýڵ�
        if (p == NULL||j>i-1)  // i>n ���� i<1,ɾ��λ�ò�����
        {
            printf("ɾ��ʧ��\n");
            return 0;
        }
    }
    t = p->next;  //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
    p->next = t->next;  //�ı�ɾ�����ǰ������ָ����
    printf("ɾ���ɹ�\n");
    free(t);  //�ͷ�ɾ�����Ŀռ�
}

int Secrch(LinkList L, int i)//��λ�ò���
{
    LinkList p;
    int j = 0, e;
    p = head;
    if (i < 1) { printf("����ʧ�ܣ���Ԫ�ز�����\n"); return 0; }
    while (j < i && L)
    {
        p = p->next;  //pָ����һ�����
        j++;  //������j��1
        if (p == NULL||j>i)  //iֵ���Ϸ�
        {
            printf("����ʧ�ܣ���Ԫ�ز�����\n");
            return 0;
        }
    }
    e = p->data; //ȡ��i������������
    printf("���ҳɹ�����%d��Ԫ��Ϊ%d\n", i, e);
}


    

int main()
{
    LinkList L;
    int select, i, e;
    while (1)
    {
        printf("1.ͷ�巨���� \t2.���� \t3.ɾ�� \t4.���� \n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            CreateHead(&L);
            Show(head);
            break;
        
        case 2:
            printf("����λ�ú�Ҫ�����Ԫ��\n");
            scanf_s("%d%d", &i, &e);
            Insert(&L, i, e);
            Show(head);
            break;
        case 3:
            printf("����Ҫɾ����Ԫ�ص�λ��\n");
            scanf_s("%d", &i);
            Delete(&L, i);
            Show(head);
            break;
        case 4:
            printf("����Ҫ���ҵ�Ԫ�ص�λ��\n");
            scanf_s("%d", &i);
            Secrch(&L, i);
            break;      
        }
    }
    return 0;
}