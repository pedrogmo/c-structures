#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED

#include "types.h"

typedef struct _treenode
{
    s32 key;
    void *value;
    struct _treenode *left, *right;
    u32 height; 
} bstree;

extern bstree *bstree_make();
extern bool bstree_empty(const bstree *);
extern u32 bstree_count(const bstree *);
extern bstree *bstree_add(bstree *, s32, void *);
extern bstree *bstree_remove(bstree *, s32);
extern void *bstree_value(const bstree *, s32);
extern void bstree_preorder(bstree *, void(*)(void *));
extern void bstree_inorder(bstree *, void(*)(void *));
extern void bstree_postorder(bstree *, void(*)(void *));
extern void bstree_clear(bstree *);
extern void bstree_delete(bstree *);

#endif /*BSTREE_H_INCLUDED*/