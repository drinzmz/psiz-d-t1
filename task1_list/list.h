#pragma once
#ifndef LIST_H
#define LIST_H

typedef struct List {
	char* pPlateNum;
	time_t entryTime;
	struct List* pNext;
} List;

List*initList(void);
void deinitList(List* pRoot); //empty the list to execute the following functions
void addCar(List* pRoot, char* plateNum);// we add cars to the list of parking lot cars
void removeCar(List* pRoot, char* plateNum);// removes a car that has left the parking lot
void printAll(List* pRoot); // show all cars in the parking lot
int numberOfElements(List* pRoot);// show number of cars

#endif // !LIST_H
