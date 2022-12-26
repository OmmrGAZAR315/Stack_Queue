#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

struct Node {
    int num;
    Node *next;

    Node(int data) {
        num = data;
        next = nullptr;
    }
};


int main() {
    auto *s1 = new stack<Node>(5);
    s1->push(10);//Last
    s1->push(9);
    s1->push(8);
    s1->push(7);
    s1->push(6);//First
    s1->Reverse_print();
    queue<Node> q1(5);
    q1.enqueue(1);//First
    q1.enqueue(2);
     q1.enqueue(3);
     q1.enqueue(4);
     q1.enqueue(5);//Last
    //////////////////////////////////////
     int x = s1->count();
     while (x--)
         q1.highPriorityEnqueue(s1->pop());
    q1.display();
    return 0;
}
