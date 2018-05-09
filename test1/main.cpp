#include <gtest\gtest.h>
#include <type_traits>


int Foo(int a, int b)
{
	if (a == 0 || b == 0)
	{
		throw "don't do that";
	}
	int c = a % b;
	if (c == 0)
		return b;
	return Foo(b, c);
}

TEST(TestNullPtr, NullPtr)
{
	bool value = std::is_same<decltype(NULL), decltype(0)>::value;
	EXPECT_TRUE(value);

	value = std::is_same<decltype(NULL), decltype((void *)0)>::value;
	EXPECT_TRUE(value);

	value = std::is_same<decltype(NULL), std::nullptr_t>::value;

	EXPECT_TRUE(value);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}