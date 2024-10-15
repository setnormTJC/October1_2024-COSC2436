#include "VectorPrime.h"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

namespace MySpace
{
	namespace DataStructs
	{
		/*Initializes all elements from index = 0 to `currentSize` to 0*/
		CharVector::CharVector()
		{
			for (int i = 0; i < currentSize; i++)
			{
				letters[i] = i + 97;//arbitrary-ish
			}
		}

		int CharVector::capacity()
		{
			return maxCurrentCapacity;
		}

		int CharVector::size()
		{
			return currentSize;
		}

		char& CharVector::operator[](int index)
		{
			assert(index < maxCurrentCapacity); //change to size if don't want uninitialized vals

			return letters[index];
		}

		/*pushBACK in std::vector*/
		void CharVector::push(char newValue)
		{
			if (currentSize == maxCurrentCapacity)
			{
				cout << "Increasing vector capacity ..." << endl;
				cout << "(Please, sir (OS), I'd like some more.)" << endl;
				increaseVectorCapacity(currentSize + 5); //add 5 "slots" (somewhat arbitrary value)
			}

			letters[currentSize] = newValue; //"pushFront" might be letters[0] = newValue
			//potentially requiring "rightshift" of ~N elements
			currentSize++;
		}

		void CharVector::increaseVectorCapacity(int newCapacity)
		{
			assert(newCapacity > currentSize); //buffer overrun warning if assert not included

			char* temporaryBlock = new char[newCapacity];
			//A wrong way: 
			//letters = new char[newCapacity]
			//letters will get a different memory address -> old set of letters will get "lost"!

			//copy old data: 
			for (int i = 0; i < currentSize; i++)
			{
				temporaryBlock[i] = letters[i];
			}
			delete[] letters;
			//deallocates old block of memory (prevent memory leak) 
			//makes sure that program isn't holding onto unnecessary resources in the future

			letters = temporaryBlock; //updates pointer to temporaryBlock's memory address
			maxCurrentCapacity = newCapacity;
			cout << "Thank you, sir. May I have another?" << endl;
		}

		void CharVector::pop()
		{
			//char initializedChar{}; //blank space autoinitialization 
			//letters[currentSize - 1] = initializedChar; 
			//letters[currentSize - 1] = ' '; //questionable approach?
			letters[currentSize - 1] = letters[currentSize]; //...

			currentSize -= 1;

		}


		//void CharVector::shrinkToFit()
		//{
		//
		//}


		void CharVector::printMemberVars()
		{
			cout << "current size: " << CharVector::currentSize << "\n";
			cout << "current capacity: " << CharVector::maxCurrentCapacity << "\n";
			cout << "\nvalues in vector: \n";
			for (int i = 0; i < currentSize; i++)
			{
				cout << letters[i] << " ";
			}
			cout << "\n";
			cout << "\nuninitialized values in vector (\"empty\" spots): \n";
			for (int i = currentSize; i < maxCurrentCapacity; i++)
			{
				cout << letters[i] << " ";
			}

			std::cout << "\n";
		}

		void CharVector::printVector()
		{
			for (int i = 0; i < maxCurrentCapacity; i++)
			{
				cout << letters[i] << " ";
			}
			cout << "\n";
		}

		CharVector::~CharVector()
		{
			delete[] letters;
			//std::cin.get(); //portable version of system("pause")
		}

	}
}