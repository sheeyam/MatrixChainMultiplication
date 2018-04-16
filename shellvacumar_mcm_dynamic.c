/************************************************************************
* Programmer: Sheeyam Shellvacumar
*
* Course: CSCI 5432.2
*
* Date: March 24, 2018
*
* Assignment: Assignment #3 - Question 04 (Program 02)
*
* Environment: OnlineGDP
*
* Files Included: mcm_dynamic.c
*
* Purpose: Get Matrices and it's dimensions from the user and then perfrom matrix chain multiplication 
* using dynamic programmaing approach to find the optimal sequence of matrix order.
*
* Input: Matrices and it's dimensions
*
* Output: optimal matrix sequence
*
* Algorithm:
* MATRIX-CHAIN-ORDER(p)
* n = p.length - 1
* let m[1..n, 1..n] and s[1..n-1; 2..n] be new tables
* for i = 1 to n
*	m[i,i] = 0
* for l = 2 to n  // l is the chain length
*	for i = 1 to n - l + 1
*		j = i + l - 1
*		m[i,j] = INFINITY
*		for k = i to j - 1
*			q = m[i,k] + m[k + 1, j] + p(i-1)pkpj
*			if q < m[i,j]
*				m[i,j] = q
*				s[i,j] = k
* return m and s
* 
***********************************************************************/ 
#include<stdio.h>
#include<conio.h>

#define INFINITY 999999999

long int m[20][20];
int s[20][20];
int d[20],i,j,n;

//Function to print the optimal sequence
void print_optimal_combination(int i,int j)
{
    if (i == j) {
        printf(" A%d ",i);
    } else {
        printf(" ( ");
        print_optimal_combination(i, s[i][j]);
        print_optimal_combination(s[i][j] + 1, j);
        printf(" ) ");
    }
}

// Algoirthm to perfrom the Matrix Multiplication
void matrixmultiplication(void)
{
    long int q;
    int k;
    
    for(i=n;i>0;i--) {
        for(j=i;j<=n;j++) {
            if(i==j) {
                m[i][j]=0;
            } else  {
                for(k=i;k<j;k++) {
                    q=m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j];
                    if(q<m[i][j]) {
                        m[i][j]=q;
                        s[i][j]=k;
                    }
                }
            }
        }
    }
}

void main()
{
    printf("*Matrix Chain Multiplication - Dynamic Programming Approach* \n");
    
    int k;
    
    //Get User Input for Matrices
    printf("Enter Number of Matrices: ");
    scanf("%d",&n);
    
    // Initial Values 
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++) {
            m[i][i]=0;
            m[i][j]=INFINITY;
            s[i][j]=0;
    }
    
    // Get User Input for Dimensions
    printf("\nEnter the Dimensions: \n");
    for(k=0;k<=n;k++) {
        printf("d%d: ",k);
        scanf("%d",&d[k]);
    }
    
    // Start Clock
    int start_s = clock();
    printf("\nStart Time: %d \n", start_s);
    
    //Matrix Multiplication Logics Call
    matrixmultiplication();
    
    //Print Operations and Cut accordging to the matrix name
    printf("\nMatrix - No_of_OPs - Cuts:\n");
    for(i=1;i<=n;i++) {
        for(j=i;j<=n;j++) {
            printf("m[%d][%d] -  %ld - %ld \n",i, j, m[i][j], s[i][j]);
        }
    }
    
    //Reset i and j
    i=1,j=n;
    
    //Print Optimal Sequence - Final Output
    printf("\nOptimal Sequence : ");
    print_optimal_combination(i,j);
    printf("\nOptimal Cost : %ld ", m[i][j]);
    
    //Stop Clock	
    int stop_s = clock();
    printf("\nStop Time: %d \n", stop_s);
    
	//Calculate Time Difference
    int diff = stop_s - start_s;
    printf("\nTime Taken to Calculate: %d milliseconds ", diff);
    
    getch();
}
// End of the Program








