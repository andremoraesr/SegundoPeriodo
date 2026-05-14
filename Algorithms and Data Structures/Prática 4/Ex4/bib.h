#ifndef BIB_H
#define BIB_H

    struct lista {
    Produto *dados; // define um ponteiro para um vetor
    int quant; // mantém a quantidade
    };
    
    typedef struct lista Lista; // simplifica o nome do tipo

    struct produto{
        int codProd;        //código do produto
        char nomeProd[10];  //nome do produto
        float valor;        //valor do produto
        int qtdeEstoque;    //quantidade disponível em estoque
    };

    typedef struct produto Produto;
    
    Lista criarlista(int tam);
    
    void insereprod(Lista *l, Produto p, int tam);

    void cheaper(Lista *l, Produto p);

#endif
