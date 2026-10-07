#include<iostream>
using namespace std;
class Queue
{
  public:
    int A[6];
    int front;
    int rear;
    Queue()
    {
      front=-1;
      rear=-1;
    }
    void enQueue(int value)
    {
      if(rear==5)
      {
        cout<<"Queue is overflow";
      }
      if(front==-1)
      { 
        front=0;
      }
      rear++;
      A[rear]=value;
      cout<<value<<"is added in queue";
    }
    
    void deQueue()
    {
      if(front==-1||front>rear)
      {
        cout<<"Queue is underflow";
      }
      cout<<A[front]<<"\t is deleted for queue"<<endl;
      front++;
      
      if(front>rear)
      {
        front=-1;
        rear=-1;
      }
    }
    
    void display()
    {
      if(front==-1)
      {
       cout<<"Queue is empty";
       return;
      }
      cout<<"Queue element are ";
       for (int i = front; i <= rear; i++)
        {
            cout << A[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n----- QUEUE MENU -----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            q.deQueue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
