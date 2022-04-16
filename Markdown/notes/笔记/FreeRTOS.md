# FreeRTOS

## 基础知识

判断任务完成判断后向事件状态组中存放状态  
执行任务先读取状态是否达成然后才运行


### 多任务系统

前后台系统	

后台指芯片持续在运行的进程(如显示,数据处理,驱动)

而前台则用来处理突发,紧急,重要的事务(如定时,通信,数据输入)

### 任务与协程

运行态(正在运行)	就绪态(即将运行)	阻塞态(等待数据等)	挂起态(被暂停)

![img](https://cdn.jsdelivr.net/gh/linxinghai/pic/image/202201102039900.png)

## 创建与删除任务

创建任务

xTaskCreate()   

​	函数指针
​    函数名
​    栈深
​    函数参数
​    优先级
​    任务句柄

xTaskCreateStatic()

删除任务	

当我们不在不要任务的时候,我们能够删除该任务来用以释放线程所占用的内存

vTaskDelete()//删除一个任务

参数	任务句柄

## 任务挂起和恢复

当我们暂时不需要该任务时能将该任务挂起,来暂停任务的使用

当我们需要再次使用能够恢复被挂起的任务,来再次使用

挂起函数

vTaskSuspend()

恢复函数

 vTaskResume()

他们的参数都是 任务的句柄

## 中断配置和临界段

```c
portNVIC_SYSPRI2_REG |= portNVIC_PENDSV_PRI;//设置好PendSV中断优先级
portNVIC_SYSPRI2_REG |= portNVIC_SYSTICK_PRI;//设置SysTick中断优先级
```

临界段代码



NVIC配置

SCB配置

测试代码片段节选

```C
//中断测试任务函数
//当该函数运行5次后将关闭低于一定中断级别的中断
void interrupt_task(void *pvParameters)
{
    static u32 total_num = 0;
    while(1)
    {
        total_num+=1;
        if(total_num==5)
        {
            printf("关闭中断....\r\n");
            portDISABLE_INTERRUPTS();//关闭中断
            delay_xms(5000);
            printf("打开中断....\r\n");
            portENABLE_INTERRUPTS();//打开中断
    }
}
```

关于中断的初始化与其中断服务函数几乎与原先的没有差别

换句话说就是该部分为可移植的部分(FreeRtos类似于新增一个支持大循环的后台任务系统,但是原先裸机本就支持的**前台中断几乎都可以原码移植**)

或者说他将一个低优先切在不停切换函数指针的中断作为任务后台

```C
//中断初始化及处理
/**
*通用定时器3中断初始化
*这里时钟选择为APB1的2倍,而APB1为32M arr为战自动重载值 psc为分频数
*/
void TIM3_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBascInitTypeDef TIM_TimeBascStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    TIM_TimeBascStructure.TIM_Period = arr;
    TIM_TimeBascStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBascStructure.TIM_CounterMode = TIM_CounterMode_UP;
    TIM_TimeBascInit(TIM3,TIM_IT_Update,ENABLE);
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    TIM_Cmd(TIM3, ENABLE);
}  
//中断服务函数
void TIM3_IRQHandler(void)
{
if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
{
printf("TIM3 输出.......\r\n"); (3)
}
TIM_ClearITPendingBit(TIM3,TIM_IT_Update); //清除中断标志位
}
```

## 列表和列表项

List_t

初始化

vListInitialiseItem

插入

vListInsert

vListInsertEnd

删除

uxListRemove

遍历

listGET_OWNER_OF_NEXT_ENTRY

## 调度器开启和任务相关函数

## 任务切换

异常

任务切换场合

'中断服务函数

查找下一个要运行任务'

时间片调度

## 其他任务API函数



## 时间管理

### 延时函数

vTaskDelay();//延时参数个数节拍数(相对时间)

参数:延时节拍数

使用需要先在宏中定义INCLUDE_vTaskDelay为1

prvAddCurrentTaskToDelayedList();//将任务添加到等待列表

vTaskDelayUntil();//阻塞任务(绝对时间)要求一定频率的任务用该函数延时

参数:上一次任务延时结束被唤醒的时间点	任务需要延时的时间节拍数(相对时间点的节拍数)

### 系统时钟节拍

## 队列

队列结构体

xQUEUIE	Queue_t

创建队列

xQueueCreate

xQueueCreateStatic

xQueueGenericCreate

xQueueGenericCreateStatic

prvInitialiseNewQueue

xQueueGenericReset

向队列发送消息

xQueueSend//发送消息到队列尾部

xQUeueSendToBack

xQueueSendToFront//发送消息到队列头

xQueueOverwite//发送消息到队列,带覆写功能,当队列满了以后自动覆盖旧消息

中断版就不再介绍XXXXXXFromISR

队列上锁和解锁

prvLockQueue

prvUnlockQueue

从队列读取消息

xQueueReceive//从队列中读取列项(消息),且读取完后删除列项

xQueuePeek//从队列中读取列项(消息),且读取完后不删除列项

中断之中

## 信号量

## 软件定时器

定时器服务	Daemon任务

单次定时器和周期定时器

复位软件定时器

xTimerResct//复位软件定时器,在任务中使用

参数:复位软件定时器句柄	阻塞时间

xTimerResctFromISR//同上但区别在该函数作用于中断服务函数中

创建软件定时器

xTimerCreate//动态创建一个软件定时器

参数:

软件定时器名字

软件定时器周期,时钟节拍数

设置定时器模	单次pdFALSE	周期 

定时器ID(当多个定时器的回调函数为同一个时,需要依靠ID来区分那个定时器触发的回调)

定时器回调函数(类似定时器的中断服务函数)

xTimerCreateStatic

开启软件定时器

xTimerStart//在任务中开启定时器

xTimerStartFromISR//在中断中开启定时器

停止软件定时器\

xTimerStop//任务中停止定时器

xTimerStopFromISR//在中断中停止定时器

## 信号量
一般用于资源管理和任务同步
分类:二值信号量  计数型信号量  互斥信号量  递归互斥量

二值信号量

创建二值信号量
vSemaphorreCreateBinary//动态创建二值信号量(老版本)
xSemaphoreCreateBinary//动态创建二值信号量
xSemaphoreCreateBinaryStatic//静态创建二值信号量

释放信号量
xSemaphoreGive
xSemaphoreGiveFormISR
获取信号量
xSemaphoreTask
xSemaphoreTaskFromISR
计数型信号量
Counting
互斥信号量
Mutex
递归互斥量
RecursiveMutex

## 事件标志组
当某个或多个事件或任务进行同步,这时我们就不使用信号量同步任务
而使用事件标志组来进行同步

创建事件标志组

xEventGroupCreate

xEventGroupCreateStatic

设置事件位

//将指定的事件位置设置为0

//参数:

要操作的事件标志组的句柄	

指定要操作的事件位	

标记退出此函数和以后是否进行任务切换

xEventGroupClearBits

xEventGroupClearBitsFromISR

//将指定的事件位置设置为1

xEventGroupSetBits

xEventGroupSetBitFromISR

获取事件标志组值

//获取当前事件标志组的值(各个事件位的值)

//参数:要获取的事件标志组的句柄

xEventGroupGetBits

xEventGroupGetBitsFromISR

等待指定的事件位

xEventGroupWaitBits

参数:

指定要等待的事件标志组

指定要等待的事件位

退出是否要将事件位进行清零

阻塞时间函数

设置阻塞时间(单位为节拍数)

## 任务通知

任务通知

发送任务通知

xTaskNotify//发送通知,带有通知值且不保留接收任务原通知值

xTaskNotifyFromISR

//参数

任务句柄

任务通知值

任务通知更新的方法

xTaskNotifyGive//发送通知,不带通知值且不保留接收任务的通知值,将接收任务的通知值加一

vTaskNotifyGiveFromISR

xTaskNotifyAndQuery//发送通知,带有通知值且保留接收任务的原通知值

xTaskNotifyAndQueryFromISR

任务通知通用放函数

获取任务通知

任务通知模拟

## 低功耗Tickles模式

睡眠

停止

待机

## 空闲任务

空闲任务创建

空闲任务函数

空闲任务钩子函数

vTaskStartScheduler

钩子函数

## 内存管理

内存碎片

内核控制函数

taskYIELD//任务切换

taskENTER_CRITICAL//进入临界区,在任务中

vTaskStartScheduler//开启任务调度

vTaskStepTick//设置系统节拍值













