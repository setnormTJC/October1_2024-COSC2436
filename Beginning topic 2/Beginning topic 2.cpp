// Beginning topic 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include<queue> //queue (line) 

#include<map> 

//std::priority_queue
#include<list> 


using std::cout, std::string, std::vector;

//abstract classes have at least one "pure" virtual function

/*we will do this later ...*/
class LinkedList
{
	//add some member vars

	//add some algorithms (AKA: functions) that allow manipulation 
	//of the linked list object 
	void insertAtFrontOfList(); 

	void insertAtBackOfList(); 

};

class Stack
{
	//member vars:

	//add some member functions (algorithms for "common" processes) 
};


int main()
{
	std::list<int> someListNums; 
	//someListNums.pus
	std::vector <string> someNames =
	{
		"Bob",
		"Alice",
		"Darth"
	};

	//for (auto& name : someNames)
	//{
	//	cout << name << "\n";
	//}
	
	std::queue <string> lane1AtGroceryStore; 
	lane1AtGroceryStore.push("Bob"); 
	lane1AtGroceryStore.push("Boboe");
	lane1AtGroceryStore.push("Alice");
	lane1AtGroceryStore.push("Darth");



	//print the contents of the queue? 
	//for (auto& personAtGroceryStore : lane1AtGroceryStore) //doesn't work!
	//{

	//}
	//lane1AtGroceryStore.print
	//for (int i = 0; i < lane1AtGroceryStore.size(); ++i)
	//{
	while (!lane1AtGroceryStore.empty())
	{
		cout << lane1AtGroceryStore.front() << " ";
		lane1AtGroceryStore.pop(); 
	}

	//}
/*	{
		"Bob", 
		"Alice", 
		"Darth"
	};*/ //"initializer list syntax" in C++
	
	//lane1AtGroceryStore.

	//std::map
}
