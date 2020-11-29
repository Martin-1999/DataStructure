#include "LinkList.h"


Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(struct ListNode)); /* ����ͷ���,��ʹLָ���ͷ��� */
	if (!*L) /* �洢����ʧ�� */
		exit(OVERFLOW);
	(*L)->next = NULL; /* ָ����Ϊ�� */
	return OK;
}

void ListDataInit(LinkList L, ElemType a[], int len)
{
	LinkList p = L, s;

	while(len--)
	{
		s = (LinkList)malloc(sizeof(struct ListNode)); /* �����½�� */
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
{ /* ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
	int i = 0;
	LinkList p = L->next; /* pָ���һ����� */
	while(p) /* û����β */
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
	printf("����Ԫ��:");
	while (p!=NULL) 
	{		
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

Status GetElem(LinkList L,int i,ElemType *e) /* �㷨2.8 */
{ /* LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ,��ֵ����e������OK,���򷵻�ERROR */
	int j = 1; /* jΪ������ */
	LinkList p = L->next; /* pָ���һ����� */
	while (p&&j < i)  /* ˳ָ��������,ֱ��pָ���i��Ԫ�ػ�pΪ�� */
	{
		p = p->next;
		j++;
	}
	if (!p || j > i) /* ��i��Ԫ�ز����� */
		return ERROR;
	*e = p->data; /* ȡ��i��Ԫ�� */
	return OK;
}

int LocateElem(LinkList L,ElemType e)
{
	int i = 0;
	LinkList p = L->next;
	while(p)
	{
		i++;
		if (p->data == e) /* �ҵ�����������Ԫ�� */
			return i;
		p = p->next;
	}
	return 0;
}

Status ListDelete(LinkList L,int i,ElemType *e) /* �㷨2.10�����ı�L */
{ /* �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ��,����e������ֵ */
	int j = 0;
	LinkList p = L, q;
	while (p->next&&j < i - 1)  /* Ѱ�ҵ�i�����,����pָ����ǰ�� */
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) /* ɾ��λ�ò����� */
		return ERROR;
	q = p->next; /* ɾ�����ͷŽ�� */
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}
