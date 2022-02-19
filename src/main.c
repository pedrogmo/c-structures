#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include "dllist.h"

static void print(void *);
static void *make_string(const char*);
static void *make_int(int);

int main(int argc, char **argv)
{
    return 0;
}

void print(void *data)
{
    printf("%i -> ", *((int *)data));
}

void *make_string(const char *cstr)
{
    char *dynstr = (char *) malloc(strlen(cstr)+1);
    strcpy(dynstr, cstr);
    return dynstr;
}

void *make_int(int i)
{
    int *ptr = (int *) malloc(sizeof(int));
    *ptr = i;
    return ptr;
}