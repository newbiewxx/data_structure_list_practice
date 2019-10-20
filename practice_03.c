/* 2019年10月20日 14:35:15 */
#include<stdio.h>

/* 问题： 已知两个链表A和B分别表示两个集合，其元素依次递增，设计一个算法，用于求A与B的交集，并存放在A链表之中。 */

/* 解题思想：
1. 合并的链表为La 和 Lb，合并后的新链表用头指针Lc来表示，Lc的表头结点同La的表头结点指向。
2. pa 和 pb分别表示链表La 和 Lb的工作结点，初始化都为相应链表的首元结点。
3. 从首元结点开始比较，当La 和 Lb均到达尾结点时，如果表中元素相等，摘取La中元素，删除Lb中元素
   如果其中一个表元素较小，删除较小元素，此表工作指针后移。
4. 当链表La 和 Lb有一个到达尾结点时，依次删除非空表中所有元素，最后释放Lb的头结点
*/

// 将两个递增的有序链表La 和 Lb 合并为一个递增的有序链表Lc
void Intersection(LinkList &La, LinkList &Lb, LinkList &Lc)
{

	pa = La->next; // pa是链表La的工作指针，初始化为首元结点
	pb = Lb->next; // pb是链表Lb的工作指针，初始化为首元结点
	Lc = pc = La;  // 将La的头结点作为Lc的头结点

	while (pa && pb)    // 当La 和 Lb均未到达尾结点
	{
		if (pa->next == pb->next)   // 相等，交集并入结果集中
		{
			pc->next = pa;  // 取出La中元素，将pa链接在pc后面
			pc = pa;  // pc指针后移，为链接下一个作准备
			pa = pa->next;  // pa后移，为下一次比较作准备
			u = pb;  // 保存当前pb结点
			pb = pb->next;  // pb指针后移
			delete u;  // 删除之前pb结点
		}
		else if (pa->next < pb->next)   // 小于pb指针中的值，之前的值再也不会出现交集值，全部删掉
		{
			u = pa;
			pa = pa->next;   // pa后移
			delete u;
		}
		else	 // 小于pa指针中的值，之前的值再也不会出现交集值，全部删掉
		{		
			u = pb;
			pb= pb->next;   // pb后移
			delete u;
		}
	}
	while (pa)   // Lb为空，清空La中的所有元素
	{
		u = pa;
		pa = pa->next;  // pa后移
		delete u;
	}
	while (pb)   // La为空，清空Lb中的所有元素
	{
		u = pb;
		pb = pb->next;  // pb后移
		delete u;
	}
	pc->next = UNLL;   // 置链表Lc为尾标志
	delete Lb;    // 释放Lb的头指针
}
