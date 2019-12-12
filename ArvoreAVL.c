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

void rotacaoSimplesEsquerda(Arvore *A){
    struct NO *B;
    B = (*A)->dir;

    (*A)->dir = B->esq;
    B->esq = (*A);

    (*A)->altura = maior(alturaNo( (*A)->esq ), alturaNo( (*A)->dir) ) + 1;
    B->altura = maior(alturaNo( B->dir ), (*A)->altura) +1;

    (*A) = B;
}

void rotacaoSimplesDireita(Arvore *A){
    struct NO *B;
    B = (*A)->esq;

    (*A)->esq = B->dir;
    B->dir = *A;

    (*A)->altura = maior(alturaNo( (*A)->esq ), alturaNo( (*A)->dir )) + 1;
    B->altura = maior( alturaNo(B->esq), (*A)->altura) + 1;

    (*A) = B;
}

void rotacaoDuplaEsquerdaDireita(Arvore *A){
    rotacaoSimplesEsquerda(&(*A)->esq);
    rotacaoSimplesDireita(A);
}

void rotacaoDuplaDireitaEsquerda(Arvore *A){
    rotacaoSimplesDireita( &(*A)->dir );
    rotacaoSimplesEsquerda(A);
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

int vazia(Arvore *raiz){
    if (raiz == NULL) return 1;
    if (*raiz == NULL) return 1;

    return 0;
}

int altura(Arvore *raiz){
    if (raiz == NULL) return 0;
    if (*raiz == NULL) return 0;

    int alturaEsq = altura( &((*raiz)->esq) );
    int alturaDir = altura( &((*raiz)->dir) );

    if (alturaEsq > alturaDir){
        return alturaEsq + 1;
    }

    else{
        return alturaDir + 1;
    }
}

int totalNo(Arvore *raiz){
    if (raiz == NULL) return 0;
    if (*raiz == NULL) return 0;

    int alturaEsq = totalNo(& ((*raiz)->esq) );
    int alturaDir = totalNo(& ((*raiz)->dir) );

    return (alturaEsq + alturaDir + 1);
}

int buscaNo(Arvore *raiz, int valor){
    if (raiz == NULL) return 0;

    struct NO* atual = *raiz;

    while (atual != NULL){
        if (atual->info == valor){
            printf("Encontrou!\n");
            printf("No -> Valor: %d\n", (*raiz)->info);
            return 1;
        }

        else if (atual->info < valor){
            atual = atual->dir;
        }

        else {
            atual = atual->esq;
        }
    }

    printf("Nao Encontrou.\n");
    return 0;
}

void exibePreOrdem(Arvore *raiz){
    if (raiz == NULL) return;

    if (*raiz != NULL){
        printf("No -> Valor: %d\n", (*raiz)->info);

        exibePreOrdem( &((*raiz)->esq) );
        exibePreOrdem( &((*raiz)->dir) );
    }
}

void exibeInOrdem(Arvore *raiz){
    if (raiz == NULL) return;

    if (*raiz != NULL){
        exibeInOrdem( &((*raiz)->esq) );

        printf("No -> Valor: %d\n", (*raiz)->info);

        exibeInOrdem( &((*raiz)->dir) );
    }
}

void exibePosOrdem(Arvore *raiz){
    if (raiz == NULL) return;

    if (*raiz != NULL){
        exibePosOrdem( &((*raiz)->esq) );
        exibePosOrdem( &((*raiz)->esq) );

        printf("No -> Valor: %d\n", (*raiz)->info);
    }
}

int insere(Arvore *raiz, int valor){
    int res;

    //Arvore Vazia ou No Folha
    if (*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*)malloc( sizeof(struct NO) );

        if (novo == NULL) return 0; //Ocorreu erro

        novo->info = valor;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;

        *raiz = novo;

        return 1; //Inseriu com Sucesso
    }

    struct NO *atual = *raiz;

    if (valor < atual->info){
        if( (res = insere(&(atual->esq), valor) ) == 1){
            if (fatorBalanceamentoNo(atual) >= 2){
                if (valor < (*raiz)->esq->info){
                    rotacaoSimplesDireita(raiz);
                }
                else {
                    rotacaoDuplaEsquerdaDireita(raiz);
                }
            }
        }
    } else {
        if (valor > atual->info){
            if ( (res = insere(&(atual->dir), valor)) == 1 ){
                if (fatorBalanceamentoNo(atual) >= 2){
                    if (valor > (*raiz)->dir->info){
                        rotacaoSimplesEsquerda(raiz);
                    }else {
                        rotacaoDuplaDireitaEsquerda(raiz);
                    }
                }
            }
        } else {
            printf ("O valor informado ja existe na Arvore.\n");
            return 0;
        }
    }

    atual->altura = maior( alturaNo(atual->esq), alturaNo(atual->dir) ) + 1;

    return res;
}
