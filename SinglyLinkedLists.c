#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *link;
};
typedef struct Node *NODE;
NODE getNode(int item) {
    NODE new_node = (NODE)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = item;
    new_node->link = NULL;
    return new_node;
}
NODE insertf(NODE root,int item) {
    NODE new_node = getNode(item);
    if (root == NULL) {
        return new_node;
    }
    new_node->link = root;
    return new_node;
}
NODE deletef(NODE root) {
    if (root == NULL) {
        printf("List is empty. Cannot delete.\n");
        return root;
    }
    NODE temp = root;
    printf("%d is popped\n",root->data);
    root = root->link;
    free(temp);
    return root;
}
NODE insertr(NODE root,int ele){
    NODE newNode=getNode(ele);
    NODE temp = root;
    if(root==NULL){
        return newNode;
    }
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=newNode;
    return root;
}
NODE deleter(NODE root){
    NODE temp=root;
    if(root==NULL||root->link==NULL){
        printf("List is empty");
        free(root);
        return NULL;
    }
    while((temp->link)->link!=NULL){
        temp=temp->link;
    }
    printf("%d is popped\n",(temp->link)->data);
    temp->link=NULL;
    return root;
}
NODE insertp(NODE root,int pos,int ele){
    NODE newNode,temp,prev;
    newNode=getNode(ele);
    while(root==NULL || pos==1){
        root=insertf(root,ele);
    }
    temp=root;
    for(int i=1;i<pos && temp!=NULL;i++){
        prev=temp;
        temp=temp->link;
    }
    if(temp==NULL){
        printf("Invalid position");
        return root;
    }
    prev->link=newNode;
    newNode->link=temp;
    return root;
}
NODE deletep(NODE root,int pos){
    NODE prev,cur;
    if(root==NULL){
        printf("List is empty");
        return NULL;
    }
    if(pos==1){
        return deletef(root);
    }
    cur=root;
    for(int i=1;i<pos && cur!=NULL;i++){
        prev=cur;
        cur=cur->link;
    }
    if(cur==NULL){
        printf("Invalid position");
        return root;
    }
    prev->link=cur->link;
    printf("%d is popped\n",cur->data);
    free(cur);
    return root;
}
void displayList(NODE root) {
    printf("Linked List: ");
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->link;
    }
    printf("\n");
}
int main() {
    NODE root = NULL;
    int ch,ele,pos;
	while(1){
		printf("Enter your choice\n1.Insert First\n2.Delete First\n3.Insert Rear\n4.Delete Rear\n5.Insert at Position\n6.Delete at position\n7.Display List");
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
            case 5: printf("Enter the element you want to insert");
                    scanf("%d",&ele);
                    printf("Enter the position you want to insert");
                    scanf("%d",&pos);
                    root=insertp(root,pos,ele);
                    break;
            case 6: printf("Enter the position you want to delete the element");
                    scanf("%d",&pos);
                    deletep(root,pos);
                    break;
			default:displayList(root);
					exit(0);
		}
    }
    return 0;
}
