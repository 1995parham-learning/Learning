#ifndef ADVANCEQUEUE_H
#define ADVANCEQUEUE_H

typedef struct qu_t{
	int item;
	struct qu_t *next;
} queue_t;

queue_t* create_queue();

int queue_empty(queue_t* qu);

void enqueue(int x, queue_t* qu);

int dequeue(queue_t* qu);

int front_element(queue_t* qu);

void remove_queue(queue_t* qu);

#endif
