#include <iostream>
using namespace std;
class Node
{
public:
char attendance;
Node *next;
Node(char status)
{
attendance = status;
next = NULL;
}
};
class Attendance
{
private:
Node *head;
public:
Attendance()
{
head = NULL;
}
void insertattendance(char status)
{
Node *newNode = new Node(status);
if (head == NULL)
{
head = newNode;
}
else
{
Node *temp = head;
while (temp->next != NULL)
{
temp = temp->next;
}    
temp->next = newNode;  
}
cout << "Attendance inserted successfully." << endl;
}
void updateattendance(int day, char status)
{
Node *temp = head;
int count = 1;
while (temp != NULL && count < day)
{
temp = temp->next;
count++;
}
if (temp == NULL)
{
cout << "Invalid day." << endl;
}
else
{
temp->attendance = status;
cout << "Attendance updated successfully." << endl;
}
}
void CalculateAttendance()
{
Node *temp = head;
int present = 0, absent = 0;
while (temp != NULL)
{
if (temp->attendance == 'P' || temp->attendance == 'p')
{
present++;
}
else if (temp->attendance == 'A' || temp->attendance == 'a')
{
absent++;
}
temp = temp->next;
}
cout << "Total Present Days: " << present << endl;
cout << "Total Absent Days: " << absent << endl;
}
void displayAttendance()
{
if (head == NULL)
{
cout << "No attendance records found." << endl;
return;
}
Node *temp = head;
int day = 1;
cout << "\nAttendance Record:\n";
while (temp != NULL)
{
cout << "Day " << day << " : " << temp->attendance << endl;
temp = temp->next;
day++;
}
}
};
int main()
{
Attendance a;
a.insertattendance('P');
a.insertattendance('A');
a.insertattendance('P');
a.insertattendance('A');
a.insertattendance('P');
cout << "\nAttendance Record:" << endl;
a.displayAttendance();
cout << "\nAttendance Summary:" << endl;
a.CalculateAttendance();
cout << "\nUpdating Day 2 Attendance to Present..." << endl;
a.updateattendance(2, 'P');
cout << "\nUpdated Attendance Record:" << endl;
a.displayAttendance();
cout << "\nUpdated Attendance Summary:" << endl;
a.CalculateAttendance();
return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
