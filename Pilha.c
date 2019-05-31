#include <stdio.h>
#include <stdlib.h>

typedef struct TInfo{
    int chave;
}TInfo;

typedef struct TItem{
    TInfo info;
    struct TItem *pProx;
}TItem;

typedef struct TPilha{
    TItem *pPrimeiro;
    int tamanho;
}TPilha;

void iniciarPilha(TPilha *pilha){
    pilha->pPrimeiro = NULL;
    pilha->tamanho = 0;
}

int isVazia(TPilha *pilha){
    return pilha->tamanho == 0;
}

// Insere na pilha
int push(TPilha *pilha, TInfo info){
    TItem *pAux;

    pAux = (TItem *) malloc(sizeof(TItem));

    if(pAux == NULL){
        return 0;
    }

    pAux->info = info;
    pAux->pProx = pilha->pPrimeiro;

    pilha->pPrimeiro = pAux;
    pilha->tamanho++;
    
    return 1;
}
// Remove e retorna
TInfo pop(TPilha *pilha){
    TInfo aux;
    TItem *pAux;

    pAux = pilha->pPrimeiro;
    aux = pAux->info;

    pilha->pPrimeiro = pAux->pProx;
    pilha->tamanho--;

    free(pAux);

    return aux;
}

// Consulta o topo
TInfo top(TPilha *pilha){
    TInfo Aux;

    Aux = pilha->pPrimeiro->info;

    return Aux;
}

int tamanho(TPilha *pilha){
    return pilha->tamanho;
}

int main(){
    return 1;
}