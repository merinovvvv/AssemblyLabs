#include "pch.h"
#include "../lab02/ex1.h"
#include "../ex2/ex2.h"
#include "../ex3/ex3.h"
#include "../ex4/ex4.h"
#include "../ex5/ex5.h"
#include "../ex6/ex6.h"
#include "../ex7/ex7.h"
#include "../ex8/ex8.h"
#include "../ex9/ex9.h"
#include "../ex10/ex10.h"
#include "../ex11/ex11.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

//ex1:

TEST(ex1Test, test1) {
	int a = 1;
	int res = ex1(a);
	EXPECT_EQ(res, 3);
}

TEST(ex1Test, test2) {
	int a = 0;
	int res = ex1(a);
	EXPECT_EQ(res, 0);
}

TEST(ex1Test, test3) {
	int a = 2;
	int res = ex1(a);
	EXPECT_EQ(res, 42);
}

//ex2:

TEST(ex2Test, test1) {
	int a = 2;
	int res = ex2(a);
	EXPECT_EQ(res, 4);
}

TEST(ex2Test, test2) {
	int a = 3;
	int res = ex2(a);
	EXPECT_EQ(res, 9);
}

TEST(ex2Test, test3) {
	int a = 0;
	EXPECT_THROW(ex2(a), std::logic_error);
}

//ex3:

TEST(ex3Test, test1) {
	int32_t a = 2;
	int res = ex3(a);
	EXPECT_EQ(res, 30);
}

TEST(ex3Test, test2) {
	int32_t a = 3;
	int res = ex3(a);
	EXPECT_EQ(res, 19);
}

TEST(ex3Test, test3) {
	int32_t a = 4;
	int res = ex3(a);
	EXPECT_EQ(res, 15);
}

//ex4:
TEST(ex4Test, test1) {
	int16_t A1 = 0x0000;
	int16_t A2 = 0x0000;
	int16_t A3 = 0x0000;
	int16_t B1 = 0x0000;
	int16_t B2 = 0x0000;
	int16_t B3 = 0x0000;

	std::vector<uint16_t> expectedResult = { 0x0000, 0x0000, 0x0000, 0x0000 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 0);
}

TEST(ex4Test, test2) {
	int16_t A1 = 0xFFFF;
	int16_t A2 = 0xFFFF;
	int16_t A3 = 0xFFFF;
	int16_t B1 = 0xFFFF;
	int16_t B2 = 0xFFFF;
	int16_t B3 = 0xFFFF;

	std::vector<uint16_t> expectedResult = { 0xFFFE, 0xFFFF, 0xFFFF, 0x0001 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 562949953421310);
}

TEST(ex4Test, test3) {
	int16_t A1 = 0xFFFF;
	int16_t A2 = 0x0000;
	int16_t A3 = 0x0000;
	int16_t B1 = 0x0001;
	int16_t B2 = 0x0000;
	int16_t B3 = 0x0000;

	std::vector<uint16_t> expectedResult = { 0x0000, 0x0001, 0x0000, 0x0000 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 65536);
}

TEST(ex4Test, test4) {
	int16_t A1 = 0x0002;
	int16_t A2 = 0xFFFF;
	int16_t A3 = 0x0000;
	int16_t B1 = 0x0009;
	int16_t B2 = 0x0001;
	int16_t B3 = 0x0000;

	std::vector<uint16_t> expectedResult = { 0x000B, 0x0000, 0x0001, 0x0000 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 4294967307);
}

TEST(ex4Test, test5) {
	int16_t A1 = 0xFFFF;
	int16_t A2 = 0xFFFF;
	int16_t A3 = 0xEFFF;
	int16_t B1 = 0x0001;
	int16_t B2 = 0x0000;
	int16_t B3 = 0x0000;

	std::vector<uint16_t> expectedResult = { 0x0000, 0x0000, 0xF000, 0x0000 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 263882790666240);
}

TEST(ex4Test, test6) {
	int16_t A1 = 0x0100;
	int16_t A2 = 0x2BA0;
	int16_t A3 = 0x000F;
	int16_t B1 = 0x0000;
	int16_t B2 = 0x0000;
	int16_t B3 = 0x0000;

	std::vector<uint16_t> expectedResult = { 0x0100, 0x2BA0, 0x000F, 0x0000 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 65156415744);
}

