#include "symbol_table.h"
#include "semantics.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern table * symtab;

table_element * insert_variable(table *tab, char * id, char * type, bool is_param){
    var_declaration * new = (var_declaration*)malloc(sizeof(var_declaration));
    table_element * new_element = (table_element*)malloc(sizeof(table_element));
    table_element * aux;

    new_element->type = var_dec;
    new_element->entry_type.var = new;
    new_element->next = NULL;

    new->id = strdup(id);
    new->type = strdup(type);
    new->is_param = is_param;

    aux = tab->element;

    if(tab->element){
        while(aux->next != NULL){
            if(aux->type == var_dec){
                if(strcmp(aux->entry_type.var->id, id) == 0){
                    free(new);
                    free(new_element);
                    return NULL;
                }
            }
            aux = aux->next;
        }
        aux->next = new_element;
    }
    else{
        tab->element = new_element;
    }

        return new_element;
}

table_element * insert_function(table *tab, char * id, char * type, func_parameter * param){
    func_declaration * new = (func_declaration*)malloc(sizeof(func_declaration));
    table_element * new_element = (table_element*)malloc(sizeof(table_element));
    table_element * aux;

    new_element -> type = func_dec;
    new_element -> entry_type.func = new;
    new_element->next = NULL;

    new->id = strdup(id);
    new->type = strdup(type);
    new->parameters = param;

    aux = tab->element;


    if(tab->element){
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new_element;
    }
    else{
        tab->element = new_element;
    }

    return new_element;
}

table * insert_table(char * name){
    //DA NULL SE JA EXISTIR, NOVO SE NAO EXISTIA
    table * new = (table*)malloc(sizeof(table));
    table * aux;
    
    new->name = strdup(name);
    new->next = NULL;
    new->element = NULL;

    if (symtab){
        aux = symtab;
        while(aux->next != NULL){   

            if(strcmp(aux->name, name) == 0){
                return NULL;
            }

            aux = aux->next;
        }

        if(strcmp(aux->name, name) == 0){
            return NULL;
        }

        aux->next = new;
    }
    else{
        symtab = new;
    }

    return new;

}

table * search_table(char * name){
    //DA NULL SE NAO EXISTIR
    table * aux = symtab;

    while(aux != NULL){   
        if(strcmp(aux->name, name) == 0){
            return aux;
        }

        aux = aux->next;
    }

    return NULL;
}

func_declaration * search_function(program * id_node, table * tab){
    table_element * aux = tab->element;

    while(aux != NULL){
        if(aux->type == func_dec){
            if(strcmp(aux->entry_type.func->id, id_node->children->type) == 0){
                
                return aux->entry_type.func;
            }
        }
        aux = aux->next;
    }
    return NULL;
}

var_declaration * search_variable(char * id, table * tab){
    table_element * aux = tab->element;

    while(aux != NULL){
        if(aux->type == var_dec){
            if(strcmp(aux->entry_type.var->id, id) == 0){
                return aux->entry_type.var;
            }
        }
        aux = aux->next;
    }
    return NULL;
}
/*
table_element_type * search_symbol(char * id, table * tab){
    bool func = false;
    bool var = false;
    
    //procurar no global scope, so ai e que ha funçoes
    function = search_function(node->children, symtab);

    //printf("RUBEN CALL\n");

    if(function){
        func = true;
    }

    variable = search_variable(node->children->type, tab);

    if(!variable){
        //procurar no global scope
        variable = search_variable(node->children->type, symtab);
    }
    else{
        var = true;
    }

    if(variable){
        var = true;
    }

    if(func == false && var == false){
        //CHECK CALL
        sprintf(help, "Unknown symbol %s", node->children->children->type);
        print_error(help, node->children->line, node->children->column);
        node -> type = strdup("Call - undef");
        return undefined_t;

        //CHECK VAR
        sprintf(help, "Unknown symbol %s", node->children->type);
        print_error(help, node->children->line, node->children->column);

        sprintf(help, "Id(%s) - undef", node->children->type);
        free(node->children);
        node->children = NULL;
        node->type = strdup(help);
        return undefined_t;
    }
}
*/

void print_tables(){
    table * aux = symtab;
    table_element * aux_ele;
    
    while(aux != NULL){
        //percorrer as tabelas
        aux_ele = aux->element;
        if(! aux_ele){
        aux = aux->next;
            continue;
        }
        printf("===== %s Symbol Table =====\n", aux->name);

        while(aux_ele != NULL){

            if(aux_ele->type == func_dec){
                char help[200] = "";
                func_parameter * param = aux_ele->entry_type.func->parameters;
                strcpy(help, param->type);
                
                param = param -> next;
                while(param != NULL){
                    strcat(help, ",");
                    strcat(help, param->type);
                    param = param -> next;
                }
                
                printf("%s\t%s(%s)\n", aux_ele->entry_type.func->id, aux_ele->entry_type.func->type, strdup(help));
            }
            else{
                if(aux_ele->entry_type.var->is_param)
                    printf("%s\t%s\tparam\n", aux_ele->entry_type.var->id, aux_ele->entry_type.var->type);
                else
                    printf("%s\t%s\n", aux_ele->entry_type.var->id, aux_ele->entry_type.var->type);
            }

            aux_ele = aux_ele->next;
        }
        printf("\n");
        aux = aux->next;
    }
}