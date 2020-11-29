#include<string.h>
#include<ctype.h>
#include<malloc.h> /* malloc()µ» */
#include<limits.h> /* INT_MAXµ» */
#include<stdio.h> /* EOF(=^ZªÚF6),NULL */
#include<stdlib.h> /* atoi() */
#include<io.h> /* eof() */
#include<math.h> /* floor(),ceil(),abs() */
#include<process.h> /* exit() */

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status;
typedef int Boolean;
typedef int ElemType;

typedef struct ListNode
{
	ElemType data;
	struct ListNode *next;
}*LinkList;

//typedef struct ListNode *LinkList;

Status InitList(LinkList *L);
void ListDataInit(LinkList L, ElemType a[], int len);
void DestroyList(LinkList *L);
Status ListEmpty(LinkList L);
void print(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L,int i,ElemType *e);
int LocateElem(LinkList L,ElemType e);
Status ListInsert(LinkList L,int i,ElemType e);
Status ListDelete(LinkList L,int i,ElemType *e);


