#include "pch.h"
#include "list.h"

List* initList(void)
{
	List* pRoot = (List*)malloc(sizeof(*pRoot));

	return pRoot;
}

void deinitList(List* pRoot)
{
	free(pRoot);
	pRoot = NULL;
}

void addCar(List* pRoot, char* plateNum)
{
<<<<<<< HEAD
   if(pRoot.size() === 0)
   {
=======
   
    if(pRoot.size() === 0){
>>>>>>> 2bce3657802988d32c61c6ae1ca01288863828b0
        cout << "pRoot is empty";
    }
	else
	{
        cout << "pRoot is not empty ";
<<<<<<< HEAD
	}
}

=======
		
    }
>>>>>>> 2bce3657802988d32c61c6ae1ca01288863828b0
void removeCar(List* pRoot, char* plateNum)
{

}
void printAll(List* pRoot) {

}

int numberOfElements(List* pRoot)
{
	return 0;
}
