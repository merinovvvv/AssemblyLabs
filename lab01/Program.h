//
// Created by merin on 2/5/2024.
//

#ifndef LAB01_PROGRAM_H
#define LAB01_PROGRAM_H

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

class Program {
public:

    Program();
    std::map <std::string, int> dataParser(const std::string& filePath);
    void codeParser(const std::string& filePath);
    void writeToFile (const std::string& filePath) const;
    int getResult() const;
    static int main();
private:
    void clearStr (std::string& str);
    bool isNumber (const std::string& str);
    static std::shared_ptr<spdlog::logger> file_logger1;
    std::string questVar; //TODO SET
    std::map <std::string, int> res;
    int result;
};


#endif //LAB01_PROGRAM_H
