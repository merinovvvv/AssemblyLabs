//
// Created by merin on 2/5/2024.
//

#ifndef LAB01_OPERATION_H
#define LAB01_OPERATION_H

#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"


class Operation {
public:

    Operation();
    ~Operation() = default;

    static int multiplication(const int &a, const int &b);

    static int division(const int &a, const int &b);

    static int sum(const int &a, const int &b);

    static int subtraction(const int &a, const int &b);

    static void move(int &a, int &b);

private:
    static std::shared_ptr<spdlog::logger> file_logger2;
};

#endif //LAB01_OPERATION_H
