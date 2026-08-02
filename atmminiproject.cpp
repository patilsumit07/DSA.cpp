#include<iostream>
using namespace std;
int main()
{
  int balance=30000;
  int amount;
  int ch;

    cout<<"================================================================================";
    cout<<"\n                        ********SBI ATM********";
    cout<<"\n================================================================================";
    cout<<"\n1.BALANCE ENQUIRY";
    cout<<"\n2.CASH DEPOSIT";
    cout<<"\n3.CASH WITHDRAW";
    cout<<"\n4.EXIT";
  do
  {
  
    cout<<"\nENTER YOUR CHOICE:";
    cin>>ch;
    
      switch(ch)
      { 
        case 1:
        cout<<"ACCOUNT BALANCE IS :"<<balance;
        break;
        case 2:
        cout<<"ENTER AMOUNT TO DEOPSIT :";
        cin>>amount;
        balance=balance + amount;
        cout<<"TOTAL BALANCE IS :"<<balance;
        break;
        case 3:
        cout<<"ENTER AMOUNT TO WITHDRAW :";
        cin>>amount;
        balance=balance - amount;
        cout<<"TOTAL BALANCE IS :"<<balance;
        break;
        case 4:
        cout<<"THANK YOU FOR VISTING OUR BANK";
        break;
        default :
        cout<<"INVALID INPUT";
        
      }
     }
   while(ch!=4);     
return 0;
}
