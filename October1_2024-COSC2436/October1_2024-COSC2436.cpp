

#include <iostream>

#include<algorithm>
#include <vector>

using std::cout; 
using std::string;
using std::vector;

int main()
{
	vector<int> someNums = { 8, 6, 7, 5, 9, 3, 0, 9, 9 };

	cout << "Is it zero? " << std::min({ 8, 6, 7, 5, 3, 0, 9 }) << "\n";

	cout << "'a' or 'z'? " << std::min('a', 'z') << "\n";
	
	//An unexpected result: 
	//cout << "The final version of std::min returns: " 
	//	<< *std::min(someNums.begin(), someNums.end()) << "\n";

	//reminder of pointers and dereferencing
	int a = 32; 
	int* ptrToA = &a; 
	cout << "32? " << *ptrToA << "\n";



	cout << "Is it 0? " << * std::min_element(someNums.begin(), someNums.end()) << "\n";

	//how to remove the '5' from "Jenny's number"? 
	auto locationOf5 = std::find(someNums.begin(), someNums.end(), 5);
	someNums.erase(locationOf5);

	cout << "Did erasing the value 5 work correctly? \n";
	for (auto& num : someNums)
	{
		cout << num << " ";
	}
	cout << "\n";

	auto locationOfSecond5 = std::find(someNums.begin(), someNums.end(), 5);
	if (locationOfSecond5 != someNums.end())
	{
		someNums.erase(locationOfSecond5);
	}

	else
	{
		cout << "There WAS NO second 5 in that array!\n";
	}

	//Let's erase the value 9 (using C++ version 2020) 
	std::erase(someNums, 9);
	//NOTE: this will not run in default Visual Studio - required C++20

	cout << "Did erasing the value 9 work successfully?\n";
	for (auto& num : someNums)
	{
		cout << num << " ";
	}
	cout << "\n\n";




}
