#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
public:
    int size; // Change stackSize to size
    
    Stack() : size(0), top(nullptr) {} // Default constructor

    T topElement() const {
        if (isEmpty()) {
            throw std::runtime_error("Accessing top of an empty stack");
        }
        return top->data;
    }

    ~Stack() { // Destructor
        while (!isEmpty()) {
            pop();
        }
    }

    Stack(const Stack<T>& other) : top(nullptr), size(0) { // Copy constructor
        *this = other;
    }

    Stack<T>& operator=(const Stack<T>& other) { // Assignment operator
        if (this != &other) {
            while (!isEmpty()) {
                pop();
            }

            Node* current = other.top;
            Node* tempTop = nullptr, *newNode;

            while (current) {
                newNode = new Node{current->data, nullptr};

                if (tempTop == nullptr) {
                    tempTop = newNode;
                } else {
                    newNode->next = tempTop;
                    tempTop = newNode;
                }
                current = current->next;
            }

            while (tempTop) {
                push(tempTop->data);
                Node* toDelete = tempTop;
                tempTop = tempTop->next;
                delete toDelete;
            }
        }

        return *this;
    }

    void push(const T& item) {
        if (isFull()) {
            throw std::overflow_error("Stack overflow");
        }
        Node* newNode = new Node{item, top};
        top = newNode;
        size++;
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        Node* nodeToDelete = top;
        T item = top->data;
        top = top->next;
        delete nodeToDelete;
        size--;
        return item;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    bool isFull() const {
        return size == MAX_SIZE;
    }

    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

private:
    struct Node {
        T data;
        Node* next;
    };

    Node* top;                      
                           
    const int MAX_SIZE = 100;       
};

#endif // STACK_HPP
