/**
 * @file 路径搜索算法.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-16
 * 
 * @copyright Copyright (c) 2022
    queue
    stack
    dfs
    bfs
    f=g+h
*/
int map[]={
                {{-1,1},{0,1},{1,1}},
                {{-1,0},{0,0},{1,0}},
                {{-1,-1},{0,-1},{1,-1}}
            };

typedef struct Queue
{
    int number;
    int arr[2];
    int G;
    int H;
    int parent;
    Queue_t *pnext;
}Queue_t;
struct searchedqueue
{
    
}

int main()
{
    
    return 0;
}
