#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template<class Node>
class queue {
    typedef Node *node;
    node front = nullptr, rear = nullptr;
    int length, size;
public:

    void deleteEverything() {
        delete front;
        delete rear;
    }

    void enqueue(int item);

    void highPriorityEnqueue(int);

    int dequeue();

    void display();

    void replace(int, int);

    void deleteLastInput() {
        if (front != nullptr) {
            Node *temp = front;
            while (temp->next != rear)
                temp = temp->next;

            temp->next = nullptr;
            delete rear;
            rear = temp;
        }
    }
};

template<class Node>
void queue<Node>::highPriorityEnqueue(int item) {
    if (front != nullptr) {
        Node *temp = front;
        front = new Node(item);
        front->next = temp;
    }
}

template<class Node>
void queue<Node>::display() {
    Node *temp = front;
    int x = 0;
    while (temp != nullptr && ++x) {
        std::cout << x << " - " << temp->num << std::endl;
        temp = temp->next;
    }
}

template<class Node>
void queue<Node>::replace(int index, int item) {
    length = 0;
    Node *temp = front;
    while (temp != nullptr) {
        temp = temp->next;
        length++;
    }
    temp = front;
    if (index > 0 && length >= index) {
        std::cout << "Replacing index number " << index;
        for (int i = 1; i < index; i++)
            temp = temp->next;
        temp->num = item;
        std::cout << "...Replaced with! " << item << std::endl;
    } else std::cout << "Index out of range\n";
}

template<class Node>
void queue<Node>::enqueue(int item) {
    if (front == NULL) rear = front = new Node(item);
    else {
        Node *temp = rear;
        rear = new Node(item);
        temp->next = rear;
    }
}

template<class Node>
int queue<Node>::dequeue() {
    if (front == nullptr) return 0;
    int value = front->num;
    Node *temp = front;
    front = front->next;
    delete temp;
    return value;
}

#endif