TEST(ex4Test, test7) {
	int16_t A1 = 0xFFFF;
	int16_t A2 = 0x0000;
	int16_t A3 = 0x0000;
	int16_t B1 = 0xFFFF;
	int16_t B2 = 0x0001;
	int16_t B3 = 0x0000;

	std::vector<uint16_t> expectedResult = { 0xFFFE, 0x0002, 0x0000, 0x0000 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 196606);
}

TEST(ex4Test, test8) {
	int16_t A1 = 0xFFFF;
	int16_t A2 = 0xFFFF;
	int16_t A3 = 0x0000;
	int16_t B1 = 0x0001;
	int16_t B2 = 0x0001;
	int16_t B3 = 0x0000;

	std::vector<uint16_t> expectedResult = { 0x0000, 0x0001, 0x0001, 0x0000 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 4295032832);
}

TEST(ex4Test, test9) {
	int16_t A1 = 0xFFFF;
	int16_t A2 = 0xFFFF;
	int16_t A3 = 0x0000;
	int16_t B1 = 0x0001;
	int16_t B2 = 0x0001;
	int16_t B3 = 0x000F;

	std::vector<uint16_t> expectedResult = { 0x0000, 0x0001, 0x0010, 0x0000 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 68719542272);
}

TEST(ex4Test, test10) {
	int16_t A1 = 0xFFFF;
	int16_t A2 = 0xFFFF;
	int16_t A3 = 0x000F;
	int16_t B1 = 0x0001;
	int16_t B2 = 0x0001;
	int16_t B3 = 0x0001;

	std::vector<uint16_t> expectedResult = { 0x0000, 0x0001, 0x0011, 0x0000 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 73014509568);
}

TEST(ex4Test, test11) {
	int16_t A1 = 0xFFFF;
	int16_t A2 = 0xFFFF;
	int16_t A3 = 0xFFFF;
	int16_t B1 = 0x0001;
	int16_t B2 = 0x0000;
	int16_t B3 = 0x0000;

	std::vector<uint16_t> expectedResult = { 0x0000, 0x0000, 0x0000, 0x0001 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 281474976710656);
}

TEST(ex4Test, test12) {
	int16_t A1 = 0xFFFF;
	int16_t A2 = 0xFFFF;
	int16_t A3 = 0xFFFF;
	int16_t B1 = 0xFFFF;
	int16_t B2 = 0xFFFF;
	int16_t B3 = 0xFFFF;

	std::vector<uint16_t> expectedResult = { 0xFFFE, 0xFFFF, 0xFFFF, 0x0001 };

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	for (size_t i = 0; i < res.size(); ++i) {
		EXPECT_EQ(res[i], expectedResult[i]);
	}

	uint64_t C = (static_cast<uint64_t>(res[3]) << 48) | (static_cast<uint64_t>(res[2]) << 32) | (static_cast<uint64_t>(res[1]) << 16) | (static_cast<uint64_t>(res[0]));

	EXPECT_EQ(C, 562949953421310);
}

//ex5:

TEST(ex5Test, test1) {
	std::pair<int, int> result = countAmountOfZeroAndEven(24680);
	EXPECT_EQ(result.first, 1);
	EXPECT_EQ(result.second, 5);
}

TEST(ex5Test, test2) {
	std::pair<int, int> result = countAmountOfZeroAndEven(-13579);
	EXPECT_EQ(result.first, 0);
	EXPECT_EQ(result.second, 0);
}

TEST(ex5Test, test3) {
	std::pair<int, int> result = countAmountOfZeroAndEven(0);
	EXPECT_EQ(result.first, 1);
	EXPECT_EQ(result.second, 1);
}

//ex6:

TEST(ex6Test, test1) {
	std::pair<int, std::string> result = GcdAndFraction(15, 10);
	EXPECT_EQ(result.first, 5); 
	EXPECT_EQ(result.second, "3/2");
}

TEST(ex6Test, test2) {
	ASSERT_THROW(GcdAndFraction(5, 0), std::logic_error);
	ASSERT_THROW(GcdAndFraction(5, -3), std::logic_error);
}

