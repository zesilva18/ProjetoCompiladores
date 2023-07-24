#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

typedef struct ast_tree
{
    char *type;
    char *value;
    struct ast_tree *father;
    struct ast_tree *son;
    struct ast_tree *brother;
}ast_tree;


ast_tree *ast_node(char *token, char* value);
void add_childs(ast_tree *father, ast_tree *son);
void add_brother(ast_tree *brother, ast_tree* newbrother);
void ast_print(ast_tree *AST, int n_pontos);