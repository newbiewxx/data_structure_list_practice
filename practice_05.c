/* 2019年10月21日 14:32:26 */
#include<stdio.h>

/* 问题： 
设计算法一个带头结点的单链表A分解为两个具有相同结构B,C,其中，其中B的结点为A表中值小于零的结点
而C的结点为大于零的结点，链表A的元素非零整数，要求B，C表利用A的结点 */
/*
算法思路:
1. B表的头可以用A的头，需要为C重新申请一个头结点
2. 对A进行遍历同时进行分解，完成结点的重新链接，再次过程记录后继结点防止断链后失去后继结点
3. 题目并未说明新表的结构是否为有序，可以采用前插法更便捷
*/


// 将A分解为具有相同结构的链表B和C
void Decompose(LinkList &A, LinkList $B, LinkList $C)
{	
	B = A; // 将A的头结点交给B
	B->next = NULL;  // B表初始化
	C = new Lnode; // 为C申请结点空间
	C-next = NULL; // C表初始化
	p = A->next; // p为工作指针
	
	while (p != NULL)   // 当A未到达尾结点
	{
	
		r = p->next;  // 保存后继结点
		if (p->data < 0)   // 将值小于0的交给B链
		{
			p->next = B->next;
			B-next = p;			
		}
		else
		{
			p-next = C->next;  // 将值小于0的交给C链
			C-next = p;
		}
		p = r; // p指向新的待处理结点
	}
 }
