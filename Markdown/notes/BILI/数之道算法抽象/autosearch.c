/*******************************************************************************

* CopyRight (c) HYTC Ltd. All rights reserved.

* Filename:  main.c

* Creator:   GaoLei

* Version:   0.0

* Date:      2011-06-15

* QQ:        38929568

* Description: A*寻路算法 测试类

*******************************************************************************/

#include <stdio.h>

#include 

#include 

#define FALSE   0

#define TRUE    1

#define NULL    0

typedefintBOOL;

intmap[20][20] =

{undefined

{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0 },

{ 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },

{ 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },

{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },

{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },

{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },

{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

};

typedef struct Node

{//节点结构体

intf,g,h;

introw;//该节点所在行

intcol;//该节点所在列

intdirection;//parent节点要移动的方向就能到达本节点

structNode * parent;

}Node, *Lnode;

typedef struct Stack

{//OPEN CLOSED 表结构体

Node * npoint;

struct Stack * next;

}Stack, *Lstack;

int rows = 20;//地图行数

int cols = 20;//地图列数

int G_OFFSET = 1;//每个图块G值的增加值

int destinationRow;//目标所在行

int destinationCol;//目标所在列

int canMoveIndex = 0;//可以通行的地图图块索引

int tileSize = 1;//图块大小

Lstack Open = NULL;

Lstack Closed = NULL;

Node * getNodeFromOpen()

{//选取OPEN表上f值最小的节点，返回该节点地址

Lstack temp = Open->next,min = Open->next,minp = Open;

Node * minx;

if( temp == NULL )

return NULL;

while(temp->next != NULL)

{undefined

if( (temp->next ->npoint->f) npoint->f) )

{undefined

min = temp->next;

minp = temp;

}

temp = temp->next;

}

minx = min->npoint;

temp = minp->next;

minp->next = minp->next->next;

free(temp);

return minx;

}

BOOLEqual(Node * suc,Node * goal)

{//判断节点是否相等，相等，不相等

if( (suc->row == goal->row) && (suc->col == goal->col)  )

{undefined

return TRUE;

}

else

{undefined

return FALSE;

}

}

Node * BelongInOpen( Node * suc )

{//判断节点是否属于OPEN表或CLOSED表，是则返回节点地址，否则返回空地址

Lstack temp = Open -> next ;

if(temp == NULL)

return NULL;

while( temp != NULL )

{undefined

if( Equal(suc,temp->npoint) )

{undefined

return temp -> npoint;

}

else

{undefined

temp = temp->next;

}

}

return NULL;

}

Node * BelongInClosed( Node * suc )

{//判断节点是否属于OPEN表或CLOSED表，是则返回节点地址，否则返回空地址

Lstack temp = Closed -> next ;

if(temp == NULL)

return NULL;

while(temp != NULL)

{undefined

if( Equal(suc,temp->npoint) )

{undefined

return temp -> npoint;

}

else

{undefined

temp = temp->next;

}

}

return NULL;

}

voidPutintoOpen(Node * suc )

{//把节点放入OPEN 或CLOSED 表中

Stack * temp;

temp =(Stack *) malloc(sizeof(Stack));

temp->npoint = suc;

temp->next = Open->next;

Open->next = temp;

}

voidPutintoClosed(Node * suc )

{//把节点放入OPEN 或CLOSED 表中

Stack * temp;

temp =(Stack *) malloc(sizeof(Stack));

temp->npoint = suc;

temp->next = Closed->next;

Closed->next = temp;

}

//得到该图块的H值

intgetH(introw,intcol)

{undefined

return (abs(destinationRow - row) + abs(destinationCol - col));

}

//得到该位置所在地图行

intgetRowPosition(inty)

{undefined

return (y / tileSize);

}

//得到该位置所在地图列

intgetColPosition(intx)

{undefined

return (x / tileSize);

}

//检测该图块是否可通行

BOOLisCanMove(intcol,introw)

{undefined

if(col = cols)

return FALSE;

if(row = rows)

return FALSE;

return map[col][row] == canMoveIndex;

}

Node* checkOpen(introw,intcol)

{undefined

Lstack temp = Open -> next;

if( temp == NULL )

return NULL;

while(temp != NULL)

{undefined

if( (temp->npoint->row==row) && (temp->npoint->col == col)  )

{undefined

return temp -> npoint;

}

else

{undefined

temp = temp->next;

}

}

return NULL;

}

BOOLisInClose(introw,intcol)

{undefined

Lstack temp = Closed -> next;

if( temp == NULL )

return FALSE;

while(temp != NULL)

{undefined

if( (temp->npoint->row==row) && (temp->npoint->col == col)  )

{undefined

returnTRUE;

}

else

{undefined

temp = temp->next;

}

}

returnFALSE;

}

intdirectionIndex =0;

intdirection[256];

voidcreatSeccessionNode(Node *bestNode,introw,intcol)

