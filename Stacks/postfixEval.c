#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define maxsize 30
struct Stack{
    char name[maxsize];
    int top;
};
typedef struct Stack S;
int overflow(S S1){
    return S1.top==maxsize-1;
}
void push(S *S1,char ele){
    if(overflow(*S1))
        printf("Stack full");
    S1->name[++S1->top]=ele;
}
int underflow(S S1){
    return S1.top==-1;
}
char pop(S *S1){
    if(underflow(*S1))
        printf("Empty Stack");
    return S1->name[S1->top--];
}
int op(int op1,int op2,char symb){
    switch(symb){
        case '+': return(op1+op2);
        case '-': return(op1-op2);
        case '*': return(op1*op2);
        case '/': return(op1/op2);
        case '^': return(pow(op1,op2));
        case '$': return(pow(op1,op2));
    }
}
int poseval(char postfix[]){
    S S1;
    int op1,op2,result;
    char symb;
    S1.top=-1;
    for(int i=0;i<strlen(postfix);i++){
        symb=postfix[i];
        if(isdigit(symb)){
            push(&S1,symb-'0');
        }else{
            op2=pop(&S1);
            op1=pop(&S1);
            result=op(op1,op2,symb);
            push(&S1,result);
        }
    }
    return pop(&S1);
}
void main(){
    char postfix[30];
    printf("Enter you postfix");
    gets(postfix);
    int res=poseval(postfix);
    printf("The result is %d", res);
}
