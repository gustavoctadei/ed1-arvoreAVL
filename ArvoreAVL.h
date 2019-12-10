struct NO{
    int info;
    int altura;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* Arvore;

//Inicia a Árvore AVL
Arvore* define();

//Destrói a Árvore
void destruir(Arvore *raiz);

//Insere na Árvore
int insere(Arvore *raiz, int valor);

//Verifica se a Árvore está vazia
int vazia(Arvore *raiz);

//Retorna a Altura da Árvore
int altura(Arvore *raiz);

//Retorna a Quantidade de Nós na Árvore
int totalNo(Arvore *raiz);

//Busca um Nó na Árvore
int buscaNo(Arvore *raiz, int valor);

//Exibe toda a Árvore Pré Ordem
void exibePreOrdem(Arvore *raiz);

//Exibe toda a Árvore In Ordem
void exibeInOrdem(Arvore *raiz);

//Exibe toda a Árvore Pós Ordem
void exibePosOrdem(Arvore *raiz);
