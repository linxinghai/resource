/**
** 初始化open_set和close_set�?
* 将起点加入open_set中，并设置优先级�?0（优先级最高）�?
* 如果open_set不为空，则从open_set中选取优先级最高的节点n�?
    * 如果节点n为终点，则：
        * 从终点开始逐步追踪parent节点，一直达到起点；
        * 返回找到的结果路径，算法结束�?
    * 如果节点n不是终点，则�?
        * 将节点n从open_set中删除，并加入close_set中；
        * 遍历节点n所有的邻近节点�?
            * 如果邻近节点m在close_set中，则：
                * 跳过，选取下一个邻近节�?
            * 如果邻近节点m也不在open_set中，则：
                * 设置节点m的parent为节点n
                * 计算节点m的优先级
                * 将节点m加入open_set�?
*/
#include <stdio.h>

typedef struct _node
{
    int *parant;
    int x,y,rank;
    int *pnext;
}node;

int map[5][5]={
                {0,0,0,0,0},
                {0,-1,-1,0,0},
                {0,0,-1,0,0},
                {0,0,-1,0,0},
                {0,0,0,0,0}
            };

int main()
{
    node open_set,close_set;
    node* phead,pend;
    phead=&open_set;
    initnode();
    open_set.x=0;
    open_set.y=0;
    open_set.rank=0;
    if(open_set!=NULL)
    {
        if()
        {
            while (phead==pend)
            {
                
            }
            
        };
        if()
        {

        };
    }
}

// staring the search
// path sorting
// continuing the search
// summary of the A* method
