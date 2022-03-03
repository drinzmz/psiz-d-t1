#include "pch.h"
#include "list.h"
#include <ctime>

List mojaLista;

int main()
{
	List* pFirstFloor = initList();
	List* pSecFloor = initList();
	
	addCar(pFirstFloor, "EA27WB");
	//_sleep(2000);
	addCar(pFirstFloor, "EB34WB");
	//_sleep(1000);
	addCar(pFirstFloor, "EC22WB");
	addCar(pFirstFloor, "ED22WB");
	addCar(pFirstFloor, "EE22WB");
	
	printAll(pFirstFloor);
	std::cout <<"Liczba aut: " << numberOfElements(pFirstFloor) << std::endl << std::endl;

	removeCar(pFirstFloor, "EB34WB");
	removeCar(pFirstFloor, "EE22WB");

	printAll(pFirstFloor);
	std::cout << "Liczba aut: " << numberOfElements(pFirstFloor) << std::endl << std::endl;

	deinitList(pFirstFloor);
	deinitList(pSecFloor);
}
