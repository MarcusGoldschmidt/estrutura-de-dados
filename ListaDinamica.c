#include <stdio.h>
#include <stdlib.h>

typedef struct TInfo{
    int chave;
}TInfo;

typedef struct TItem{
    TInfo info;
    struct TItem *pProx;
}TItem;

typedef struct TLista{
    TItem *pPrimeiro;
    TItem *pUltimo;
}TLista;

int iniciarLista(TLista *lista){
    lista->pPrimeiro = (TItem *) malloc(sizeof(TItem));
    lista->pUltimo = lista->pPrimeiro;
    lista->pPrimeiro->pProx = NULL;
    return 1;
}

int isVazia(TLista *lista){
    return lista->pPrimeiro == lista->pUltimo;
}

int insereInicio(TLista *lista, TInfo item){
    TItem *pAux;

    pAux = lista->pPrimeiro;
    lista->pPrimeiro = (TItem *) malloc(sizeof(TItem));
    lista->pPrimeiro->info = item;
    lista->pPrimeiro->pProx = pAux;
    return 1;
}

int insereFinal(TLista *lista, TInfo item){

    lista->pUltimo->pProx = (TItem *) malloc(sizeof(TItem));
    lista->pUltimo = lista->pUltimo->pProx;
    lista->pUltimo->info = item;
    lista->pUltimo->pProx = NULL;

    return 1;
}

int removeInicio(TLista *lista){

    if(isVazia(lista)){
        return 0;
    }

    TItem *pAux;

    pAux = lista->pPrimeiro;
    lista->pPrimeiro = lista->pPrimeiro->pProx;
    free(pAux);

    return 1;
}

int removeFinal(TLista *lista){
    TItem *pAux;

    if(isVazia(lista)){
        return 0;
    }

    pAux = lista->pPrimeiro;

    // Penutimo
    while(pAux->pProx->pProx != NULL){
        pAux = pAux->pProx;
    }
    free(pAux->pProx);
    pAux->pProx = NULL;
    lista->pUltimo = pAux;

    return 1;
}

void imprimirLista(TLista *lista){
    TItem *pAux;

    pAux = lista->pPrimeiro;

    while(pAux != NULL){
        printf("Item: %d\n", pAux->info.chave);
        pAux = pAux->pProx;
    }
}

int main(){

    return 0;
}