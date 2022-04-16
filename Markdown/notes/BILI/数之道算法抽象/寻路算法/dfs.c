/**
 * @file dfs.c
 * @author your name (you@domain.com)
 * @brief 只进行三种操作 *2  +5  -3 
 *        取的从4开始得到56的最简洁步骤
 *        fifo
 * @version 0.1
 * @date 2022-01-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct searchqueue
{
    int date;
    struct searchqueue *pNext;
}Queue_t;

Queue_t *CreateQueue(int num)
{
    Queue_t* p = (Queue_t*)malloc(sizeof(Queue_t));
    p->date = num;
    p->pNext = NULL;
    return p;
}

void addend(Queue_t *sEnd,Queue_t *p)
{
    sEnd->pNext = p;
    sEnd = p;
    sEnd->pNext = NULL;
}

void headdelete(Queue_t *sHead,Queue_t *sEnd,Queue_t *qEnd)
{
    Queue_t *pTemp = sHead;
    int temp = sHead->date;
    sHead = sHead->pNext;
    addend(qEnd,sHead);
    addend(sEnd,CreateQueue(temp*2));
    addend(sEnd,CreateQueue(temp+5));
    addend(sEnd,CreateQueue(temp-3));
}

int main()
{
    Queue_t *sHead,*sEnd = NULL;
    Queue_t *qEnd = NULL;
    Queue_t* qHead = (Queue_t*)malloc(sizeof(Queue_t));
    sHead = CreateQueue(4);
    sEnd = sHead;
    addend(sEnd,CreateQueue(8));
    qEnd = qHead;
    printf("star");
    do
    {
        //printf(".");
        headdelete(sHead,sEnd,qEnd);
    } while (qEnd->date != 9);
    printf("ok");
}