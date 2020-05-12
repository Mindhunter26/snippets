#include "header.h"

using namespace std;

bool isNumber(char ch) {
    if (ch >= '0' && ch <= '9' || ch == '.') return true;
    else return false;
}

Priority priority(char ch) {
    switch (ch) {
    case '^':
        return HIGH;
    case '/':
        return MEDIUM;
    case '*':
        return MEDIUM;
    case '+':
        return LOW;
    case '-':
        return LOW;
    default:
        return VERY_LOW;
    }
}

string toRpn(string input) {
    stack<char> operators;
    string res;

    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == ' ') continue;

        if (isNumber(input[i])) {
            stringstream inputStr;
            inputStr << input[i];
            res += inputStr.str();

            if (input[i + 1] == ' ' || (i + 1) >= input.size()) res += ' ';
        }
        else if (input[i] == '(') operators.push(input[i]);
        else if (!(operators.empty())) {
            if (input[i] == ')') {
                while (operators.top() != '(') {
                    res += operators.top();
                    res += " ";
                    operators.pop();
                }
                operators.pop();
            }
            else if (priority(input[i]) <= priority(operators.top())) {
                res += operators.top();
                res += " ";
                operators.pop();
                operators.push(input[i]);
            }
            else operators.push(input[i]);
        }
        else operators.push(input[i]);
    }
    while (!operators.empty()) {
        if (priority(operators.top()) > 1) {
            res += operators.top();
            res += " ";
        }
        operators.pop();
    }
    return res;
}

double count(string res) {
    stack<double> nums;
    string temp_str_d;
    double count;
    for (size_t i = 0; i < res.length(); i++) {
        if (isNumber(res[i])) {
            stringstream output;
            output << res[i];
            temp_str_d += output.str();
        }
        else if (res[i] == ' ' && isNumber(res[i - 1])) {
            nums.push(stod(temp_str_d));
            temp_str_d = "";
        }
        else {
            switch (res[i]) {
            case '^':
            {
                double power = nums.top();
                nums.pop();
                double temp_num = pow(nums.top(), power);
                nums.pop();
                nums.push(temp_num);
                break;
            }
            case '/':
            {
                double operand = nums.top();
                nums.pop();
                double num = nums.top() / operand;
                nums.pop();
                nums.push(num);
                break;
            }
            case '*':
            {
                double operand = nums.top();
                nums.pop();
                double num = nums.top() * operand;
                nums.pop();
                nums.push(num);
                break;
            }
            case '-':
            {
                double operand = nums.top();
                nums.pop();
                double num = nums.top() - operand;
                nums.pop();
                nums.push(num);
                break;
            }
            case '+':
            {
                double operand = nums.top();
                nums.pop();
                double num = nums.top() + operand;
                nums.pop();
                nums.push(num);
                break;
            }
            }
        }
    }
    count = nums.top();
    return count;
}
