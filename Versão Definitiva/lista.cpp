#include <stdlib.h>
struct No {
    int info;
    No *prox;
};

void inserir(No *, int);
void remove(No *, int);

int main() {
}

void inserir(No *r, int info) {
    if (r == 0) {
        r = (No *)malloc(sizeof(No));
        r->info = info;
        r->prox = 0;
        return;
    }
    No *aux = r;
    while (aux->prox != 0) {
        aux = aux->prox;
    }
    aux = (No *)malloc(sizeof(No));
    aux->info = info;
    aux->prox = 0;
}

void remove(No *r, int info) {
    No *aux = r;
    if (r->info == info) {
        r = r->prox;
        free(aux);
        return;
    }
    while (aux->prox != 0) {
        if(aux->prox->info == info){
            //remover
            No* rem = aux->prox;
            aux->prox = aux->prox->prox;
            free(rem);
        }
        aux = aux->prox;
    }
}
