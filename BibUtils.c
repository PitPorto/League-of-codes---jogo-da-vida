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
        
int verificacaoVizinhos(int *Matriz, int posicao)
{
    
        int vizinhos = 0, i = posicao;
        
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

void CicloVidaCelula(int *Matriz, int posicao)
{
    if(verificacaoVizinhos(Matriz, posicao) < 2 && Matriz[posicao] == 1)
      Matriz[posicao] = 0;
    else if(verificacaoVizinhos(Matriz, posicao) > 3 && Matriz[posicao] == 1)
        Matriz[posicao] = 0;

    else if(verificacaoVizinhos(Matriz, posicao) == 2 || verificacaoVizinhos(Matriz, posicao) == 3 && Matriz[posicao] == 1)
        Matriz[posicao] = 1;

    else if(verificacaoVizinhos(Matriz, posicao) == 3 && Matriz[posicao] == 0)
        Matriz[posicao] = 1;

}

void simulacaoDoJogo(int *Matriz, int linhas, int colunas, int geracoes)
{
    for(int n = 0; n < geracoes; n++)
    {
        for(int i = 0; i < linhas * colunas; i++)
        {
            CicloVidaCelula(Matriz, i);
        }
    }
}

//Saída de dados

void imprimeMatriz(int *Matriz, int linhas, int colunas)
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        { 
            if(Matriz[i*colunas+j] == 1)
                printf("O");
            else
                printf(" ");
        }
        printf("\n");
    }
}



