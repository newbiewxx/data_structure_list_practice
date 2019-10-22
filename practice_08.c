/*  2019年10月22日 16:06:38 */
#include<stdio.h>

/* 问题: 设计一个算法，删除递增序列表中大于mink以及小于maxk的所有元素。（mink和maxk实现给定，可以和表中元素相同或不同）*/

/*
解题思路:
本题关键在于找到上边界以及下边界，即可找到满需的结点，然后全部删除
1. 查找大于mink的结点，用q指向pre指向该节点的前驱结点
2. 找到大于maxk的结点，用p指向该节点
3. 改下边界前驱结点的指针域，使pre->next = p
4. 依次释放删除结点的空间
*/


// 删除链表中大于mink小于maxk的结点
void DeleteMinMax(LinkList &L,int mink, int maxk) 
{	
	p = L->next;  // p指向首元结点
	
	while (p && p->data <= mink)   // 查找第一个大于mink的结点
	{
		pre = p;
		p = p->next;
	}
	while (p && p->data < maxk)  // 查找第一个大于等于mink的结点
	{
		p = p->next;  // 工作指针后移
		q = pre->next;	// 保留q的指针  及下界临界值
		pre->next = p;  // 修改待删除的结点		
	}
	while (q != p)  // 依次释放带删除的结点
	{
		s = q->next;
		delete q;
		q = s;
	}	
}
