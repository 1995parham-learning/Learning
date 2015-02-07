/*
 * In The Name Of God
 * ========================================
 * [] File Name : DecToBin.c
 *
 * [] Creation Date : 07-02-2015
 *
 * [] Last Modified : Sat 07 Feb 2015 10:18:11 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>

struct stack {
	struct stack *prev;
	int val;
	struct stack *next;
};

struct stack *first, *cur, *tmp;
int counter = 0;

struct stack *GETNODE()
{
	return malloc(sizeof(struct stack));
}


void push(int val)
{
	tmp = GETNODE();
	tmp->prev = NULL;
	tmp->val = val;
	tmp->next = NULL;

	if (first == NULL) {
		first = tmp;
		cur = first;
	} else {
		tmp->prev = cur;
		cur->next = tmp;
		cur = tmp;
	}
	counter++;
}

int pop(void)
{
	int val = cur->val;

	tmp = cur;
	cur = cur->prev;
	free(tmp);
	counter--;

	return val;
}


int main(int argc, char *argv[])
{
	int num;

	scanf("%d", &num);

	while (num != 0) {
		push(num % 2);
		num /= 2;
	}
	while (counter != 0)
		printf("%d ", pop());
	printf("\n");
}
