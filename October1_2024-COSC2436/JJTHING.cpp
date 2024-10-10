#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T> 
class Color //simple class
{
public:
	string color_name;
	int hex_num; //0x = hexadecimal integers 

};

void doSomething(int a)
{
	cout << a << "\n";
}
int main()
{

	Color <int> purp_color;//making class objects
	purp_color.color_name = "eggplant";
	purp_color.hex_num = 0x5a4e88; //5918344 hexadecimal value

	Color green_color;
	green_color.color_name = "shamrock green";
	green_color.hex_num = 0x4da57c; //5088636 

	Color orange_color;
	orange_color.color_name = "exotic blossom";
	orange_color.hex_num = 0xfd9d45; //16620869

	Color red_color;
	red_color.color_name = "race car stripe";
	red_color.hex_num = 0xcf4944; //13584708

	vector<Color> colors;//vector for objects to mingle

	colors.push_back(purp_color);
	colors.push_back(green_color);
	colors.push_back(orange_color);
	colors.push_back(red_color);//inserting object into vector

	//---------------------------------------------------

	std::sort(colors.begin(), colors.end(), [](const Color& a, const Color& b)
		{
			return a.color_name < b.color_name; //ascend < by first char "alphabetically"
		});

	cout << " color list sort (ascending) : " << "\n" << endl;
	for (const auto& color : colors)
	{
		cout << " color name: " << color.color_name << ", hexadecimal:#" << hex << color.hex_num << endl; //std::hex output format
	}

	cout << "\n";
	cout << "----------------------------------------------------" << endl; //space
	cout << "\n";

	std::sort(colors.begin(), colors.end(), [](const Color& a, const Color& b)
		{
			return a.hex_num > b.hex_num; //descend > by hexadeciaml true value
		});

	cout << " hexadecimal number sort (descending) : " << "\n" << endl;
	for (const auto& color : colors)
	{
		cout << " color name: " << color.color_name << ", hexadecimal:#" << hex << color.hex_num << endl;
	}

	return 0;
}