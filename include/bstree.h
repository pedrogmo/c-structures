#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>

typedef struct _treenode
{
    int32_t key;
    void *value;
    struct _treenode *left, *right;
    size_t height; 
} bstree;

extern bstree *bstree_make();
extern bool bstree_empty(const bstree *);
extern size_t bstree_count(const bstree *);
extern bstree *bstree_add(bstree *, int32_t, void *);
extern bstree *bstree_remove(bstree *, int32_t);
extern void *bstree_value(const bstree *, int32_t);
extern void bstree_preorder(bstree *, void(*)(void *));
extern void bstree_inorder(bstree *, void(*)(void *));
extern void bstree_postorder(bstree *, void(*)(void *));
extern void bstree_clear(bstree *);
extern void bstree_delete(bstree *);

#endif /*BSTREE_H_INCLUDED*/