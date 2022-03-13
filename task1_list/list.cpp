#include "pch.h"
#include "list.h"



List* initList(void)
{
	List* pRoot = (List*)malloc(sizeof(*pRoot));

	if (pRoot == NULL)
	{
		std::cout << "B³¹d: Alokacji pamiêci nie powiod³a siê!" << std::endl;
		return NULL;
	}

	pRoot->pNext = NULL;
	
	return pRoot;
}

void deinitList(List* pRoot)
{
	free(pRoot);
	pRoot = NULL;
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
	return 0;
}