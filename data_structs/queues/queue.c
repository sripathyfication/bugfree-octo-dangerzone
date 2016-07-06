/*
 * Basic queue implementation
 *
 * Enqueues at tail
 * Dequeues at head
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE        5 
#define EMPTY_Q         0 
#define FULL_Q          (MAX_SIZE -1)  

struct queue {
    int queue_store[MAX_SIZE];
    int head;
    int tail;
};

struct queue *que;

void init_queue()
{
    struct queue *q;

    q = (struct queue *) malloc(sizeof(struct queue));
    q->head = q->tail = EMPTY_Q;
    
    /* Init the queue_store with -1 */
    for (int i = 0; i < MAX_SIZE; i++)
        q->queue_store[i] = -1;
            
    /* save q pointer */
    que = q;

    return;
}

bool empty_q(struct queue *q)
{
    if (q->tail == EMPTY_Q) return true;
    else return false;
}

bool full_q(struct queue *q) 
{
    if (q->head == ) return true;
    else return false;
}

void enqueue(int value)
{
    struct queue *q = que;

    q->queue_store[q->tail] = value;
    q->tail += 1;

    /* move every element over in queue by 1 element */
    for (int i = 0; i < (MAX_SIZE - 1); i++)
        q->queue_store[i+1] = q->queue_store[i];

    /* always add element at tail */
    q->queue_store[q->tail] = value;

    /* increment head */
    if (full_q(q)) 
        q->head = FULL_Q;
    else 
        q->head += 1;

    return;
}

/* Returns, -1 if queue is empty.
 */
int dequeue()
{
    int val = 0;
    struct queue *q = que;

    /* if the queue is empty return -1 */
    if (empty_q(q)) return EMPTY_Q;

    /* otherwise, return val from q->head, decrement head */
    val = q->queue_store[q->head] ;
    q->head -=1;

    return val;
}

void print_queue ()
{
    int queue_iter = 0;
    struct queue *q = que;

    printf("\nQUEUE \n");
    printf("  ----- \n");

    if (empty_q(q)) { 
        printf(" EMPTY \n"); 
        return;
    }

    queue_iter = q->tail;
    while (queue_iter <= FULL_Q) {
        printf(" queue [ %d ]: %d \n", queue_iter, q->queue_store[queue_iter]);
        queue_iter++;
    }

    return;
}


int main()
{
    init_queue();

    enqueue(5);
    enqueue(6);
    enqueue(1);
    enqueue(2);
    enqueue(0);

    print_queue();

    dequeue();
    dequeue();

    print_queue();


}
