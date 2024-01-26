#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *link;
};
typedef struct Node NODE;
NODE *getNode(int data){
	NODE *temp;
	temp=(NODE*)malloc(sizeof(struct Node));
	if(temp==NULL){
		printf("Memory not allocated");
		exit(0);
	}
	temp->data=data;
	temp->link=temp;
	return temp;
}
NODE *insertf(NODE *rear,int data){
	NODE *newNode = getNode(data);
	if(rear==NULL)
		return newNode;
	NODE *first = rear->link;
	newNode->link=first;
	rear->link=newNode;
	return rear;
}
NODE *deletef(NODE *rear){
	if(rear==NULL){
		printf("List is empty");
		return NULL;
	}
	if(rear->link==NULL){
		printf("%d is popped",rear->data);
		free(rear);
		return NULL;
	}
	NODE *first=rear->link;
	rear->link=first->link;
	printf("%d is popped",first->data);
	free(first);
	return rear;
}
NODE *deleter(NODE *rear){
	if(rear==NULL){
		printf("It is empty");
		return NULL;
	}
	if(rear->link==NULL){
		printf("%d is popped",rear->data);
		free(rear);
		return NULL;
	}
	NODE *temp=rear;
	while(temp->link!=rear)
		temp=temp->link;
	temp->link=rear->link;
	printf("%d is popped",rear->data);
	free(rear);
	return temp;
}
NODE *insertr(NODE *rear,int data){
	NODE *newNode = getNode(data);
	if(rear==NULL)
		return newNode;
	newNode->link=rear->link;
	rear->link=newNode;
	return newNode;
}
void searche(NODE *rear,int ele){
	NODE *temp=rear;
	int flag=0;
	while(temp->link!=rear){
		if(temp->data==ele){
			printf("%d is present in list",ele);
			flag=1;
			break;
		}
		temp=temp->link;
	}
	if(flag==0)
		printf("It is not there in list");
}
void display(NODE *rear){
	NODE *temp=rear->link;
	if(temp==NULL)
		printf("It is empty");
	while(temp!=rear){
		printf("%d->",temp->data);
		temp=temp->link;
	}
	printf("%d",temp->data);
}
void main(){
	NODE *rear=NULL;
	int ele,ch;
	while(1){
		printf("Enter your choice : \n1.Insert First\n2.Delete First\n3.Insert Rear\n4.Delete Rear\n5.Search ele\n6.Display\n7.Exit");
		scanf("%d",&ch);
		switch(ch){
			case 1 : printf("Enter the element you want to add");
					 scanf("%d",&ele);
					 rear=insertf(rear,ele);
					 break;
			case 2 : rear=deletef(rear);
				 	 break;
			case 3 : printf("Enter the element you want to add");
					 scanf("%d",&ele);
					 rear=insertr(rear,ele);
					 break;
			case 4 : rear=deleter(rear);
				 	 break;
			case 5 : printf("Enter element you want to search");
					 scanf("%d",&ele);
					 searche(rear,ele);
					 break;
			case 6 : display(rear);
				 	 break;
			default : exit(0);
		}
	}
}