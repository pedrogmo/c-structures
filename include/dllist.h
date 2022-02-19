#ifndef DLLIST_H_INCLUDED
#define DLLIST_H_INCLUDED

#include "types.h"

typedef struct _doublelistnode
{
	void *value;
	struct _doublelistnode *prev, *next;
} dllnode;

typedef struct
{
	dllnode *first, *last;
} dllist;

extern dllist* dllist_make();
extern bool dllist_empty(const dllist *);
extern u32 dllist_count(const dllist *);
extern void dllist_push_back(dllist *, void *);
extern void dllist_push_front(dllist *, void *);
extern void dllist_insert(dllist *, void*, u32);
extern void dllist_pop_front(dllist *);
extern void dllist_pop_back(dllist *);
extern void dllist_remove(dllist *, const void *);
extern void dllist_erase(dllist *, u32);
extern void dllist_traverse(dllist *, void(*)(void *));
extern void dllist_reverse(dllist *, void(*)(void *));
extern void dllist_delete(dllist *);

#endif /*DLLIST_H_INCLUDED*/