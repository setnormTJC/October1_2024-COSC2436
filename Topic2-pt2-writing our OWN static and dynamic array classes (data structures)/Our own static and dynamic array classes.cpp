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
    static const int totalNumberOfElements = 3; 
    //std::array<int, 4> someNums;// = { 1, 2, 3, 4, 5 };
    
    T theData[totalNumberOfElements];   //theData is a pointer! (C-style array -> unsafe)
    
    //member functions 
public: 
    /*This is our default constructor - it ASSUMES that elements are INTEGERS*/
    CustomStaticArray() //= delete;
    {
        for (int i = 0; i < totalNumberOfElements; i++)
        {
            int a{};
           /* theData[i] = -999;*/ //silly initialization assuming integer data type (no templates) 
            theData[i] = T{}; //will call the default constructor of Car 
        }
    }

    CustomStaticArray(const T&initialValue)
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
            cout << theData[i] << "\n"; 
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

    T& operator [] (int clientSpecifiedIndex)
    {
        try
        {
            if (clientSpecifiedIndex < 0)
            {
                throw std::exception{ "out of bounds" };
            }
            return theData[clientSpecifiedIndex];

        }

        catch (std::exception e)
        {
            cout << e.what() << "\n";
        }
        
    }

};

struct Car
{
    string name = "TBD";
    int miles = -999; 

    Car() //= delete;
    {

    }

    Car(string name, int miles)
        :name(name), miles(miles)
    {

    }

    friend std::ostream& operator<<(std::ostream& os, const Car& carObj);

};

std::ostream& operator<<(std::ostream& os, const Car& carObj)
{
    os << carObj.name << " with mileage = " << carObj.miles;
    return os;
}

int main()
{
    //Car defaultCar2(); 
    Car defaultCar{};
    //Car defaultCar{}; 
    cout << "defaultCar: " << defaultCar << "\n";

    //int defaultInt; 
    int defaultInt{}; 
    cout << "defaultInt: " << defaultInt << "\n";

    system("pause"); 
   // int a = 32; 
   // int copyOfA = a; 

   // int& referenceToA = a; 
   // //cout << "Initial values of a and its DEEP copy: " << a << "\t" << referenceToA << "\n";
   // a = 47469; 

   // //cout << "values of a and its DEEP copy AFTER modifying a (and a alone): " << a << "\t" << referenceToA << "\n";

   // std::array<int, 4> someNums = { 1, 2, 3, 4 };
   // //someNums.
   // //someNums.prin
   // //someNums.

   // CustomStaticArray <int> someNumbers{};// = { 1, 2, 3, 4 }
   // //cout << "Initial contents of the someNumbers: \n";
   // //someNumbers.print(); 

   // CustomStaticArray <string> someStrings{ "What is going on?\n" };// = { "Alice", "Bob", "Carol" }

   // //cout << "\n\n\ninitial contents of someNames:\n";
   // //someNames.print(); 

   // int desiredIndex = -22;
   // //someStrings.modifyElementAtIndex(desiredIndex, "aaaaaa\n");
   // 
   // someStrings[desiredIndex] = "this string will be inserted at the given index";

   // cout << "After modifying an element, the array of words is: \n";
   // someStrings.print(); 
   //// cout << "The element at index = " << desiredIndex << " is: \n";
   // //cout << someNames.getElementAtGivenIndex(desiredIndex) << "\n";

    CustomStaticArray<Car> firstRowOfCars{ Car{"Ford", 123'001} };
    CustomStaticArray<Car> secondRowOfCars{ Car{"Honda", 99'999} };

    //cout << firstRowOfCars[0].miles << "\n";

    using parkingLotType = CustomStaticArray<CustomStaticArray<Car>>; //an alias!

    //simpler example of alias: 
    using INTEGER = int; 
    //INTEGER mySpecialNumber = 42; 

    parkingLotType mySpecialParkingLot{ firstRowOfCars };
    mySpecialParkingLot[1] = secondRowOfCars; 

    //mySpecialParkingLot.print(); //printing a 2D array of type Car didn't work!
    
    mySpecialParkingLot[0].print(); //how about printing a 1D array (row/column) of Cars?
    cout << "The mileage of the car in the SECOND row and first column is: "
        << mySpecialParkingLot[1][0].miles << "\n";

    //cout << mySpecialParkingLot[1][0].name << "\n"; //print the name of the car in the 2nd row, 1st column

    //parkingLotType mySpecialParkingLot{ RowOfCars };




}

