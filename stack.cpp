#include "stack.hpp"

template <typename T>
Stack<T>::Stack() : top(nullptr), size(0) {}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other) : top(nullptr), size(0) {
    *this = other;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
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

template <typename T>
void Stack<T>::push(const T& item) {
    if (isFull()) {
        throw std::overflow_error("Stack overflow");
    }

    Node* newNode = new Node{item, top};
    top = newNode;
    size++;
}

template <typename T>
T Stack<T>::pop() {
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

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
bool Stack<T>::isFull() const {
    return size == MAX_SIZE;
}

template <typename T>
void Stack<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Explicit template instantiation
template class Stack<int>;
template class Stack<double>;
// Add more explicit instantiations if needed for other types