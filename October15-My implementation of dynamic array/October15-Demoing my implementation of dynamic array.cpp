// October15-My implementation of dynamic array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<vector> 

#include"VectorPrime.h"
//using namespace std; 

namespace SomeNamespace
{
	int a = 32; 
}

using namespace MySpace::DataStructs;

using std::cout; 


int main()
{
	CharVector dynamicListOfLetters{}; 
	//cout << dynamicListOfLetters.back() << "\n";
	
	cout << "INITIAL vector (aka: dynamic array) contents: \n";
	dynamicListOfLetters.printVector(); 

	dynamicListOfLetters.increaseVectorCapacity(20); 
	dynamicListOfLetters.push('z'); 
	dynamicListOfLetters.push('y');
	dynamicListOfLetters.push('x');
	dynamicListOfLetters.push('w');


	cout << "UPDATED Capacity is: " << dynamicListOfLetters.capacity() << "\n";
	
	cout << "FINAL vector (aka: dynamic array) contents: \n";
	dynamicListOfLetters.printVector(); 

	//std::vector
	//std::cout << 
	//using namespace SomeNamespace; 
	//std::cout << SomeNamespace::a << "\n";


}
