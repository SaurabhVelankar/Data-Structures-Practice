#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//Declaration of Functions
void PrintMatrix(int[][50], int[][50], int, int, int, int); //Print both the matrix
void MatrixAddition(int[][50], int[][50], int, int, int, int); //Add both matrix and print result
void MatrixSubtraction(int[][50], int[][50], int, int, int, int); // Subtract Matrix A from B and print result
void MatrixMultiplication(int[][50], int[][50], int, int, int, int); // Multiply both matrix and print result
void TransposeMatrix(int A[50][50], int, int); //Permanently changes and Displays transpose of a Matrix

//Driver Function
int main()
{
    int choice;
    int i, j;
    int A[50][50], B[50][50]; //can use dynamic memory allocation or use variable in array declaration
    int r1, c1, r2, c2; //r1 & c1 are row and column of first, while r2 & c2 are row and column of second matrix

    printf("______Welcome to My Code Practice!!______\n");
    printf("We'll be learning Matrix Operations this time!\n");
    printf("\n\n");

    do
    {
        printf("Enter the operation you want to perform\n");
        printf("1] Take Input Matrix\n2] Print Matrix\n3] Addition of Matrix\n4] Subtraction of Matrix\n5] Multiplication of Matrix\n6] Transpose of Matrix\n7] Exit\n");
        scanf("%d",&choice);

        switch(choice) //Entered choices are in Switch case
        {
            case 1:
			{
				/*Can make a separate function for taking input, But as these
				are local variables, the information is lost after the scope ends.
				Possible solutions are global variables or using OOPs in C++
				*/
				//Input first Matrix
				printf("Enter the size of first matrix as row x column\n");
				scanf("%d%d", &r1,&c1);
				printf("Enter the values of First matrix\n");
				for(i = 0; i < r1; i++)
					for(j = 0; j < c1; j++)
						scanf("%d", &A[i][j]);

				//Input second Matrix
				printf("Enter the size of second matrix as row x column\n");
				scanf("%d%d", &r2,&c2);
				printf("Enter the values of Second matrix\n");
				for(i = 0; i < r2; i++)
					for(j = 0; j < c2; j++)
						scanf("%d", &B[i][j]);

				printf("\n\n");
			}
            break;

            case 2:
				PrintMatrix(A, B, r1, c1, r2, c2);
            break;

            case 3:
				MatrixAddition(A, B, r1, c1, r2, c2);
            break;

            case 4:
				MatrixSubtraction(A, B, r1, c1, r2, c2);
            break;

            case 5:
				MatrixMultiplication(A, B, r1, c1, r2, c2);
            break;

            case 6:
			{
				int ch;
				printf("Print transpose of which matrix?\n1] First\n2] Second\n");
				scanf("%d", &ch);
				if(ch == 1)
					TransposeMatrix(A, r1, c1);
				else if(ch == 2)
					TransposeMatrix(B, r2, c2);
				else
					printf("Enter valid choice\n\n");
			}
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
void PrintMatrix(int A[50][50], int B[50][50], int r1, int c1, int r2, int c2)
{
	int i, j;
	printf("\nThe first matrix is:\n");
	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c1; j++)
			printf("%d  ", A[i][j]);
		printf("\n");
	}
	printf("\n");

	printf("The second matrix is:\n");
	for(i = 0; i < r2; i++)
	{
		for(j = 0; j < c2; j++)
			printf("%d  ", B[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void MatrixAddition(int A[50][50], int B[50][50], int r1, int c1, int r2, int c2)
{
	if(r1 != r2 || c1 != c2) //Edge case whereby the order is not equal
	{
		printf("Can't perform addition, Both matrix should be matrices of equal order\n");
		return;
	}

	int i, j;
	PrintMatrix(A, B, r1, c1, r2, c2);

	int C[r1][c1];
	for(i = 0; i < r2; i++)
		for(j = 0; j < c2; j++)
			C[i][j] = A[i][j] + B[i][j]; //Add each element to result

	printf("Addition Matrix is:\n");
	for(i = 0; i < r2; i++)
	{
		for(j = 0; j < c2; j++)
			printf("%d  ", C[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void MatrixSubtraction(int A[50][50], int B[50][50], int r1, int c1, int r2, int c2)
{
	if(r1 != r2 || c1 != c2) //Edge case whereby the order is not equal
	{
		printf("Can't perform Subtraction, Both matrix should be matrices of equal order\n");
		return;
	}

	int i, j;
	PrintMatrix(A, B, r1, c1, r2, c2);

	int C[r1][c1];
	for(i = 0; i < r2; i++)
		for(j = 0; j < c2; j++)
			C[i][j] = A[i][j] - B[i][j]; //Subtract element of B from A element and assign to result

	printf("Subtraction Matrix is:\n");
	for(i = 0; i < r2; i++)
	{
		for(j = 0; j < c2; j++)
			printf("%d  ", C[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void MatrixMultiplication(int A[50][50], int B[50][50], int r1, int c1, int r2, int c2)
{
	if(c1 != r2) //Edge case whereby the orders aren't in required order, c1 should be equal to r2. (e.g. 2x3 and 3x2)
	{
		printf("Can't perform Multiplication, Matrices should be of order MxN and PxQ where N=P\n");
		return;
	}

	int i, j, k;
	int C[r1][c2];

	PrintMatrix(A, B, r1, c1, r2, c2);

	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c2; j++)
		{
			C[i][j] = 0;
			for(k = 0; k < c1; k++)
			{
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	printf("Multiplication Matrix is:\n");
	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c2; j++)
			printf("%d  ", C[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

//Permanently changes and Displays transpose of a Matrix, can be modified to simply print transpose
void TransposeMatrix(int A[50][50], int r, int c)
{
	int i, j;
	int temp = 0;

	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			if(i < j) //That is the upper triangle from diagonal
			{
				//swap with lower half
				temp = A[i][j];
				A[i][j] = A[j][i];
				A[j][i] = temp;
			}
		}
	}

	printf("Transpose Matrix is:\n");
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
			printf("%d  ", A[i][j]);
		printf("\n");
	}
	printf("\n\n");

}
