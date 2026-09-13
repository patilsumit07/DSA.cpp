#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool searchKey(Node* head, int key) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            return true;

        temp = temp->next;
    }

    return false;
}

int main() {
    
    Node* head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    head->next->next->next = new Node{40, NULL};

    int key;
    cout << "Enter key: ";
    cin >> key;

    if (searchKey(head, key))
        cout << "true";
    else
        cout << "false";

    return 0;
}
