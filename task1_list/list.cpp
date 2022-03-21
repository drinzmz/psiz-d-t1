#include "pch.h"
#include "list.h"

List* initList(void)
{
	List* pRoot = (List*)malloc(sizeof(*pRoot));

	return pRoot;
}

void deinitList(List* pRoot)
{
    free(pRoot->pPlateNum);

    if (pRoot != NULL) {
        free(pRoot);
    }

}

void addCar(List* pRoot, char* plateNum)
{


    while (pLastElement->pNext != NULL)
    {
        pLastElement = pLastElement->pNext;
    }

    pNewElement = (List*)malloc(sizeof(*pNewElement));
    pNewElement->pPlateNum = (char*)malloc(strlen(plateNum) + 1u); //We use 1u (unsigned int), since the number of chars in plateNum can't be negative
    strcpy(pNewElement->pPlateNum, plateNum);
    time(&(pNewElement->entryTime));
    pNewElement->pNext = NULL;
    pLastElement->pNext = pNewElement;

}

void removeCar(List* pRoot, char* plateNum)
{

}

void printAll(List* pRoot) 
{
    List* pCurrent = pRoot->pNext;
    time_t time;


    while (NULL != pCurrent)
    {
        time = pCurrent->entryTime;
        std::cout << "[" << strtok(ctime(&time), "\n") << "] Wjechal samochod o numerze rejestracyjnym " << pCurrent->pPlateNum << std::endl;
        pCurrent = pCurrent->pNext;
    }
}

int numberOfElements(List* pRoot)
{
	return 0;
}
