#include "pch.h"
#include "../lab02/ex1.h"
#include "../ex2/ex2.h"
#include "../ex3/ex3.h"
#include "../ex4/ex4.h"

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
	int16_t A1 = 0;
	int16_t A2 = 0;
	int16_t A3 = 0;
	int16_t B1 = 0;
	int16_t B2 = 0;
	int16_t B3 = 0;

	std::vector <uint16_t> res = ex4 (A1, A2, A3, B1, B2, B3);

	EXPECT_EQ(res[0], 0);
	EXPECT_EQ(res[1], 0);
	EXPECT_EQ(res[2], 0);

	uint64_t C = ((uint64_t)res[2] << 32) | ((uint64_t)res[1] << 16) | res[0];

	EXPECT_EQ(C, 0);
}

TEST(ex4Test, test2) {
	int16_t A1 = 9;
	int16_t A2 = 8;
	int16_t A3 = 7;
	int16_t B1 = 9;
	int16_t B2 = 8;
	int16_t B3 = 7;

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	EXPECT_EQ(res[0], 18);
	EXPECT_EQ(res[1], 16);
	EXPECT_EQ(res[2], 14);

	uint64_t C = ((uint64_t)res[2] << 32) | ((uint64_t)res[1] << 16) | res[0];

	EXPECT_EQ(C, 60130590738);
}
TEST(ex4Test, test3) {
	int16_t A1 = 4;
	int16_t A2 = 8;
	int16_t A3 = 3;
	int16_t B1 = 9;
	int16_t B2 = 6;
	int16_t B3 = 3;

	std::vector <uint16_t> res = ex4(A1, A2, A3, B1, B2, B3);

	EXPECT_EQ(res[0], 13);
	EXPECT_EQ(res[1], 14);
	EXPECT_EQ(res[2], 6);

	uint64_t C = ((uint64_t)res[2] << 32) | ((uint64_t)res[1] << 16) | res[0];

	EXPECT_EQ(C, 25770721293);
}