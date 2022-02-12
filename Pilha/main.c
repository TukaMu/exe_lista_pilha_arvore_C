#include <stdio.h>
#include <stdlib.h>

// ESTRUTURA
struct elemento
{
    int val;
    struct elemento *cima;
};

// CRIA NIVEL DA PILHA
struct elemento *cria_nivel(int val)
{
    struct elemento *novo;

    novo = (struct elemento *)malloc(sizeof(struct elemento));
    novo->cima = NULL;
    novo->val = val;

    return novo;
}

// CRIA A PILHA OU INSERE NO TOPO
struct elemento *insere_fim(struct elemento *pilha, int val)
{
    if (pilha != NULL)
    {
        struct elemento *aux;
        for (aux = pilha; aux->cima != NULL; aux = aux->cima)
            ;
        aux->cima = cria_nivel(val);
    }
    else
    {
        pilha = cria_nivel(val);
    }
    return pilha;
}

// TROCA VALOR NA POSIÇÃO
void troca_local_val(struct elemento *pilha, int val, int local_val)
{
    if (pilha != NULL)
    {
        if (local_val == 0)
        {
            pilha->val = val;
            return;
        }
        local_val--;
        troca_local_val(pilha->cima, val, local_val);
    }
}

// TROCAR VALOR DO VALOR
void troca_val(struct elemento *pilha, int val, int val_local)
{
    if (pilha != NULL)
    {
        if (pilha->val == val_local)
        {
            pilha->val = val;
            return;
        }
        troca_val(pilha->cima, val, val_local);
    }
}

// ADICIONA NA BASE
struct elemento *insere_base(struct elemento *pilha, int val)
{
    if (pilha != NULL)
    {
        struct elemento *aux;
        aux = cria_nivel(val);
        aux->cima = pilha;
        pilha = aux;
    }
    else
    {
        pilha = cria_nivel(val);
    }
    return pilha;
}

// APAGAR VALOR
struct elemento *apaga(struct elemento *pilha, int local)
{
    if (pilha != NULL)
    {
        struct elemento *aux, *base;
        base = pilha;
        for (aux = NULL; pilha != NULL; pilha = pilha->cima, local--)
        {
            if (local == 1)
            {
                aux = pilha;
            }
            else if (local == 0)
            {
                if (aux == NULL)
                {
                    base = pilha->cima;
                }
                else
                {
                    aux->cima = pilha->cima;
                    free(pilha);
                }
                break;
            }
        }
        return base;
    }
}

// UTEIS
// MOSTRA PILHA
void mostra_pilha(struct elemento *pilha)
{
    if (pilha != NULL)
    {
        mostra_pilha(pilha->cima);
        printf("\n\t%d", pilha->val);
    }
}

// FREE PILHA
int freepilha(struct elemento *pilha)
{
    if (pilha != NULL)
    {
        if (freepilha(pilha->cima) == 1)
        {
            free(pilha);
        }
    }
    return 1;
}

// CRIA PILHA
struct elemento *cria_pilha(struct elemento *pilha)
{
    pilha = insere_fim(pilha, 10);
    pilha = insere_fim(pilha, 6);
    pilha = insere_fim(pilha, 9);
    pilha = insere_fim(pilha, 1);
    pilha = insere_fim(pilha, 5);
    pilha = insere_fim(pilha, 33);
    troca_local_val(pilha, 66, 4);
    troca_val(pilha, 15, 1);
    pilha = insere_base(pilha, 20);
    pilha = apaga(pilha, 6);

    return pilha;
}

// MAIINNNNNNNNNNNNNNN
void main()
{
    struct elemento *pilha;
    pilha = NULL;

    pilha = cria_pilha(pilha);

    mostra_pilha(pilha);

    if (freepilha(pilha) == 1)
    {
        printf("\n Pilha liberada!");
    }
    else
    {
        printf("\n Erro ao liberar pilha!");
    }
}
