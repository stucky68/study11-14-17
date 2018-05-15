#include <iostream>
#include <array>
#include <unordered_map>
#include <map>
#include <string>

void testArray()
{
	std::array<int, 4> arr = { 1,2,3,4 };
	for (int value : arr)
	{
		std::cout << "value:" << value << std::endl;
	}
}

void testMap()
{
	std::unordered_map<int, std::string> u = 
	{
		{1, "1"},
		{2, "2"},
		{3, "3"}
	};
	std::map<int, std::string> v =
	{
		{ 1, "1" },
		{ 2, "2" },
		{ 3, "3" }
	};
	std::cout << "std::unordered_map" << std::endl;
	for (const auto &value : u)
	{
		std::cout << "Key:[" << value.first << "] Value:[" << value.second << "]\n";
	}
	std::cout << "std::map" << std::endl;
	for (const auto &value : v)
	{
		std::cout << "Key:[" << value.first << "] Value:[" << value.second << "]\n";
	}

}

int main()
{
	testArray();
	testMap();
	getchar();
	return 0;
}