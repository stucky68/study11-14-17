#include <type_traits>
#include <iostream>
#include <vector>
#include <initializer_list>

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
	std::cout << "constexpr int len() { return 5; } " << len() << std::endl;
}

void testIf_Switch()
{
	std::vector<int> vec = { 1,2,3,4 };
	if (const std::vector<int>::iterator iter = std::find(vec.begin(), vec.end(), 3);
	iter != vec.end())
	{
		*iter = 4;
		std::cout << "if (const std::vector<int>::iterator iter = std::find(vec.begin(), vec.end(), 3); iter != vec.end()) " << *iter << std::endl;
	}

	switch (int i = 6)
	{
	case 6:
		std::cout << "switch (int i = 6)" << std::endl;
		break;
	}
}

void testInitalizer_list()
{
	class MagicFoo
	{
	public:
		std::vector<int> vec;
		MagicFoo(std::initializer_list<int> list)
		{
			for (std::initializer_list<int>::iterator it = list.begin();
				it != list.end(); ++it)
			{
				vec.push_back(*it);
			}
		}
		void foo(std::initializer_list<int> list)
		{
			std::cout << "MagicFoo.foo() :" << std::endl;
			for (std::initializer_list<int>::iterator it = list.begin();
				it != list.end(); ++it)
			{
				std::cout << *it << "\t";
			}
			std::cout << std::endl;
		}
	};
	MagicFoo magicFoo = { 1, 2, 3, 4 };
	std::cout << "Initalizer_list:";
	for (std::vector<int>::iterator it = magicFoo.vec.begin();
		it != magicFoo.vec.end(); ++it)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	magicFoo.foo({ 6,7,8,9 });
}

std::tuple<int, double, std::string> f()
{
	return std::make_tuple(1, 2.3, "456");
}

void testTuple()
{
	auto[x, y, z] = f();
	std::cout << "x: " << x << std::endl 
		<< "y: " << y << std::endl 
		<< "z: " << z.c_str() << std::endl;
}

template<typename T, typename U>
auto add2(T x, U y) ->decltype(x + y)
{
	return x + y;
}

template<typename T, typename U>
auto add3(T x, U y)
{
	return x + y;
}

void testDecltype()
{
	auto x = 1;
	auto y = 2;
	decltype(x + y) z;
	if (std::is_same<decltype(x), int>::value)
	{
		std::cout << "type x == int" << std::endl;
	}
	if (std::is_same<decltype(y), float>::value)
	{
		std::cout << "type y == float" << std::endl;
	}
	if (std::is_same<decltype(x), decltype(z)>::value)
	{
		std::cout << "type x == type z" << std::endl;
	}
	//after c++11
	auto w = add2<int, double>(1, 2.0);
	if (std::is_same<decltype(w), double>::value)
	{
		std::cout << "w is double£º";
	}
	std::cout << w << std::endl;

	//after c++14
	auto q = add3<double, int>(1.0, 2);
	std::cout << "q:" << q << std::endl;
}

template<typename T0>
void printf(T0 value)
{
	std::cout << value << std::endl;
}

template <typename T, typename ... Args>
void printf(T value, Args... args)
{
	std::cout << value << std::endl;
	printf(args...);
}

template <typename T0, typename ... T>
void printf1(T0 t0, T... t)
{
	std::cout << t0 << std::endl;
	if constexpr (sizeof...(t) > 0) printf(t...);
}

template <typename T, typename ...Args>
auto printf2(T value, Args ...args)
{
	std::cout << value << std::endl;
	return std::initializer_list<T>{([&] {
		std::cout << args << std::endl;
	}(), value)...};
}


void testRecTemplate()
{
	printf(1, 2, "123", 1.1);
	printf1(1, 2, "1234", 1.2);
	printf2(1, 2, "1234", 1.3);
}

template <typename ...T>
auto sum(T ...t)
{
	return (t + ...);
}

void testFoldExpr()
{
	std::cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
}


int main(int argc, char **argv)
{
	testNullPtr();
	testConstexpr();
	testIf_Switch();
	testInitalizer_list();
	testTuple();
	testDecltype();
	testRecTemplate();
	testFoldExpr();

	getchar();
	return 0;
}