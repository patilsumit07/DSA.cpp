#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int rollNo;
    char name[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertStudent(int rollNo, char name[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->rollNo = rollNo;
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    if (rollNo < head->rollNo) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *current = head;

    while (current->next != NULL &&
           current->next->rollNo < rollNo) {
        current = current->next;
    }

    
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL)
        current->next->prev = newNode;
    else
        tail = newNode;

    current->next = newNode;
}


void deleteStudent(int rollNo) {
    struct Node *current = head;

    while (current != NULL && current->rollNo != rollNo) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with roll number %d not found.\n", rollNo);
        return;
    }

    if (current == head)
        head = current->next;
    else
        current->prev->next = current->next;

    if (current == tail)
        tail = current->prev;
    else
        current->next->prev = current->prev;

    free(current);

    printf("Student deleted successfully.\n");
}

void displayForward() {
    struct Node *current = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nStudents in ascending roll number:\n");
    while (current != NULL) {
        printf("Roll No: %d, Name: %s\n",
               current->rollNo, current->name);
        current = current->next;
    }
}

void displayBackward() {
    struct Node *current = tail;

    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nStudents in reverse order:\n");
    while (current != NULL) {
        printf("Roll No: %d, Name: %s\n",
               current->rollNo, current->name);
        current = current->prev;
    }
}

// Main function
int main() {
    int choice, rollNo;
    char name[50];

    do {
        printf("\n===== Student Doubly Linked List =====\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Forward\n");
        printf("4. Display Backward\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollNo);

                printf("Enter student name: ");
                scanf(" %[^\n]", name);

                insertStudent(rollNo, name);
                printf("Student inserted successfully.\n");
                break;

            case 2:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollNo);

                deleteStudent(rollNo);
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayBackward();
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
