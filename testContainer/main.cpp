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

auto getStudent(int id)
{
	if (id == 0)
	{
		return std::make_tuple(3.8, 'A', "zhangsan");
	}
	if (id == 1)
	{
		return std::make_tuple(2.9, 'C', "lisi");
	}
	if (id == 2)
		return std::make_tuple(1.7, 'D', "wangwu");
	return std::make_tuple(0.9, 'D', "NULL");
}

void testTuple()
{
	auto student = getStudent(0);
	std::cout << "ID: 0, "
		<< "GPA:" << std::get<0>(student) << ", "
		<< "Grade:" << std::get<1>(student) << ", "
		<< "Name:" << std::get<2>(student) << "\n";
	double gpa;
	char grade;
	std::string name;
	std::tie(gpa, grade, name) = getStudent(1);
	std::cout << "ID: 1, "
		<< "GPA:" << gpa << ", "
		<< "Grade:" << grade << ", "
		<< "Name:" << name << "\n";

	auto new_tuple = std::tuple_cat(getStudent(0), getStudent(1));
	double gpa1;
	char grade1;
	std::string name1;
	std::tie(gpa, grade, name, gpa1, grade1, name1) = new_tuple;
	std::cout << "ID: 0, "
		<< "GPA:" << gpa << ", "
		<< "Grade:" << grade << ", "
		<< "Name:" << name << "\n";
	std::cout << "ID: 1, "
		<< "GPA:" << gpa1 << ", "
		<< "Grade:" << grade1 << ", "
		<< "Name:" << name1 << "\n";
}

void testSharedPtr()
{
	auto pointer = std::make_shared<int>(10);
	auto pointer2 = pointer;
	auto pointer3 = pointer;
	int *p = pointer.get();
	std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;

	pointer2.reset();
	std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;

	pointer3.reset();
	std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;
}

struct Foo
{
	Foo()
	{
		std::cout << "Foo::Foo" << std::endl;
	}
	~Foo()
	{
		std::cout << "Foo::~Foo" << std::endl;
	}
	void foo()
	{
		std::cout << "Foo::foo" << std::endl;
	}
};

void f(const Foo &)
{
	std::cout << "f(const Foo&)" << std::endl;
}

void testUniquePtr()
{
	std::unique_ptr<Foo> p1(std::make_unique<Foo>());
	if (p1)
		p1->foo();
	{
		std::unique_ptr<Foo> p2(std::move(p1));
		f(*p2);
		if (p2)
			p2->foo();
		if (p1)
			p1->foo();
		p1 = std::move(p2);
		if (p2)
			p2->foo();
		std::cout << "~p2()" << std::endl;
	}
	if (p1)
		p1->foo();
}


int main()
{
	testArray();
	testMap();
	testTuple();
	testSharedPtr();
	testUniquePtr();
	getchar();
	return 0;
}