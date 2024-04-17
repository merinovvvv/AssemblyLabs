#include <iostream>
#include <string>

extern "C" int __fastcall isPalindrome(char* str, int length);

int main() {
    std::string inputStr;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputStr);

    for (size_t i = 0; i < inputStr.size(); ++i) {
        inputStr[i] = std::tolower(inputStr[i]);
    }

    /*for (size_t i = 0; i < inputStr.size(); ++i) {
        std::cout << inputStr[i];
    }*/

    // Преобразование строки C++ в массив символов (C-style string)
    char* str = &inputStr[0];
    int length = inputStr.length();

    
    // Вызов ассемблерной процедуры
    int result = isPalindrome(str, length);

    // Вывод результата
    if (result == 1)
        std::cout << "The string is a palindrome." << std::endl;
    else
        std::cout << "The string is not a palindrome." << std::endl;

    return 0;
}
