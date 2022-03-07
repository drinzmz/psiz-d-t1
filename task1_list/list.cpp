#include "pch.h"
#include "list.h"
#include "iostream"

using namespace std;

List* initList(void)
{
	List* pRoot = (List*)malloc(sizeof(*pRoot));

	if (pRoot == NULL)
	{
		cout << "Memory allocation error";
	}
	else if (pRoot != NULL)
	{
		pRoot->pNext = NULL;
		cout << "Memory allocation done successfully" << endl;
	}

	else
	{
		cout << "pNext not NULL. Error" << endl;

	}

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
void printAll(List* pRoot)
{

}

int numberOfElements(List* pRoot)
{
	return 0;
}