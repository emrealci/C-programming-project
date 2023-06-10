#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
	char songName[50];
    int duration;
    struct Song *next; 
}song;

song *newSong(char songName[], int duration) {
	
    song *node = (song*)malloc(sizeof(song)); // allocate memory 
    strcpy(node->songName, songName);
    node->duration = duration;
    
    node->next = NULL; //we should add NULL to the end
    return node;
}

song *insertSong(song *root, song *node) {
	
    if (root == NULL || (root->duration >= node->duration) ){
    //if list is empty or lower
        node->next = root;
        return node;
        
    }
    
    song *current = root;
       //for middle case
    while (current->next != NULL && current->next->duration < node->duration) {
        current = current->next;
    }
    
    node->next = current->next;
    current->next = node;
	return root;
}

song *deleteSong(song *root, char songName[]) {
	song *temp = root; 
    song *previous;
    
    if (temp != NULL && strcmp(temp->songName, songName) == 0) {
   		root = temp->next;
        free(temp); // we should delete the temp 
        //check that the linked lists are connected before using the free command
        
        return root;   
    }
    
    while (temp != NULL && strcmp(temp->songName, songName) != 0) {
		previous = temp;
        temp = temp->next;  
    }
    
    if (temp == NULL) return root;
    previous->next = temp->next;
    free(temp);
    
    return root;
}

void printList(song *node) {
	
    printf("The list in duration-time order:\n");
	int songCount = 1;
    
    while (node != NULL) {
        printf("%d.%s %d:%02d\n",songCount++,node->songName, node->duration/60, node->duration%60);
        node = node->next; //circulates the entire linked list and print
    }
}

int main() {
    song *root = NULL;
    char songName[50];
    int minute, second, input, duration ;
    char filename[25];
    
    FILE *file;
    file = fopen("songs.txt", "r");
    
    if (file == NULL) //if the file is not found
    	printf("Error\n");

	
	else {
		
        while (fscanf(file, " %[^\t]\t%d:%d",songName, &minute, &second) != EOF) {
        	
            duration = minute * 60 + second; //find the duration
            root = insertSong(root, newSong(songName, duration));
            
        }
    }
    
    fclose(file); 

while (input != 5) {
	
    printf("\nEnter your choice:\n");
    printf("1 to insert a song into the list.\n");
    printf("2 to delete a song from the list.\n");
    printf("3 to print the songs in the list.\n");
    printf("4 to print the songs to an output file.\n");
    printf("5 to end.\n");
    
    scanf("%d", &input); //take input from user

    if (input == 1) {
    	
		printf("\nEnter a song name with duration:\n");
        scanf(" %[^\n]", songName);

        int index = strlen(songName) - 1;
        
        while(songName[index] != ' ') {
            --index;
        }
        
        sscanf(&songName[index], " %d:%d", &minute, &second);
        songName[index] = '\0';
        
        duration = minute * 60 + second;
        root = insertSong(root, newSong(songName,duration));
    }
    
    else if (input == 2) {
    	
        printf("\nEnter a song name:\n");
        scanf(" %[^\n]", songName);
        root = deleteSong(root, songName);
        printf("The song \"%s\" is deleted from the list!\n", songName);
        
    }
    
    else if (input == 3) 
        printList(root);

    else if (input == 4) {
    	
        printf("\nEnter a file name:\n");
        scanf("%s", filename);
        
        file = fopen(filename, "w");
        
        if (file == NULL) 
            printf("Error\n");
        
		
		else {
            song *temp = root;
            
            int count = 1;
            
            fprintf(file, "The list in duration-time order:\n");
            
            while (temp != NULL) {
            	
                fprintf(file, "\t%d.%s %d:%02d\n", count++, temp->songName, temp->duration/60, temp->duration%60);
                temp = temp->next;
            }
            
            fclose(file);
            printf("Output is printed to the file %s\n", filename);
        }
    }
    
    else if (input != 5)
    	 printf("Invalid choice\n");
    
}

    return 0;
}

