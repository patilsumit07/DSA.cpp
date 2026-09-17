#include <iostream>
#include <string>
using namespace std;

// ================= CROP STRUCTURE =================

struct Crop
{
    int id;
    string name;
    string farmer;
    float price;
    int quantity;
    Crop *next;
};

Crop *head = NULL;


// ================= STACK =================

string operations[50];
int top = -1;

// Push
void push(string operation)
{
    if (top == 49)
    {
        cout << "\nStack is Full!";
        return;
    }

    operations[++top] = operation;
}

// Pop
void pop()
{
    if (top == -1)
    {
        cout << "\nStack is Empty!";
        return;
    }

    cout << "\nRemoved Operation: "
         << operations[top--] << endl;
}

// Peek
void peek()
{
    if (top == -1)
    {
        cout << "\nStack is Empty!";
        return;
    }

    cout << "\nLatest Operation: "
         << operations[top] << endl;
}

// Display Stack
void displayStack()
{
    if (top == -1)
    {
        cout << "\nNo recent operations.";
        return;
    }

    cout << "\n--- Recent Operations ---\n";

    for (int i = top; i >= 0; i--)
    {
        cout << operations[i] << endl;
    }
}


// ================= ADD CROP =================

void addCrop()
{
    Crop *newCrop = new Crop;

    cout << "\nEnter Crop ID: ";
    cin >> newCrop->id;

    cout << "Enter Crop Name: ";
    cin >> newCrop->name;

    cout << "Enter Farmer Name: ";
    cin >> newCrop->farmer;

    cout << "Enter Market Price (per kg): ";
    cin >> newCrop->price;

    cout << "Enter Quantity (kg): ";
    cin >> newCrop->quantity;

    newCrop->next = NULL;

    if (head == NULL)
    {
        head = newCrop;
    }
    else
    {
        Crop *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newCrop;
    }

    push("Added Crop: " + newCrop->name);

    cout << "\nCrop added successfully!";
}


// ================= DISPLAY =================

void displayCrops()
{
    if (head == NULL)
    {
        cout << "\nNo crop records available.";
        return;
    }

    Crop *temp = head;

    cout << "\n\n===== CROP RECORDS =====\n";

    while (temp != NULL)
    {
        cout << "\nID       : " << temp->id;
        cout << "\nCrop     : " << temp->name;
        cout << "\nFarmer   : " << temp->farmer;
        cout << "\nPrice/kg : Rs." << temp->price;
        cout << "\nQuantity : " << temp->quantity << " kg\n";

        temp = temp->next;
    }
}


// ================= LINEAR SEARCH =================

void searchCrop()
{
    if (head == NULL)
    {
        cout << "\nNo crop records available.";
        return;
    }

    string searchName;
    bool found = false;

    cout << "\nEnter crop name to search: ";
    cin >> searchName;

    Crop *temp = head;

    while (temp != NULL)
    {
        if (temp->name == searchName)
        {
            cout << "\n--- Crop Found ---";
            cout << "\nID       : " << temp->id;
            cout << "\nFarmer   : " << temp->farmer;
            cout << "\nPrice/kg : Rs." << temp->price;
            cout << "\nQuantity : " << temp->quantity << " kg\n";

            found = true;

            push("Searched Crop: " + temp->name);

            break;
        }

        temp = temp->next;
    }

    if (!found)
        cout << "\nCrop not found.";
}


// ================= BUBBLE SORT =================

void sortByPrice()
{
    if (head == NULL)
    {
        cout << "\nNo crop records available.";
        return;
    }

    Crop *i;
    Crop *j;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = head; j->next != NULL; j = j->next)
        {
            if (j->price < j->next->price)
            {
                swap(j->id, j->next->id);
                swap(j->name, j->next->name);
                swap(j->farmer, j->next->farmer);
                swap(j->price, j->next->price);
                swap(j->quantity, j->next->quantity);
            }
        }
    }

    push("Sorted Crops by Market Price");

    cout << "\nCrops sorted by highest market price:\n";

    displayCrops();
}


// ================= HIGHEST PRICE =================

void highestPrice()
{
    if (head == NULL)
    {
        cout << "\nNo crop records available.";
        return;
    }

    Crop *temp = head;
    Crop *maxCrop = head;

    while (temp != NULL)
    {
        if (temp->price > maxCrop->price)
        {
            maxCrop = temp;
        }

        temp = temp->next;
    }

    cout << "\n--- HIGHEST PRICE CROP ---";
    cout << "\nCrop     : " << maxCrop->name;
    cout << "\nFarmer   : " << maxCrop->farmer;
    cout << "\nPrice/kg : Rs." << maxCrop->price << endl;
}


// ================= MAIN =================

int main()
{
    int choice;

    do
    {
        cout << "\n\n====================================";
        cout << "\n     SMART CROP-TO-MARKET SYSTEM";
        cout << "\n====================================";

        cout << "\n1. Add Crop";
        cout << "\n2. Display Crops";
        cout << "\n3. Search Crop";
        cout << "\n4. Sort by Market Price";
        cout << "\n5. Find Highest Price Crop";
        cout << "\n6. Display Recent Operations";
        cout << "\n7. Peek Latest Operation";
        cout << "\n8. Pop Operation";
        cout << "\n9. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addCrop();
            break;

        case 2:
            displayCrops();
            break;

        case 3:
            searchCrop();
            break;

        case 4:
            sortByPrice();
            break;

        case 5:
            highestPrice();
            break;

        case 6:
            displayStack();
            break;

        case 7:
            peek();
            break;

        case 8:
            pop();
            break;

        case 9:
            cout << "\nThank you!";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while (choice != 9);

    return 0;
}