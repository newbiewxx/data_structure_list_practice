/* 2019年10月20日 11:29:10 */
#include<stdio.h>
/* 练习一：
将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间，不另外占用其他的存储空间。表中不允许有重复的数据.
*/

/* 解题思想：
1. 合并的链表为La 和 Lb，合并后的新链表用头指针Lc来表示，Lc的表头结点同La的表头结点指向。
2. pa 和 pb分别表示链表La 和 Lb的工作结点，初始化都为相应链表的首元结点。
3. 从首元结点开始进行比较，当两个链表La 和 Lb均达到表尾结点时，依次摘取其较小者重新连接在Lc表的最后。
4. 如果两表元素相同，摘取La表中的元素，删除Lb中的元素，这样去日报无重复
5. 当一个表的到达表尾结点为空时，将非空的表剩余元素接到Lc表的最后，并释放链表Lb的头结点
*/


// 将两个递增的有序链表La 和 Lb 合并为一个递增的有序链表Lc
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{

	pa = La->next; // pa是链表La的工作指针，初始化为首元结点
	pb = Lb->next; // pb是链表Lb的工作指针，初始化为首元结点
	Lc = pc = La;  // 将La的头结点作为Lc的头结点

	while (pa && pb) {   // 当La 和 Lb均未到达尾结点

		if (pa->data < pb->data) {
			// 取较小者中La中的元素，将pa连接在pc的后面， pa的指针后移
			pc -> next = pa;
			pc = pa;  // pc也跟着后移
			pa = pa -> next; // pa指针后移
		}
		else if (pa->data > pb->data) {
			// 取较小者中Lb中的元素，将pb连接在pc的后面， pb的指针后移
			pc->next = pb;
			pc = pb;  // pc也跟着后移
			pb = pb -> next; // pb指针后移
		}
		else {
			// 当二者相等时，取La中元素，删除Lb中元素
			pc->next = pa;  
			pc = pa;  // pc后移
			pa = pa>next; // pa 后移
			q = pb->next;  // 创建一个临时变量，保存后驱，防止断链
			delete pb;  // 删除当前pb结点
			pb = q;    // 指针后移
		}
	}
	// 此时已经有链表为空
	pc->next = pa ? pa:pb; // 将非空链表剩余元素直接链接在Lc表的后面
	delete Lb; // 释放Lb的有指针
}

