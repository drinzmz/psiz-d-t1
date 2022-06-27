#include "pch.h"
#include "list.h"
#include <ctime>

int main()
{
	List* firstFloor = initList();
	addCar(firstFloor, (char*)"AA0000");
	addCar(firstFloor, (char*)"AA0001");
	removeCar(firstFloor, (char*)"AA0000");
	removeCar(firstFloor, (char*)"AA0001");

	List* secFloor = initList();
	addCar(secFloor, (char*)"AA0002");
	addCar(secFloor, (char*)"AA0003");
	removeCar(secFloor, (char*)"AA0002");
	removeCar(secFloor, (char*)"AA0003");

	deinitList(firstFloor);
	deinitList(secFloor);

	return 0;
}
