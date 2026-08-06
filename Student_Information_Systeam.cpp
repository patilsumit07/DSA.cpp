#include <iostream>
#include <string>
using namespace std;

struct student
{
    int roll_no;
    string name;
    float cgpa;
};

student s[100];
int n;

// Display students
void display()
{
    if (n == 0)
    {
        cout << "No students found.\n";
        return;
    }

    cout << "\nRoll No\tName\tCGPA\n";
    cout << "-----------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << s[i].roll_no << "\t"
             << s[i].name << "\t"
             << s[i].cgpa << endl;
    }
}

// Insert student
void insertstu()
{
    if (n == 100)
    {
        cout << "Student list is full.\n";
        return;
    }

    int pos;
    cout << "Enter position (1 to " << n + 1 << "): ";
    cin >> pos;

    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = n; i >= pos; i--)
    {
        s[i] = s[i - 1];
    }

    cout << "Enter Roll Number: ";
    cin >> s[pos - 1].roll_no;

    cout << "Enter Name: ";
    cin >> s[pos - 1].name;

    cout << "Enter CGPA: ";
    cin >> s[pos - 1].cgpa;

    n++;

    cout << "Student inserted successfully.\n";
}

// Delete student
void deletestudent()
{
    if (n == 0)
    {
        cout << "No students to delete.\n";
        return;
    }

    int roll;
    int index = -1;

    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    for (int i = 0; i < n; i++)
    {
        if (s[i].roll_no == roll)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Student not found.\n";
        return;
    }

    for (int i = index; i < n - 1; i++)
    {
        s[i] = s[i + 1];
    }

    n--;

    cout << "Student deleted successfully.\n";
}

// Search student
void searchstudent()
{
    if (n == 0)
    {
        cout << "No students available.\n";
        return;
    }

    int roll;
    bool found = false;

    cout << "Enter Roll Number to search: ";
    cin >> roll;

    for (int i = 0; i < n; i++)
    {
        if (s[i].roll_no == roll)
        {
            found = true;

            cout << "\nRecord Found\n";
            cout << "Roll No : " << s[i].roll_no << endl;
            cout << "Name    : " << s[i].name << endl;
            cout << "CGPA    : " << s[i].cgpa << endl;

            break;
        }
    }

    if (!found)
    {
        cout << "Record not found.\n";
    }
}

int main()
{
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Enter Roll Number: ";
        cin >> s[i].roll_no;

        cout << "Enter Name: ";
        cin >> s[i].name;

        cout << "Enter CGPA: ";
        cin >> s[i].cgpa;
    }

    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Display Students\n";
        cout << "2. Insert Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Search Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            display();
            break;

        case 2:
            insertstu();
            break;

        case 3:
            deletestudent();
            break;

        case 4:
            searchstudent();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
