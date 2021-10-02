/*#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

//Declaration of Functions

//Insert Functions
void InsertAtBeginning();
void InsertAtIndex();
void InsertAtEnd();

//Delete Functions
void DeleteAtBeginning();
void DeleteAtElement();
void DeleteFromEnd();

//Miscellaneous Functions
void PrintLinkedList();
void PrintLinkedListReverse();
int GetSize();
struct Node* GetNewNode();

//Head node made global
struct Node* head;

//driver function
int main()
{
    int choice;

    printf("______Welcome to My Code Practice!!______\n");
    printf("We'll be learning Doubly Linked list this time!\n");
    printf("\n\n");

    do
    {
        printf("\nEnter the operation you want to perform\n\n");
        printf("1] Insert element at the beginning \n2] Insert element at an nth position \n3] Insert element at the end\n4] Delete element at the beginning \n5] Delete element at an nth position \n6] Delete element at the end \n7] Print Linked List \n8] Print Linked List in reverse \n9] Print Size of Linked List \n10] Exit \n\n");
        scanf("%d",&choice);

        switch(choice) //Entered choices are in Switch case
        {
            case 1:
                InsertAtBeginning();
            break;

            case 2:
                InsertAtIndex();
            break;

            case 3:
                InsertAtEnd();
            break;

            case 4:
                DeleteAtBeginning();
            break;

            case 5:
                DeleteAtElement();
            break;

            case 6:
                DeleteFromEnd();
            break;

            case 7:
                PrintLinkedList();
                printf("\n\n");
            break;

            case 8:
                PrintLinkedListReverse();
                printf("\n\n");
            break;

            case 9:
                printf("The Size of the Linked List is %d\n\n",GetSize());
            break;

            case 10:
                printf("Exiting...\nThanks for the practising with me!\n\n");
                exit(0);
            break;

            default:
                    printf("Enter the correct choice!\n\n");

        }

    }while(choice != -1);
    printf("Exiting!\n\n");
    return 0;
}

//Functionalities
void InsertAtBeginning() // Insert a node at the beginning of the Linked List
{
    struct Node* temp;
    int value;
    temp = GetNewNode();

    printf("Enter the value to insert\n\n");
    scanf("%d", &value);
    temp->data  = value;

    if(head == NULL) //List is Empty
    {
        head = temp;
        return;
    }
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    //printf("You have performed InsertAtBeginning\n");
}

void InsertAtIndex() // Insert a node at an nth position of the Linked List
{
    int index, value, i;

    printf("Enter the index at which you want to enter the element\n\n");
    scanf("%d", &index);

    if(index == 1)
    {
        InsertAtBeginning();
        return;
    }

    if(index == (GetSize() + 1)) //Insert at end i.e. size plus 1
    {
        InsertAtEnd();
        return;
    }

    if(index > GetSize() || index <= 0) // Index out of bounds
    {
        printf("As the size of the Linked List is %d, Index doesn't exist!!\n\n", GetSize());
        return;
    }

    printf("Enter the value at nth index\n\n");
    scanf("%d",&value);

    struct Node* temp = GetNewNode();
    struct Node* current;

    temp -> data = value;
    current = head;

    for(i = 0; i < index - 2; i++) //traverse
    {
        current = current -> next;
    }
    temp -> next = current -> next;
    (current -> next) -> prev = temp;

    current -> next = temp;
    temp -> prev = current;
    //printf("You have performed InsertAtIndex\n");
}

void InsertAtEnd() // Insert a node at the end of the Linked List
{

    struct Node* temp;
    struct Node* current;

    int value;
    printf("Enter the value\n");
    scanf("%d", &value);

    temp = GetNewNode();
    temp -> data = value;

    current = head;
    while(current != NULL)
    {
        current = current -> next;
    }

    current -> next = temp;
    temp -> prev = current;
    //printf("You have performed InsertAtEnd\n");
}

void DeleteAtBeginning() //Delete an element at the beginning
{
    if(head == NULL) //List is Empty
    {
        printf("There is nothing to delete!\n\n");
        return;
    }

    struct Node* temp;
    int value;

    temp = head;
    value = temp -> data;

    head = temp -> next;
    temp -> next -> prev = NULL;
    printf("%d has been deleted from the linked list\n\n", value);
    free(temp);
    //printf("You have performed DeleteAtBeginning\n");
}

void DeleteAtElement() //Delete an element at an nth position
{
    if(head == NULL) //List is Empty
    {
        printf("There is nothing to delete!\n\n");
        return;
    }

    int index, value, i;

    printf("Enter the index at which you want to delete the element\n\n");
    scanf("%d", &index);

    if(index == 1) //Delete first element hence DeleteAtBeginning()
    {
        DeleteAtBeginning();
        return;
    }

    if(index == GetSize()) //Delete last element hence used GetSize()
    {
        DeleteFromEnd();
        return;
    }

    if(index > GetSize() || index <= 0) //Index Out of bounds
    {
        printf("As the size of the Linked List is %d, Index doesn't exist!!\n\n", GetSize());
        return;
    }

    struct Node* temp;
    struct Node* current;

    current = head;
    temp = head;
    for(i = 0; i < index - 2; i++) //Node Previous to the element in question
    {
        current = current -> next;
    }

    for(i = 0; i < index - 1; i++) //element node in question
    {
        temp = temp -> next;
    }


    value = temp -> data;
    current -> next = temp -> next; //Bypass temp
    temp -> next -> prev  = current;
    printf("%d at position %d has been deleted from the list\n\n", value, index);
    free(temp); //Free memory

    //printf("You have performed DeleteAtElement\n");
}

void DeleteFromEnd() //Delete an element at the end
{
    if(head == NULL) //List is Empty
    {
        printf("There is nothing to delete!\n\n");
        return;
    }

    if(GetSize() == 1)
    {
        DeleteAtBeginning();
        return;
    }

    int value;
    struct Node* temp;

    temp = head;
    while(temp -> next -> next != NULL) //traverse till second last
    {
        temp = temp -> next;
    }

    value = (temp -> next) -> data; //We are to delete temp->next
    free(temp -> next);
    temp -> next = NULL; //making the next node as null means we terminate the list

    printf("%d has been deleted from the list\n\n", value);

    //printf("You have performed DeleteFromEnd\n");
}

void PrintLinkedList() //Print Linked List normally
{
    if(head == NULL) //List is Empty
    {
        printf("Linked List doesn't exist!!\n\n");
        return;
    }

    struct Node* temp;

    temp = head;
    printf("The linked list is:\n");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp -> next;
    }
    //printf("You have performed PrintLinkedList\n");
}

void PrintLinkedListReverse() // Print Linked List without reversing it
{
    if(head == NULL) //List is Empty
    {
        printf("Linked List doesn't exist!!\n\n");
        return;
    }

    struct Node* temp;

    temp = head;
    printf("The linked list is:\n");
    while(temp != NULL)
    {
        temp = temp -> next;
    }
    while(temp == head)
    {
        printf("%d ", temp->data);
        temp = temp -> prev;
    }
    //printf("You have performed PrintLinkedList\n");
    //Print later than the call for reverse print, before for normal print
}

struct Node* GetNewNode() //returns a readied node to use directly
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

int GetSize() //User can use this function to find out the size of the linked list
{
    if(head == NULL)
        return 0;

    struct Node* temp;
    int count = 0;

    temp = head;
    while(temp != NULL) //traverse till end and increment for each node
    {
        temp = temp -> next;
        count++;
    }

    return count; //return count as and "int" in place of Function call
}
*/
