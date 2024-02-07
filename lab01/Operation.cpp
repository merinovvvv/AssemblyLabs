//
// Created by merin on 2/5/2024.
//

#include "Operation.h"

std::shared_ptr<spdlog::logger> Operation::file_logger3 = spdlog::basic_logger_mt("operation_logger", "../files/spdlog.txt");

Operation::Operation() {
    file_logger3 ->set_level(spdlog::level::debug);
}

int Operation::multiplication(const int& a, const int& b) {
    file_logger3->debug("multiplication func.");
    return a * b;
}

int Operation::division(const int& a, const int& b) {
    file_logger3->debug("division func.");
    return a / b;
}

int Operation::sum(const int& a, const int& b) {
    file_logger3->debug("sum func.");
    return a + b;
}

int Operation::subtraction(const int& a, const int& b) {
    file_logger3->debug("subtraction func.");
    return a - b;
}

void Operation::move(int &a, int &b) {
    file_logger3->debug("move func.");
    a = b;
}
