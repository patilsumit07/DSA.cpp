#include<iostream>
using namespace std;
#define MAX 100

int queueA[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int token;

    if (rear == MAX - 1) {
        cout << "Queue is full" << endl;
        return;
    }

    cout << "Enter student token number: ";
    cin >> token;

    if (front == -1)
        front = 0;

    rear++;
    queueA[rear] = token;

    cout << "Student with token number " << token
         << " added to the queue." << endl;
}

void dequeue()
{
  if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Student with token number " << queueA[front]
         << " is being processed." << endl;

    front++;

    if (front > rear) {
        front = -1;
        rear = -1;
    }
}
void displayFrontRear() 
{
    if (front == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Front token number: " << queueA[front] << endl;
    cout << "Rear token number: " << queueA[rear] << endl;
}
void displayQueue() 
{
    if (front == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Complete queue: ";

    for (int i = front; i <= rear; i++) {
        cout << queueA[i] << " ";
    }

    cout << endl;
}
int main() 
{
    int choice;

    do 
    {
        cout << "\n****** Admission Queue ******" << endl;
        cout << "1. Enqueue student token number" << endl;
        cout << "2. Dequeue and display student" << endl;
        cout << "3. Display front and rear token number" << endl;
        cout << "4. Display complete queue" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                displayFrontRear();
                break;

            case 4:
                displayQueue();
                break;

            case 5:
                cout << "Exiting program..." << "\n Thank You..."<<endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } 
    while (choice != 5);

    return 0;
}
