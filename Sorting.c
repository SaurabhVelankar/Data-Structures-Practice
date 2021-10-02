#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//Declaration of Functions
//Sorting Functions
void BubbleSort(int[], int);
void SelectionSort(int[], int);
void InsertionSort(int[], int);
void MergeSort(int[], int);
void QuickSort(int[], int);
//Miscellaneous Function
void Swap (int*, int*);
//void DeleteFromEnd();
//void PrintLinkedList();

//driver function
int main()
{
    int choice;
	int size, i;
	int arr[50];

    printf("______Welcome to My Code Practice!!______\n");
    printf("We'll be learning Sorting Algorithms this time!\n");
    printf("\n\n");
    do
    {
        printf("Enter the algorithm you want to perform\n");
        printf("1] Take Input \n2] Bubble Sort \n3] Selection Sort \n4] Insertion Sort \n5] Merge Sort \n6] Quick Sort \n7] Exit \n");
        scanf("%d",&choice);

        switch(choice) //Entered choices are in Switch case
        {
        	case 1:
			{
				printf("Enter the size of the array\n");
				scanf("%d",&size);

				printf("Enter the %d elements of the array\n", size);
				for(i = 0; i < size; i++)
					scanf("%d", &arr[i]);

				printf("The array is: \n");
				for(i = 0; i < size; i++)
					printf("%d ", arr[i]);
				printf("\n\n");

			}
            break;

            case 2:
            	BubbleSort(arr, size);
            break;

            case 3:
            	SelectionSort(arr, size);
            break;

            case 4:
            	InsertionSort(arr, size);
            break;

            case 5:
            	MergeSort(arr, size);
            break;

            case 6:
            	QuickSort(arr, size);
            break;

            case 7:
                printf("Exiting...\n Thanks for the practicing with me!");
                exit(0);
            break;

            default:
                    printf("Enter the correct choice!\n");

        }

    }while(choice != 0);

    return 0;
}


//Functionalities
void BubbleSort(int arr[50], int size)
{
	int i, j;
	int arr1[size];

	for(i = 0; i < size; i++)
		arr1[i] = arr[i];

	printf("Before Sorting:\n");
	for(i = 0; i < size; i++)
		printf("%d ", arr1[i]);

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if(arr1[j] > arr1[j+1])
				Swap(&arr1[j], &arr1[j + 1]);
		}
	}

	printf("\nAfter Sorting:\n");
	for(i = 0; i < size; i++)
		printf("%d ", arr1[i]);
}

void SelectionSort(int arr[50], int size)
{

}

void InsertionSort(int arr[50], int size)
{

}

void MergeSort(int arr[50], int size)
{

}

void QuickSort(int arr[50], int size)
{

}

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b
	*b = temp;
}
