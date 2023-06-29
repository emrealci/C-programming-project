#include <stdio.h>
#include <stdlib.h>

//Implementation of Stack using Linked List <----

struct node{
	int data;
	struct node *next;
};

struct node *top = NULL; // like head

void push(int x){
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next = top;
	top = newnode;
	printf("%d is added\n", x);
}

void pop(){
	struct node *temp;
	temp = top;
	
	if (top == NULL)
		printf("Stack is empty!\n");
		
	else{
		printf("%d is popped\n",top->data);
		top = top->next;
		free(temp);
		
	}

}

void peek(){
	if (top == NULL)
		printf("Stack is empty!\n");
	
	else{
		printf("Top element is %d\n", top->data);
	}
}

void display(){
	struct node *temp;
	temp = top;
	
	if (top == NULL)
		printf("Stack is empty!\n");
	
	else{
		while(temp!= NULL){
			printf("%d\n",temp->data);
			temp = temp->next;
		}
	}
	
}

int main(){
	int number, x;
	
	while(1){
		printf("Press: 1 to push, 2 to pop, 3 to peek, 4 to display, 0 to quit ");
		scanf("%d",&number);
		
		switch(number){
			case 0:
				return 0;
			case 1:
				printf("Enter data ");
				scanf("%d",&x);
				push(x);
				break;
			
			case 2:
				pop();
				break;
			
			case 3:
				peek();
				break;
			
			case 4:
				display();
				break;
			
			default:
				printf("Invalid choice!\n");
		}
	}
	

}



//################################################################################//

//Implementation of Stack using Array <----

/*
#define N 6
int stack[N];
int top = -1; //implement top as -1 while using array representation

void push(int x){
	if (top == N-1)
		printf("Stack is full!\n");
	
	else{
		top++;
		stack[top] = x;
		printf("%d is added\n", x);
	}
}

void pop(){
	if (top == -1)
		printf("Stack is empty!\n");

	else{
		printf("%d is popped\n", stack[top]);
		top--;
	}
}

void peek(){
	if (top == -1)
		printf("Stack is empty!\n");
		
	else
		printf("Top element is: %d\n",stack[top]);
}

void display(){
	int i;
	if (top == -1)
		printf("Stack is empty!\n");
	
	else{
		for (i = top; i>=0; i--){
			printf("%d\n", stack[i]);
		}
	}
}

int main(){
	int number, x;
	while(1){
		printf("Press: 1 to push, 2 to pop, 3 to peek, 4 to display, 0 to quit ");
		scanf("%d",&number);
		
		switch(number){
			case 0:
				return 0;
			case 1:
				printf("Enter data ");
				scanf("%d",&x);
				push(x);
				break;
			
			case 2:
				pop();
				break;
			
			case 3:
				peek();
				break;
			
			case 4:
				display();
				break;
			
			default:
				printf("Invalid choice!\n");
		}
	}
	
}

*/
