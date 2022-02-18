#include <stdlib.h>
#include "bstree.h"
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

static u32 height(const bstree *tree)
{
    if (!tree)
    {
        return 0u;
    }
    return tree->height;
}

static s32 balance_factor(const bstree *tree)
{
    if (!tree)
    {
        return 0;
    }
    return height(tree->left) - height(tree->right);    
}

static bstree* right_rotate(bstree *tree)
{
    bstree *a = tree->left;
    bstree *b = a->right;

    a->right = tree;
    tree->left = b;

    tree->height = MAX(height(tree->left), height(tree->right)) + 1;
    a->height = MAX(height(a->left), height(a->right)) + 1;

    return a;
}

static bstree* left_rotate(bstree *tree)
{
    bstree *a = tree->right;
    bstree *b = a->left;

    a->left = tree;
    tree->right = b;

    tree->height = MAX(height(tree->left), height(tree->right)) + 1;
    a->height = MAX(height(a->left), height(a->right)) + 1;

    return a;
}

bstree* bstree_make()
{
    bstree *tree = (bstree*) malloc(sizeof(bstree));
    tree->key = 0;
    tree->value = NULL;
    tree->left = NULL;
    tree->right = NULL;
    tree->height = 1u;
    return tree;
}    

bool bstree_empty(const bstree *tree)
{
    return !tree || !tree->value;
}

u32 bstree_count(const bstree *tree)
{
    if (!tree)
    {
        return 0u;
    }
    return 1u + bstree_count(tree->left) + bstree_count(tree->right);
}

bstree* bstree_add(bstree *tree, s32 key, void *value)
{
    if (bstree_empty(tree))    
    {
        tree = (bstree*) malloc(sizeof(bstree));
        tree->key = key;
        tree->value = value;
        tree->left = NULL;
        tree->right = NULL;
        tree->height = 0u;
    }

    else if (key < tree->key)
    {
        tree->left = bstree_add(tree->left, key, value);
    }
    else if (key > tree->key)
    {
        tree->right = bstree_add(tree->right, key, value);
    }
    else
    {
        return tree;
    }

    tree->height = 1 + MAX(height(tree->left), height(tree->right));
    s32 balance = balance_factor(tree);

    if (balance > 1 && key < tree->left->key)
    {
        return right_rotate(tree);
    }   

    if (balance < -1 && key > tree->right->key)
    {
        return left_rotate(tree);
    }

    if (balance > 1 && key > tree->left->key)
    {
        tree->left = left_rotate(tree->left);
        return right_rotate(tree);
    }

    if (balance < -1 && key < tree->right->key)
    {
        tree->right = right_rotate(tree->right);
        return left_rotate(tree);
    }

    return tree;
}

void* bstree_value(const bstree *tree, s32 key)
{
    if (bstree_empty(tree))
    {
        return NULL;
    }
    if (key == tree->key)
    {
        return tree->value;
    }
    if (key < tree->key)
    {
        return bstree_value(tree->left, key);
    }
    return bstree_value(tree->right, key);
}

void bstree_preorder(bstree *tree, void(*f)(const void*))
{
    if (bstree_empty(tree))
    {
        return;
    }

    (*f)(tree->value);
    bstree_preorder(tree->left, f);
    bstree_preorder(tree->right, f);
}

void bstree_inorder(bstree *tree, void(*f)(const void*))
{
    if (bstree_empty(tree))
    {
        return;
    }

    bstree_inorder(tree->left, f);
    (*f)(tree->value);
    bstree_inorder(tree->right, f);
}

void bstree_postorder(bstree *tree, void(*f)(const void*))
{
    if (bstree_empty(tree))
    {
        return;
    }

    bstree_postorder(tree->left, f);
    bstree_postorder(tree->right, f);
    (*f)(tree->value);
}

void bstree_delete(bstree *tree)
{
    if (!tree)
    {
        return;
    }

    bstree_delete(tree->left);
    bstree_delete(tree->right);
    free(tree->value);
    free(tree);
}
