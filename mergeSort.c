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
    lista = (TItem *) malloc(sizeof(TLista));
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

void mergeSort(TLista *lista, int n){
    mergeSortOrdena(lista->pPrimeiro, 0, n -1);
}

void mergeSortOrdena(TItem *pItem, int esq, int dir){
    if(esq < dir){
        int meio = (esq + dir) / 2;
        mergeSortOrdena(pItem, esq, meio);
        mergeSortOrdena(pItem, meio + 1, dir);
        mergeSortInterpela(pItem, esq, meio, dir);
    }
}

void mergeSortInterpela(TItem *vetor, int esq, int meio, int dir){
    int i = 0;
    int aAux = 0;
    int bAux = 0;

    int trocaAux;

    int a_tam = meio - esq + 1;
    int b_tam = dir - meio;

    // Vetores auxiliares
    TItem *a = (TItem *) malloc(sizeof(TItem) * a_tam);
    TItem *b = (TItem *) malloc(sizeof(TItem) * b_tam);

    // Store valores
    for (i = 0; i < a_tam; i++){
        a[i] = vetor[esq + i];
    }
    for (i = 0; i < b_tam; i++){
        b[i] = vetor[meio + 1 + i];
    }

    // Realizandoa troca
    i = 0;
    for (trocaAux = esq; trocaAux <= dir; trocaAux++){
        if(aAux == a_tam){
            vetor[trocaAux] = b[bAux++];
        }else if (bAux == b_tam){
            vetor[trocaAux] = a[aAux++];
        }else if (a[i].info.chave < b[bAux].info.chave){
            vetor[trocaAux] = a[aAux++];
        }else{
            vetor[trocaAux] = b[bAux++];
        }
    }
    
    free(a);
    free(b);
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