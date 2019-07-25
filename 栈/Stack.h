#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "ShareDef.h"


//结构
typedef struct{
    TypeData data[MAXSIZE];
    int top;    //top指向栈顶元素，为空是指向-1
}Stack;

void ShowStack();

//初始化·
void InitStack(Stack **s);

//打印调试·
void PrintStack(Stack *s);

//增，进栈·
void Push(Stack *s, TypeData data);

//删，出栈·
void Pop(Stack *s);

//获得栈顶元素·
TypeData GetTop(Stack *s);




#endif // STACK_H_INCLUDED
