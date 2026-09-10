#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int d) {
        data = d;
        int cnt = 0; 
        next = NULL;
    }
};

class Stack {
    Node* top;
    int size;

public:
    Stack() {
        top = NULL;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    int pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return -1;
        }
        Node* temp = top;
        top = top->next;
        int poppedData = temp->data;
        size--;
        delete temp; 
        return poppedData;
    }

    int getTop() {
        if (top == NULL) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.getTop() << endl;
    cout << "Size is: " << s.getSize() << endl;

    cout << "Popped element: " << s.pop() << endl;
    cout << "Top element after pop: " << s.getTop() << endl;
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
