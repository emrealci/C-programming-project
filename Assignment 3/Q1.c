/*
First, we received 2 inputs from the user. Then we sent the address of one of them and the other directly 
to the function itself. There is something important to note here: Since we sent the variable's address to the function,
we used a pointer to hold it. Afterwards, using a while loop, we determined the size of our array and 
created an array with the size we found inside the function. Then, we parsed the number  entered by the 
user and stored it in the array. Finally, based on the entered "N" value, we reversed the last 
N digits of the number and printed it.

*/
#include <stdio.h>

void reverseN(int *number, int N){
	
	int sizeArr, i,j;
	int temp1 = *number;
	int temp2 = *number;
	
	while(temp1 > 0 ){ // we check size of array
		temp1 = temp1 / 10;
		sizeArr = sizeArr + 1;
		
	}
	
	int arr[sizeArr]; //create the array
	
	for (i = 0; i < sizeArr; i++){ //put elements in the array
		
		arr[sizeArr-1-i] = (*number) % 10;
		(*number) = (*number) / 10;
	}
	
	if (N > sizeArr){
		printf("N must be less than %d!",sizeArr+1);
	}
	
	else if(N == sizeArr){
		for (i = 0; i < sizeArr; i++){
			printf("%d",arr[sizeArr-i-1]);
		}
	}
	
	else{
		
		for (i = 0; i < sizeArr; i++){
			if ( i < sizeArr - N)
				printf("%d",arr[i]);
		}
		
		for (i = sizeArr-1; i >= sizeArr-N; i--){
			printf("%d",arr[i]);
		}
	
	}
}

int main(){
	
	int number, N;
	scanf("%d %d",&number,&N);
	reverseN(&number,N);	
	
	
}
