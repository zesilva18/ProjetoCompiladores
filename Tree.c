#include "tree.h"



ast_tree *ast_node(char *token, char* value) { //criar arvore
    ast_tree *node = (ast_tree *)malloc(sizeof(ast_tree));
    node->type = token;
    node->value = value;
    node->father = NULL;
    node->brother = NULL;

    return node;
}

void add_childs(ast_tree *root, ast_tree* new) { //adicionar filhos
    if (new == NULL) {
        return;
    }
    if (root->son == NULL) {
        root->son = new;
    } else {
        ast_tree *temp = root->son;
        while (temp->brother != NULL) {
            temp = temp->brother;
        }
        temp->brother = new;
    }
    new->father = root;
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

void ast_print(ast_tree* ast,int level)
{
    //printf("estou aqui \n");
    if (ast == NULL)
    {
        printf("A RAIZ ESTA A NULL\n");
    }
    for (int i = 0; i < level; i++)
        printf(".");
    
    printf("%s", ast->type);
    if (strcmp(ast->value, "") != 0)
    {
        printf("(%s)\n", ast->value);
    }else{
        printf("\n");
    }

    if(ast->son != NULL){
        ast_print(ast->son,level+2);
    }
    if(ast->brother != NULL){
        ast_print(ast->brother,level);
    }
}
int nrChilds (ast_tree* ast){
    int count=0;
    ast_tree* root = ast;

    if(root->son==NULL || root ==NULL){
        return 0;
    }
    else{
        count++;
        while (root->brother != NULL) {
            count++;
            root = root->brother;
        }
        return count;
    }
}
