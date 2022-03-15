#include "pch.h"
#include "list.h"
#include <ctime>

using namespace std;

List* initList(void)
{
	List* pRoot = (List*)malloc(sizeof(*pRoot));
	if (pRoot != NULL)
	{
		cout << "Memory allocation done successfully";
	}
	else
	{
		cout << "Memory allocation error" << endl;
	}

	return pRoot;
}
