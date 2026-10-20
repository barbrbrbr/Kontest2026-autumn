#include "brackets_checker.hpp"
#include "stack.hpp"

#include <iostream>
#include <string>

static int failed = 0;

static void check(bool ok, const std::string& name)
{
    if (!ok) {
        std::cout << "ошибка: " << name << '\n';
        ++failed;
    }
}

static void testStack()
{
    Stack stack;
    check(stack.isEmpty(), "новый стек пустой");

    stack.push('a');
    stack.push('b');
    check(stack.peek() == 'b', "peek возвращает вершину");
    check(stack.pop() == 'b', "pop вернул последний элемент");
    check(stack.pop() == 'a', "pop вернул первый элемент");
    check(stack.isEmpty(), "после pop стек пустой");

    stack.push('x');
    stack.clear();
    check(stack.isEmpty(), "clear очищает стек");
}

static void testBigStack()
{
    Stack stack;
    for (int i = 0; i < 1000000; ++i)
        stack.push('(');
    check(!stack.isEmpty(), "большой стек не пустой");
}

struct Case {
    std::string text;
    bool expected;
};

static void testBrackets()
{
    Case cases[] = {
        { "", true },
        { "()", true },
        { "[]", true },
        { "{}", true },
        { "()[]{}", true },
        { "{[()()]()}", true },
        { "abc", true },
        { "(", false },
        { "())", false },
        { ")(", false },
        { "(]", false },
        { "([)]", false },
    };

    for (const Case& c : cases)
        check(bracketsChecker(c.text) == c.expected, "строка \"" + c.text + "\"");
}

static void testLongString()
{
    std::string open(100000, '(');
    std::string close(100000, ')');

    check(bracketsChecker(open + close), "длинная правильная строка");
    check(!bracketsChecker(open), "длинная строка без закрывающих");
}

int main()
{
    testStack();
    testBigStack();
    testBrackets();
    testLongString();

    if (failed) {
        std::cout << "не прошло тестов: " << failed << '\n';
        return 1;
    }

    std::cout << "все тесты прошли\n";
    return 0;
}
