#include <stdio.h>
#include <stdlib.h>

// ESTRUTURA
struct elemento
{
    int val;
    int lin;
    int col;
    struct elemento *prox;
    struct elemento *ant;
};

// CRIA ELEMENTO
struct elemento *cria_ele(int val, int lin, int col)
{
    struct elemento *novo;
    novo = (struct elemento *)malloc(sizeof(struct elemento));

    novo->lin = lin;
    novo->col = col;
    novo->val = val;
    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

// INSERE ELEMENTO
struct elemento *insere(struct elemento *matriz, int val, int lin, int col)
{
    if (matriz != NULL)
    {
        struct elemento *aux, *aux2;
        aux = matriz;
        do
        {
            if (lin == aux->lin && col == aux->col)
            {
                break;
            }
            else if (aux->prox == NULL)
            {
                aux2 = cria_ele(val, lin, col);
                aux2->ant = aux;
                aux->prox = aux2;
                break;
            }
            aux = aux->prox;
        } while (aux != NULL);
    }
    else
    {
        matriz = cria_ele(val, lin, col);
    }
    return matriz;
}

// REMOVE UM VALOR
struct elemento *remover(struct elemento *matriz, int lin, int col)
{
    if (matriz != NULL)
    {
        struct elemento *aux;
        aux = matriz;

        do
        {

            if ((aux->lin == lin) && (aux->col == col))
            {
                struct elemento *aux2;
                if (aux->ant == NULL)
                {
                    matriz = aux->prox;
                    matriz->ant = NULL;
                    free(aux);
                }
                else if (aux->prox == NULL)
                {
                    aux2 = aux->ant;
                    aux2->prox = NULL;
                    free(aux);
                }
                else
                {
                    aux2 = aux->ant;
                    aux2->prox = aux->prox;
                    aux2 = aux->prox;
                    aux2->ant = aux->ant;
                    free(aux);
                }
                break;
            }

            aux = aux->prox;
        } while (aux != NULL);

        return matriz;
    }
}

// UTEIS
// FREE NA MATRIZ
void freematriz(struct elemento *matriz)
{
    if (matriz != NULL)
    {
        freematriz(matriz->prox);
        free(matriz);
    }
}

// MOSTRA MATRIZ
void mostra_matriz(struct elemento *matriz)
{
    if (matriz != NULL)
    {
        struct elemento *aux;

        int max_lin = 0;
        int max_col = 0;
        int lin, col;

        aux = matriz;

        do
        {
            if (max_lin < aux->lin)
            {
                max_lin = aux->lin;
            }
            if (max_col < aux->col)
            {
                max_col = aux->col;
            }
            aux = aux->prox;
        } while (aux != NULL);

        for (lin = 0; lin <= max_lin; lin++)
        {
            for (col = 0; col <= max_col; col++)
            {
                printf("\t%d", existe(matriz, lin, col));
            }
            printf("\n");
        }
    }
}

// VERIFICA SE EXISTE O VALOR E O RETORNA
int existe(struct elemento *matriz, int lin, int col)
{
    if (matriz != NULL)
    {
        if ((matriz->lin == lin) && (matriz->col == col))
        {
            return matriz->val;
        }
        else
        {
            return existe(matriz->prox, lin, col);
        }
    }
    return 0;
}

// CRIA MATRIZ
struct elemento *cria_matriz(struct elemento *matriz)
{
    matriz = insere(matriz, 1, 0, 1);
    matriz = insere(matriz, 1, 0, 2);
    matriz = insere(matriz, 1, 0, 3);

    matriz = insere(matriz, 1, 1, 0);
    matriz = insere(matriz, 1, 1, 2);
    matriz = insere(matriz, 1, 1, 3);

    matriz = insere(matriz, 1, 2, 0);
    matriz = insere(matriz, 1, 2, 1);
    matriz = insere(matriz, 1, 2, 3);

    matriz = insere(matriz, 1, 3, 0);
    matriz = insere(matriz, 1, 3, 1);
    matriz = insere(matriz, 1, 3, 2);

    return matriz;
}

void main()
{
    struct elemento *matriz;

    matriz = NULL;

    matriz = cria_matriz(matriz);

    printf("\nANTES DA MUDANCA\n");
    mostra_matriz(matriz);

    matriz = remover(matriz, 2, 1);

    printf("\nDPS DA MUDANCA\n");
    mostra_matriz(matriz);

    freematriz(matriz);
}