#pragma once

#include <memory>

class Stack {
public:
    Stack() = default;
    ~Stack();

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    // true, если стек пустой
    bool isEmpty() const { return !m_head; }

    void push(char data);
    char pop();
    char peek() const;
    void clear();

private:
    struct Node {
        char data;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> m_head;
};
