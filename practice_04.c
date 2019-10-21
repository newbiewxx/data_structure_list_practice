/* 2019年10月21日 12:30:38 */
#include<stdio.h>

/* 问题： 
已知两个链表的A和B分别两个集合，其元素递增排列，设计算法求A和B集合的差集（在A中而不再B中出现的元素所构成的集合),
并以同样的形式存储，同时返回该集合的元素个数 */
/*
算法思路:
1. 关键点在于要保存带删除结点的前驱
2. La如果小于Lb的元素，La的元素即为带求差集中的元素，差集元素+1
3. pre置于La的工作指针pa，pa后移
4. Lb如果小于La,pb后移
5. La元素如果等于Lb元素，则删除La该
*/


// La和Lb差集的结果存在于La中，n是结果集中的元素，调用时为0
void Difference(LinkList &La, LinkList $Lb, int &n)
{	
	pa = La->next;  // pa是链La的工作指针，初始化为首元结点
  pb = Lb->next;  // pb是链Lb的工作指针，初始化为首元结点
	pre = La;

	while (pa && pb) { // La 和 Lb链表均不为空
		if (pa->data < pb ->data) // A链表当前结点指针后移
		{
			n++;  // 元素+1
			pre = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data) // B链表后移
		{
			pb = pb->next;
  		}
		else  // 相等时
		{
			pre->next = pa->next;
			u = pa;
			pa = pa->next;
			delete u;  // 删除结点
		}
	}	
}
