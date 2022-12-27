#ifndef STACK_H
#define STACK_H

#include <iostream>

template<class Node>
class stack {
    Node *top = nullptr;
    int size;
    int length;

public:
    stack() {}

    stack(stack<Node> &ss) {
        ss.count();
        size = ss.size;
        length = ss.length;
        int x = 0;
        Node *temp = ss.top;
        while (x++ < length) {
            push(temp->num);
            temp = temp->next;
        }
    }

    void deleteEverything() {
        delete top;
    }

    void push(int item);

    int pop();

    stack<Node> Reverse_print();

    void print();

    int count();

    void Delete(int item);

};

template<class Node>
int stack<Node>::pop() {
    int value = top->num;
    Node *temp = top;
    top = top->next;
    delete temp;
    return value;
}

template<class Node>
void stack<Node>::Delete(int item) {
    Node *temp = top;
    Node *beforeTemp = top;
    while (temp != nullptr && temp->num != item) {
        beforeTemp = temp;
        temp = temp->next;
    }
    if (temp == nullptr) std::cout << "Not found!!!\n";
    else {
        beforeTemp->next = temp->next;
        std::cout << "'" << temp->num << "'" << " Found!!...Deleted\n";
        delete temp;
        length--;
    }
}

template<class Node>
void stack<Node>::print() {
    Node *temp = top;
    int x = 0;
    while (temp != nullptr && ++x) {
        std::cout << x << " - " << temp->num << std::endl;
        temp = temp->next;
    }

}

template<class Node>
int stack<Node>::count() {
    length = 0;
    Node *temp = top;
    while (temp != nullptr) {
        temp = temp->next;
        length++;
    }
    return length;
}

template<class Node>
stack<Node> stack<Node>::Reverse_print() {
    stack<Node> ss;
    Node *temp = top;
    while (temp != nullptr) {
        ss.push(temp->num);
        temp = temp->next;
    }
    return ss;
}

template<class Node>
void stack<Node>::push(int item) {
    if (top == nullptr) {
        top = new Node(item);
    } else {
        Node *temp = new Node(item);
        temp->next = top;
        top = temp;
    }
}

#endif