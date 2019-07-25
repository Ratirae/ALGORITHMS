#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "ShareDef.h"


//结构·
typedef struct _List
{
    TypeData data;
    struct _List *pre;
    struct _List *next;
}List;

void ShowList();

//初始化
void InitList(List **l, TypeData data);

//打印调试
void PrintList(List *l);

//查，查找元素返回节点指针


//增，在第i个节点前插入一个元素
void Insert(List *l, int i, TypeData node);




















#endif // LIST_H_INCLUDED
