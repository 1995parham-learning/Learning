/*
 * In The Name of God
 * =======================================
 * [] File Name : linked_list.h
 *
 * [] Creation Date : 07-11-2019
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
*/
/*
* Copyright (c)  2019 Parham Alvani.
*/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// here we assume the following structure for a linked-list
// [ head ] -> [0] -> [1] -> ...
// so the first element of array is its head and does not contain any value
// we ignore it in foreach loop but use it in append macro

#define linked_list_foreach(lst, element, type, next) \
    for (type *element = lst->next; element != NULL; element = element->next)
#define linked_list_append(lst, element, type, next) \
{ \
    type *ptr; \
    for (ptr = lst; ptr->next != NULL; ptr = ptr->next); \
    ptr->next = element; \
    element->next = NULL; \
}

#endif
