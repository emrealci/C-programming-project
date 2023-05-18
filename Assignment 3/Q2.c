/*
First, we received the number of rows and columns from the user. Initially, we created 
the Iteration function and a multidimensional array with dimensions of 30, and assigned 
0 as the initial value for the element at row 0 and column 0. Then, inside a for loop, we 
divided our problem into three parts. First, when the column is 0, we took half of the previous 
row's value and added 40 to it. This way, we calculated both its own weight and the load it carries from above.
If the row and column numbers are equal, we implemented a similar algorithm. Finally, we created an algorithm for
the middle columns. Next,let's look at the recursion part.For this problem, the Recursion algorithm is more suitable, 
and we can solve the problem very briefly using recursion.Again, we divided this part into three sections. 
The only difference here is that instead of using an array, we allowed the function to update each value 
by calling itself again. Finally, we returned the value and calculated the total load at the desired row and column.

*/
#include <stdio.h>

//########################## FOR ITERATION PART #################################
                                                                              
double calculateWeightBack_Iteration(int row, int col){                     
	                                                                        
 	int i,j;
	int arr[30][30];
	arr [0][0] = 0; //initial value
	
	
	for (i = 1; i < 30; i++){
		for (j = 0; j <= i; j++){
			
			if (j == 0)
				arr[i][j] = ( (arr[i-1][0]) / 2) + 40; 
			
			else if ( i == j)
				arr[i][j] = ( (arr[i-1][j-1]) / 2) +40;
			
			else
				arr[i][j] = (arr[i-1][j-1] / 2) + (arr[i-1][j] / 2) + 80;
						
		}
	}
	return arr[row][col];
}

//######################## FOR RECURSION PART ####################################

double calculateWeightBack_Recursion(int row,int col){
	
	if (row == 0 && col == 0) //base case
		return 0;
		
	if ( col == 0 ) 
		return (calculateWeightBack_Recursion(row-1,col) / 2 + 40);
		 
	else if ( row == col)
		return (calculateWeightBack_Recursion(row-1,col-1) / 2 + 40);
		
	else
		return ( (calculateWeightBack_Recursion(row-1,col-1)/2 ) + (calculateWeightBack_Recursion(row-1,col)/2) + 80);

	
}

int main() {                                                                
	
	int row,column;
	
	printf("Enter number of row: ");
	scanf("%d",&row);
	
	printf("Enter number of column: ");
	scanf("%d",&column);
	
	double result_Iteration = calculateWeightBack_Iteration(row,column);
	printf("%.2f\n",result_Iteration);
	
	double result_Recursion = calculateWeightBack_Recursion(row,column);
	printf("%.2f",result_Recursion);
}
