#include <iostream>
#include <map>

void testDelegatingConstructor()
{
	//委托构造
	class Base
	{
	public:
		int value1;
		int value2;
		Base()
		{
			value1 = 1;
		}
		Base(int value) : Base()
		{
			value2 = 2;
		}
	};
	//委托构造
	Base b(2);
	std::cout << b.value1 << std::endl;
	std::cout << b.value2 << std::endl;
}

//显示虚函数重载
void testOverride()
{
	class Base
	{
		virtual void foo(int) {}
	};
	class SubClass : public Base
	{
		virtual void foo(int) override { }
		/* 错误 父类没有这个虚函数
		virtual void foo(float) override { }
		*/
	};
}

void testFinal()
{
	class Base
	{
		virtual void foo() final {}
	};
	class SubClass1 final : public Base
	{

	};

	/* 非法 SubClass1已经final
	class SubClass2 : public SubClass1 { };
	*/

	/* 非法 foo已经final
	class SubClass3 : public Base
	{
		void foo() {}
	};
	*/
}

template <typename Key, typename Value, typename F>
void update(std::map<Key, Value> &m, F foo) 
{
	for (auto &[key, value] : m) 
		value = foo(key);
}

void testStructuredBinding()
{
	std::map<std::string, long long int> m
	{
		{ "a", 1 },
		{ "b", 2 },
		{ "c", 3 }
	};
	update(m, [](std::string key) 
	{
		return std::hash<std::string>{}(key);
	});
	for (auto &&[key, value] : m)
		std::cout << key.c_str() << ":" << value << std::endl;
}

void testFunc(int a, int b, int c)
{
	std::cout << a << b << std::endl;
}

int main()
{
	testDelegatingConstructor();
	testOverride();
	testFinal();
	testStructuredBinding();
	getchar();
	
	return 0;
}