#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BibUtils.h"

//Funções de entrada de dados

void Menu()
{
    printf("Escolha uma opção de inicialização:\n");
    printf("Opção 1: Inicialização randômica\n");
    printf("Opção 2: Usuário indicando onde deve começar as células\n");
}

void InicializaMatriz(int *Matriz, int linhas, int colunas, int escolha)
{
    srand(time(NULL));

    int x = 0, y = 0;
    
    if(escolha == 1)
    {
        for(int i = 0; i < linhas * colunas; i++)
        {
           Matriz[i] = rand() % 2;
        } 

    }
    else if(escolha == 2)
    {
        while(x != -1 && y != -1)
        {
            scanf("%d %d", &x, &y);

            Matriz[x*colunas+y] = 1;
        }
    }
    else
    {
        printf("Opção inválida.");
    }
}

//Andamento do jogo
        
int verificacao(int *Matriz, int linha, int coluna)
{
    
        int vizinhos = 0, i = linha*30+coluna;
        
        if(i == 0)
        {
            if(Matriz[i+1] == 1)
                vizinhos++;

            if(Matriz[i+30] == 1)
                vizinhos++;
            
            if(Matriz[i+29] == 1)
                vizinhos++;

            if(Matriz[870] == 1)
                vizinhos++;
        
            return vizinhos;
        }
        
        if(i == 29)
        {
            if(Matriz[0] == 1)
                vizinhos++;

            if(Matriz[i+30] == 1)
                vizinhos++;
            
            if(Matriz[i-1] == 1)
                vizinhos++;

            if(Matriz[899] == 1)
                vizinhos++;
        
            return vizinhos;
        }
        
        if(i == 870)
        {
            if(Matriz[i+1] == 1)
                vizinhos++;

            if(Matriz[i+30] == 1)
                vizinhos++;
            
            if(Matriz[i+29] == 1)
                vizinhos++;

            if(Matriz[0] == 1)
                vizinhos++;
        
            return vizinhos;
        }
        if(i == 899)
        {
            if(Matriz[i-1] == 1)
                vizinhos++;

            if(Matriz[29] == 1)
                vizinhos++;
            
            if(Matriz[i-29] == 1)
                vizinhos++;

            if(Matriz[879] == 1)
                vizinhos++;
        
            return vizinhos;
        }
        
        if(i % 30 == 0 && i > 29 && i < 870)
        {
            if(Matriz[i+1] == 1)
                vizinhos++;

            if(Matriz[i-30] == 1)
                vizinhos++;

            if(Matriz[i+30] == 1);
                vizinhos++;
            
            if(Matriz[i+29] == 1);
                vizinhos++;
            
            return vizinhos;            
        }
        
        if(i % 30 == 29 && i > 29 && i < 870)
        {
            if(Matriz[i-1] == 1)
                vizinhos++;

            if(Matriz[i+30] == 1)
                vizinhos++;

            if(Matriz[i-30] == 1);
                vizinhos++;
            
            if(Matriz[i-29] == 1);
                vizinhos++;
            
            return vizinhos;            
        }

        if(i % 30 != 0 && i % 30 != 29 && i > 29 && i < 870)
        {
            if(Matriz[i-1] == 1)
                vizinhos++;

            if(Matriz[i+1] == 1)
                vizinhos++;
            
            if(Matriz[i+30] == 1)
                vizinhos++;
        
            if(Matriz[i-30] == 1)
                vizinhos++;

            return vizinhos;
        }


}



//Saída de dados

void imprimeMatriz(int *Matriz, int linhas, int colunas)
{
    for(int i = 0; i < linhas * colunas; i++)
    {
        if(Matriz[i] == 1)
            printf("O");
        else
            printf(" ");


        if(i % colunas == 0)
            printf("\n");
    }
    printf("\n");
}



