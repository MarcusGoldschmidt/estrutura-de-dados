#include <stdio.h>
#include <stdlib.h>

typedef struct TItem {
    int chave;
}TItem;


void booblesort(TItem *v){
    int trocou = 1;
    TItem aux;

    while(trocou){
        trocou = 0;

        for (int i = 0; i < (sizeof(v) / sizeof(TItem)) - 1; i++)
        {
            if(v[i].chave > v[i + 1].chave){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                trocou = 1;
            }
        }
    }
}

int main(){
    printf("%ld\n",__LONG_MAX__);
    return 1;
}