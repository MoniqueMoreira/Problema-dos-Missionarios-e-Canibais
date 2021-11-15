# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "grafo.c"
# include "pilha.c"

TGrafo * atravesando(TGrafo* g,Stack * p, int md, int cd, int b, int ma, int ca, int b1, int me, int ce)
{
    //printf("(%d,%d,%d) -> (%d,%d,%d)(%d,%d,-) -> ",ma,ca,b1,md,cd,b,me,ce);
    int i;
    if(md==0 && cd==0 && me == 3 && ce == 3)
    {
        g = insere_vertice(g,md,cd,b);
        insere_aresta(g,md,cd,b,ma,ca,b1);
        //imprime(g);
        push(p,md,cd,b);
        //imprimir_pilha(p);
        return g;
    }
    if(md<0 || cd<0 || md>3 || cd>3 || me<0 || ce<0 || me>3 || ce>3)
    {
        return g;
    }
    if ((md>=cd || md==0) && (me>=ce || me == 0))
    {
            //printf("(%d,%d,%d) -> (%d,%d,%d)(%d,%d,-) -> ",ma,ca,b1,md,cd,b,me,ce);
            g =insere_vertice(g,md,cd,b);
            if (md!=3 || cd != 3 || b==1)
            {
                insere_aresta(g,md,cd,b,ma,ca,b1);
            }
            
            //imprime(g);
            push(p,md,cd,b);
            //imprimir_pilha(p);
            if (b==0)
            {
                i = Busca_pilha(p,md-1,cd,1);
                if (i == 0)
                {
                   g = atravesando(g,p,md-1,cd,1,md,cd,0,me+1,ce);
                }
                i = Busca_pilha(p,md-2,cd,1);
                if (i == 0)
                {
                    g = atravesando(g,p,md-2,cd,1,md,cd,0,me+2,ce);
                }
                i = Busca_pilha(p,md-1,cd-1,1);
                if (i == 0)
                {
                    g = atravesando(g,p,md-1,cd-1,1,md,cd,0,me+1,ce+1);
                }
                i = Busca_pilha(p,md,cd-1,1);
                if (i == 0)
                {
                    g = atravesando(g,p,md,cd-1,1,md,cd,0,me,ce+1);
                }
                i = Busca_pilha(p,md,cd-2,1);
                if (i == 0)
                {
                    g = atravesando(g,p,md,cd-2,1,md,cd,0,me,ce+2);
                }
            }
            else
            {
                i = Busca_pilha(p,md+1,cd,0);
                if (i == 0)
                {
                    g = atravesando(g,p,md+1,cd,0,md,cd,1,me-1,ce);
                }
                i = Busca_pilha(p,md+2,cd,0);
                if (i == 0)
                {
                    g = atravesando(g,p,md+2,cd,0,md,cd,1,me-2,ce);
                }
                i = Busca_pilha(p,md+1,cd+1,0);
                if (i == 0)
                {
                    g = atravesando(g,p,md+1,cd+1,0,md,cd,1,me-1,ce-1);
                }
                i = Busca_pilha(p,md,cd+1,0);
                if (i == 0)
                {
                    g = atravesando(g,p,md,cd+1,0,md,cd,1,me,ce-1);
                }
                i = Busca_pilha(p,md,cd+2,0);
                if (i == 0)
                {
                    g = atravesando(g,p,md,cd+2,0,md,cd,1,me,ce-2);
                }
            }
            pop(p);
    }
    return g;
}

int main()
{
    int i;
    TGrafo * g = inicializa();
    Stack p;
	p.tam = 0;
	p.inicio = NULL;
    g = atravesando(g,&p,3,3,0,3,3,0,0,0);
    imprime(g);
    return 0;
}
