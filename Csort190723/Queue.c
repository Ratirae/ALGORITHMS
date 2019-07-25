#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "Queue.h"


void ShowQueue()
{
    Queue *qu;
    InitQueue(&qu);
    PrintQueue(qu);
    EnQueue(qu, 4);
    PrintQueue(qu);
    EnQueue(qu, 5);
    PrintQueue(qu);
    EnQueue(qu, 6);
    PrintQueue(qu);
    DeQueue(qu);
    PrintQueue(qu);
}

//初始化·
void InitQueue(Queue **qu)
{
    *qu = malloc(sizeof(Queue));
    (*qu)->head = 0;   //队头和队尾相等才是空
    (*qu)->tail = 0;
}

//打印调试
void PrintQueue(Queue *qu)
{
    if(qu->head == qu->tail)
    {
        printf("Queue is empty!\n");
    }
    if((qu->tail+1)%MAXSIZE == qu->head )
    {
        printf("Queue is full!\n");
    }
    int len = ((qu->tail)-(qu->head) + MAXSIZE) % MAXSIZE;
    int i = qu->head;
    printf("length: %d\n", len);
    while(i != qu->tail )
    {
        printf("%d  ", qu->data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n\n");
}

//入队
void EnQueue(Queue *qu, TypeData data)
{
    if((qu->tail+1)%MAXSIZE == qu->head )
    {
        printf("Queue is full!\n");
        return;
    }
    qu->data[qu->tail] = data;
    qu->tail = (qu->tail) + 1;
}

//出队
void DeQueue(Queue *qu)
{
    if(qu->head == qu->tail)
    {
        printf("Queue is empty!\n");
        return;
    }
    qu->tail = (qu->tail - 1 + MAXSIZE) % MAXSIZE;
}

























