#include "pch.h"
#include "list.h"

#include "iostream"

List* initList(void)
{
    List* pRoot = (List*)malloc(sizeof(*pRoot));

    if (pRoot != NULL)
    {
        pRoot->pNext = NULL;
        cout << "Alokacja pamieci zakonczona pomyslnie :)";
    }
    else
    {
        cout << "Blad przydzialu pamieci :(";
    }

    return pRoot;
}

void deinitList(List* pRoot)
{
    free(pRoot->pPlateNum);
    free(pRoot);
}

void addCar(List* pRoot, char* plateNum)
{
    List* pLastElement = pRoot;
    List* pNewElement = NULL;

    while (pLastElement->pNext != NULL)
    {
        pLastElement = pLastElement->pNext;
    }

    pNewElement = (List*)malloc(sizeof(*pNewElement));
    pNewElement->pPlateNum = (char*)malloc(strlen(plateNum) + 1u);
    strcpy(pNewElement->pPlateNum, plateNum); //Funkcja strcpy() nie sprawdza, czy jest wystarczająco dużo miejsca na miejsce docelowe.
                                              //Może to być niebezpieczne, ponieważ strcpy() zastąpi obszar pamięci poza docelowym limitem, 
                                              //co może spowodować przepełnienie bufora. 
                                              //Dlatego zaleca się, aby zamiast tego używać strcpy_s.
    time(&(pNewElement->entryTime));
    pNewElement->pNext = NULL;
    pLastElement->pNext = pNewElement;
}

void removeCar(List* pRoot, char* plateNum)
{
    bool elementFound = false;
    List* pIterElementBefre = NULL;
    List* pIterElement = pRoot;
    List* pIterElementAfter = pRoot->pNext;

    //search until the end of the list or till the element is found
    while ((NULL != pIterElement) && (false == elementFound))
    {
        //Check if we are looking for pIterElement 
        if (0 != strstr(pIterElement->pPlateNum, plateNum))
        {
            elementFound = true; //set the flag
        }
        else //element is still not found
        {
            //if there is next element move to it
            if (NULL != pIterElement->pNext)
            {
                pIterElementBefre = pIterElement;
                if (NULL != pIterElement->pNext)
                    pIterElementAfter = (pIterElement->pNext->pNext);
                else
                    pIterElementAfter = NULL;
                pIterElement = (pIterElement->pNext);
            }
        }
    }
    //if the element has been found
    if (true == elementFound)
    {
        //if element is the last in the list
        if (NULL == pIterElementAfter)
        {
            pIterElementBefre->pNext = NULL;
        }
        else //our element is in the middle in the list
        {
            pIterElementBefre->pNext = pIterElementAfter;
        }
        //remove element from the memory
        free(pIterElement->pPlateNum);
        free(pIterElement);
    }

}
void printAll(List* pRoot) 
{

}

int numberOfElements(List* pRoot)
{
	return 0;
}