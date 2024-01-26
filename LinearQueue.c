#include<stdio.h>
#include<stdlib.h>
#define maxsize 20
struct Queue{
	int items[maxsize];
	int front,rear;
};
typedef struct Queue LQ;
int isfull(LQ q){
	return q.rear==maxsize-1;
}
void insertq(LQ *q, int ele){
	if(isfull(*q))
		printf("Queue is full \n");
	q->items[++q->rear]=ele;
}
int isempty(LQ q){
	return q.front>q.rear;
}
int removeq(LQ *q){
	if(isempty(*q)){
		printf("Queue is empty");
		return 9999;
	}else{
		int ele = q->items[q->front];
		q->front++;
		return ele;
	}
}
void main(){
	LQ q;
	q.front=0;
	q.rear=-1;
	int ch,ele;
	while(1){
		printf("Enter your choice\n1.Enqueue\n2.dequeue\n3.display queue");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter element to add ");
					scanf("%d",&ele);
					insertq(&q,ele);
					break;
			case 2: ele=removeq(&q);
					printf("%d is popped",ele);
					break;
			default: for(int i=q.front;i<=q.rear;i++){
						printf("%d \t",q.items[i]);
					}
					exit(0);
		}
    }
}