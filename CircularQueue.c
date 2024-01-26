#include<stdio.h>
#include<stdlib.h>
#define max 5
struct Queue{
	int items[max];
	int front,rear;
};
typedef struct Queue CQ;
int isfull(CQ q){
	return (q.rear+1)%max==q.front;
}
int isempty(CQ q){
	return (q.front==-1 && q.rear==-1);
}
void enqueue(CQ *q,int ele){
	if(isfull(*q)){
		printf("Queue is full");
	}else if(isempty(*q)){
		q->front=0;
	}
	q->rear=(++q->rear)%max;
	q->items[q->rear]=ele;
}
int dequeue(CQ *q){
	int ele;
	if(isempty(*q)){
		printf("Queue is empty");
		return 9999;
	}else if(q->front==q->rear){
		ele = q->items[q->rear];
		q->front=-1;
		q->rear=-1;
		return ele;
	}else{
		ele = q->items[q->front];
		q->front=(++q->front)%max;
		return ele;
	}
}
void display(CQ *q) {
    if (isempty(*q)) {
        printf("Queue is empty\n");
        return;
    }
    int f = q->front;
    int r = q->rear;
    printf("Queue elements: ");
    if (f <= r) {
        for (int i = f; i <= r; i++) {
            printf("%d\t", q->items[i]);
        }
    } else {
        for (int i = f; i < max; i++) {
            printf("%d\t", q->items[i]);
        }
        for (int i = 0; i <= r; i++) {
            printf("%d\t", q->items[i]);
        }
    }
    printf("\n");
}
void main(){
	CQ q;
	q.front=-1;
	q.rear=-1;
	int ch,ele;
	while(1){
		printf("Enter your choice\n1.Enqueue\n2.dequeue\n3.display queue");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter element to add ");
					scanf("%d",&ele);
					enqueue(&q,ele);
					break;
			case 2: ele=dequeue(&q);
					printf("%d is popped",ele);
					break;
			default:display(&q);
					exit(0);
		}
	}
}