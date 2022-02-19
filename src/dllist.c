#include <stdlib.h>
#include "dllist.h"

static dllnode *new_node(void *data, dllnode *prev, dllnode *next)
{
	dllnode *newnode = (dllnode *) malloc(sizeof(dllnode));
	newnode->value = data;
	newnode->prev = prev;
	newnode->next = next;
	return newnode;
}

dllist *dllist_make()
{
	dllist *newlist = (dllist *) malloc(sizeof(dllist));
	newlist->first = NULL;
	newlist->last = NULL;
	return newlist;
}

bool dllist_empty(const dllist *list)
{
	return list->first != NULL;
}

u32 dllist_count(const dllist *list)
{
	u32 count = 0u;
	for(dllnode *n = list->first; n; n = n->next)
		count++;
	return count;
}

void dllist_push_back(dllist *list, void *data)
{
	dllnode *newnode = new_node(data, list->last, NULL);

	if (list->last)
		list->last->next = newnode;
	else
		list->first = newnode;

	list->last = newnode;
}

void dllist_push_front(dllist *list, void *data)
{
	dllnode *newnode = new_node(data, NULL, list->first);

	if (list->first)
		list->first->prev = newnode;
	else
		list->last = newnode;

	list->first = newnode;
}

void dllist_insert(dllist *list, void *data, u32 pos)
{

}

void dllist_pop_front(dllist *list)
{
	if (!list->first)
		return;

	list->first = list->first->next;

	if (!list->first)
		list->last = NULL;
	else
		list->first->prev = NULL;
}

void dllist_pop_back(dllist *list)
{
	if (!list->last)
		return;

	list->last = list->last->prev;

	if (!list->last)
		list->first = NULL;
	else
		list->last->next = NULL;
}

void dllist_remove(dllist *list, const void *data)
{

}

void dllist_erase(dllist *list, u32 pos)
{

}

void dllist_traverse(dllist *list, void(*f)(void*))
{
	for(dllnode *n = list->first; n; n = n->next)
		(*f)(n->value);
}

void dllist_reverse(dllist *list, void(*f)(void*))
{
	for(dllnode *r = list->last; r; r = r->prev)
		(*f)(r->value);
}

void dllist_delete(dllist *list)
{
	for(dllnode *n = list->first; n; )
	{
		dllnode *next = n->next;

		free(n->value);
		free(n);

		n = next;
	}

	free(list);
}
