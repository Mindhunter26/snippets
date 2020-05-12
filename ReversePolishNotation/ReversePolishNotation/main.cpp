#include <iostream>
#include "header.h"

int main()
{
    std::string input;
    getline(std::cin, input);
    std::cout << toRpn(input) << std::endl;
    std::cout << count(toRpn(input)) << std::endl;

    system("pause");
    return 0;
}
