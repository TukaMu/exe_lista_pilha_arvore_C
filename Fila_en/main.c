#include <stdio.h>
#include <stdlib.h>

// ESTRUTURA
struct elemento
{
    int val;
    struct elemento *prox;
};

// CRIA O NOVO
struct elemento *cria_ele(int val)
{
    struct elemento *novo;

    novo = (struct elemento *)malloc(sizeof(struct elemento));
    novo->prox = NULL;
    novo->val = val;

    return novo;
}

// INSERE NO FIM OU CRIA LISTA
struct elemento *insere_fim(struct elemento *fila, int val)
{
    if (fila != NULL)
    {
        struct elemento *aux;
        for (aux = fila; aux->prox != NULL; aux = aux->prox)
            ;
        aux->prox = cria_ele(val);
    }
    else
    {
        fila = cria_ele(val);
    }

    return fila;
}

// INSERE NO INICIO E CRIA LISTA
struct elemento *insere_inicio(struct elemento *fila, int val)
{
    if (fila != NULL)
    {
        struct elemento *aux;

        aux = cria_ele(val);
        aux->prox = fila;
        fila = aux;
    }
    else
    {
        fila = cria_ele(val);
    }

    return fila;
}

// SUBSTITUI NO VALOR
struct elemento *insere_n_val(struct elemento *fila, int val, int local_val)
{
    if (fila != NULL)
    {
        struct elemento *aux;
        for (aux = fila; aux != NULL; aux = aux->prox)
        {
            if (aux->val == local_val)
            {
                aux->val = val;
                break;
            }
        }
    }

    return fila;
}

// SUBSTITUI VALO NO LOCAL
struct elemento *insere_n_local(struct elemento *fila, int val, int local)
{
    if (fila != NULL)
    {
        struct elemento *aux;
        for (aux = fila; aux != NULL; aux = aux->prox, local--)
        {
            if (local == 0)
            {
                aux->val = val;
                break;
            }
        }
    }

    return fila;
}

// TROCA FILA1 PRIMEIRO PELO ULTIMO DA FILA2 -> TROCA O ENDEREÇO
struct elemento *troca_end(struct elemento *fila1, struct elemento *fila2)
{
    if (fila1 != NULL && fila2 != NULL)
    {
        struct elemento *aux;
        for (aux = fila2, fila2 = fila2->prox; fila2->prox != NULL; fila2 = fila2->prox, aux = aux->prox)
            ;
        fila2->prox = fila1->prox;
        aux->prox = fila1;
        fila1->prox = NULL;

        return fila2;
    }
}

// TROCA FILA1 ENTRE FILA2 -> TROCA O VALOR
void troca_val(struct elemento *fila1, struct elemento *fila2)
{
    if (fila1 != NULL && fila2 != NULL)
    {
        int val;
        for (; fila1 != NULL; fila1 = fila1->prox, fila2 = fila2->prox)
        {
            val = fila1->val;
            fila1->val = fila2->val;
            fila2->val = val;
        }
    }
}

// APAGA VALOR

// UTEIS ----------------------------------------------------------------------

// LIMPA LISTA
int freefila(struct elemento *fila)
{
    if (fila != NULL)
    {
        if (freefila(fila->prox) == 1)
        {
            free(fila);
        }
    }
    return 1;
}

// MOSTRA LISTA
void mostra_fila(struct elemento *fila)
{
    if (fila != NULL)
    {
        printf("-> %d\t", fila->val);
        mostra_fila(fila->prox);
    }
}

/////////////////CRIA FILAS
struct elemento *cria_fila(struct elemento *fila)
{
    fila = insere_fim(fila, 10);
    fila = insere_fim(fila, 6);
    fila = insere_fim(fila, 8);
    fila = insere_fim(fila, 4);
    fila = insere_fim(fila, 0);
    fila = insere_fim(fila, 3);
    fila = insere_inicio(fila, 40);
    fila = insere_n_val(fila, 7, 3);
    fila = insere_n_val(fila, 3, 8);
    fila = insere_n_local(fila, 15, 3);

    return fila;
}

//////////////////////////////MAINNNNNNNNNNNNNNN
void main()
{
    struct elemento *fila1, *fila2, *fila3;
    fila1 = NULL;
    fila2 = NULL;
    fila3 = NULL;

    fila1 = cria_fila(fila1);
    fila2 = cria_fila(fila2);
    fila3 = cria_fila(fila3);

    printf("\n ANTES MUDANCAS\n");
    mostra_fila(fila1);
    printf("\n");
    mostra_fila(fila2);
    printf("\n");
    mostra_fila(fila3);

    fila1 = troca_end(fila1, fila2);

    printf("\n DPS MUDANCA 1\n");
    mostra_fila(fila1);
    printf("\n");
    mostra_fila(fila2);
    printf("\n");
    mostra_fila(fila3);

    troca_val(fila3, fila2);

    printf("\n DPS MUDANCA 2\n");
    mostra_fila(fila1);
    printf("\n");
    mostra_fila(fila2);
    printf("\n");
    mostra_fila(fila3);

    if ((freefila(fila1) + freefila(fila2) + freefila(fila3)) == 3)
    {
        printf("\n Filas Limpas!");
    }
    else
    {
        printf("\n Erro ao lipar as filas!");
    }
}