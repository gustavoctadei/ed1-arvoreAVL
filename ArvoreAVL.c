#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

Arvore* define(){
    Arvore* raiz = (Arvore*) malloc( sizeof(Arvore) );

    if(raiz != NULL){
        *raiz = NULL;
    }

    return raiz;
}

//////////////////////////////////////////////////
/**< Funções Utilitárias */
//////////////////////////////////////////////////

int maior(int x, int y){
    if(x > y) return x;
    else return y;
}

//////////////////////////////////////////////////
/**< Funções Auxiliares */
//////////////////////////////////////////////////

void destruirNo(struct NO* no){
    if(no == NULL){
        return;
    }

    destruirNo(no->esq);
    destruirNo(no->esq);

    free(no);
    no = NULL;
}

int alturaNo(struct NO* no){
    if(no == NULL){
        return -1;
    }

    else{
        return no->altura;
    }
}

int fatorBalanceamentoNo(struct NO* no){
    return alturaNo(no->esq) - alturaNo(no->dir);
}

//////////////////////////////////////////////////
/**< Funções do Header da Árvore */
//////////////////////////////////////////////////

void destruir(Arvore *raiz){
    if(raiz == NULL) {
        return;
    }

    destruirNo(*raiz);
    free(raiz);
}

int insere(Arvore *raiz, int valor);

int vazia(Arvore *raiz){
    if (raiz == NULL) return 1;
    if (*raiz == NULL) return 1;

    return 0;
}

int altura(Arvore *raiz);

int totalNo(Arvore *raiz){
    if (raiz == NULL) return 0;
    if (*raiz == NULL) return 0;

    int alturaEsq = totalNo(& ((*raiz)->esq) );
    int alturaDir = totalNo(& ((*raiz)->dir) );

    return (alturaEsq + alturaDir + 1);
}

int buscaNo(Arvore *raiz, int valor);

void exibePreOrdem(Arvore *raiz);

void exibeInOrdem(Arvore *raiz);

void exibePosOrdem(Arvore *raiz);
