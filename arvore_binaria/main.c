#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int val;
    struct elemento *esq;
    struct elemento *dir;
};

struct elemento *cria_filho(int val)
{
    struct elemento *novo;

    novo = (struct elemento *)malloc(sizeof(struct elemento));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->val = val;

    return novo;
}

struct elemento *inserir_noh(struct elemento *noh, int val)
{
    if (noh == NULL)
    {
        return cria_filho(val);
    }
    else
    {

        if (val < noh->val)
        {
            if (noh->esq == NULL)
            {
                printf("criou filho do %d com valor de %d\n", noh->val, val);
                noh->esq = cria_filho(val);
            }
            else
            {
                inserir_noh(noh->esq, val);
            }
        }
        else if (val > noh->val)
        {
            if (noh->dir == NULL)
            {
                printf("criou filho do %d com valor de %d\n", noh->val, val);
                noh->dir = cria_filho(val);
            }
            else
            {
                inserir_noh(noh->dir, val);
            }
        }
        else
        {
            printf("\nValor %d ja existe!", val);
        }
        return noh;
    }
}

void showarv(struct elemento *noh)
{
    if (noh != NULL)
    {
        printf("%d --", noh->val);
        showarv(noh->esq);
        showarv(noh->dir);
    }
}

int freearv(struct elemento *noh)
{
    if (noh != NULL)
    {
        if ((freearv(noh->esq) + freearv(noh->dir)) == 2)
        {
            free(noh);
        }
    }
    return 1;
}

int soma_folhas(struct elemento *noh)
{
    if (noh != NULL)
    {
        if (noh->dir == NULL && noh->esq == NULL)
        {
            return noh->val;
        }
        else
        {
            return soma_folhas(noh->esq) + soma_folhas(noh->dir);
        }
    }
    return 0;
}

int menor_valor(struct elemento *noh)
{
    if (noh != NULL)
    {
        if (noh->dir == NULL && noh->esq == NULL)
        {
            return noh->val;
        }
        else
        {
            int n1 = menor_valor(noh->esq);
            int n2 = menor_valor(noh->dir);

            if (n1 < n2)
                return n1;
            else
                return n2;
        }
    }
    return 1000;
}

struct elemento *menor(struct elemento *noh)
{
    if (noh != NULL)
    {
        struct elemento *n1, *n2;
        if (noh->esq == NULL && noh->dir == NULL)
        {
            return noh;
        }
        else
        {
            n1 = menor(noh->esq);
            n2 = menor(noh->dir);

            if (n1 == NULL)
            {
                return n2;
            }
            else if (n2 == NULL)
            {
                return n1;
            }
            else
            {
                if (n1->val < n2->val)
                {
                    return n1;
                }
                else
                {
                    return n2;
                }
            }
        }
    }
    return NULL;
}

int num_nohs(struct elemento *noh, int num)
{
    if (noh != NULL)
    {
        if (num > 0)
        {
            num--;
            int som = num_nohs(noh->esq, num) + num_nohs(noh->dir, num);
            num++;
            return som;
        }
        else if (num == 0)
        {
            printf("entrou");
            return 1;
        }
    }
    return 0;
}

int num_nohs_menor(struct elemento *noh, int num)
{
    if (noh != NULL)
    {
        num++;
        int som = num_nohs_menor(noh->esq, num) + num_nohs_menor(noh->dir, num);
        if (num > noh->val)
        {
            som++;
        }
        return som;
    }
    return 0;
}

int soma_at_val(struct elemento *noh, int val)
{
    if (noh != NULL)
    {
        if (noh->val == val)
        {
            return val;
        }
        else
        {
            int som = soma_at_val(noh->esq, val) + soma_at_val(noh->dir, val);
            if (som != 0)
            {
                som = som + noh->val;
            }
            return som;
        }
    }
    return 0;
}

