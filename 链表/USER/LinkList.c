#include "LinkList.h"


Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(struct ListNode)); /* 产生头结点,并使L指向此头结点 */
	if (!*L) /* 存储分配失败 */
		exit(OVERFLOW);
	(*L)->next = NULL; /* 指针域为空 */
	return OK;
}

void ListDataInit(LinkList L, ElemType a[], int len)
{
	LinkList p = L, s;

	while(len--)
	{
		s = (LinkList)malloc(sizeof(struct ListNode)); /* 生成新结点 */
		s->data = a[len];
		s->next = p->next;
		p->next = s;
	}
}

void DestroyList(LinkList *L)
{
	LinkList q;
	while(*L)
	{
		q = (*L)->next;
		free(*L);
		*L = q;
	}
}

Status ListEmpty(LinkList L)
{
	if(L->next)
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{ /* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
	int i = 0;
	LinkList p = L->next; /* p指向第一个结点 */
	while(p) /* 没到表尾 */
	{
		i++;
		p = p->next;
	}
	return i;
}

Status ListInsert(LinkList L,int i,ElemType e) 
{
	int j = 0;
	LinkList p = L, s;
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = (LinkList)malloc(sizeof(struct ListNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

void print(LinkList L){
	LinkList p = L->next;
	printf("所有元素:");
	while (p!=NULL) 
	{		
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

Status GetElem(LinkList L,int i,ElemType *e) /* 算法2.8 */
{ /* L为带头结点的单链表的头指针。当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR */
	int j = 1; /* j为计数器 */
	LinkList p = L->next; /* p指向第一个结点 */
	while (p&&j < i)  /* 顺指针向后查找,直到p指向第i个元素或p为空 */
	{
		p = p->next;
		j++;
	}
	if (!p || j > i) /* 第i个元素不存在 */
		return ERROR;
	*e = p->data; /* 取第i个元素 */
	return OK;
}

int LocateElem(LinkList L,ElemType e)
{
	int i = 0;
	LinkList p = L->next;
	while(p)
	{
		i++;
		if (p->data == e) /* 找到这样的数据元素 */
			return i;
		p = p->next;
	}
	return 0;
}

Status ListDelete(LinkList L,int i,ElemType *e) /* 算法2.10。不改变L */
{ /* 在带头结点的单链线性表L中，删除第i个元素,并由e返回其值 */
	int j = 0;
	LinkList p = L, q;
	while (p->next&&j < i - 1)  /* 寻找第i个结点,并令p指向其前趋 */
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) /* 删除位置不合理 */
		return ERROR;
	q = p->next; /* 删除并释放结点 */
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}
