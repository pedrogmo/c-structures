typedef long int s32;
typedef unsigned long int u32;
typedef enum
{
    false, true
} bool;    

typedef struct _treenode
{
    s32 key;
    void *value;
    struct _treenode *left, *right;
    u32 height; 
} bstree;

extern bstree* bstree_make();
extern bool bstree_empty(bstree*);
extern u32 bstree_count(bstree*);
extern bstree* bstree_add(bstree*, s32, void*);
extern bstree* bstree_remove(bstree*, s32);
extern void* bstree_value(bstree*, s32);
extern void bstree_preorder(bstree*, void(*)(void*));
extern void bstree_inorder(bstree*, void(*)(void*));
extern void bstree_postorder(bstree*, void(*)(void*));
extern void bstree_delete(bstree*);
