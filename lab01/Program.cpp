//
// Created by merin on 2/5/2024.
//

#include <vector>
#include <algorithm>

#include "Program.h"
#include "Operation.h"


std::shared_ptr<spdlog::logger> Program::file_logger1 = spdlog::basic_logger_mt("Program_logger",
                                                                               "../files/spdlog.txt");
Program::Program() {
    file_logger1->set_level(spdlog::level::trace);
    result = 0;
}

std::map<std::string, int> Program::dataParser(const std::string &filePath) {

    file_logger1->trace("dataProgram func.");

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

void Program::clearStr(std::string &str) {

    file_logger1->trace("clearStr func.");

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

bool Program::isNumber(const std::string &str) {

    file_logger1->trace("isNumber func.");

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

void Program::codeParser(const std::string &filePath) {
    file_logger1->trace("codeProgram func.");

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

void Program::writeToFile (const std::string& filePath) const {
    file_logger1->trace("writeToFile func.");
    std::ofstream fout (filePath, std::ios::in);
    fout << "The result equals to: ";
    fout << result;
    fout << '\n';
}

int Program::getResult() const {
    return result;
}

int Program::main() {
    Program a;
    std::map <std::string, int> assemblyData = a.dataParser("../files/input.txt");

    /*for (const auto& pair : assemblyData) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }*/

    a.codeParser("../files/input.txt");

    a.writeToFile("../files/output.txt");

    int answer = a.getResult();

    std::cout << answer;

    return 0;
}