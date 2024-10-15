// October15-Demoing my implementation of dynamic array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include"VectorPrime.h"


using std::cout; 

int main()
{
	//while (true)
	//{
	//	int* ptrToAnInt = new int; //"naked new" (a use of new that is not "matched" by a DELETE operation
	//	delete ptrToAnInt; //DE-allocates the memory given to this pointer

	//	//this is the worst possible memory leak that can be created! (take this with a grain of salt)
	//}

	//system("pause"); 
	
	cout << "How big do you want the array of integers to be?\n";

	int desiredSize;// = 42;
	std::cin >> desiredSize; 

	//int staticCStyleArray[desiredSize];
	cout << "The amount of memory allocated for an integer is: " << sizeof(int) << " BYTES \n";
	int* dynamicallyGeneratedArrayPointer = new int[desiredSize];
	//The new keyword does 2 things: 
	//1 -> it makes space in RAM in the amount requested 
	//2 -> it RETURNS a MEMORY address (which gets stored in a POINTER data type) 
	

	//int* dynamicallyGeneratedArrayPointer = new int[desiredSize];
	for (int i = 0; i < desiredSize; i++)
	{
		dynamicallyGeneratedArrayPointer[i] = i; 
		cout << dynamicallyGeneratedArrayPointer[i] << "\n";
	}


}
