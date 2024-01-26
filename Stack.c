#include<stdio.h>
#include<stdlib.h>// For exit function
#include<string.h>
#define maxsize 10
typedef struct Stack S;
struct Stack{
    char st[maxsize];
    int top;
};
int overflow(S S1){
    return S1.top==9;
}
void push(S *S1,int ele){
    if(overflow(*S1)){
        printf("Stack is full \n");
    }else{
        S1->st[++S1->top]=ele;
    }
}
int underflow(S S1){
    return S1.top==-1;
}
int pop(S *S1){
    if(underflow(*S1)){
        printf("Empty Stack\n");
        return -999;
    }else{
        return S1->st[S1->top--];
    }
}
void main(){
    S S1;
    int ch,ele;
    S1.top=-1;
    while(1){
        printf("Enter your choice:\n1.Add element\n2.Pop element\n3.Display stack");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element you want to add");
                    scanf("%d",&ele);
                    push(&S1,ele);
                    break;
            case 2: ele=pop(&S1);
                    if(ele==-999){
                        printf("ELement not popped\n");
                    }else{
                        printf("The element %d is popped\n",ele);
                    }
                    break;
            default:printf("your stack is:\n");
                    for(int i=0;i<S1.top;i++){
                        printf("%d\n",S1.st[S1.top-i]);
                    }
                    exit(0);
        }
    }
}