TEST(ex6Test, test3) {
	std::pair<int, std::string> result = GcdAndFraction(0, 7);
	EXPECT_EQ(result.first, 0);
	EXPECT_EQ(result.second, "0/1");
}

TEST(ex6Test, test4) {
	std::pair<int, std::string> result = GcdAndFraction(123456, 7890);
	EXPECT_EQ(result.first, 6);
	EXPECT_EQ(result.second, "20576/1315");
}

//ex7:

TEST(ex7Test, test1) {
	EXPECT_EQ(NumInDeg(2, 3), 8);
	EXPECT_EQ(NumInDeg(3, 4), 81);
}

TEST(ex7Test, test2) {
	EXPECT_EQ(NumInDeg(5, 0), 1);
}

TEST(ex7Test, test3) {
	EXPECT_EQ(NumInDeg(-2, 3), -8);
	EXPECT_EQ(NumInDeg(2, -3), 0);
}

//ex8:

TEST(ex8test, test1) {
	std::pair<int, int> result = degOfTwo(10);
	EXPECT_EQ(result.first, 3);
	EXPECT_EQ(result.second, 4);

	result = degOfTwo(16);
	EXPECT_EQ(result.first, 4);
	EXPECT_EQ(result.second, 5);
}

TEST(ex8test, test2) {
	ASSERT_THROW(degOfTwo(0), std::logic_error);
}

//ex9:

TEST(ex9test, test1) {
	std::vector <int> a = { 5, 1, 1, 2, 2, 3 };
	int* ptr = a.data();
	vectorRebuild(ptr);
	auto it = a.end() - 2;
	a.erase(it, a.end());
	std::vector <int> b = { 3, 1, 2, 3 };

	EXPECT_EQ(a, b);
}

TEST(ex9test, test2) {
	std::vector <int> a = { 10, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6};
	int* ptr = a.data();
	vectorRebuild(ptr);
	auto it = a.end() - 4;
	a.erase(it, a.end());
	std::vector <int> b = { 6, 1, 2, 3, 4, 5, 6 };

	EXPECT_EQ(a, b);
}

TEST(ex9test, test3) {
	std::vector <int> a = { 3, 1, 1, 2 };
	int* ptr = a.data();
	vectorRebuild(ptr);
	std::vector <int> b = { 2, 1, 2 };
	auto it = a.end() - 1;
	a.erase(it, a.end());
	EXPECT_EQ(a, b);
}

//ex10:

TEST(ex10test, test1) {
	std::vector <int> a = { 1, 2, 3 };
	int* ptr1 = a.data();
	std::vector <int> b = { 4, 5, 6 };
	int* ptr2 = b.data();
	std::vector <int> res = vectorMerge(ptr1, ptr2, a.size());
	std::vector <int> test = { 1, 2, 3, 4, 5, 6 };

	EXPECT_EQ(res, test);
}

TEST(ex10test, test2) {
	std::vector <int> a = { 1, 2, 4 };
	int* ptr1 = a.data();
	std::vector <int> b = { 3, 5, 6 };
	int* ptr2 = b.data();
	std::vector <int> res = vectorMerge(ptr1, ptr2, a.size());
	std::vector <int> test = { 1, 2, 3, 4, 5, 6 };

	EXPECT_EQ(res, test);

}

//ex11:

TEST(ex11test, test1) {
	std::vector<int> a = { 4, 7, 2 };
	std::vector<int> b = { 7, 4, 15 };
	std::vector<int> c = { 4, 7 };
	EXPECT_EQ(arrayIntersection(a, b, c), 1);
}

TEST(ex11test, test2) {
	std::vector<int> a = { 4, 7, 2 };
	std::vector<int> b = { 7, 4, 15 };
	std::vector<int> c = { 4, 7, 7 };
	EXPECT_EQ(arrayIntersection(a, b, c), 0);
}

TEST(ex11test, test3) {
	std::vector<int> a = { 4, 7, 2 };
	std::vector<int> b = { 7, 4, 15 };
	std::vector<int> c = { 4, 5 };
	EXPECT_EQ(arrayIntersection(a, b, c), 0);
}