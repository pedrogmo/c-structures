#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct _doublelistnode
{
	void *value;
	struct _doublelistnode *prev, *next;
} listnode;

typedef struct
{
	listnode *head, *tail;
	u32 count;
} list;

extern list *list_make();
extern bool list_empty(const list*);
extern u32 list_count(const list*);
extern 


#endif /*LIST_H_INCLUDED*/