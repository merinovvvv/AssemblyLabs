//
// Created by merin on 2/8/2024.
//

#include <gtest/gtest.h>

struct TestFixtures : public testing::Test {
    //Array<int>* newArr{};
    void SetUp() override {
        //newArr = new Array<int>(3);
    }
    void TearDown() override {
        //delete newArr;
    };
};