{undefined

intg = bestNode->g + G_OFFSET;

if(!isInClose(row, col))

{undefined

Node *oldNode = NULL;

if((oldNode = checkOpen(row, col)) != NULL)

{undefined

if(oldNode->g 

{undefined

oldNode->parent = bestNode;

oldNode->g = g;

oldNode->f = g + oldNode->h;

}

}

else

{undefined

Node *node = (Node *) malloc(sizeof(Node));

node->parent = bestNode;

node->g = g;

node->h = getH(row, col);

node->f = node->g + node->h;

node->row = row;

node->col = col;

directionIndex++;

node->direction = directionIndex;

//              openNode.addElement(node);

PutintoOpen( node );

}

}

}

/**

* 根据传入的节点生成子节点

* @param bestNode

* @param destinationRow

* @param destinationCol

*/

voidseachSeccessionNode(Node *bestNode)

{undefined

introw, col;

//      Node *bestNodeInOpen = NULL;

//上部节点

if(isCanMove(row = bestNode->row - 1, col = bestNode->col))

{undefined

creatSeccessionNode(bestNode, row, col);

}

//下部节点

if(isCanMove(row = bestNode->row + 1, col = bestNode->col))

{undefined

creatSeccessionNode(bestNode, row, col);

}

//左部节点

if(isCanMove(row = bestNode->row, col = bestNode->col - 1))

{undefined

creatSeccessionNode(bestNode, row, col);

}

//右部节点

if(isCanMove(row = bestNode->row, col = bestNode->col + 1))

{undefined

creatSeccessionNode(bestNode, row, col);

}

PutintoClosed( bestNode );

}

//正序遍历链表

voidprintfOpenData()

{//判断节点是否属于OPEN表或CLOSED表，是则返回节点地址，否则返回空地址

Lstack temp = Open -> next;

Node *p_node;

if(temp == NULL)

return;

while(temp != NULL)

{undefined

Lstack head = temp;

temp = temp->next;

p_node = head->npoint;

printf("Open库数据！[%d,%d]\n", p_node->col, p_node->row );

free(p_node);

free( head );

Open->next = temp;

}

printf("\n Open库数据 数据全部清楚 \n");

return;

}

voidprintfClosedData()

{//判断节点是否属于OPEN表或CLOSED表，是则返回节点地址，否则返回空地址

Lstack temp = Closed -> next ;

Node *p_node;

if(temp == NULL)

return;

while(temp != NULL)

{undefined

Lstack head = temp;

temp = temp->next;

p_node = head->npoint;

printf("Closed库数据！[%d,%d]\n", p_node->col, p_node->row );

free(p_node);

free( head );

Closed -> next = temp;

}

printf("\n Closed库数据 数据全部清楚 \n");

/*

temp = Closed -> next;

while(temp != NULL)

{undefined

printf("Closed库数据！节点");

temp = temp->next;

}*/

return;

}

voidgetPath(intstartX,intStartY,intdestinationX,intdestinationY)

{undefined

Node *startNode = (Node *) malloc(sizeof(Node));

Node *bestNode  = NULL;

intindex = 0;

destinationRow = getRowPosition(destinationY);

destinationCol = getColPosition(destinationX);

startNode->parent= NULL;

startNode->row = getRowPosition(StartY);

startNode->col = getColPosition(startX);

startNode->g = 0;

startNode->h = getH( startNode->row, startNode->col );

startNode->f = startNode->g + startNode->h;

startNode->direction = 0;

PutintoOpen( startNode );// openNode.add(startNode);

while(TRUE)

{undefined

bestNode = getNodeFromOpen(); //从OPEN表中取出f值最小的节点

if(bestNode == NULL)//未找到路径

{undefined

printf("未找到路径\n");

return;

}

elseif(bestNode->row == destinationRow

&& bestNode->col == destinationCol )

{undefined

Node *_Node = bestNode;

intnodeSum = 0;

intnodeIndex =0;

printf("程序运行次数=%d\n",index);

while( _Node->parent != NULL )

{undefined

printf("x:%d  y:%d  direction = %d \n", _Node->col, _Node->row, _Node->direction );

_Node = _Node->parent;

nodeSum += 1;

}

printf("节点数量=%d\n",nodeSum);

_Node = bestNode;

nodeIndex = nodeSum-1;

while( _Node->parent != NULL && nodeIndex>=0)

{undefined

Node *_NodeParent = _Node->parent;

printf("x:%d  y:%d  direction = %d \n", _Node->col, _Node->row, _Node->direction );

if( _NodeParent->col - _Node->col == 0 && _NodeParent->row - _Node->row == +1 )

{//从父节点到本节点的操作是  上

direction[nodeIndex] = 1;

}

elseif( _NodeParent->col - _Node->col == 0 && _NodeParent->row - _Node->row == -1 )

{//从父节点到本节点的操作是  下

direction[nodeIndex] = 2;

}

elseif( _NodeParent->col - _Node->col == +1 && _NodeParent->row - _Node->row == 0 )

{//从父节点到本节点的操作是  左

direction[nodeIndex] = 3;

}

elseif( _NodeParent->col - _Node->col == -1 && _NodeParent->row - _Node->row == 0 )

{//从父节点到本节点的操作是  右

direction[nodeIndex] = 4;

}

else

{undefined

direction[nodeIndex] = 0;

}

nodeIndex -= 1;

_Node = _Node->parent;

}

for( nodeIndex=0; nodeIndex

{undefined

printf("direction[%d]=%d\n",nodeIndex,direction[nodeIndex]);

}

return;

}

index++;

seachSeccessionNode(bestNode);

}

}

voidmain()

{//主函数

//初始操作，建立open和closed表

Open = (Stack *) malloc(sizeof(Stack));

Open->next = NULL;

Closed = (Stack *) malloc(sizeof(Stack));

Closed->next = NULL;

//-----------------------------------

getPath( 0, 0, 19, 19 );

printf("程序认定该起始状态无法道达目标状态!\n");

printfOpenData();

printfClosedData();

free(Open);

free(Closed);

//--------------------------------------

}