#include <type_traits>
#include <iostream>
#include <vector>

void testNullPtr()
{
	bool value = std::is_same<decltype(NULL), decltype(0)>::value;
	std::cout << value << std::endl;

	value = std::is_same<decltype(NULL), decltype((void *)0)>::value;
	std::cout << value << std::endl;

	value = std::is_same<decltype(NULL), std::nullptr_t>::value;
	std::cout << value << std::endl;
}

constexpr int len() { return 5; }

void testConstexpr()
{
	std::cout << len() << std::endl;
}

void testIf_Switch()
{
	std::vector<int> vec = { 1,2,3,4 };
	if (const std::vector<int>::iterator iter = std::find(vec.begin(), vec.end(), 3);
	iter != vec.end())
	{
		*iter = 4;
		std::cout << *iter << std::endl;
	}
}



int main(int argc, char **argv)
{
	testNullPtr();
	testConstexpr();
	testIf_Switch();

	getchar();
	return 0;
}