int arv_pesquisa(struct elemento *noh)
{
    if (noh != NULL)
    {
        if ((noh->esq != NULL) && (noh->esq->val > noh->val))
        {
            return 0;
        }
        else if ((noh->dir != NULL) && (noh->dir->val < noh->val))
        {
            return 0;
        }
        else
        {
            if ((arv_pesquisa(noh->esq) || arv_pesquisa(noh->dir)) == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    return 1;
}

int mndetect(struct elemento *noh, int m, int n)
{
    if (noh != NULL)
    {
        int n1 = mndetect(noh->esq, m, n);
        int n2 = mndetect(noh->dir, m, n);

        if (noh->val == m || noh->val == n)
        {
            if (n1 >= 1 || n2 >= 1)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }

        if (n1 == 2 || n2 == 2)
        {
            return 2;
        }
        else if (n1 == 1 || n2 == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

struct elemento *menorpont(struct elemento *noh)
{
    if (noh != NULL)
    {
        if (noh->esq != NULL)
        {
            if (noh->esq->val < noh->val)
            {
                return menorpont(noh->esq);
            }
        }

        if (noh->dir != NULL)
        {
            if (noh->dir->val < noh->val)
            {
                return menorpont(noh->dir);
            }
        }
        return noh;
    }
}

struct elemento *menordif6(struct elemento *noh, int num)
{
    if (noh != NULL)
    {
        if (num == 0)
        {
            struct elemento *n1, *n2;
            n1 = menordif6(noh->esq, 1);
            n2 = menordif6(noh->dir, 2);

            if (n1->val > n2->val)
            {
                if ((n2->val - noh->val) > (noh->val - n1->val))
                {
                    return n1;
                }
                else
                {
                    return n2;
                }
            }
            else
            {
                if ((n1->val - noh->val) > (noh->val - n2->val))
                {
                    return n2;
                }
                else
                {
                    return n1;
                }
            }
        }
        else if (num == 1)
        {
            if (noh->dir != NULL)
            {
                return menordif6(noh->dir, 1);
            }
        }
        else
        {
            if (noh->esq != NULL)
            {
                return menordif6(noh->esq, 2);
            }
        }
        return noh;
    }
}

int func(struct elemento *noh, int nivel)
{
    if (noh != NULL)
    {
        nivel++;
        int n1 = func(noh->esq, nivel);
        int n2 = func(noh->dir, nivel);
        int result = n1 + n2;

        if ((noh->esq != NULL) && (noh->esq->val < noh->val))
        {
            result++;
        }
        if ((noh->dir != NULL) && (noh->dir->val > noh->val))
        {
            result++;
        }
        if (noh->val < nivel)
        {
            result++;
        }

        return result;
    }
    return 1;
}

int maior_valor(struct elemento *noh, int cont)
{
    if (noh != NULL)
    {

        if (noh->dir == NULL)
        {
            if (noh->esq != NULL)
            {
                int n2 = maior_valor(noh->esq, 1);

                return noh->val - n2;
            }
            else
            {
                ;
                ;
                if (cont == 1)
                {
                    return noh->val;
                }
                else
                {
                    return -1;
                }
            }
        }
        return maior_valor(noh->dir, cont);
    }
    return 0;
}

int main()
{
    struct elemento *noh, *aux;
    noh = NULL;

    noh = inserir_noh(noh, 6);
    noh = inserir_noh(noh, 3);
    noh = inserir_noh(noh, 4);
    noh = inserir_noh(noh, 5);
    noh = inserir_noh(noh, 1);
    noh = inserir_noh(noh, 2);
    noh = inserir_noh(noh, 10);
    noh = inserir_noh(noh, 9);
    noh = inserir_noh(noh, 15);
    noh = inserir_noh(noh, 7);
    noh = inserir_noh(noh, 10);
    noh = inserir_noh(noh, 20);

    showarv(noh);

    printf("\nO valor das folhas eh %d", soma_folhas(noh));

    printf("\nO menor valor eh %d", menor_valor(noh));

    printf("\nO numero de filhos no nivel eh %d", num_nohs(noh, 2));

    printf("\nO numero de filhos menores que o nivel eh %d", num_nohs_menor(noh, -1));

    printf("\nSoma ateh o valor eh %d", soma_at_val(noh, 8));

    printf("\nCaso a arv seja de pesquisa =1 || %d", arv_pesquisa(noh));

    aux = menor(noh);
    printf("\nO menor valor da arv eh %d", aux->val);

    printf("\nValor do mn sequencia existe =2 || %d", mndetect(noh, 6, 1));

    aux = menorpont(noh);
    printf("\nO noh de menor valor eh %d", aux->val);

    aux = menordif6(noh, 0);
    printf("\nO noh de menor valor diferenca com o 6 eh %d", aux->val);

    freearv(noh);

    return 0;
}