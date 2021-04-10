//使用结构链表，实现电影信息列表
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45 /*储存片名的数组大小*/

struct film {
  char title[TSIZE];
  int rating;
  struct film *next; /*指向链表的下一个结构*/
};
char *s_gets(char *st, int n);

int main(void) {
  struct film *head = NULL;
  struct film *prev, *current;
  char input[TSIZE];
  int i;

  /*收集并储存信息*/
  puts("Enter first movie title:");
  while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
    current = (struct film *)malloc(sizeof(struct film));
    if (head == NULL) /* 第 1 个结构 */
      head = current;
    else /* 后续结构 */
      prev->next = current;
    current->next = NULL;
    strcpy(current->title, input);
    puts("Eenter you rating <0-10>");
    scanf("%d", &current->rating);
    while (getchar() != '\n') continue;
    puts("Enter next movie title (empty line to stop):");
    prev = current;
  }

  /* 显示电影列表 */
  if (head == NULL)
    printf("No date entered. ");
  else
    printf("Here is the movie list:\n");
  current = head;
  while (current != NULL) {
    printf("Movie: %s Rating: %d\n", current->title, current->rating);
    current = current->next;
  }

  while (1) {
    printf("请选择你要进行的操作：1.插入\n2.删除\n3.查找\n4.退出\n");
    scanf("%d", &i);
    if (i == 1) {
      int j, x;
      printf("请输入要插入的位置和电影：");
      scanf("%d %d", &j, &x);
      ListInsert(L, j, x);
      DispList(L);
    }
    if (i == 2) {
      int j;
      printf("请输入要删除电影的位置：");
      scanf("%d", &j);
      ListDelete(L, j, i);
      DispList(L);

    } else if (i == 3) {
      int j;
      printf("请输入要查找的电影的位置:");
      int LocateElem(LinkNode *L,ElemType e)
    } else
      break;
  }

  /* 完成任务，释放已分配的空间 */
  current = head;
  while (current != NULL) {
    head = head->next;
    free(current);
    current = head;
  }
  printf("Bye!\n");

  return 0;
}

char *s_gets(char *st, int n) {
  char *ret_val;
  char *find;

  ret_val = fgets(st, n, stdin);
  if (ret_val) {
    find = strchr(st, '\n');  //查找换行符
    if (find)                 //如果地址不是 NULL
      *find = '\0';           //在此处放一个空字符
    else
      while (getchar() != '\n') continue;  //处理剩余输入行
  }
  return ret_val;
}

int LocateElem(LinkNode *L,ElemType e)
{
	LinkNode *p=L->next;
	int n=1;
	while (p!=NULL && p->data!=e)
	{	p=p->next;
		n++;
	}
	if (p==NULL)
		return(0);
	else
		return(n);
}
