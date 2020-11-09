#include "structures.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

 program * insert_element(char * type,  program * children){

    program * new = (program *) malloc(sizeof(program));
    new->next = NULL;
    new->type = strdup(type);
    new->children = children;

    return new;
 }