#include <stdio.h>
#include <stdlib.h>

typedef struct TInfo{
    int chave;
}TInfo;

typedef struct TItem{
    TInfo info;
    struct TItem *pProx;
    struct TItem *pAnte;
}TItem;

typedef struct TFila{
    TItem *pPrimeiro;
    TItem  *pUltimo;
    int tamanho;
}TFila;

void iniciarFila(TFila *fila){
    fila->pPrimeiro = NULL;
    fila->pUltimo = NULL;
    fila->tamanho = 0;
}

int isVazia(TFila *fila){
    return fila->tamanho == 0;
}

int enqueue(TFila *fila, TInfo info){
    TItem *pAux;

    pAux = (TItem *) malloc(sizeof(TItem));

    if(pAux == NULL){
        return 0;
    }

    pAux->info = info;
    
    pAux->pProx = fila->pPrimeiro;
    pAux->pAnte = NULL;

    fila->pPrimeiro->pAnte = pAux;

    fila->pPrimeiro = pAux;

    return 1;
}

TInfo dequeue(TFila *fila){
    TInfo aux;
    TItem *pAux;

    pAux = fila->pUltimo;
    aux = pAux->info;

    fila->pUltimo = pAux->pAnte;
    fila->pUltimo->pProx = NULL;
    free(pAux);

    return aux;
}

int main(){
    return 1;
}