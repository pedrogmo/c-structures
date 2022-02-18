#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

static void print(void*);
static void* make_string(char*);

int main(int argc, char **argv)
{
    bstree *tree = bstree_make();
    
    tree = bstree_add(tree, 1, make_string("A"));
    tree = bstree_add(tree, 5, make_string("B"));
    tree = bstree_add(tree, 10, make_string("C"));

    bstree_postorder(tree, &print);

    bstree_delete(tree);

    return EXIT_SUCCESS;
}

void print(void *value)
{
    printf("%s\n", (char*) value);
}

void* make_string(char *cstr)
{
    char *dynstr = (char*) malloc(strlen(cstr)+1);
    strcpy(dynstr, cstr);
    return dynstr;
}
