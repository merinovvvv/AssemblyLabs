//
// Created by merin on 2/5/2024.
//

#ifndef LAB01_PARSER_H
#define LAB01_PARSER_H

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

class Parser {
public:

    Parser();
    std::map <std::string, int> dataParser(const std::string& filePath);
    int codeParser(const std::string& filePath);
    void writeToFile (const std::string& filePath) const;
private:
    void clearStr (std::string& str);
    bool isNumber (const std::string& str);
    static std::shared_ptr<spdlog::logger> file_logger1;
    static std::shared_ptr<spdlog::logger> file_logger2;
    std::string questVar;
    std::map <std::string, int> res;
    int result;

};


#endif //LAB01_PARSER_H
