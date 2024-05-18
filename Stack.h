#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* data;
    int capacity;
    int top;

public:
    // Constructor
    Stack();
    // Copy constructor
    Stack(const Stack& other);
    // Destructor
    ~Stack();
    // Assignment operator
    Stack& operator=(const Stack& other);

    // Stack operations
    void push(int elem);
    int pop();
    bool isEmpty();
    void multiPop(int N);
    void show();

    // Utility functions
    int getCapacity() const;
    int getSize() const;
};

#endif