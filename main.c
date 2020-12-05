#include <stdio.h>
#include "BibUtils.h"
#include <stdlib.h>

#define L 30
#define C 30

int main(){
    
    int escolha, matriz[900] = {0};
    
    Menu();
    scanf("%d", &escolha);

    InicializaMatriz(matriz, escolha); 
    imprime(matriz);

    return 0;
}
