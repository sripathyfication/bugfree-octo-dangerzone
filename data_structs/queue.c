/* Program to implement a queue */

#include <stdio.h>

#define MAX_SIZE 6
struct queue {
	int arr[MAX_SIZE];
	int head;
	int tail;
};


int de_queue(struct queue *q) 
{
	int element;

	if (q->head == -1)
		return;

	element = q->arr[q->head];
	q->head++;
	
	return element;
}

void en_queue(struct queue *q,int element)
{
	if (q->tail == -1) {
	// First element
		q->tail++;
		q->arr[q->tail] = element;	
		q->head = q->tail;
	}	

	q->arr[q->tail] = element;
	q->tail++;
	return;
}


int main(void)
{

	struct queue q;
	int dq;
	int i;
	
	q.head = q.tail = -1;

	en_queue(&q,2);
	en_queue(&q,1);
	en_queue(&q,4);
	en_queue(&q,3);
	en_queue(&q,7);

	printf("Printing Queue..\n");
	for (i=0;i<MAX_SIZE;i++)
		printf("%d \t",q.arr[i]);
	printf("\n");

	dq = de_queue(&q);
	printf("Dq:%d\n",dq);
	dq = de_queue(&q);
	printf("Dq:%d\n",dq);
	dq = de_queue(&q);
	printf("Dq:%d\n",dq);

	return 0;
}
