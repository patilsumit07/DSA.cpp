#include <stdio.h>
#include <stdlib.h>

// Structure for linked list
struct Node
{
    int marks;
    struct Node *next;
};

// Function to insert a node at the end
void insertNode(struct Node **head, int marks)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->marks = marks;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

// Function to display array
void displayArray(int marks[], int n)
{
    int i;

    printf("\n----- ARRAY REPRESENTATION -----\n");
    printf("Index\tMarks\tAddress\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%p\n",
               i, marks[i], (void *)&marks[i]);
    }
}

// Function to display linked list
void displayLinkedList(struct Node *head)
{
    struct Node *temp = head;

    printf("\n----- LINKED LIST REPRESENTATION -----\n");
    printf("Node Address\tMarks\tNext Address\n");

    while (temp != NULL)
    {
        printf("%p\t%d\t%p\n",
               (void *)temp,
               temp->marks,
               (void *)temp->next);

        temp = temp->next;
    }
}

// Count students scoring more than 80 using array
int countArray(int marks[], int n)
{
    int i;
    int count = 0;

    for (i = 0; i < n; i++)
    {
        if (marks[i] > 80)
        {
            count++;
        }
    }

    return count;
}

// Count students scoring more than 80 using linked list
int countLinkedList(struct Node *head)
{
    struct Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        if (temp->marks > 80)
        {
            count++;
        }

        temp = temp->next;
    }

    return count;
}

// Free linked list memory
void freeList(struct Node *head)
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int n;
    int i;
    int marks[100];

    struct Node *head = NULL;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of students.\n");
        return 0;
    }

    // a. Insert marks in array and linked list
    printf("\nEnter IA marks:\n");

    for (i = 0; i < n; i++)
    {
        printf("Enter marks of Student %d: ", i + 1);
        scanf("%d", &marks[i]);

        // Insert same marks into linked list
        insertNode(&head, marks[i]);
    }

    // b. Display memory representation
    displayArray(marks, n);
    displayLinkedList(head);

    // c. Count students scoring more than 80
    printf("\n----- COUNT RESULT -----\n");

    printf("Students scoring more than 80 (Array): %d\n",
           countArray(marks, n));

    printf("Students scoring more than 80 (Linked List): %d\n",
           countLinkedList(head));

    // Free dynamically allocated memory
    freeList(head);

    return 0;
}
