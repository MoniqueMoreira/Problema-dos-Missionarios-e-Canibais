# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct vizinho 
{
    int Mviz;
    int Cviz;
    int B;
    struct vizinho * prox;
}TVizinho;

typedef struct grafo
{
    int Mvert;
    int Cvert;
    int B;
    TVizinho * prim_viz;
    struct grafo * prox;
}TGrafo;

TGrafo * inicializa (){
    return NULL;
}

void imprime(TGrafo *g)
{
    printf("----------------------------GRAFO----------------------------\n");
    while(g != NULL)
    {
        printf("Vertice (%d,%d,%d)\n", g->Mvert, g->Cvert,g->B);
        printf("Vizinhos: ");
        TVizinho *v = g->prim_viz;
        while(v != NULL)
        {
            printf("(%d,%d,%d) ", v->Mviz, v->Cviz, v->B);
            v = v->prox;
        }
    printf("\n\n");
    g = g->prox;
    }
}

TGrafo * busca_vertice(TGrafo * g, int x, int y, int b)
{
    while ((g != NULL) && ((g->Mvert != x) || (g->Cvert != y) || (g->B != b)))
    {
        g = g->prox;
    }
    return g;
}


TGrafo *insere_vertice(TGrafo *g, int x, int y, int b)
{
    TGrafo * p = busca_vertice(g, x, y,b);
    if(p == NULL)
    {
        p = (TGrafo*) malloc(sizeof(TGrafo));
        p->Mvert = x;
        p->Cvert = y;
        p->B = b;
        p->prox = g;
        p->prim_viz = NULL;
        g=p;
    }
    return g;
}

TVizinho* busca_aresta(TGrafo *g, int v1M, int v1C,int b, int v2M, int v2C,int b1)
{
    TGrafo *pv1 = busca_vertice(g,v1M,v1C,b);
    TGrafo *pv2 = busca_vertice(g,v2M,v2C,b1);
    TVizinho *resp = NULL;
    //checa se ambos os vértices existem
    if((pv1 != NULL) && (pv2 != NULL)) 
    {
        //percorre a lista de vizinhos de v1 procurando por v2
        resp = pv1->prim_viz;
        while ((resp != NULL) && ((resp->Mviz != v2M) || (resp->Cviz != v2C) || (resp->B != b1))) 
        {
            resp = resp->prox;
        }
    }
    return resp;
}

void insere_um_sentido(TGrafo *g, int v1M, int v1C,int b, int v2M, int v2C,int b1)
{
    TGrafo *p = busca_vertice(g, v1M, v1C,b);
    TVizinho *nova = (TVizinho *) malloc(sizeof(TVizinho));
    nova->Mviz = v2M;
    nova->Cviz = v2C;
    nova->B = b1;
    nova->prox = p->prim_viz;
    p->prim_viz = nova;
}

void insere_aresta(TGrafo *g, int v1M, int v1C, int b ,int v2M, int v2C, int b1)
{

    TVizinho *v = busca_aresta(g, v1M, v1C,b, v2M, v2C,b1);
    if(v == NULL)
    {
            insere_um_sentido(g,v1M, v1C,b, v2M, v2C,b1);
            insere_um_sentido(g,v2M, v2C,b1, v1M, v1C,b); 
    }
}