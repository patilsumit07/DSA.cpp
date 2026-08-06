#include<iostream>
using namespace std;
class Node
{
public:
char attendance;
Node *next;
Node(char status){
attendance=status;
next=NULL;
}
};
class Attendance
{
private:
Node *head;
public:
Attendance(){
head=NULL;
}
void insertattendance(char status){
Node *newNode=new Node(status);
if(head==NULL)
{
head=newNode;
}
else{
Node *temp=head;
while(temp->next!=NULL)

temp=temp->next;
}
temp->next=newNode;
}
cout<<"Attendance inserted successfully";
}
void updateattendance(int day,char status)
{
Node *temp=head;
int count=1;
while(temp!=NULL && count<day)
{
temp=temp->next;
count++;
}
if(temp==NULL){
cout<<"invalid day";
}
else
{
temp->attendance=status;
cout<<"Attendance updated successfully.\n";
}
}
};


                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
