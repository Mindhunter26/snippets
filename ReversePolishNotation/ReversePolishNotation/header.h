#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <stack>
#include <sstream>
#include <cmath>

enum Priority
{
    HIGH,
    MEDIUM,
    LOW,
    VERY_LOW
};

bool isNumber(char ch);
Priority priority(char ch);
std::string toRpn(std::string input);
double count(std::string res);

#endif // HEADER_H
