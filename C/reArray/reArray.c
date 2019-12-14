/*
 * In The Name Of God
 * ========================================
 * [] File Name : reArray.c
 *
 * [] Creation Date : 20-03-2015
 *
 * [] Last Modified : Fri 20 Mar 2015 11:34:31 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <assert.h>
#include <stdlib.h>

typedef struct stackImp *Stack;

struct stackImp {
  void **items;
  int top;
  int maxSize;
};

Stack createStack(void) {
  Stack s = malloc(sizeof(struct stackImp));

  assert(s != NULL);
  s->items = malloc(10 * sizeof(void *));
  assert(s->items != NULL);
  s->top = 0;
  s->maxSize = 10;
  return s;
}

void push(Stack stack, void *item) {
  /*
   * Over here I'm checking
   * if the top index is less than the
   * maximum Items the array can store.
   */
  if (stack->top < stack->maxSize) {
    /*
     * If it's less then it pushes the
     * item to the top of the array.
     */
    stack->items[stack->top] = item;
    stack->top++;
  } else {
    /*
     * If the index is greater than or equal
     * to the maximum size then
     * I realloc a new array which is twice
     * the size of the initial array.
     */
    void *temp = realloc(stack->items, 2 * (stack->maxSize) * sizeof(void *));
    assert(temp != NULL);
    stack->items = temp;
  }
}

int main(int argc, char *argv[]) {
  int i;
  Stack s;

  s = createStack();
  for (i = 0; i < 20; i++)
    push(s, &i);
}
