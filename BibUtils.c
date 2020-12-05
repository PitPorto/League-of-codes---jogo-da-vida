#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BibUtils.h"

void Menu()
{
    printf("Escolha uma opção de inicialização:\n");
    printf("Opção 1: Inicialização randômica\n");
    printf("Opção 2: Usuário indicando onde deve começar as células\n");
}

void InicializaMatriz(int *Matriz, int escolha)
{
    srand(time(NULL));

    int x = 0, y = 0;
    
    if(escolha == 1)
    {
        for(int i = 0; i < 900; i++)
        {
           Matriz[i] = rand() % 2;
        } 

    }
    else if(escolha == 2)
    {
        while(x != -1 && y != -1)
        {
            scanf("%d %d", &x, &y);

            Matriz[x*30+y] = 1;
        }
    }
    else
    {
        printf("Opção inválida.");
    }
}

void imprime(int *Matriz)
{
    for(int i = 0; i < 900; i++)
    {
        if(Matriz[i] == 1)
            printf("O ");
        else
            printf(" ");


        if(i % 30 == 0)
            printf("\n");
    }
}
        




