#include"linkelist.cpp"

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
        ListInsert(L, i+1, '5'+i);
    }
    printf("List status: %s\n", ListEmpty(L) ? "Empty" : "Not Empty");
    printf("Lenght of List: %d\n", ListLength(L));
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
    printf("Lenght of List: %d\n", ListLength(L));
    printf("Output list: ");
    DispList(L);
    printf("\n");
    printf("---------------\n");
     
    ListDelete(L, 4, e);
    printf("Delete 4th element( %c ) of the list.\n", e);    
    printf("Lenght of List: %d\n", ListLength(L));
    printf("Output list: ");
    DispList(L);
    printf("\n");
    printf("---------------\n");
    
    printf("Destroy List.\n");
    DestroyList(L);
    return 0;
}