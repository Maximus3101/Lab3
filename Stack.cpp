#include "stack.h"
#include <iostream>

Stack::Stack() {
    capacity = 10;
    data = new int[capacity];
    top = -1;
}

Stack::Stack(const Stack& other) {
    capacity = other.capacity;
    data = new int[capacity];
    top = other.top;

    for (int i = 0; i <= top; ++i) {
        data[i] = other.data[i];
    }
}

Stack::~Stack() {
    delete[] data;
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        data = new int[capacity];
        top = other.top;

        for (int i = 0; i <= top; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

void Stack::push(int elem) {
    if (top == capacity - 1) {
        // Resize array if capacity is reached
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i <= top; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[++top] = elem;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty" << std::endl;
        return -1; // Return a default value indicating error
    }
    return data[top--];
}

bool Stack::isEmpty() {
    return top == -1;
}

void Stack::multiPop(int N) {
    if (N > top + 1) {
        std::cerr << "Error: Cannot pop more elements than stack size" << std::endl;
        return;
    }
    top -= N;
}

void Stack::show() {
    for (int i = 0; i <= top; ++i) {
        if (i == top)
            std::cout << data[i];
        else
            std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int Stack::getCapacity() const {
    return capacity;
}

int Stack::getSize() const {
    return top + 1;
}