/* 2019年10月20日 12:46:16 */
#include<stdio.h>
/* 练习一：
将两个非递减的有序链表合并为一个非递增的有序链表。要求结果链表仍使用原来两个链表的存储空间，不另外占用其他的存储空间。表中允许有重复的数据

注意： 
1. 非递减，即为递增，含有相同元素
2. 非递增，即为递减，含有相同元素
*/

/* 解题思想：
1. 合并的链表为La 和 Lb，合并后的新链表用头指针Lc来表示，Lc的表头结点同La的表头结点指向。
2. pa 和 pb分别表示链表La 和 Lb的工作结点，初始化都为相应链表的首元结点。
3. 从首元结点开始进行比较，当两个链表La 和 Lb均达到表尾结点时，依次摘取其较小者重新连接在Lc表头结点的后面。
4. 如果两表元素相同，摘取La表中的元素，保留Lb中的元素
5. 当一个表的到达表尾结点为空时，将非空的表剩余元素依次摘取接到Lc表的表头结点之后，并释放链表Lb的头结点
*/


// 将两个非递减的有序链表La,Lb合并为一个新的非递增
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{
	pa = La->next; // pa是La的工作指针，初始化为首元结点
	pb = Lb->next; // pb是La的工作指针，初始化为首元结点
	Lc = pc = La;  // 将La的头结点作为Lc的头结点
	Lc-next = NULL;  // 利用前插法

	while (pa || pb) { // 只要有一个表未达到表尾结点
		if (!pa) {   // 当La为空时，用q指向 pb,pb指针后移
			q = pb;  
			pb = pb->next;
		}
		else if (!pb) {   // 当Lb为空时，用q指向 pa,pa指针后移
			q = pa;  
			pa = pa->next;
		}
		else if (pa->data <= pb->next) { // 取较小者La中的元素，用q指向pa，pa指针后移 
			q = pa;
			pa =pa->next;
		}
		else // 取较小者Lb中的元素，用q指向pb，pb指针后移 
		{
			q =pb;
			pb =pb->next;
		}
		// 此行代码为插入元素关键代码，否则将出现断链
		q->next = Lc->next;
		Lc->next = q;  // 将q所指向的结点插在Lc的表头之后
	}
	delete Lb; // 释放Lb的头结点
}
