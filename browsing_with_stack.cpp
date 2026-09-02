#include<iostream>
#include<string>
#define Max 10
using namespace std;
class Stack
{
  public:
  string A[Max];
  int top;
  
  Stack()
  {
    top=-1;
  }
   bool isFull()
    {
        if (top == Max -1)
        {
            return true;
        }
        else
        {
            return false;
        }
     }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }   
        else
        {
            return false;
        }
    }
    
   void push(string url)
   {
    if(isFull())
    {
      cout<<"Stack is overflow"<<endl;
     }
     else
     {
      top++;
      A[top]=url;
      cout<<url<<"is visited"<<endl;
      }
    }
    void pop()
    {
      if(isEmpty())
      {
        cout<<"Stack is underflow"<<endl;
      }
      else
      {
        cout<<A[top]<<"is removed"<<endl;
        top--;
      }
    }
    void current()
    {
      if(isEmpty())
      {
        cout<<"No current page"<<endl;
      }
      else
      {
        cout<<"current page :"<<A[top]<<endl;
        top--;
      }
    }
    void display()
    {
      if(isEmpty())
      {
        cout<<"stack is empty"<<endl;
      }
      else
      {
        cout<<"Browser History"<<endl;
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
    int choice;
    string url;
    do
    {
      cout<<"\n***** STUDENT PORTAL *****"<<endl;
      cout<<"1.Visit New Page"<<endl;
      cout<<"2.Go Back"<<endl;
      cout<<"3.Current Page"<<endl;
      cout<<"4.Show Page"<<endl;
      cout<<"5.Exit"<<endl;
      
      cout<<"Enter Your Choice :";
      cin>>choice;
      
      switch(choice)
      {
        case 1:
          cout<<"Enter URL :";
          cin>>url;
          s1.push(url);
          break;
          
        case 2:
          s1.pop();
          break;
          
        case 3:
          s1.current();
          break;
          
        case 4:
          s1.display();
          break;
          
        case 5:
          cout<<"Program End";
          break;
          
        default :
          cout<<"Invalid Choice";
        }
      }
      while(choice!=5);
  return 0;
}
    
    
