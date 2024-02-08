//
// Created by merin on 2/5/2024.
//

#include <vector>
#include <algorithm>

#include "Parser.h"
#include "Operation.h"


std::shared_ptr<spdlog::logger> Parser::file_logger1 = spdlog::basic_logger_mt("dataParser_logger",
                                                                               "../files/spdlog.txt");
std::shared_ptr<spdlog::logger> Parser::file_logger2 = spdlog::basic_logger_mt("codeParser_logger",
                                                                               "../files/spdlog.txt");


Parser::Parser() {
    file_logger1->set_level(spdlog::level::debug);
    file_logger2->set_level(spdlog::level::debug);

}

std::map<std::string, int> Parser::dataParser(const std::string &filePath) {

    file_logger1->debug("dataParser func.");

    std::vector<std::string> list;
    std::string str;
    std::ifstream fin(filePath, std::ios::in);
    while (std::getline(fin, str) && str != ".code") {
        clearStr(str);
        if (str != ".data") {
            list.push_back(str);
        }
    }
    fin.close();

    /*for (const auto &i: list) {
        std::cout << i;
    }*/

    std::string variable;
    std::string value;
    std::map<std::string, int> result;

    for (const auto &i: list) {
        std::stringstream ss(i);
        std::getline(ss, variable, '\t');

        std::getline(ss, value, '\t');


        if (isNumber(value)) {
            result.insert(std::make_pair(variable, std::stoi(value)));
        } else if (value == "?") {
            result.insert(std::make_pair(variable, 0));
            questVar = variable;
        } else {
            throw std::invalid_argument("File contains not only ? sign and numbers in the value box.");
        }
    }

    /*for (const auto& pair : result) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }*/
    res = result;
    return result;
}

void Parser::clearStr(std::string &str) {

    file_logger1->debug("clearStr func.");

    for (size_t i = 0; i < str.size(); ++i) {
        /*std::string wordToRemove = ".data";
        if (str == wordToRemove) {
            str.clear();
        }*/
        if (str[i] == '/') {
            if (str[i + 1] == '/') {
                size_t com = str.find("//");
                if (com != std::string::npos) {
                    str.erase(com);
                }
            } else if (str[i + 1] == '*') {
                size_t comStart = str.find("/*");
                if (comStart != std::string::npos) {
                    size_t comEnd = str.find("/*");
                    if (comEnd != std::string::npos) {
                        str.erase(comStart, comEnd - comStart + 1);
                    }
                }
            }
        }
    }
}

bool Parser::isNumber(const std::string &str) {

    file_logger1->debug("isNumber func.");

    if (str.empty()) {
        return false;
    }

    size_t pos = 0;
    if (str[pos] == '-') {
        // Если встречен минус, двигаемся к следующему символу
        ++pos;
    }

    return pos < str.size() && std::all_of(str.begin() + pos, str.end(), ::isdigit);
}

int Parser::codeParser(const std::string &filePath) {
    file_logger2->debug("codeParser func.");

    std::vector<std::string> list;
    std::string str;
    std::ifstream fin(filePath, std::ios::in);

    while (std::getline(fin, str) && str != ".code");

    while (std::getline(fin, str) && str != ".code") {
        clearStr(str);
        list.push_back(str);
    }
    fin.close();

    /*for (const auto &i : list) {
        std::cout << i;
    }*/

    std::string operation;
    std::string op1;
    std::string op2;


    res.insert(std::make_pair(("Ak"), 0));

    for (const auto &i: list) {
        std::stringstream ss(i);

        std::getline(ss, operation, '\t');


        std::getline(ss, op1, '\t');

        std::getline(ss, op2, '\t');


        if (operation == "end") {
            result = res[questVar];
            return result;
        }
        else if (operation == "mov") {
            int a = res[op1];
            int b = res[op2];
            Operation::move(a, b);
            res[op1] = res[op2];
        } else if (operation == "mul") {
            int a = res[op1];
            int b = res[op2];
            res[op1] = Operation::multiplication(a, b);
        } else if (operation == "div") {
            int a = res[op1];
            int b = res[op2];
            res[op1] = Operation::division(a, b);
        } else if (operation == "add") {
            int a = res[op1];
            int b = res[op2];
            res[op1] = Operation::sum(a, b);
        } else if (operation == "sub") {
            int a = res[op1];
            int b = res[op2];
            res[op1] = Operation::subtraction(a, b);
        } else {
            throw std::invalid_argument("Wrong operation.");
        }
    }
}

void Parser::writeToFile (const std::string& filePath) const {
    std::ofstream fout (filePath, std::ios::app);
    fout << "The result equals to: ";
    fout << result;
    fout << '\n';
}