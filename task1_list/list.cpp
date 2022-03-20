#include "pch.h"
#include "list.h"



List* initList(void)
{
	List* pRoot = (List*)malloc(sizeof(*pRoot));
	pRoot->pNext = NULL;
	
	return pRoot;
}

void deinitList(List* pRoot)
{
	List* pCurrent = pRoot;
	List* pPrev;
	
	while(pRoot->pNext != NULL)
	{
		while(pCurrent->pNext != NULL)
		{
			pPrev = pCurrent;
			pCurrent = pCurrent->pNext;
		}
		free(pCurrent);
		pCurrent = NULL;
		pPrev->pNext = NULL;
		pCurrent = pRoot;
	}
	
	free(pRoot);
	pRoot = NULL;
	pRoot->pNext = NULL;
	
	
}

void addCar(List* pRoot, char* plateNum)
{

}

void removeCar(List* pRoot, char* plateNum)
{

}
void printAll(List* pRoot) {
	
}

int numberOfElements(List* pRoot)
{
	List* pCurrent = pRoot;
	int number = 0;
	
	if ( pRoot == NULL )
		return 0;
	
	
	while( pCurrent->pNext != NULL )
	{
		pCurrent = pCurrent->pNext;
		number++;
	}
	
	return number+1;
}
