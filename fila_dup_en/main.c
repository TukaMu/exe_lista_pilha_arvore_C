#include <stdio.h>
#include <stdlib.h>

// ESTRUTURA
struct elemento
{
    int val;
    struct elemento *prox;
    struct elemento *ant;
};

// CRIA O NOVO
struct elemento *cria_ele(int val)
{
    struct elemento *novo;

    novo = (struct elemento *)malloc(sizeof(struct elemento));
    novo->prox = NULL;
    novo->ant = NULL;
    novo->val = val;

    return novo;
}

// ADICIONA NO FIM
struct elemento *insere_fim(struct elemento *fila, int val)
{
    if (fila != NULL)
    {
        struct elemento *aux, *aux2;
        for (aux = fila; aux->prox != NULL; aux = aux->prox)
            ;
        aux2 = cria_ele(val);
        aux->prox = aux2;
        aux2->ant = aux;
    }
    else
    {
        fila = cria_ele(val);
    }
    return fila;
}

// ADICIONA NO INI
struct elemento *insere_inicio(struct elemento *fila, int val)
{
    if (fila != NULL)
    {
        struct elemento *aux;
        aux = cria_ele(val);
        aux->prox = fila;
        fila->ant = aux;
        fila = aux;
    }
    else
    {
        fila = cria_ele(val);
    }
    return fila;
}

// INSERIR DPS DE X
struct elemento *insere_local(struct elemento *fila, int val, int local)
{
    if (fila != NULL)
    {
        if (local == 0)
        {
            struct elemento *aux;
            aux = cria_ele(val);
            if (fila->ant == NULL)
            {
                aux->prox = fila;
                fila->ant = aux;
                fila = aux;
            }
            else
            {
                aux->prox = fila->prox;
                fila->prox = aux;
                aux->ant = fila;
                aux = aux->prox;
                aux->ant = fila->prox;
            }
        }
        else if (insere_local(fila->prox, val, local - 1) == NULL)
        {
            struct elemento *aux;
            aux = cria_ele(val);
            fila->prox = aux;
            aux->ant = fila;
        }
        return fila;
    }
    else
    {
        return NULL;
    }
}

// TROCAR VALOR DO LOCAL
void troca_val_local(struct elemento *fila, int val, int local)
{
    if (fila != NULL)
    {
        if (local == 0)
        {
            fila->val = val;
        }
        else
        {
            troca_val_local(fila->prox, val, local - 1);
        }
    }
}

// TROCA VALOR DO VALOR
void troca_val(struct elemento *fila, int val, int local)
{
    if (fila != NULL)
    {
        if (local == fila->val)
        {
            fila->val = val;
        }
        else
        {
            troca_val(fila->prox, val, local);
        }
    }
}

// RETIRAR OS IMPARES
struct elemento *tira_impar(struct elemento *fila)
{
    if (fila != NULL)
    {
        struct elemento *aux, *aux2;
        for (aux = fila; aux != NULL; aux = aux->prox)
        {
            if ((aux->val % 2) != 0)
            {
                if (aux->ant == NULL && aux->prox == NULL)
                {
                    free(aux);
                    fila = NULL;
                    break;
                }
                else if (aux->ant == NULL)
                {
                    fila = fila->prox;
                    free(aux);
                    aux = fila;
                    aux->ant = NULL;
                }
                else if (aux->prox == NULL)
                {
                    aux2 = aux->ant;
                    aux2->prox = NULL;
                    free(aux);
                    break;
                }
                else
                {
                    aux2 = aux->ant;
                    aux2->prox = aux->prox;
                    aux2 = aux->prox;
                    aux2->ant = aux->ant;
                    free(aux);
                    aux = aux2->ant;
                }
            }
        }
        return fila;
    }
}

// TROCAR O PRIMEIRO DA FILA1 COM O ULTIMO FILA2
struct elemento *troca_troca(struct elemento *fila1, struct elemento *fila2)
{
    if (fila1 != NULL && fila2 != NULL)
    {
        struct elemento *aux;
        for (aux = fila2; fila2->prox != NULL; fila2 = fila2->prox)
            ;
        aux = fila2->ant;
        fila2->prox = fila1->prox;
        // ajeita fila1
        aux->prox = fila1;
        fila1->ant = aux;
        fila1->prox = NULL;

        // aejita ersto fila2
        aux = fila2->prox;
        aux->ant = fila2;
        fila2->ant = NULL;

        return fila2;
    }
}

// UTEIS

// MOSTRA FILA
void mostra_fila(struct elemento *fila)
{
    if (fila != NULL)
    {
        printf("\t-> %d", fila->val);
        mostra_fila(fila->prox);
    }
}

// LIMPA FILA
void freefila(struct elemento *fila)
{
    if (fila != NULL)
    {
        freefila(fila->prox);
        free(fila);
    }
}

// CRIA A FILA
struct elemento *cria_fila(struct elemento *fila)
{
    fila = insere_fim(fila, 5);
    fila = insere_fim(fila, 6);
    fila = insere_fim(fila, 3);
    fila = insere_fim(fila, 1);
    fila = insere_fim(fila, 32);
    fila = insere_fim(fila, 9);
    fila = insere_fim(fila, 17);
    fila = insere_inicio(fila, 22);
    fila = insere_local(fila, 10, 5);
    troca_val_local(fila, 6, 3);
    troca_val(fila, 55, 17);

    return fila;
}

// MAINNNNNNN
void main()
{
    struct elemento *fila, *fila2;
    fila = NULL;
    fila2 = NULL;

    fila2 = cria_fila(fila2);
    fila = cria_fila(fila);

    printf("\n ANTES DA MUDANCA\n");
    mostra_fila(fila);
    printf("\n");
    mostra_fila(fila2);

    fila = tira_impar(fila);

    printf("\n DPS DA MUDANCA\n");
    mostra_fila(fila);
    printf("\n");
    mostra_fila(fila2);

    fila = troca_troca(fila, fila2);

    printf("\n DPS DA MUDANCA\n");
    mostra_fila(fila);
    printf("\n");
    mostra_fila(fila2);

    freefila(fila);
    freefila(fila2);
}