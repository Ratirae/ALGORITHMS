#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "ShareDef.h"


//结构·
typedef struct
{
    TypeData data[MAXSIZE];
    int head;   //队头，从这里出队
    int tail;   //队尾，尾后指针，从这里入队
}Queue;

void ShowQueue();

//初始化
void InitQueue(Queue **qu);

//打印调试
void PrintQueue(Queue *qu);

//入队
void EnQueue(Queue *qu, TypeData data);

//出队
void DeQueue(Queue *qu);















#endif // QUEUE_H_INCLUDED
