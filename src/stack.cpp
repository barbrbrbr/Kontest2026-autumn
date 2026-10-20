#include "stack.hpp"

#include <cassert>
#include <utility>

Stack::~Stack()
{
    clear();
}

void Stack::push(char data)
{
    auto node = std::make_unique<Node>();
    node->data = data;
    node->next = std::move(m_head);
    m_head = std::move(node);
}

char Stack::pop()
{
    assert(!isEmpty());

    char data = m_head->data;
    m_head = std::move(m_head->next);
    return data;
}

char Stack::peek() const
{
    assert(!isEmpty());

    return m_head->data;
}

void Stack::clear()
{
    while (m_head)
        m_head = std::move(m_head->next);
}
