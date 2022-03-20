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
	
	List* pCurrent = pRoot;
	int i = 1;
	
	while( pCurrent->pNext != NULL )
	{
		std::cout << i << ", ";
		while( pPlateNumb != NULL )
		{
			std::cout << pCurrent->pPlateNum;
			pCurrent->pPlateNum++;
		}
		std::cout << " " << ctime(pCurrent->entryTime << "\n";
		i++;
		
	}

}

int numberOfElements(List* pRoot)
{
	return 0;
}
