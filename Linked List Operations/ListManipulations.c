/*
The reason we perform all operations in separate functions in this code is for its educational for beginners. 
For instance, if you want to do all insertion operations in a single function, you can run the code provided in the comment line at the bottom.
*/

#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node *next;
};

struct node *head = NULL; // head as a global variable
int count = 0; // number of nodes

void createList(){
	head = NULL;  // reset the list if user wants to create new list
	struct node *newnode, *temp; 

	while(1){
		
		int choice;
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("Enter data ");
		scanf("%d", &newnode->data);
		newnode ->next = NULL;
		
		if(head == NULL)
			head = temp = newnode;	
		
		else{
			temp ->next = newnode;
			temp = newnode;
		}
		
		count += 1;
		
		while(1){
			
			printf("Do you want to continue? (0,1) ");
			scanf("%d", &choice);
			
			if (choice == 0 || choice == 1)
				break;
			else
				printf("Invalid choice! Press 1 to continue adding, 0 to quit\n");
		}
		
		if (choice == 0)
			break;
	}	
	
}

void addToBeginning(){
	count += 1;
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the number you want to add beginning of the list ");
	scanf("%d", &newnode->data);
	newnode->next = head;
	head = newnode;
	
}

void addToEnd(){
	count += 1;
	struct node *newnode,*temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the number you want to add to the end of the list ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	temp = head;
	while(temp ->next != NULL){
		temp = temp->next;
	}
	temp->next = newnode;
	
}

void addToMiddle(){
	struct node *newnode, *temp;
	int position, i = 1;
	
	printf("Enter the position where you want to insert the element in the list \n");
	printf("For example: If you enter 3, the number you are adding will be the 3rd number in the list \n");
	scanf("%d",&position);
	
	if (position > count)
		printf("Invalid position");
		
	else{
		newnode = (struct node*)malloc(sizeof(struct node));
		count += 1;
		temp = head;
		while(i < position -1){
			
			temp = temp -> next;
			i++;
		}
	
	printf("Enter data ");
	scanf("%d",&newnode->data);
	
	newnode->next = temp->next;
	temp->next = newnode;
	
	}
}

void deleteFromBeginning(){
	
	struct node *temp;
	
	if (head == NULL){
		printf("Already empty!");
	}
	
	else{
		count -= 1;
		temp = head;
		head = head->next;
		free(temp);
	}
}

void deleteFromMiddle(){
	
	struct node *nextNode, *temp;
	int position, i = 1;
	temp = head;
	printf("Enter the element at which position you want to delete ");
	scanf("%d", &position);
	temp = head;
	
	if(position > count || position <= 0){
        printf("Invalid position\n");
        return; 
    }
		
	else if (position == 1) {
        deleteFromBeginning();
        return;
    }
    
	else{
		count -= 1;
		while (i < position - 1){
			temp = temp->next;
			i++;
		}
		nextNode = temp->next;
		temp->next = nextNode->next;
		free(nextNode);
	}
}

void deleteFromEnd(){
	count -= 1;
	struct node *previousNode, *temp;
	temp = head;
	
	while(temp->next != NULL){
		previousNode = temp;
		temp = temp->next;
		
	}
	
	if (temp == head){
		head = NULL;
		free(temp);
	}
	else{
		previousNode->next = NULL;
		free(temp);
	}
}

void printList(){
	
	struct node *temp;
	temp = head;
	printf("Created list:\n");
	while(temp != 0){
		
		printf("%d\n",temp->data);
		temp = temp -> next;
	}
}

int main(){
	int number;
	
	while(1){
		
		printf("Press 1 to create a list \nPress 2 to add number to beginnig of the list \nPress 3 to add number to middle of the list \nPress 4 to add number to end of the list\n");
		printf("Press 5 to delete number from beginning \nPress 6 to delete number from middle \nPress 7 to delete number from end \nPress 8 to show linked list \nPress 9 to quit\n");
		scanf("%d",&number);
		
		if (number == 1)
			createList();
		
		else if (number == 2)
			addToBeginning();
			
		else if (number == 3)
			addToMiddle();
			
		else if (number == 4)
			addToEnd();
			
		else if (number == 5)
			deleteFromBeginning();
		
		else if (number == 6)
			deleteFromMiddle();
			
		else if (number == 7)
			deleteFromEnd();
			
		else if(number == 8)
			printList();		
			
		else if (number == 9){
			printf("The program has ended.\nThe latest updated list:\n");
			printList();
			break;
	 	}
	 	else
	 		printf("Invalid choice!\n");
	}
	
}

//############################################################################

/*

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL; 
int count = 0; 

void insertNode(int position){
	if(position < 1 || position > count + 1){
        printf("Invalid position\n");
        return;
    }

	struct node *newnode, *temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the number you want to add ");
	scanf("%d", &newnode->data);

	if(position == 1){
		newnode->next = head;
		head = newnode;
	}else{
		temp = head;
		for(int i=2; i<position; i++){
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
	count += 1;
}

void deleteNode(int position){
	if(position < 1 || position > count){
        printf("Invalid position\n");
        return;
    }

	struct node *temp, *nextNode;
	if(position == 1){
		temp = head;
		head = head->next;
		free(temp);
	}else{
		temp = head;
		for(int i=2; i<position; i++){
			temp = temp->next;
		}
		nextNode = temp->next;
		temp->next = nextNode->next;
		free(nextNode);
	}
	count -= 1;
}

void printList(){
	struct node *temp = head;
	printf("Current List:\n");
	while(temp != NULL){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

int main(){
	int number, position;
	
	while(1){
		printf("Press 1 to insert a number \nPress 2 to delete a number \nPress 3 to show the list \nPress 4 to quit\n");
		scanf("%d",&number);

		switch(number){
			case 1:
				printf("Enter the position to insert the number ");
				scanf("%d", &position);
				insertNode(position);
				break;
			case 2:
				printf("Enter the position to delete the number ");
				scanf("%d", &position);
				deleteNode(position);
				break;
			case 3:
				printList();
				break;
			case 4:
				printf("The program has ended.\nThe latest updated list:\n");
				printList();
				return 0;
			default:
				printf("Invalid choice!\n");
		}
	}
	
	return 0;
}
*/

//############################################################################
