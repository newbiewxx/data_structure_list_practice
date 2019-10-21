/* 2019年10月21日 15:15:24 */
#include<stdio.h>

/* 问题： 
设计一个算法，通过遍历确定长度为n的单链表之中的最大值，返回该节点的数据域
*/
/*
解题思想：
1. 将指针pmax指向首元结点，在依次与后者比较
2. 当发现后面大于前者，最大值指针给后者
*/

// 确定单链表中最大结点，并返回该数据域
ElemType Max(LinkList &A)
{	
	if (A->next = NULL)  // 首先判断该链表是否为空
	{
		return NULL;
	}
	
	pmax = L->next;  // 将最大值初始为第一个结点
	p = L->next->next;  // 将p指向下下个结点

	while (p != NULL)  // 遍历结点，如果下一节点存在
	{
		if (pa->data > pmax->data) // 如果后者大于前者，将最大值结点给后者
		{
			pmax = p;
			p = p->next;   // 指针后移
		}
		else
		{
			p = p->next; // 后移继续遍历
		}
	}
	return pmax->data;  // 返回最大数据域
}
