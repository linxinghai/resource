# Markdown教学

## 标题

# 一级标题

 ========= 

## 二级标题

------------



## 段落格式
段落1  
段落2

段落3

### 字体

*斜体*

_斜体_

**粗体**

__粗体__

***粗体斜体***

___粗体斜体___

### 分割线

***
* * *
*****
- - -
--------
删除线

~~删除~~

下划线

<u>下划线</u>

脚注

 [^要注明的文本]

[^要注明的文本]:                 脚        注

## 列表

* 1
+ 2
- 3

1. da:
	- 1.1
2. ad

## 区块
>区块
>
>>嵌套

## 代码

`printf()`函数
```
​	<?php

​		echo 'r';

​		function test(){
​			echo 'test';
​		}
```


```javascript
$(document).ready(function(){
	alert('r');
});
```

## 链接

这是一个链接 [菜鸟教程](https://www.runoob.com)
<https://www.runoob.com>

这个链接用 1 作为网址变量 [Google][1]
这个链接用 runoob 作为网址变量 [Runoob][runoob]
然后在文档的结尾为变量赋值（网址）

[1]: http://www.google.com/
[runoob]: http://www.runoob.com/

## 图片

![RUNOOB 图标](http://static.runoob.com/images/runoob-logo.png)
这个链接用 1 作为网址变量 [RUNOOB][1].
然后在文档的结尾为变量赋值（网址）

[1]: http://static.runoob.com/images/runoob-logo.png
![RUNOOB 图标](http://static.runoob.com/images/runoob-logo.png "RUNOOB")
<img src="http://static.runoob.com/images/runoob-logo.png" width="50%">

## 表格

| 左对齐 | 右对齐 | 居中对齐 |
| :-----| ----: | :----: |
| 单元格 | 单元格 | 单元格 |
| 单元格 | 单元格 | 单元格 |

## 高级


加粗	Ctrl+B 或者 **加粗** 或者 __加粗__	加粗
斜体	Ctrl+I 或者 *斜体* 或者 _斜体_	斜体
加粗且斜体	***加粗且斜体*** 或者 ___加粗且斜体___	加粗且斜体
下划线	Ctrl+U 或者 下划线	下划线
删除线	Alt+Shift+5 或者 ~~删除线~~	删除线
水平分割线	*** 或者 - - - 或者 _ _ _	—
高亮	==高亮==	高亮
下标	~下标~	下标2
上标	^上标^	上标2
注释	[^注释1]	注释注释1
代码	Ctrl+Shift+` 或者 ``	代码
选中一行	Ctrl+L	/
选中一个单词	Ctrl+D	/
选中相同格式的文字	Ctrl+E	/
生成目录	[TOC]	/
一级标题	Ctrl+1 或者 #+空格+文字	/
二级标题	Ctrl+2 或者 ##+空格+文字	/
三级标题	Ctrl+3 或者 ###+空格+文字	/
四级标题	Ctrl+4 或者 ####+空格+文字	/
五级标题	Ctrl+5 或者 #####+空格+文字	/
六级标题	Ctrl+6 或者 ######+空格+文字	/
返回顶部	Ctrl+Home	/
返回底部	Ctrl+End	/
创建表格	Ctrl+T	/
创建超链接	Ctrl+K 或者 [链接名称](链接地址)	百度
搜索并替换	Ctrl+H	/
插入图片	Ctrl+Shift+I 或者 复制粘贴 或者 直接拖动 或者![图片的替代文字](图片地址)	/
表情	:happy: 或者 :smiley: 或者 :cry:	? ? ?
向右缩进	Tab	/
向左缩进	Shift+Tab	/
引言	Ctrl+Shift+Q 或者 >+空格	/
有序列表	Ctrl+Shift+[ 或者 *+空格	/
无序列表	Ctrl+Shift+] 或者 *+空格	/