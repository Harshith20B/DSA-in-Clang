#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *llink;
    struct Node *rlink;
};
typedef struct Node *NODE;
NODE getNode(int data){
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->rlink=NULL;
    newNode->llink=NULL;
    return newNode;
}
NODE insertf(NODE root,int data){
    NODE newNode = getNode(data);
    if(root==NULL)
        return newNode;
    root->llink=newNode;
    newNode->rlink=root;
    return newNode;
}
NODE deletef(NODE root){
    if(root==NULL){
        printf("List is empty");
        return NULL;
    }
    if(root->rlink==NULL){
        printf("%d is deleted",root->data);
        free(root);
        return NULL;
    }
    NODE newNode = root->rlink;
    newNode->llink=NULL;
    printf("%d is deleted",root->data);
    free(root);
    return newNode;
}
NODE insertr(NODE root,int data){
    NODE newNode = getNode(data);
    if(root==NULL)
        return newNode;
    NODE temp = root;
    while(temp->rlink!=NULL)
        temp=temp->rlink;
    temp->rlink=newNode;
    newNode->llink=temp;
    return root;
}
NODE deleter(NODE root){
    if(root==NULL){
        printf("List is empty");
        return NULL;
    }
    if(root->rlink==NULL){
        printf("%d is deleted",root->data);
        free(root);
        return NULL;
    }
    NODE temp = root;
    while(temp->rlink!=NULL)
        temp=temp->rlink;
    NODE prev=temp->llink;
    prev->rlink=NULL;
    printf("%d is deleted",temp->data);
    free(temp);
    return root;
}
void displayList(NODE root){
    NODE temp=root;
    printf("Linked List :\n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->rlink;
    }
}
int main() {
    NODE root = NULL;
    int ch,ele,pos;
	while(1){
		printf("Enter your choice\n1.Insert First\n2.Delete First\n3.Insert Rear\n4.Delete Rear\n5.Display List");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter element to add ");
					scanf("%d",&ele);
					root = insertf(root,ele);
					break;
			case 2: root=deletef(root);
					break;
            case 3: printf("Enter element to add ");
					scanf("%d",&ele);
					root = insertr(root,ele);
					break;
            case 4: root=deleter(root);
					break;
			default:displayList(root);
					exit(0);
		}
    }
    return 0;
}
