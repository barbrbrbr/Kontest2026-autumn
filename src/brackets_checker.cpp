#include "brackets_checker.hpp"

#include "stack.hpp"

bool bracketsChecker(const std::string& str)
{
    Stack stack;

    for (char ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.isEmpty())
                return false;

            char open = stack.pop();
            if ((ch == ')' && open != '(')
                || (ch == ']' && open != '[')
                || (ch == '}' && open != '{'))
                return false;
        }
    }

    return stack.isEmpty();
}
