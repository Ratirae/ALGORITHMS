#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "Stack.h"



void ShowStack()
{
    Stack *s;
    InitStack(&s);
    PrintStack(s);
    Push(s,5);
    PrintStack(s);
    Push(s,6);
    PrintStack(s);
    Pop(s);
    PrintStack(s);
    TypeData i = GetTop(s);
    printf("%d\n", i);
}
//初始化``
void InitStack(Stack **s)
{
    *s = malloc(sizeof(Stack));
    (*s)->top = -1;
}

//打印调试
void PrintStack(Stack *s)
{
    if(-1 == s->top)
    {
        printf("Stack is empty!\n");
    }
    if(MAXSIZE == s->top)
    {
        printf("Stack is full!\n");
    }
    int i;
    printf("size: %d\nStack: ", s->top);
    for(i = 0; i <= (s->top); ++i)
    {
        printf("%d  ", s->data[i]);
    }
    printf("\n\n");
}

//增，进栈
void Push(Stack *s, TypeData data)
{
    if(MAXSIZE-1 == s->top)
    {
        return;
    }
    s->top++;
    s->data[s->top] = data;
}

//删，出栈
void Pop(Stack *s)
{
    if(-1 == s->top)
    {
        return;
    }
    s->top--;
}

//获得栈顶元素
TypeData GetTop(Stack *s)
{
    if(-1 == s->top)
    {
        return;
    }
    return s->data[s->top];
}
