#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "livros.h"

    int main () {

        setlocale(LC_ALL, "");

        int tam;

        printf("Digite quantos livros serão incluídos num primeiro momento: ");
        scanf("%d", &tam);

        lista *lp = criarlista(tam);
        livro vp;

        int option;
        
        do {
            printf("Menu de opções: \n");
            printf("Digite 1 para cadastrar um livro.\n");
            printf("Digite 2 para remover um livro.\n");
            printf("Digite 3 para visualizar todos os livros cadastrados.\n");
            printf("Digite 0 para sair do menu e encerrar.\n");
            scanf("%d", &option);
            printf("\n");

            switch (option)  {
                case 1:
                    setbuf(stdin, NULL);
                    printf("Digite o título do livro: ");
                    scanf(" %29[^\n]", vp.titulo);
                    printf("Digite o nome do autor do livro: ");
                    scanf(" %29[^\n]", vp.autor);
                    printf("Digite o ano de lançamento do livro: ");
                    scanf("%d", &vp.ano);
                    printf("Digite o preço do livro: R$");
                    scanf("%f", &vp.preco);
                    insere(lp, vp);

                    printf("\n");
                    break;
                case 2:  {
                    char apaga[30];
                    printf("Digite o título do livro a ser removido: ");
                    setbuf(stdin, NULL);

                    scanf(" %29[^\n]", apaga);
                    excluir(lp, apaga);
                    break;  }
                case 3:
                    imprime(lp);
                    break;
                case 0:
                    break;
                default:
                    printf("Opção inválida.\n");
            }

        } while(option!=0);

        free(lp->dados);
        free(lp);

        return 0;
}
