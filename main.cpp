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
    stack<Node> s1;
    s1.push(10);//Last
    s1.push(9);
    s1.push(8);
    s1.push(7);
    s1.push(6);//First
    s1.print();
    cout << "Reversing by push into a new stack\n";
    stack<Node> s2 = s1;//Q.1.) 1.
    //print in reversed ordered
//    s1.Reverse_print().print();
    s2.print();
    cout << "Deleting specific item\n";
    s1.Delete(10);//Q.1.) 3.
    s1.print();
    queue<Node> q1(5);
    q1.enqueue(1);//First
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(500);//Last
    cout << "printing q1\n";
    q1.display();
    cout << "delete last input from q1\n";
    q1.deleteLastInput();//Q.2.)i
    q1.display();
    q1.replace(3, 300);//Q.2.)ii
    q1.display();
    cout << "copy s1 data with the same order into q1\n";
    int x = s1.count();//Q.1.)2.
    while (x--)
        q1.highPriorityEnqueue(s1.pop());//Q.2.)iii
    q1.display();
    cout << "Delete all dynamic variable\n";
    s1.deleteEverything();
    q1.deleteEverything();
    return 0;
}
