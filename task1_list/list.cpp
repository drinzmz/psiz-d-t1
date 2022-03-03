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
	List* pPrevious;

	while (pRoot->pNext != NULL)
	{
		while (pCurrent->pNext != NULL)
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}
		free(pCurrent);
		pCurrent = NULL;
		pPrevious->pNext = NULL;
		pCurrent = pRoot;
	}

	free(pRoot);
	pRoot = NULL;
}

void addCar(List* pRoot, const char* plateNum)
{
	List* pNext = (List*)malloc(sizeof(*pRoot));
	List* pCurrent = pRoot;
	time_t timer;

	while (pCurrent->pNext != NULL) pCurrent = pCurrent->pNext;

	pNext->entryTime = time(&timer);
	pNext->pPlateNum = const_cast<char*>(plateNum);
	pNext->pNext = NULL;
	pCurrent->pNext = pNext;
}

void removeCar(List* pRoot, const char* plateNum)
{
	List* pCurrent = pRoot;
	List* pPrevious;

	while (pCurrent->pNext != NULL)
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;

		if (pCurrent->pPlateNum == plateNum)
		{
			pPrevious->pNext = pCurrent->pNext;
			free(pCurrent);
			pCurrent = NULL;
			break;
		}
	}
}

void printAll(List* pRoot) 
{
	List* pCurrent = pRoot->pNext;
	time_t time;

	while (pCurrent != NULL)
	{
		time = pCurrent->entryTime;
		std::cout << "[" << strtok(ctime(&time),"\n") << "] Wjechal samochod o numerze rejestracyjnym " << pCurrent->pPlateNum << std::endl;
		pCurrent = pCurrent->pNext;
	}
}

int numberOfElements(List* pRoot)
{
	List* pCurrent = pRoot->pNext;
	int count = 0;

	while (pCurrent != NULL)
	{
		count++;
		pCurrent = pCurrent->pNext;
	}
	return count;
}