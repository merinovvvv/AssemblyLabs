#include <gtest/gtest.h>
#include "Operation.h"
#include "Program.h"

// Test cases for the Operation class
TEST(OperationTest, MultiplicationTest) {
    EXPECT_EQ(Operation::multiplication(3, 4), 12);
    EXPECT_EQ(Operation::multiplication(-2, 5), -10);
    EXPECT_EQ(Operation::multiplication(0, 7), 0);
}

TEST(OperationTest, DivisionTest) {
    EXPECT_EQ(Operation::division(10, 2), 5);
    EXPECT_EQ(Operation::division(-15, 3), -5);
    EXPECT_THROW(Operation::division(7, 0), std::invalid_argument); // Division by zero should throw an exception
}

TEST(OperationTest, SumTest) {
    EXPECT_EQ(Operation::sum(5, 7), 12);
    EXPECT_EQ(Operation::sum(-3, 9), 6);
}

TEST(OperationTest, SubtractionTest) {
    EXPECT_EQ(Operation::subtraction(10, 3), 7);
    EXPECT_EQ(Operation::subtraction(-5, -2), -3);
}

TEST(OperationTest, MoveTest) {
    int a = 5, b = 10;
    Operation::move(a, b);
    EXPECT_EQ(a, 10);
}

// Test cases for the Program class
TEST(ProgramTest, DataParserTest) {
    Program program;
    std::map<std::string, int> data = program.dataParser("../files/test_input.txt");

    EXPECT_EQ(data.size(), 3);
    EXPECT_EQ(data["var1"], 10);
    EXPECT_EQ(data["var2"], 20);
    EXPECT_EQ(data["var3"], 0); // '?' value should be initialized as 0
}

TEST(ProgramTest, CodeParserTest) {
    Program program;
    program.dataParser("../files/test_input.txt");
    program.codeParser("../files/test_input.txt");

    EXPECT_EQ(program.getResult(), 30); // 10 + 20 = 30
}

TEST(ProgramTest, FileWriteTest) {
    Program program;
    program.dataParser("../files/test_input.txt");
    program.codeParser("../files/test_input.txt");

    program.writeToFile("../files/test_output.txt");

    std::ifstream outputFile("../files/test_output.txt");
    std::string line;
    getline(outputFile, line);
    EXPECT_EQ(line, "The result equals to: 30");
}

TEST(ProgramTest, MainTest) {
    // Integration test for the main functionality
    int result = Program::main();
    EXPECT_EQ(result, 30); // The expected result after parsing the input file
}

TEST(ProgramTest, InvalidFileTest) {
    Program program;
    // Attempting to parse an invalid file should throw an exception
    EXPECT_THROW(program.dataParser("../files/nonexistent_file.txt"), std::ifstream::failure);
    EXPECT_THROW(program.codeParser("../files/nonexistent_file.txt"), std::ifstream::failure);
}

TEST(ProgramTest, InvalidOperationTest) {
    Program program;
    program.dataParser("../files/test_input.txt");
    // Testing with an invalid operation in the code section
    EXPECT_THROW(program.codeParser("../files/invalid_operation_input.txt"), std::invalid_argument);
}
