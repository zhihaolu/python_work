#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
struct sqlist
{
    int a[20];
    int length;
    int listsize;
}L1;
struct sqlist*L=&L1;
void initlist(struct sqlist *);//����˳���
void displist(struct sqlist *);//��ӡ
void listinsert(struct sqlist *,int i,int no);//����
void listdelete(struct sqlist *,int i);//ɾ��
int LengthList(struct sqlist *);//��
void inputlist(struct sqlist *);//����



void main()
{
  int i;
  initlist(L);
  inputlist(L);
  displist(L);

while(1)
{
      printf("��ѡ����Ĳ�����1.����\n                2.ɾ��\n                3.�˳�\n");
      scanf("%d",&i);
      if(i==1)
      {
        int j,x;
        printf("����������λ�ú����ݣ�");
        scanf("%d %d",&j,&x);
        listinsert(L,j,x);
        displist(L);
      }
      else if(i==2)
      {
        int j;
        printf("������Ҫɾ���ڼ������ݣ�");
        scanf("%d",&j);
        listdelete(L,j);
        displist(L);
      }
      else
        break;

}
      printf("�˳��ɹ���");
}
void initlist(struct sqlist *L)
{
    L->length=0;
    L->listsize=MAXSIZE;
}


void displist(struct sqlist*L)
{
    int i;
    for(i=0;i<L->length;i++)
    {
        printf(" %d",L->a[i]);
    }
    printf("\n");
}


void listinsert(struct sqlist *L,int i,int no)
{
    int j;
    if((i<1)||(i>L->length+1))
        printf("����λ�ò�����");
    if(L->length==MAXSIZE)
        printf("��ǰ�洢�ռ�����");
    for(j=L->length-1;j>=i-1;j--)
        L->a[j+1]=L->a[j];
    L->a[i-1]=no;
    ++L->length;
}


void listdelete(struct sqlist *L,int i)
{
    int j;
    if((i<1)||(i>L->length))
        printf("ɾ����Ԫ�ز�����");
    for(j=i;j<=L->length-1;j++)
        L->a[j-1]=L->a[j];
    --L->length;
}

int LengthList(struct sqlist*L)
{
      int tempL;
      tempL = L->length+1;
      return tempL;
}

void inputlist(struct sqlist *L)
{int i;
    for(i=0;;i++)
  {
      printf("�������%d��Ԫ�أ�",L->length+1);
      L->length++;
      scanf("%d",&L->a[i]);
      if(L->a[i]==0)
      {
          L->length--;
          break;
      }
  }
}

