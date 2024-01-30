#include<stdio.h>
#include<stdlib.h>
#define max 10
struct Node{
    int data;
    struct Node *link;
};
int count=0;
typedef struct Node *NODE;
NODE getNode(int data){
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->link=NULL;
    return newNode;
}
NODE push(NODE top, int data){
    if(count==max){
        printf("Stacks is full");
        return top;
    }
    NODE newNode = getNode(data);
    if(count==0){
        count++;
        return newNode;
    }
    count++;
    newNode->link=top;
    return newNode;
}
NODE pop(NODE top){
    if(count==0){
        printf("Stack is empty");
        return NULL;
    }
    NODE temp = top->link;
    printf("%d is popped",top->data);
    free(top);
    return temp;
}
void peek(NODE top){
    if(count==0)
        printf("Stack is empty");
    printf("Element at top of stack is %d", top->data);
}
void display(NODE top){
    if(count==0)
        printf("Stack is empty");
    NODE temp = top;
    printf("Stack :\n");
    while(temp!=NULL){
        printf("%d \n",temp->data);
        temp=temp->link;
    }
}
void main(){
    NODE top=NULL;
    int ch,ele;
    while(1){
        printf("Enter your choice \n1.Push\n2.Pop\n3.Peek\n4.Display");
        scanf("%d",&ch);
        switch(ch){
            case 1 : printf("Enter the element you want to add");
                     scanf("%d",&ele);
                     top=push(top,ele);
                     break;
            case 2 : top=pop(top);
                     break;
            case 3 : peek(top);
                     break;
            default: display(top);
                     exit(0);
        }
    }
}