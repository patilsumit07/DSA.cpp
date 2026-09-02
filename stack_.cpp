#include<iostream>
#define Max 5
using namespace std;
class Stack
{
  public:
  int A[Max];
  int top;
  Stack()
  {
    top=-1;
  }
  void push (int value)
  {
    if(top== Max-1)
    {
      cout<<"Stack is overflow"<<endl;
    }
    else
    {
      top++;
      A[top]=value;
      cout<<value<<"is pushed into stack"<<endl;
    }
  }
  void pop()
  {
    if(top==-1)
    {
      cout<<"stack is underflow"<<endl;
    }
    else
    {
      cout<<A[top]<<"is remove from stack"<<endl;
      top--;
    }
  }
  void display()
  {
    if(top==-1)
    {
      cout<<"stack is empty";
    }
    else
    {
      for(int i=top;i>=0;i--)
      {
        cout<<A[i]<<endl;
      }
    }
  }
 };
  int main()
  {
    Stack s1;
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.display();
    s1.pop();
    s1.push(50);
    s1.display();
    s1.pop();
    return 0;
   }
    
