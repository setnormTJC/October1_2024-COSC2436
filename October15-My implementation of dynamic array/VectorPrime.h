#pragma once
#include <initializer_list>


namespace MySpace
{
	namespace DataStructs
	{
		/*
		No template use - only for character data 
		*/
		class CharVector
		{
			//a, b, c, d, e, _, _, _, _, _
			int currentSize = 5; //this will change! (because this class is meant to be a DYNAMIC vector!) 
			char* letters = new char[2 * 5];
			//letters[0] = 'a'
			int maxCurrentCapacity = 2 * currentSize; //just one approach 

		public:
			CharVector();

			int capacity();

			int size();

			char& operator[](int index);

			void printMemberVars();

			/*checks if currentSize == currentCapacity
			if not - inserts `newValue` at next empty (uninitialized) position
			if so - calls `increaseVectorCapacity` and THEN inserts `newValue` at next empty position
			*/
			void push(char newValue);

			/*removes first element and decreases SIZE by 1 (no change to capacity)*/
			void pop();

			/*gets last (initialized) element*/
			char back();

			/*called "top" for stack*/
			char front();

			void increaseVectorCapacity(int newCapacity);

			void shrinkToFit();

			void printVector(); //function declaration 

			~CharVector();
		};

	}
}
