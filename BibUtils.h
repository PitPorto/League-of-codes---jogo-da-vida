#ifndef BibUtils
#define BibUtils

void Menu();

void InicializaMatriz(int *Matriz, int linhas, int colunas, int escolha);

void imprimeMatriz(int *Matriz, int linhas, int colunas);

int verificacaoVizinhos(int *Matriz, int posicao);

void CicloVidaCelula(int *Matriz,int posicao);

void simulacaoDoJogo(int *Matriz, int linhas, int colunas, int geracoes);





#endif
