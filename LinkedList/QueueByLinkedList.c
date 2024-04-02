#include<stdio.h>
#include<stdlib.h>
#define max 10
struct Node{
    int data;
    struct Node *link;
};
typedef struct Node *NODE;
NODE front=NULL,rear=NULL;
NODE getNode(int data){
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->link=NULL;
    return newNode;
}
void enqueue(int val){
    NODE newNode = getNode(val);
    if(front==NULL && rear==NULL){
        front=newNode;
        rear=newNode;
        return;
    }
    rear->link=newNode;
    rear=newNode;
}
void dequeue(){
    if(front==NULL && rear==NULL){
        printf("Empty queue");
        return;
    }
    if(front==rear){
        printf("%d is popped",front->data);
        free(front);
        free(rear);
        front=NULL;
        rear=NULL;
        return;
    }
    NODE temp=front;
    front=front->link;
    printf("%d is removed",temp->data);
    free(temp);
}
void display(){
    if(front==NULL && rear==NULL){
        printf("Empty queue");
        return;
    }
    NODE temp1=front;
    printf("Queue :\n");
    while(temp1!=rear){
        printf("%d\n",temp1->data);
        temp1=temp1->link;
    }
    printf("%d",temp1->data);
}
void main(){
    int ch,ele;
    while(1){
        printf("Enter your choice \n1.Enqueue\n2.Dequeue\n3.Display");
        scanf("%d",&ch);
        switch(ch){
            case 1 : printf("Enter the element you want to add");
                     scanf("%d",&ele);
                     enqueue(ele);
                     break;
            case 2 : dequeue();
                     break;
            default: display();
                     exit(0);
        }
    }
}

