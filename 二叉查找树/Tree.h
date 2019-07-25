#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "ShareDef.h"

//结构`
typedef struct _Tree
{
    TypeData node;
    struct _Tree *p;
    struct _Tree *l;
    struct _Tree *r;
}Tree;

void ShowTree();

//初始化
void InitTree(Tree **t);

//打印调试
void PrintTree(Tree *t);

//插入节点
void InsertNode(Tree *t, TypeData n);

//树的最小节点
Tree* MinNode(Tree *t);

//树的最大节点
Tree* MaxNode(Tree *t);

//树的前驱
Tree* Predecessor(Tree *t);

//树的后继
Tree* Successor(Tree *t);

//用一颗树(node)替换另一棵树(t)
void Transplant(Tree *t, Tree *node);

//查找节点
Tree* FindNode(Tree *t, TypeData target);

//删除节点
void DeleteNode(Tree *t, TypeData target);






















#endif // TREE_H_INCLUDED
