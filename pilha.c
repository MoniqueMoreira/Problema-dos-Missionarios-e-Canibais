#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int M, C, B;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Stack;

void imprimir_pilha(Stack *p) 
{
    No *inicio = p->inicio;

    printf("Tamanho da lista: %d\n", p->tam);

    while(inicio != NULL) {
        printf("(%d,%d,%d)", inicio->M, inicio->C, inicio->B);
        inicio = inicio->proximo;
    }
    printf("\n");
}

void push(Stack *p,  int m, int c, int  b) // colocar na pilha
{
    No *novo = (No*)malloc(sizeof(No));
    novo->M = m;
    novo->C = c;
    novo->B = b;

    if(p->inicio == NULL) 
    {
        novo->proximo = NULL;
        p->inicio = novo;
    } 
    else 
    {
        novo->proximo = p->inicio;
        p->inicio = novo;
    }
    p->tam++;
}

void pop(Stack *p) // retirar da pilha
{
    No * inicio = p->inicio;
    No * noARemover = p->inicio;


    if(p->tam == 0)
    {
    	printf("PILHA UNDERFLOW, NÃO E POSSIVEL retirar \n");
    }
    else
    {
    	p->inicio = inicio->proximo;
    	free(noARemover);
        p->tam--;

    }
}

int Busca_pilha(Stack * p, int m, int c, int  b) // Buscando na pilha
{
    No *inicio = p->inicio;

    while(inicio != NULL) 
    {
        if(inicio->M == m && inicio->C == c && inicio->B == b)
        {
            return 1;
        }
        inicio = inicio->proximo;
    }
    return 0;
}

/*int main()
{
	Stack p;
	p.tam = 0;
	p.inicio = NULL;
	imprimir(&p);
	pop(&p);
	imprimir(&p);
	return 0;
}
*/