#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

# define MAX_SIZE 50 //Max size for Queue and Stack, one can use dynamic memory allocation if need be

/*
If this program is implemented in an object oriented language, The global variables
can be privatised under a class, and functions can be made public/ private/ protected
as needed. Since C is non OOP, we use global variables for the ease of use.
*/

//Declaration of Functions
//Stack Functions
void Stack();
void Push();
void Pop();
void Top();
void PrintStack();
int IsEmpty();
int IsFull();

//Queue Functions
void Queue();
void Enqueue();
void Dequeue();
void Front();
void Rear();
void PrintQueue();
int IsEmptyQ();

//Global Variables
//Stack Variables
int top = -1;
int stack[MAX_SIZE];

//Queue Variables
int front = -1;
int rear = -1;
int queue[MAX_SIZE];

//Driver function
int main()
{
    int choice;

    printf("______Welcome to My Code Practice!!______\n");
    printf("We'll be learning Stack and Queue this time!\n");
    printf("\n\n");

    do
    {
        printf("Choose the Data Structure you want to perform\n");
        printf("1] Stack \n2] Queue \n3] Exit \n"); //Choice given to the user
        scanf("%d",&choice);
        printf("\n");

        switch(choice) //Entered choices are in Switch case
        {
            case 1:
                Stack(); //Implement Stack
            break;

            case 2:
                Queue(); //Implement Queue
            break;

            case 3:
                printf("Exiting...\nThanks for the practising with me!\n\n");
                exit(0); // Exits from the program itself
            break;

            default:
                    printf("Enter the correct choice!\n\n");

        }

    }while(choice != 0); // end of do...while

    return 0;
}

//Functionalities - Stack driver function
void Stack() //Stack driver function
{
    int choice;

    do
    {
        printf("Choose the Stack Operation\n");
        printf("1] Push \n2] Pop \n3] Top \n4] Print Stack \n5] IsEmpty \n6] IsFull \n7] Go Back \n");
        scanf("%d",&choice);
        printf("\n");

        switch(choice) //Entered choices are in Switch case
        {
            case 1:
                Push(); //Add Element at top
            break;

            case 2:
               Pop(); //Remove top element
            break;

            case 3:
               Top(); // Returns top element
            break;

            case 4:
               PrintStack(); // Print the stack from bottom to top
            break;

            case 5:
               if(IsEmpty()) //Check whether stack is empty
					printf("The Stack is Empty!\n\n");
				else
					printf("The Stack is not Empty (For Now)\n\n");

            break;

            case 6:
			   if(IsFull()) //Check whether stack is Full
					printf("The Stack is Full!\n\n");
				else
					printf("The Stack is not Full (Yet)\n\n");

            break;

            case 7:
                printf("Exiting Stack\n\n");
                top = -1; //Make top -1 so that we can start over since we're  using global variables
                return;
            break;

            default:
				printf("Enter the Correct Choice!\n");

        }

    }while(choice != 0); //End of do...while

	top = -1; //Make top -1 so that we can start over since we're  using global variables
	printf("Exiting Stack\n\n");
}

//Stack Functionalities
void Push()
{
	if(IsFull()) //We first check if the stack is full, abort if yes
	{
		printf("Stack is Full! Pop some Elements\n\n");
		return;
	}

	int value;
	printf("Enter the Value to Push\n");
	scanf("%d",&value);
	printf("\n");

	top++;
	stack[top] = value;
	printf("%d was Pushed\n\n", value);
}

void Pop ()
{
	int value;
	if(IsEmpty()) //Nothing can be popped if stack is empty hence we check if stack is empty
	{
		printf("The Stack is Empty cannot Pop!\n\n");
		return;
	}

	value = stack[top];
	top--; //No need to delete the element at top, since it will be overwritten after pushing another element
	printf("%d was Popped from the Stack\n\n", value);
}

void Top() // Function can be modified to return top as an integer
{
	if(IsEmpty()) //Can't return if there's nothing to return
	{
		printf("Stack is Empty, Can't give Top\n\n");
		return;
	}

	printf("%d is the Top Element\n\n", stack[top]);
}

