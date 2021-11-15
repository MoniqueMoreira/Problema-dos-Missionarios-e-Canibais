#include <stdio.h>
#include <stdlib.h>

 typedef struct No {
    int M,C,B;
    struct No *proximo;
} No;

typedef struct {
    No *inicio, *fim;
    int tam;
} Lista;

Lista * inicializar_lista()
{
    Lista  h;
    h.inicio = NULL;
    h.fim = NULL;
    h.tam = 0;

    Lista * d = &h;

    return d;
}

// imprimir a lista
void imprimirL(Lista *lista) {
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL) {
        printf("(%d,%d,%d)", inicio->M, inicio->C, inicio->B);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}

int busca(Lista * lista, int m, int c, int b)
{
    No * aux = lista->inicio;
    while(aux != NULL)
    {
        //printf("(%d,%d,%d)",m,c,b);
        if(aux->M == m && aux->C == c && aux->B == b)
        {
            return 1;
        }
        aux = aux->proximo;
    }
    return 0;
}

// inserir no final da lista
void inserirFim(Lista *lista, int m, int c, int b) {
    No *novo = (No*)malloc(sizeof(No)); // cria um novo nó
    novo->M = m;
    novo->C = c;
    novo->B = b;
    novo->proximo = NULL;

    if(lista->inicio == NULL) { // lista vazia
        lista->inicio = novo;
        lista->fim = novo;
    } else { // lista não vazia
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tam++;
}
