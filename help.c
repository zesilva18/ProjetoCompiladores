void ast_print(ast_tree *AST, int n_pontos)
{
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