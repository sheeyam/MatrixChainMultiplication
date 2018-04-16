/************************************************************************
* Programmer: Sheeyam Shellvacumar
*
* Course: CSCI 5432.2
*
* Date: March 24, 2018
*
* Assignment: Assignment #3 - Question 04 (Program 01)
*
* Environment: OnlineGDP
*
* Files Included: mcm_general.c
*
* Purpose: Get Matrices and it's dimensions from the user and then perfrom matrix chain multiplication 
* using the general approcah to find the number of operations and compute time taken.
*
* Input: Matrices and it's dimensions
*
* Output: No of Matrix Operations with General Approach and Time Taken
*
* Algorithm:
* MATRIX-MULTIPLY(A,B)
* if A.columns NOTEQUAL B.rows
*	error incompatible dimensions
* else let C be a new A.rows * B.columns matrix
*	for i = 1 to A.rows
*		for j = 1 to B.columns
*			cij = 0
*			for k = 1 to A.columns
*				cij = cij + aik.bkj
*	return C
* 
***********************************************************************/ 

#include<stdio.h>
#include<limits.h>
#include<time.h>
 
// Matrix Multiplication logic
int MatrixChainMultiplication(int p[], int n)
{
 
    int j, ops;
    ops = 0;
    
    // L is chain length.
    for (j=2; j<n; j++) {
        ops = ops + p[0]*p[j-1]*p[j];
    }
 
    return ops;
}
 
int main()
{
    printf("*Matrix Chain Multiplication - General Approach* \n");
    
    int n,i;
    
    //Get User Input for Matrices
    printf("Enter Number of Matrices: ");
    scanf("%d",&n);
    n++;
 
    int arr[n];
 
    // Get User Input for Dimensions
    printf("\nEnter the Dimensions: \n");
    for(i=0;i<n;i++) {
        printf("Enter d%d : ",i);
        scanf("%d",&arr[i]);
    }
    
    // Start Clock
    int start_s = clock();
    printf("\nStart Time: %d \n", start_s);
 
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("\nNumber of Matrix Operations: %d \n", MatrixChainMultiplication(arr, size));
    
    //Stop Clock	
    int stop_s = clock();
    printf("\nStop Time: %d \n", stop_s);
    
	//Calculate Time Difference
    int diff = stop_s - start_s;
    printf("\nTime Taken to Calculate: %d milliseconds ", diff);
 
    return 0;
}









