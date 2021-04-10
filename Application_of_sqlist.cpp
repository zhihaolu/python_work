#include"sqlist.cpp"

/* 
// 使用数组建立顺序表
int main()
{
	ElemType e = 4;
	int i;
	SqList *L;
	int a[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(a)/sizeof(a[0]);
	
	printf("Create List\n");
	CreateList(L, a, n);
	printf("Disp List\n");
	DispList(L);
	printf("Lenght of list: %d\n", ListLenght(L));
	
	
	i = LocateElem(L, 4);
	printf("Delete 4 in list\n");
	ListDelete(L, i, 4);
	printf("Disp List\n");
	DispList(L);
	printf("Lenght of list: %d\n", ListLenght(L));
	
	
	printf("List insert 9: ", ListInsert(L, 5, 9));
	DispList(L);
	
	DestroyList(L);
	DispList(L);
	printf("Destroy List\n");
	printf("Lenght of list: %d\n", ListLenght(L));
	printf("ListEmpty: %s\n", ListEmpty(L) ? "Empty" : "Not Empty");
	return 1;
}
*/

/*
// 逐个插入建立顺序表(非数组建立)
int main()
{
	SqList *L;
	ElemType e;
	
	printf("Init list.\n");
	InitList(L);
	printf("List status: %s\n", ListEmpty(L) ? "Empty" : "Not Empty");
	
	printf("Insert Element 1, 2, 3, 4, 5.\n");
	for (int i = 0; i < 5; i++)
	{
		ListInsert(L, i+1, i+1);	
	}

	printf("List status: %s\n", ListEmpty(L) ? "Empty" : "Not Empty");
	printf("List lenght: %d\n", ListLenght(L));
	printf("Disp list: ");
	DispList(L);
	printf("\n");
	
	printf("Location of 3: %d\n", LocateElem(L, 3));
	if (ListDelete(L, 4, 4))
		printf("Successfully delete 4.\n");
	
	printf("List lenght: %d\n", ListLenght(L));
	printf("Disp list: ");
	DispList(L);
	printf("\n");
	
	if (GetElem(L, 2, e))
		printf("Successfully get 2th element of list.\n");
	printf("Destroy list.\n");
	DestroyList(L);

	printf("List status: %s\n", ListEmpty(L) ? "Empty" : "Not Empty");
	printf("Disp list: ");

	return 0;
} 
*/



/* 问题一：
在一个顺序表中，设计一个算法，删除其中所有值为 x 的元素，
要求算法时间复杂度为 O(n), 空间复杂度为 O(1)
 */

/*
解法一：显然删除 X 后的顺序表 L' 为原来顺序表 L 的子集，
		故 L' 可以重用 L 的存储空间，算法过程为置 k = 0（ k 记录新表的长度），
		用 i 从头到尾的扫描 L 中所有的元素，当 i 指向的元素等于 x 时跳过它；
		否则将其放在 k 的位置，即 L->data[k]=L->[i], k++
 */
/* // 代码如下
void delnode1(SqList *&L, ElemType x)
{
	int k = 0;
	for (int i = 0; i < L->lenght; i++)
	{
		if (L->data[i] != x)
		{
			L->data[k] = L->data[i];
			k++;
		}
	}
	L->lenght = k;
}
*/

/*
解法二：扫描顺序表 L，用 i 从头到尾扫描 L 中的所有元素，
		用 k 来记录 L 中当前等于 x 的元素个数，一边扫描 L，
		一遍统计当前 k 值。简单说，就是 L 中的元素，前面有多少
		个元素等于 x，就要移前多少位，最后修改 L 的长度 
 */
/*// 代码如下
void delnode2(SqList *&L, ElemType x)
{
	int k = 0, i = 0;
	while (i < L->lenght)
	{
		if (L->data[i] == x)
			k++;
		else
			L->data[i-k] = L->data[i];
		i++;		// 判断一次一次 i 自增 1，
	}
	L->lenght -= k; 
}
*/
/* 
// 测试一下代码，数据集不够大，无法测出时间复杂度来，只能理论计算了
int main()
{
	SqList *L;
	int a[] = {12, 22, 6, 7, 6, 18, 36, 6, 11, 6};
	int b[] = {6, 6, 6, 12, 17, 10, 6, 7, 39, 101};
	int n = sizeof(a) / sizeof(a[0]);
	int m = sizeof(b) / sizeof(b[0]);

	//CreateList(L, a, n);
	CreateList(L, b, m);
	printf("Original List: ");
	DispList(L);
	printf("\n");

	//delnode1(L, 6);
	delnode2(L, 6);
	printf("New List: ");
	DispList(L);
	printf("\n");

	DestroyList(L);
	return 0;
}
*/



/* 问题二：
一个顺序表 L，假设元素类型 ElemType 是整型，设计一个尽可能高效的算法，
以第一个元素为分界线（基线），将所有小于等于它的元素移到该基线前面，
将所有大于它的元素移到该基线的后面
 */
/*
解法一：用 pivot 存放基准，即 L->data[0]，i(初值为 0)从左向右扫描，
		j(初值为 L->lenght-1)从右向左扫描，当 i ！= j 时循环(
		即当 i 和 j指向同一元素时循环停止)：j 从右向左找到小于等于
		基准的元素 L->data[j], i从左向右找到大于基准的元素 L->data[i],
		然后交换 L->data[j] 与 L->data[i]。最后循环结束时，交换 data[0]
		与基准 pivot
 */
/*// 代码如下
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
} */

void partition1(SqList *&L)
{
	int i = 0, j = L->lenght-1;
	ElemType pivot = L->data[0];
	while (i < j)
	{
		while (i < j && L->data[j] > pivot)
			j--;
		while (i < j && L->data[i] <= pivot)
			i++;
		if (i < j)
		{
			//swap(L->data[i], L->data[j]);
			int t = L->data[i];
			L->data[i] = L->data[j];
			L->data[j] = t;
		}
	}
	//swap(L->data[0], L->data[i]);
	int t = L->data[0];
			L->data[0] = L->data[i];
			L->data[i] = t;
}

int mian()
{
	SqList *L;
	int a[] = {44, 21, 55, 101, 45, 78, 90, 44, 6};
	int n = sizeof(a) / sizeof(a[0]);

	CreateList(L, a, n);
	printf("Original List: ");
	DispList(L);

	partition1(L);
	printf("New List: ");
	DispList(L);

	DestroyList(L);
	return 0;
}