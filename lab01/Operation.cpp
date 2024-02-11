//
// Created by merin on 2/5/2024.
//

#include "Operation.h"



std::shared_ptr<spdlog::logger> Operation::file_logger2 = []() {
    std::shared_ptr<spdlog::logger> file_logger2 = spdlog::basic_logger_mt("Operation_logger", "../files/spdlog.txt");
    file_logger2->set_level(spdlog::level::trace);
    return file_logger2;
}();

int Operation::multiplication(const int& a, const int& b) {
    file_logger2->trace("multiplication func.");
    return a * b;
}

int Operation::division(const int& a, const int& b) {
    file_logger2->trace("division func.");
    return a / b;
}

int Operation::sum(const int& a, const int& b) {
    file_logger2->trace("sum func.");
    return a + b;
}

int Operation::subtraction(const int& a, const int& b) {
    file_logger2->trace("subtraction func.");
    return a - b;
}

void Operation::move(int &a, int &b) {
    file_logger2->trace("move func.");
    a = b;
}
