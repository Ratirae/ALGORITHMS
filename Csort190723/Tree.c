#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "Tree.h"



void ShowTree()
{
    Tree *t = NULL;
    PrintTree(t);
    InitTree(&t);
    t->node = 12;
    PrintTree(t);
    InsertNode(t, 2);
    InsertNode(t, 5);
    InsertNode(t, 18);
    InsertNode(t, 9);
    InsertNode(t, 15);
    InsertNode(t, 19);
    PrintTree(t);

    Tree *min_node = NULL;
    min_node = MinNode(t);
    PrintTree(min_node);
    Tree *max_node = NULL;
    max_node = MaxNode(t);
    PrintTree(max_node);

    //前驱·
    Tree *predecessor_node = NULL;
    predecessor_node = Predecessor(t);
    PrintTree(predecessor_node);

    //后继
    Tree *successor_node = NULL;
    successor_node = Successor(t);
    PrintTree(successor_node);

    //替换
    //Transplant(t->l, t->r);
    //PrintTree(t);

    //查找
    TypeData target = 18;
    Tree *target_node = FindNode(t, target);
    printf("find: %d\n", target);
    PrintTree(target_node);

    //删除
    TypeData dele_node = 18;
    printf("delete: %d\n", dele_node);
    DeleteNode(t, dele_node);
    PrintTree(t);

}


//初始化
void InitTree(Tree **t)
{
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->node = 0;
    (*t)->p = NULL;
    (*t)->l = NULL;
    (*t)->r = NULL;
}


//打印调试
void _PrintTree(Tree *t)
{
    if(t == NULL)
        return;
    printf("%d  ",t->node);
    _PrintTree(t->l);
    _PrintTree(t->r);
}
void PrintTree(Tree *t)
{
    if(t == NULL)
    {
        printf("Tree is empty!\n");
    }
    printf("Preorder: ");
    _PrintTree(t);
    printf("\n\n");
}

//插入节点
void InsertNode(Tree *t, TypeData n)
{
    Tree *record_node = NULL;   //记录遍历时，节点的前驱
    Tree *current_node = t;     //从根节点开始遍历
    Tree *t_node = NULL;      //当前节点
    InitTree(&t_node);
    t_node->node = n;
    while(current_node != NULL)
    {
        record_node = current_node;
        if(n < current_node->node)
            current_node = current_node->l;
        else
            current_node = current_node->r;
    }
    t_node->p = record_node;
    if(n < record_node->node)
        record_node->l = t_node;
    else
        record_node->r = t_node;
}

//树的最小节点
Tree* MinNode(Tree *t)
{
    Tree *root = t;
    Tree *cu = NULL;
    if(root == NULL)
        return NULL;
    while(root != NULL)
    {
        cu = root;
        root = root->l;
    }
    return cu;
}

//树的最大节点
Tree* MaxNode(Tree *t)
{
    Tree *root = t;
    Tree *cu = NULL;
    if(root == NULL)
        return NULL;
    while(root != NULL)
    {
        cu = root;
        root = root->r;
    }
    return cu;
}

//树的前驱
Tree* Predecessor(Tree *t)
{
    if(t->l == NULL)
        return NULL;
    return MaxNode(t->l);
}

//树的后继
Tree* Successor(Tree *t)
{
    if(t->r == NULL)
        return NULL;
    return MinNode(t->r);
}

//用一颗树(node)替换另一棵树(t)
void Transplant(Tree *t, Tree *node)
{
    if(t->p == NULL)
    {
        t = node;
    }else if(t->p->l == t)
    {
        t->p->l = node;
    }else
    {
        t->p->r = node;
    }
    if(node != NULL)
        node->p = t->p;
}

//查找节点
Tree* FindNode(Tree *t, TypeData target)
{
    if(t == NULL)
    {
        return NULL;
    }
    Tree *root = t;
    Tree *target_node = NULL;
    while(root != NULL)
    {
        if(root->node == target)
        {
            target_node = root;
            break;
        }else if(root->node > target)
        {
            root = root->l;
        }else
        {
            root = root->r;
        }
    }
    return target_node;
}

//删除节点
void DeleteNode(Tree *t, TypeData target)
{
    if(t == NULL)
        return;
    Tree *target_node = FindNode(t, target);
    if(target_node == NULL)
        return;
    Tree *successor = Successor(target_node);
    if(target_node->l == NULL)
    {
        Transplant(target_node, target_node->r);
    }else if(target_node->r == NULL)
    {
        Transplant(target_node, target_node->l);
    }else
    {
        if(successor != target_node->r)
        {
            Transplant(successor, successor->r);
            Transplant(successor->r, target_node->r);
        }
        Transplant(target_node, successor);
        successor->l = target_node->l;
    }
    target_node = NULL;
}



















