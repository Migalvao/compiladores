#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct _s1
{
    char *type;
    char *annotation;
    struct _s1 *children;
    struct _s1 *next;

    int line;
    int column;
} program;

#endif
