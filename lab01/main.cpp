//
// Created by merin on 2/5/2024.
//

#include <iostream>
#include <map>


#include "Parser.h"
#include "Operation.h"

int main() {

    Parser pars;
    std::map <std::string, int> assemblyData = pars.dataParser("../files/input.txt");

    /*for (const auto& pair : assemblyData) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }*/

    int result = pars.codeParser("../files/input.txt");

    pars.writeToFile("../files/output.txt");

    std::cout << result;
}