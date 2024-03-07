#include <iostream>

//****************************************************************************
template <typename T> Stack<T>::Stack() : top(nullptr), _size(0) {}

//****************************************************************************
template <typename T> Stack<T>::~Stack() { clear(); }

//****************************************************************************
template <typename T>
Stack<T>::Stack(const Stack<T> &s) : top(nullptr), _size(0) {
    *this = s;
}

//****************************************************************************
template <typename T> Stack<T> &Stack<T>::operator=(const Stack<T> &s) {
    if (this == &s)
        return *this;
    clear();
    if (!s.isEmpty()) {
        push(s.getTop()); // top = new Element (p.top->value, nullptr);
        Element *now = s.top->next, *deep = top;
        while (now != nullptr) {
            deep->next = new Element(now->value);
            deep = deep->next;
            now = now->next;
        }
    }

    _size = s._size;
    return *this;
}

//****************************************************************************
template <typename T> void Stack<T>::push(T value) {
    try {
        Element *new_ = new Element(value, top);
        top = new_;
        ++_size;
    } catch (std::bad_alloc &) {
        throw "Error: it's not possible to push the value onto the stack.";
    }
}

//****************************************************************************
template <typename T> void Stack<T>::pop() {
    if (isEmpty())
        throw "Error: The stack is empty.";
    Element *aux = top;
    top = top->next;
    delete aux;
    --_size;
}

//****************************************************************************
template <typename T> void Stack<T>::clear() {
    while (!isEmpty())
        pop();
}

//****************************************************************************
template <typename T> T Stack<T>::getTop() const {
    if (isEmpty())
        throw "Error: The stack is empty. T";
    return top->value;
}

//****************************************************************************
template <typename T> int Stack<T>::size() const { return _size; }

//****************************************************************************
template <typename T> bool Stack<T>::isEmpty() const { return _size == 0; }

//****************************************************************************
template <typename T> void Stack<T>::print() const {
    if (isEmpty())
        throw "Error: The stack is empty. P";
    Element *aux;
    aux = top;
    while (aux != nullptr) {
        std::cout << aux->value << std::endl;
        aux = aux->next;
    }
}

//****************************************************************************
// internal method of the stack.
template <typename T>
Stack<T>::Element::Element(T v, Stack<T>::Element *next_)
: value(v), next(next_) {}
//****************************************************************************
