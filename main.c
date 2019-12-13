#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main(){
    Arvore* raiz;
    int opcao, num, res;

    raiz = define();
    printf("Arvore definida.\n\n");

    do{
        printf("1 - Inserir\n");
        printf("2 - Exibir pre-ordem\n");
        printf("3 - Exibir in-ordem\n");
        printf("4 - Exibir pos-ordem\n");
        printf("5 - Altura da Arvore\n");
        printf("6 - Numero total de nos\n");
        printf("7 - Nivel de um no\n");
        printf("8 - Buscar um no\n");
        printf("9 - Destruir Arvore e Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){

        case 1: //inserir
            printf("Digite o valor que deseja inserir: ");
            scanf("%d", &num);
            res = insere(raiz, num);
            if(res==1) printf("Valor inserido na arvore com sucesso.\n");
            else printf("Erro ao inserir o valor na arvore.\n");
            break;

        case 2: //exibe Pre-Ordem
            printf("Exibindo a Arvore na sequencia Pre-Ordem\n");
            exibePreOrdem(raiz);
            break;

        case 3: //exibe In-Ordem
            printf("Exibindo a Arvore na sequencia In-Ordem\n");
            exibeInOrdem(raiz);
            break;

        case 4: //exibe Pos-Ordem
            printf("Exibindo a Arvore na sequencia In-Ordem\n");
            exibePosOrdem(raiz);
            break;

        case 5: //Altura da Arvore
            res = altura(raiz);
            if(res==0) printf("Arvore Vazia\n");
            else printf("Altura da Arvore: %d\n", res);
            break;

        case 6: //Numero de Nos na Arvore
            res = totalNo(raiz);
            printf("Numero total de Nos na Arvore: %d\n", res);
            break;

        case 7:
            printf("Digite o Valor do No que deseja buscar: ");
            scanf("%d", &num);
            buscaAlturaNo(raiz, num);
            break;

        case 8: //Buscar um No
            printf("Digite o Valor do No que deseja buscar: ");
            scanf("%d", &num);
            buscaNo(raiz, num);
            break;

        case 9: //Destruir a Arvore e Sair
            destruir(raiz);
            printf("Saindo...\n");
            break;

        default: //Caso o usuario digite um numero invalido
            printf("Opcao Invalida. Por favor, digite novamente.\n");
            break;

        }
    }while(opcao!=9);

    getch();
    return 0;
}
