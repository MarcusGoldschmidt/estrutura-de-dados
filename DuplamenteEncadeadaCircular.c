#include <stdio.h>
#include <stdlib.h>

typedef struct TInfo{
    int chave;
}TInfo;

typedef struct TItem{
    TInfo info;
    struct TItem *pProx;
    struct TItem *pAnte
}TItem;

typedef struct TLista{
    TItem *pPrimeiro;
    TItem *pUltimo;
}TLista;

int iniciarLista(TLista *lista){
    
    lista->pPrimeiro = NULL;
    lista->pUltimo = NULL;

    return 1;
}

int isEmpty(TLista *lista){
    return lista->pPrimeiro == lista->pUltimo;
}

int inserirComeco(TLista *lista, TInfo info){
    TItem *pAux;

    pAux = (TItem *) malloc(sizeof(TItem));

    if(pAux == NULL){
        return 0;
    }

    pAux->pAnte = lista->pUltimo;
    pAux->pProx = lista->pPrimeiro;

    lista->pPrimeiro = pAux;

    return 1;
}

int inserirFinal(TLista *lista, TInfo info){
    TItem *pAux;

    pAux = (TItem *) malloc(sizeof(TItem));

    if(pAux == NULL){
        return 0;
    }

    pAux->pAnte = lista->pUltimo;
    pAux->pProx = lista->pPrimeiro;

    lista->pUltimo =pAux;

    return 1;
}

int isItemInList(TLista *lista, TInfo info){

    TItem *pAux;

    if(isEmpty(lista)){
        return 0;
    }

    pAux = lista->pPrimeiro;

    do{
        if(pAux->info.chave == info.chave){
            return 1;
        }
        pAux = pAux->pProx;
    }while(pAux->pProx != lista->pPrimeiro);

    return 0;
}

int remover(TLista *lista, TInfo info){
    TItem *pAux;

    if(isEmpty(lista)){
        return 0;
    }

    pAux = lista->pPrimeiro;

    do{
        if(pAux->info.chave == info.chave){
            // Realiza a troca

            // Primeiro
            if(lista->pPrimeiro == pAux){
                lista->pPrimeiro = pAux->pProx;
            }

            // Se for final
            if(lista->pUltimo == pAux){
                lista->pUltimo = pAux->pAnte;
            }

            pAux->pProx->pAnte = pAux->pAnte;
            pAux->pAnte->pProx = pAux->pProx;

            free(pAux);

            return 1;
        }
        pAux = pAux->pProx;
    }while(pAux->pProx != lista->pPrimeiro);
    return 0;
}

int main(){

    return 0;
}