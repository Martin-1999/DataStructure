#include "LinkList.h"

int main()
{
	Status i;
	ElemType a[] = { 1, 3, 4, 5, 6 };
	LinkList L;

	i = InitList(&L);
	if (i == OK)
	{
		ListDataInit(L, a, sizeof(a) / sizeof(a[0]));
		print(L);
	}

	return 0;
}