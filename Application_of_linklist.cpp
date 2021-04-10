/* 谨记：2019.07.29
这次写代码搞错了，字符串的输出，单个字符使用 %c，字符串使用 %s，而我这次使用 %s 来输出单个字符，一直出错。 
*/
#include"linkelist.cpp"

// Baisc Operation: InitList, delete, insert, destroy, get,
int main()
{
    LinkNode *L;
    ElemType e;

    printf("Init List.\n");
    InitList(L);
    printf("List status: %s\n", ListEmpty(L) ? "Empty" : "Not Empty");

    printf("Insert Element in the list.\n");
    for (int i = 0; i < 6 ; i++)
    {
        ListInsert(L, i+1, 'a'+i);
    }
    printf("List status: %s\n", ListEmpty(L) ? "Empty" : "Not Empty");
    printf("Lenght of List: %d\n", ListLenght(L));
    printf("Output list: ");
    DispList(L);
    printf("\n");
     
    if (GetElem(L, 5, e))
    {
        printf("Successful get 5th Element of list! Output: %c\n", e);
    }
    else
    {
        printf("False get 5th Element of list!\n");
    } 
    
    printf("---------------\n");
    printf("Insert 'g' to the list in the 3th position.\n");
    ListInsert(L, 3, 'g');
    printf("Lenght of List: %d\n", ListLenght(L));
    printf("Output list: ");
    DispList(L);
    printf("\n");
    printf("---------------\n");
     
    ListDelete(L, 4, e);
    printf("Delete 4th element( %c ) of the list.\n", e);    
    printf("Lenght of List: %d\n", ListLenght(L));
    printf("Output list: ");
    DispList(L);
    printf("\n");
    printf("---------------\n");
    
    printf("Destroy List.\n");
    DesstroyList(L);
    return 0;
}