void PrintStack() //Simply print the stack
{
	int i;
	if(IsEmpty())
	{
		printf("Stack is Empty, Cannot Print!\n\n");
		return;
	}
	//printf("top is: %d", top);
	printf("The Stack is:  ");
	for(i = 0; i < top + 1; i++)
		printf("%d ", stack[i]);
	printf("\n\n");
}

int IsEmpty()
{
	if(top == -1) //Stack is empty only when top is -1
		return 1;
	else
		return 0;
}

int IsFull()
{
	if(MAX_SIZE == top + 1) //MAX_SIZE is the macro for the space allocated for stack, and top is 0 based
		return 1;
	else
		return 0;
}

//Queue driver function
void Queue()
{
    int choice;

    do
    {
        printf("Choose the Queue Operation\n");
        printf("1] Enqueue \n2] Dequeue \n3] Front \n4] Rear \n5] Print Queue \n6] IsEmpty \n7] Go Back \n");
        scanf("%d",&choice);
        printf("\n");

        switch(choice) //Entered choices are in Switch case
        {
            case 1:
                Enqueue(); //Add an element to the rear end of the queue
            break;

            case 2:
                Dequeue(); //Remove an element from the front of the queue
            break;

            case 3:
                Front(); //Print or Return the element at the front of the queue
            break;

            case 4:
				Rear(); //Print or Return the element at the rear of the queue
            break;

            case 5:
                PrintQueue(); //Print queue from the front to the rear index
            break;

            case 6:
                if(IsEmptyQ()) //Check whether the queue is empty
					printf("The Queue is empty (For now)\n\n");
				else
					printf("The queue is not empty!\n\n");
            break;

            case 7:
                printf("Exiting Queue\n\n");
                //Front and Rear will be reset so that queue can be used again, Since they're global variables
                front = -1;
                rear = -1;
                return;
            break;

            default:
                    printf("Enter the correct choice!\n\n");
        }

    }while(choice != 0);

	printf("Exiting Queue\n\n");
	//Front and Rear will be reset so that queue can be used again, Since they're global variables
	front = -1;
	rear = -1;
}

//Queue Functionalities
void Enqueue()
{
	int value;
	printf("Enter the value\n");
	scanf("%d",&value);

	if(IsEmptyQ()) //if empty, front and rear will have same value, i.e. -1 hence the special case
	{
		front++;
		rear++;
		queue[rear] = value;
	}
	else
	{
		rear = (rear + 1) % MAX_SIZE; //doing this leaves no holes in the queue when rear goes "out of bounds"
		queue[rear] = value;
	}
	printf("%d was enqueued\n\n", value);
}

void Dequeue()
{
	if(IsEmptyQ()) //Can't dequeue an empty queue
	{
		printf("Queue is Empty, Enqueue Elements!\n\n");
		return;
	}

	printf("%d has been Dequeued\n\n", queue[front]);
	if(front == rear) //when there's only one element, a simple "front++" won't do
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front + 1) % MAX_SIZE; //doing this leaves no holes in the queue when front goes "out of bounds"
	}
}

void Front() // Function can be modified to return Front as an integer
{
	if(IsEmptyQ())
	{
		printf("Queue is Empty, can't give Front\n\n");
		return;
	}

	printf("%d is the Front Element\n\n", queue[front]);
}

void Rear() // Function can be modified to return Rear as an integer
{
	if(IsEmptyQ())
	{
		printf("Queue is Empty, can't give Rear\n\n");
		return;
	}

	printf("%d is the Rear Element\n\n", queue[rear]);
}

void PrintQueue()
{
	if(IsEmptyQ()) //Can't print if there's nothing to print!
	{
		printf("Queue is Empty, can't Print!\n\n");
		return;
	}

	int i;

	printf("Queue is: ");
	for(i = front; i < rear + 1; i++)
	{
		printf("%d ", queue[i]);
	}
	printf("\n\n");
}

int IsEmptyQ()
{
	return ((front == -1 && rear == -1)); //One line return statement using conditional operators
}

