#include "tree.h"



ast_tree *ast_node(char *token, char* value) { //criar arvore
    ast_tree *node = (ast_tree *)malloc(sizeof(ast_tree));
    node->type = token;
    node->value = value;
    node->father = NULL;
    node->brother = NULL;

    return node;
}

void add_childs(ast_tree *root, ast_tree *son)
{
    if (son == NULL || root == NULL)
    {
        return;
    }
    if (root->son == NULL)
    {
        root->son = son;
    }
    else
    {
        ast_tree *temp = root->son;
        while (temp->brother != NULL)
        {
            temp = temp->brother;
        }
        temp->brother = son;
    }
    son->father = root;
}

void add_brother(ast_tree *brother, ast_tree *newbrother) { //adicionar irmaos
    if (newbrother == NULL) {
        return;
    }
    if (brother == NULL) {
        return;
    } else {
        ast_tree *temp = brother;
        while (temp->brother != NULL) {
            temp = temp->brother;
        }
        temp->brother = newbrother;
    }
    newbrother->father = brother->father;
}

void ast_print(ast_tree *AST, int n_pontos)
{
    // printf("estou aqui \n");
    if (AST == NULL)
    {
        return;
    }
    if (strcmp(AST->type, "Semicolon") != 0)
    {
        for (int i = 0; i < n_pontos; i++)
            printf(".");

        printf("%s", AST->type);
        if (strcmp(AST->value, "") != 0)
        {
            printf("(%s)\n", AST->value);
        }
        else
        {
            printf("\n");
        }
    }
    if (AST->son != NULL)
    {
        ast_print(AST->son, n_pontos + 2);
    }
    if (AST->brother != NULL)
    {
        ast_print(AST->brother, n_pontos);
    }
}