// Topic2-pt2-writing our OWN static and dynamic array classes (data structures).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include"array"
#include"vector"

#include<cassert>

using std::cout; 
using std::string; 

/*intended to behave similarly to std::vector*/
//class CustomDynamicArray
//{
//
//};

template<typename T> //T is a standin/placeholder for whatever data type, T, we want!
/*intended to behave similarly to std::array*/
class CustomStaticArray
{
    //member variables 
//public: 
private:
    static const int totalNumberOfElements = 10; 
    //std::array<int, 4> someNums;// = { 1, 2, 3, 4, 5 };
    
    T theData[totalNumberOfElements];   //theData is a pointer! (C-style array -> unsafe)
    
    //member functions 
public: 
    /*This is our default constructor - it ASSUMES that elements are INTEGERS*/
    CustomStaticArray()
    {
        for (int i = 0; i < totalNumberOfElements; i++)
        {
            theData[i] = -999;
        }
    }

    CustomStaticArray(T initialValue)
    {
        for (int i = 0; i < totalNumberOfElements; i++)
        {
            theData[i] = initialValue;
        }

    }

    void print()
    {
        for (int i = 0; i < totalNumberOfElements; ++i)
        {
            cout << theData[i] << " "; 
        }
        cout << "\n";
    }

    //what else "should" go here? 
    T getElementAtGivenIndex(int clientSuppliedIndex)
    {
        assert(clientSuppliedIndex >= 0);
        assert(clientSuppliedIndex < totalNumberOfElements - 1);

        return theData[clientSuppliedIndex];
    }

    void modifyElementAtIndex(int indexToChange, T newValue)
    {
        assert(indexToChange < totalNumberOfElements - 1);

        theData[indexToChange] = newValue; 
    }

};

int main()
{
    std::array<int, 4> someNums = { 1, 2, 3, 4 };
    //someNums.
    //someNums.prin
    //someNums.

    CustomStaticArray <int> someNumbers{};// = { 1, 2, 3, 4 }
    //cout << "Initial contents of the someNumbers: \n";
    //someNumbers.print(); 

    CustomStaticArray <string> someStrings{ "What is going on?\n" };// = { "Alice", "Bob", "Carol" }

    //cout << "\n\n\ninitial contents of someNames:\n";
    //someNames.print(); 

    int desiredIndex = 5;
    someStrings.modifyElementAtIndex(desiredIndex, "aaaaaa\n");
     
    cout << "After modifying an element, the array of words is: \n";
    someStrings.print(); 
   // cout << "The element at index = " << desiredIndex << " is: \n";
    //cout << someNames.getElementAtGivenIndex(desiredIndex) << "\n";


}

