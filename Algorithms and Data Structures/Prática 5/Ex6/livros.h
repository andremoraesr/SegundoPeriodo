#ifndef LIVROS_H
#define LIVROS_H

    struct Livro {
    char titulo[30], autor[30];
    int ano;
    float preco; 
    };

    typedef struct Livro livro;

    struct Lista  {
        livro *dados;
        int quant;
        int cap;
    };

    typedef struct Lista lista;

    lista *criarlista(int tam);

    void insere(lista *l, livro v);

    void excluir(lista *l, char *tit);

    void imprime(lista *l);

#endif