#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct _s3 {
} func_def;

typedef struct _s3 {
} func_decl;

typedef struct _s2 {
    type typespec;
    char * id;
} var_decl;

typedef enum {int, void, short, double, char} type;

typedef struct _s1 {
    func_def * func_def_list;
    var_decl * var_decl_list;
    func_decl * func_decl_list;
} program;

#endif
