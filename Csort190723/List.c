#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "List.h"




void ShowList()
{
    List *l = NULL;
    PrintList(l);
    InitList(&l,3);
    PrintList(l);
    Insert(l,1, 5);
    PrintList(l);
    Insert(l,1, 6);
    PrintList(l);
    Insert(l,3, 7);
    PrintList(l);
    free(l);

}

//初始化·
void InitList(List **l, TypeData data)
{
    *l = (List*)malloc(sizeof(List));
    (*l)->data = data;
    (*l)->pre = NULL;
    (*l)->next = NULL;
}

//打印调试
void PrintList(List *l)
{
    List *head = l;
    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    int len = 0;
    while(head != NULL)
    {
        printf("%d  ", head->data);
        head = head->next;
        len++;
    }
    printf("\nlength: %d\n\n", len);
}

//增，在第i个节点后插入一个元素
void Insert(List *l, int i, TypeData node)
{
    List *head = l;
    List *now = NULL;
    InitList(&now, node);
    int j = 1;
    while(head != NULL && j < i)
    {
        head = head->next;
        j++;
    }
    if(head == NULL || j>i)
    {
        printf("Cannot find this node!\n");
        return;
    }
    now->pre = head;
    now->next = head->next;
    if(head->next != NULL)
        now->next->pre = now;
    head->next = now;
    now->data = node;
}


















