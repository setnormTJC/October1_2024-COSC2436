// October10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include"C:/Users/Work/Downloads/MyArray.h"


using std::string; 

struct Car
{
    string name = "TBD";
    int miles = -999;

    Car()
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
    os << carObj.name << "and miles " << carObj.miles;
    return os;
}


int main()
{
    MyArray<Car, 3> firstRow = { Car{"Ford", 123}, Car{"Honda", 456}, Car{"Toyota", 989} };
    firstRow.print(); 

    MyArray<Car, 3> secondRow = { Car{"NOT Ford", 1233223}, Car{"NOT Honda", 412356}, Car{"NOT Toyota", 912389} };


    MyArray<MyArray<Car, 3>, 2> mySpecialParkingLot =
    {
        firstRow, 
        secondRow
        //{Car{"Ford", 123}, Car{"Honda", 456}, Car{"Toyota", 989}}//, Car{"adsfads", 12334}
        //{ Car{}, Car{}, Car{} }
    };

    for (int i = 0; i < 3; ++i)
    {
        cout << mySpecialParkingLot[0][0].name << "\n";
    }




    std::cout << "Hello World!\n";
}

