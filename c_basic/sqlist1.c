#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
struct sqlist {
  int a[20];
  int length;
  int listsize;
} L1;
struct sqlist *L = &L1;
void initlist(struct sqlist *);                   //创建顺序表
void displist(struct sqlist *);                   //打印
void listinsert(struct sqlist *, int i, int no);  //插入
void listdelete(struct sqlist *, int i);          //删除
int LocateElem(struct sqlist *L, int i);          //查找
int LengthList(struct sqlist *);                  //表长
void inputlist(struct sqlist *);                  //输入

int main() {
  int i;
  initlist(L);
  inputlist(L);
  displist(L);

  while (1) {
    printf("请选择你的操作：1.插入\n2.删除\n3.查找\n4.退出\n");
    scanf("%d", &i);
    if (i == 1) {
      int j, x;
      printf("请输入插入的位置和数据：");
      scanf("%d %d", &j, &x);
      listinsert(L, j, x);
      displist(L);
    }
    if (i == 2) {
      int j;
      printf("请输入要删除第几个数据：");
      scanf("%d", &j);
      listdelete(L, j);
      displist(L);
    }
    if (i == 3) {
      int j;
      printf("请输入要查找的第几个数据：");
      scanf("%d", &j);
      LocateElem(L, j);
      displist(L);
    } else
      break;
  }
  printf("退出成功。");
  return 0;
}
void initlist(struct sqlist *L) {        //定义链表
  L->length = 0;
  L->listsize = MAXSIZE;
}

void displist(struct sqlist *L) {
  int i;
  for (i = 0; i < L->length; i++) {
    printf(" %d", L->a[i]);
  }
  printf("\n");
}

void listinsert(struct sqlist *L, int i, int no) {
  int j;
  if ((i < 1) || (i > L->length + 1)) printf("插入位置不存在");
  if (L->length == MAXSIZE) printf("当前存储空间已满");
  for (j = L->length - 1; j >= i - 1; j--) L->a[j + 1] = L->a[j];
  L->a[i - 1] = no;
  ++L->length;
}

void listdelete(struct sqlist *L, int i) {
  int j;
  if ((i < 1) || (i > L->length)) printf("删除的元素不存在");
  for (j = i; j <= L->length - 1; j++) L->a[j - 1] = L->a[j];
  --L->length;
}

int LocateElem(struct sqlist *L, int i) {
  int j = 0;
  while (j < L->length && L->a[j] != i) j++;
  if (j >= L->length)
    return 0;
  else
    return j + 1;
}

void inputlist(struct sqlist *L) {
  int i;
  for (i = 0;; i++) {
    printf("请输入第%d个元素：", L->length + 1);
    L->length++;
    scanf("%d", &L->a[i]);
    if (L->a[i] == 0) {
      L->length--;
      break;
    }
  }
}
