#include <stdlib.h>
#include "AdvanceQueue.h"

queue_t* create_queue(){
	queue_t *entrypoint, *placeholder;
	entrypoint = (queue_t*) malloc(sizeof(queue_t));
	placeholder = (queue_t*) malloc(sizeof(queue_t));
	entrypoint->next = placeholder;
	placeholder->next = placeholder;
	return entrypoint;
}

int queue_empty(queue_t* qu){
	return (qu->next == qu->next->next);
}

void enqueue(int item, queue_t* qu){
	queue_t *tmp, *new;
	new = malloc(sizeof(queue_t));
	new->item = item;
	tmp = qu->next;
	qu->next = new;
	new->next = tmp->next;
	tmp->next = new;
}

int dequeue(queue_t* qu){
	queue_t* tmp;
	int item;
	tmp = qu->next->next->next;
	qu->next->next->next = tmp->next;
	if(tmp == qu->next)
		qu->next = tmp->next;
	item = tmp->item;
	free(tmp);
	return item;
}

int front_element(queue_t* qu){
	return qu->next->next->next->item;
}
