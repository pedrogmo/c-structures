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
	return list->first == NULL;
}

size_t dllist_count(const dllist *list)
{
	size_t count = 0u;
	dllnode *n = list->first;
	
	for(; n; n = n->next)
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

void dllist_insert(dllist *list, void *data, size_t pos)
{
	dllnode	*before = NULL, 
			*after = list->first,
			*newnode = new_node(data, NULL, NULL);

	for(; pos > 0u; --pos)
	{
		if (!after)
			return;

		before = after;
		after = after->next;
	}

	newnode->prev = before;
	newnode->next = after;

	if (before)
		before->next = newnode;
	else
		list->first = newnode;

	if (after)
		after->prev = newnode;
	else
		list->last = newnode;
}

void dllist_pop_front(dllist *list)
{
	dllnode *removed = list->first;

	if (dllist_empty(list))
		return;

	list->first = list->first->next;

	if (!list->first)
		list->last = NULL;
	else
		list->first->prev = NULL;

	free(removed->value);
	free(removed);
}

void dllist_pop_back(dllist *list)
{
	dllnode *removed = list->last;

	if (dllist_empty(list))
		return;

	list->last = list->last->prev;

	if (!list->last)
		list->first = NULL;
	else
		list->last->next = NULL;

	free(removed->value);
	free(removed);
}

void dllist_remove(dllist *list, const void *data)
{
	dllnode *curr = list->first;

	if (dllist_empty(list))
		return;

	while(curr->value != data)
	{
		curr = curr->next;
		if (!curr)
			return;
	}

	if (curr->prev)
		curr->prev->next = curr->next;
	else
		list->last = curr->next;

	if (curr->next)
		curr->next->prev = curr->prev;
	else
		list->first = curr->prev;

	free(curr->value);
	free(curr);
}

void dllist_erase(dllist *list, size_t pos)
{
	dllnode *curr = list->first;
	
	if (dllist_empty(list))
		return;

	for(; pos > 0u; --pos)
	{
		curr = curr->next;
		if (!curr)
			return;
	}

	if (curr->prev)
		curr->prev->next = curr->next;
	else
		list->last = curr->next;

	if (curr->next)
		curr->next->prev = curr->prev;
	else
		list->first = curr->prev;

	free(curr->value);
	free(curr);
}

void dllist_traverse(dllist *list, void(*f)(void*))
{
	dllnode *n = list->first;
	for(; n; n = n->next)
		(*f)(n->value);
}

void dllist_reverse(dllist *list, void(*f)(void*))
{
	dllnode *r = list->last;
	for(; r; r = r->prev)
		(*f)(r->value);
}

void dllist_delete(dllist *list)
{
	dllnode *n = list->first;
	for(; n; )
	{
		dllnode *next = n->next;

		free(n->value);
		free(n);

		n = next;
	}

	free(list);
}
