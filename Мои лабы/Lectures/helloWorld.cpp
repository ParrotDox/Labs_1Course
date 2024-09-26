#include <iostream>
#include <string>

int main(){
    std::cout << "Hello World\n"; //Однострочный комментарий
/*
    Многострочный комментарий
    Ipsum (０ふ０)
*/
    std::string Word = "Booba";
    std::cout << "Please,write a random word:\n";
    /*
    std::getline(std::cin,Word);
    std::cin >> Word;
    */
    std::cout << "Well " << Word << " isn't that bad...\n";

}