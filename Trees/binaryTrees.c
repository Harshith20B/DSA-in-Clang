#include<stdio.h>
#include<stdlib.h>
struct bnode{
    int info;
    struct bnode *left;
    struct bnode *right;
};
struct bnode *insert(int item,struct bnode *root){
    struct bnode *prev,*cur,*newNode;
    newNode = (struct bnode*)malloc(sizeof(struct bnode));
    newNode->info=item;
    newNode->left=NULL;
    newNode->right=NULL;
    if(root==NULL)
        return newNode;
    prev=NULL;
    cur=root;
    while(cur!=NULL){
        prev=cur;
        if(cur->info>item)
            cur=cur->left;
        else if(cur->info<item)
            cur=cur->right;
        else
            return root;
    }
    if(prev->info>item)
        prev->left=newNode;
    else
        prev->right=newNode;
    return root;
}
void search(int item, struct bnode *root){
    struct bnode *cur;
    int flag=0;
    cur=root;
    while(cur!=NULL){
        if(cur->info>item)
            cur=cur->left;
        else if(cur->info<item)
            cur=cur->right;
        else{
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("Element not found in tree\n");
    else
        printf("Element found in tree\n");
}
void inorder_trav(struct bnode *root){
    if(root==NULL)
        return;
    inorder_trav(root->left);
    printf("%d\n",root->info);
    inorder_trav(root->right);
}
void preorder_trav(struct bnode *root){
    if(root==NULL)
        return;
    printf("%d\n",root->info);
    preorder_trav(root->left);
    preorder_trav(root->right);
}
void postorder_trav(struct bnode *root){
    if(root==NULL)
        return;
    postorder_trav(root->left);
    postorder_trav(root->right);
    printf("%d\n",root->info);
}
struct bnode *delete(struct bnode *root,int key){
    struct bnode *cur,*prev;
    cur=root;
    while(cur!=NULL && cur->info!=key){
        prev=cur;
        if(key<cur->info)
            cur=cur->left;
        else
            cur=cur->right;
    }
    if(cur==NULL){
        printf("Element not found in array");
        return root;
    }
    if(cur->left==NULL || cur->right==NULL){//deleting node with 1 or no children
        struct bnode *new;
        if(cur->left==NULL)
            new=cur->right;
        else
            new=cur->left;
        if(prev==NULL){
            free(cur);
            return new;
        }
        if (cur==prev->left)
            prev->left=new;
        else
            prev->right=new;
        free(cur);
        return root;
    }else{
        struct bnode *p,*temp;
        p=NULL;
        temp=cur->right;
        while(temp->left!=NULL){
            p=temp;
            temp=temp->left;
        }
        cur->info=temp->info;
        if(p==NULL)
            cur->right=temp->right;
        else
            p->left=temp->right;
        free(temp);
        return root;
    }
}
void main(){
    struct bnode *root=NULL;
    int ch,ele;
    while(1){
        printf("Enter your choice\n1.Insert element\n2.Delete element\n3.Search element\n4.Inorder display\n5.Preorder display\n6.postorder display\n7.Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter element to insert");
                    scanf("%d",&ele);
                    root=insert(ele,root);
                    break;
            case 2: printf("Enter element to delete");
                    scanf("%d",&ele);
                    root=delete(root,ele);
                    break;
            case 3: printf("Enter element to search");
                    scanf("%d",&ele);
                    search(ele,root);
                    break;
            case 4: inorder_trav(root);
                    break;
            case 5: preorder_trav(root);
                    break;
            case 6: postorder_trav(root);
                    break;
            default:exit(0);
        }
    }
}
