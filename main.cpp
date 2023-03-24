#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node{
	int data;
	struct node *nextNode;
	struct node *prevNode; 	
};
struct node *startNode=0,*lastNode=0, *newNode, *ptr;

struct node* getNode(){
	newNode=(struct node *)malloc(sizeof(struct node));
	printf("Insert Data : ");
	scanf("%d",&newNode->	data);
	newNode->nextNode=NULL;
	newNode->prevNode=NULL;
	return newNode;
}

void insert();
void deleteListItem();
void traverse();
void insertAtBegining();
void insertAtMiddle();
void insertAtEnd();
void DeleteAtBegining();
void DeleteAtEnd();
void insertMiddleBeforeOperation(int);
void insertMiddleAfterOperation(int);
void traverseForward();
void traverseBackward();

int main(int argc, char** argv) {
	int oper;
	printf("Linked list is Empty. Therefore insert an item to the linked list...\n");
	struct node *newNode=getNode();
	startNode=newNode;
	lastNode=newNode;
	printf("\n");
	printf("Enter list operation (1-Insert, 2-Delete, 4-Traverse) : ");
	scanf("%d",&oper);
	
	while(oper!=-1){
			
		switch(oper){    
		case 1:    
			insert();
		 break;   
		case 2:    
			deleteListItem();
		 break;    
    	case 4:    
    		traverse();
		 break;
		default:     ;
		    printf("Invalid...\n\n");
		}
		printf("Enter list operation (1-Insert, 2-Delete, 4-Traverse) : ");
		scanf("%d",&oper);
	}	
	return 0;
}
void insert(){

		printf("Insert Node at (1-Begining, 2-Middle, 3-End) : ");
		int insertOp;
		scanf("%d",&insertOp);
		
		switch(insertOp){    
		case 1:    
	    	insertAtBegining(); 
	 	break;   
		case 2:    
		    insertAtMiddle();
	 	break;  
	    case 3:    
		    insertAtEnd();
	 	break;	
	    	
		default:     
	    	printf("Invalid insert operation...");
		}    	

	printf("\n\n");	
}
void deleteListItem(){
	printf("Delete Node from (1-Begining, 2-End) : ");
	int deleteOp;
	scanf("%d",&deleteOp);
	
	switch(deleteOp){    
	case 1:    
    	DeleteAtBegining(); 
 	break;   
	case 2:    
	    DeleteAtEnd();
 	break;  
        	
	default:
		printf("Invalid Delete operation...\n");
	}
	printf("\n");
}

void traverse(){
	printf("Traverse Node from (1-Begining to End , 2-End to Begin ) : ");
	int traverseOp;
	scanf("%d",&traverseOp);
	
	switch(traverseOp){    
	case 1:    
    	traverseForward(); 
 	break;   
	case 2:    
	    traverseBackward();
 	break;  
        	
	default:
		printf("Invalid Traverse operation...\n");
	}
	printf("\n");
}
void traverseForward(){
	if(startNode==0){
		printf("List is Empty...\nYou can't traverse...'");
	}else{
		printf("You are to Print List begin to end...\n");
		struct node *ptr=startNode;
		while(ptr!=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->nextNode;
		}	
	}
	printf("\n\n");
}
void traverseBackward(){
	if(startNode==0){
		printf("List is Empty...\nYou can't traverse...'");
	}else{
		printf("You are to Print List end to begin...\n");
		struct node *ptr=lastNode;
		while(ptr!=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->prevNode;
		}	
	}
	printf("\n\n");
}
void insertAtBegining(){
		printf("You are to Insert at the Begining ...\n");
		struct node *newNode=getNode();
		newNode->nextNode=startNode;
		startNode->prevNode=newNode;
		startNode=newNode;
		printf("\n");
}
void insertAtMiddle(){
	int data;
	if(startNode==0){
		printf("List is Empty...\nYou can't Insert at middle ...'");
	}else{
		printf("You are to Insert at Middle ...\n");
		int insertMiddleOperation;
		printf("1-Insert before specific node , 2-Insert after specific node : ");
		scanf("%d",&insertMiddleOperation);
		switch(insertMiddleOperation){    
		case 1:   
			printf("Enter data of the specific node : ");
			scanf("%d",&data); 
	    	insertMiddleBeforeOperation(data); 
	 	break;   
		case 2:    
			printf("Enter data of the specific node : ");
			scanf("%d",&data);
		    insertMiddleAfterOperation(data);
	 	break;  
	        	
		default:
			printf("Invalid Delete operation...");
		}
	}
	printf("\n");
}
void insertAtEnd(){
	if(startNode==0){
		printf("List is Empty...\nYou can't Insert at end ...");
	}else{	
		printf("You are to Insert at the End ...\n");
		struct node *newNode=getNode();
		lastNode->nextNode=newNode;
		newNode->prevNode=lastNode;
		lastNode=newNode;
	}
	printf("\n");
}
void DeleteAtBegining(){
	if(startNode==0){
		printf("List is Empty...\nYou can't Delete at begining ...");
	}else{
		printf("You are to Delete from the Begining ...\n");
		startNode=startNode->nextNode;
		startNode->prevNode=NULL;
		free(ptr);
	}
	printf("\n");
}
void DeleteAtEnd(){
	if(startNode==0){
		printf("List is Empty...\nYou can't Delete at end ...");
	}else{
		printf("You are to Delete from the End ...\n");
		lastNode=lastNode->prevNode;
		lastNode->nextNode=NULL;			
		free(ptr);
	}
	printf("\n");
}
void insertMiddleBeforeOperation(int data){
	if(startNode==0){
		printf("List is Empty...\nYou can't Insert at middle ...");
	}else if(startNode->data==data){
		struct node *newNode=getNode();
		newNode->nextNode=startNode;
		startNode->prevNode=newNode;
		startNode=newNode;	
	}else{
		struct node *ptr=startNode;
		while(ptr->nextNode->data!=data){
			ptr=ptr->nextNode;
		}
		struct node *newNode=getNode();
		newNode->nextNode=ptr->nextNode;
		newNode->nextNode->prevNode=newNode;
		ptr->nextNode=newNode;
		newNode->prevNode=ptr;
	}
	printf("\n");
}
void insertMiddleAfterOperation(int data){
	if(startNode==0){
		printf("List is Empty...\nYou can't Insert at middle ...");
	}else if(startNode->data==data){
		struct node *newNode=getNode();
		newNode->nextNode=startNode->nextNode;
		newNode->nextNode->prevNode=newNode;
		startNode->nextNode=newNode;
		newNode->prevNode=startNode;
	}else{
		struct node *ptr=startNode;
		while(ptr->data!=data){
			ptr=ptr->nextNode;
		}
		struct node *newNode=getNode();
		newNode->nextNode=ptr->nextNode;
		newNode->prevNode=ptr;
		ptr->nextNode=newNode;
		newNode->nextNode->prevNode=newNode;		
	}
	printf("\n");
}


