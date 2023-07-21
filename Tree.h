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

void add_childs(ast_tree *root, ast_tree* new);
ast_tree *ast_node(char *token, char* value);
void add_brother(ast_tree *brother, ast_tree* newbrother);
void ast_print(ast_tree* ast,int level);
int nrChilds (ast_tree* ast);