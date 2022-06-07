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

// INSERE NO FIM
struct elemento *insere_fim(struct elemento *fila, int val)
{
    if (fila != NULL)
    {
        struct elemento *aux;
        aux = cria_ele(val);
        aux->prox = fila;
        aux->ant = fila->ant;
        fila->ant = aux;
        aux = aux->ant;
        aux->prox = fila->ant;
    }
    else
    {
        fila = cria_ele(val);
        fila->prox = fila;
        fila->ant = fila;
    }
    return fila;
}

// INSERE NO INICIO
struct elemento *insere_inicio(struct elemento *fila, int val)
{
    if (fila != NULL)
    {
        struct elemento *aux;
        aux = cria_ele(val);
        aux->prox = fila;
        aux->ant = fila->ant;
        fila->ant = aux;
        aux = aux->ant;
        aux->prox = fila->ant;
        fila = aux->prox;
    }
    else
    {
        fila = cria_ele(val);
        fila->prox = fila;
        fila->ant = fila;
    }
    return fila;
}

// INSERE NO LOCAL
struct elemento *insere_local(struct elemento *fila, int val, int local)
{
    if (fila != NULL)
    {
        struct elemento *aux;
        aux = fila;
        if (local == 0)
        {
            fila = insere_inicio(fila, val);
        }
        else
        {
            do
            {
                if (local == 0)
                {
                    struct elemento *aux2;
                    aux2 = cria_ele(val);
                    aux2->prox = aux->prox;
                    aux2->ant = aux;
                    aux->prox = aux2;
                    aux = aux2->prox;
                    aux->ant = aux2;
                    break;
                }
                aux = aux->prox;
                local--;
            } while (aux != fila);
        }
        return fila;
    }
}

// TROCA VAL DO LOCAL
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

// TROCA VAL PARA VAL
void troca_val(struct elemento *fila, int val, int local)
{
    if (fila != NULL)
    {
        struct elemento *aux;
        aux = fila;
        do
        {
            if (aux->val == local)
            {
                aux->val = val;
                break;
            }
            aux = aux->prox;
        } while (aux != fila);
    }
}

// EXCLUI UM VALOR
struct elemento *exclui(struct elemento *fila, int local)
{
    if (fila != NULL)
    {
        struct elemento *aux;

        if (local == 0)
        {
            aux = fila->ant;
            aux->prox = fila->prox;
            aux = fila->prox;
            aux->ant = fila->ant;
            free(fila);
            fila = aux;
        }
        else
        {
            aux = fila;
            do
            {
                if (local == 0)
                {
                    struct elemento *aux2;
                    aux2 = aux->ant;
                    aux2->prox = aux->prox;
                    aux2 = aux->prox;
                    aux2->ant = aux->ant;
                    free(aux);
                    break;
                }
                local--;
                aux = aux->prox;
            } while (aux != fila);
        }
        return fila;
    }
}

// UTEIS

// MOSTRA FILA
void mostra_fila(struct elemento *fila, struct elemento *ini)
{
    if (fila != NULL)
    {
        printf("\t-> %d", fila->val);
        if (fila->prox != ini)
        {
            mostra_fila(fila->prox, ini);
        }
    }
}

// LIMPA FILA
void freefila(struct elemento *fila, struct elemento *ini)
{
    if (fila != NULL)
    {
        if (fila->prox != ini)
        {
            freefila(fila->prox, ini);
        }
        free(fila);
    }
}

// CRIA FILA
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
    mostra_fila(fila, fila);
    printf("\n");
    mostra_fila(fila2, fila2);

    fila = exclui(fila, 3);
    fila2 = exclui(fila2, 0);

    printf("\n DPS DA MUDANCA\n");
    mostra_fila(fila, fila);
    printf("\n");
    mostra_fila(fila2, fila2);

    freefila(fila, fila);
    freefila(fila2, fila2);
}

