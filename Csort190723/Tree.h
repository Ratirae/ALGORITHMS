#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "ShareDef.h"

//�ṹ
typedef struct _Tree
{
    TypeData node;
    struct _Tree *p;
    struct _Tree *l;
    struct _Tree *r;
}Tree;

void ShowTree();

//��ʼ��
void InitTree(Tree **t);

//��ӡ����
void PrintTree(Tree *t);

//����ڵ�
void InsertNode(Tree *t, TypeData n);

//������С�ڵ�
Tree* MinNode(Tree *t);

//�������ڵ�
Tree* MaxNode(Tree *t);

//����ǰ��
Tree* Predecessor(Tree *t);

//���ĺ��
Tree* Successor(Tree *t);

//��һ����(node)�滻��һ����(t)
void Transplant(Tree *t, Tree *node);

//���ҽڵ�
Tree* FindNode(Tree *t, TypeData target);

//ɾ���ڵ�
void DeleteNode(Tree *t, TypeData target);






















#endif // TREE_H_INCLUDED
