struct NO{
    int info;
    int altura;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* Arvore;

//Inicia a �rvore AVL
Arvore* define();

//Destr�i a �rvore
void destruir(Arvore *raiz);

//Insere na �rvore
int insere(Arvore *raiz, int valor);

//Verifica se a �rvore est� vazia
int vazia(Arvore *raiz);

//Retorna a Altura da �rvore
int altura(Arvore *raiz);

//Retorna a Quantidade de N�s na �rvore
int totalNo(Arvore *raiz);

//Busca um N� na �rvore
int buscaNo(Arvore *raiz, int valor);

//Exibe toda a �rvore Pr� Ordem
void exibePreOrdem(Arvore *raiz);

//Exibe toda a �rvore In Ordem
void exibeInOrdem(Arvore *raiz);

//Exibe toda a �rvore P�s Ordem
void exibePosOrdem(Arvore *raiz);
