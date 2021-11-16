# Problema-dos-Missionarios-e-Canibais


Três missionários e três canibais estão em um lado do rio, juntamente com um
barco que pode conter uma ou duas pessoas. Descubra um meio de fazer todos
atravessarem o rio, sem deixar que um grupo de missionários de um lado fique em
número menor que o número de canibais nesse lado do rio. Esse problema é famoso
em IA, porque foi assunto do primeiro artigo que abordou a formulação de problemas a
partir de um ponto de vista analítico (Amarel, 1968).

Implemente e resolva o problema de forma ótima, utilizando um algoritmo de busca
apropriado. É boa idéia verificar a existência de estados repetidos?



## A resolução e feita em 3 arquivos, o ***MC.c*** que responsável pela parte da resolução do problema, o ***Grafo.c*** que serve para criar No e Aresta(funções para gerenciamento um grafo) e o ***Pilha.c*** que responsável por cria Pilha(funções para gerenciamento uma pilha).

## O algoritmo busca resolver o problema dos missionários e canibais, por meio da implementação de ***Busca em Profundidade***.

## No arquivo ***Out.txt*** podemos ver o Grafo criado para solução do problema.

## Legendas:
md = missionários do lado direito;

me = missionários do lado esquerdo;

ma = missionários antes de muda de lado(estado anterior);

cd = canibais do lado direito;

ce = canibais do lado esquerdo;

ca = canibais antes da troca de lado(estado anterior);

b = barco(1 - lado direito, 0 - lado esquerdo);

b1 = posição do barco antes da trocar(estado anterior);

g = ponteiro que aponta para grafo;

p = ponteiro que aponta para pilha(responsável por marca os estados visitados);

Estado anterior(ma, ca, b1) -> Estado atual(md, cd, b);

(me, ce, b) usado para impedir que outro lado fique com mais canibais do que missionários.
