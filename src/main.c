#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

static void print(const void*);
static void* make_string(const char*);

int main(int argc, char **argv)
{
    bstree *tree = bstree_make();
    
    tree = bstree_add(tree, 1, make_string("A"));
    tree = bstree_add(tree, 5, make_string("B"));
    tree = bstree_add(tree, 10, make_string("C"));

    bstree_inorder(tree, &print);

    bstree_delete(tree);

    return EXIT_SUCCESS;
}

void print(const void *value)
{
    printf("%s\n", (char*) value);
}

void* make_string(const char *cstr)
{
    char *dynstr = (char*) malloc(strlen(cstr)+1);
    strcpy(dynstr, cstr);
    return dynstr;
}
