/**
 * @file 遗传算法.c
 * @author your name (you@domain.com)
 * @brief 染色体 基因 遗传 互换 变异 繁殖
 *        祖先群落 演化出新新部落 新旧合并 适合度值排序 优胜群落 演化代数
 *        代码说明:祖先群落随机生成N个染色体
 * @version 0.1
 * @date 2022-01-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define evolution_of_algebra 10

int *group[10];

int swap(int *px,int *py)
{
    int temp = *px;
    px = *py;
    py = temp;
}

int Create_SatrGroup()
{
    int (*gene)[5] = NULL;
    for (int i = 0; i < 5; i++)
    {
        gene = function(10);
        *group[i] = gene;
    }
    return &group;
}

int GiveGene(int count)
{
    int arr[10];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (rand() % count);
    }
    return &arr;
}

void newswap(int *group[10])
{
    int a = rand()%10;
    int b = rand()%10;
    int *p1 = &group[a];
    int *p2 = &group[b];
    swap(p1+1,p2+1);
    swap(p1+2,p2+2);
    group[6] = p1;
    group[7] = p2;
}

void newchange(int *group[10])
{
    int a = rand()%10;
    int *p = &group[a];
    *(p+a) = rand()%10;
    group[8] = p;
}

void conformitysort()
{
    int arr1[10],arr2[10];
    for (int i = 0; i < count; i++)
    {
        arr1[i] = function();//获取每组基因的评分
    }
    Getgene();//获得优胜基因
}
void heredity()
{

}

int main()
{
    groupinit();//生成祖先群落
    for (int i = 0; i < evolution_of_algebra; i++)
    {
        newswap();//群落繁殖的新个体
        newchange();//群落发生个体变异
        conformity();//个体竞争
        heredity();//优胜群落形成新群落
    }
}