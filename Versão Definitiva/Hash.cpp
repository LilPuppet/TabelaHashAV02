#ifndef HASH_CPP
#define HASH_CPP

#include "cidade.cpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Tamanho do vetor
#define SIZE 16

// Vetor de ponterios do tipo dataItem
typedef dataItem *hash[SIZE];

int divisao(dataItem *d)
{
  return d->key % SIZE;
}

void init(hash &H)
{
  for (int i = 0; i < SIZE; i++)
  {
    H[i] = 0;
  }
}

int inserirNovo(hash H, dataItem d)
{
  dataItem *copy = (dataItem *)malloc(sizeof(dataItem));
  struct no *novo = (struct no *)malloc(sizeof(struct no));
  *copy = d;
  int chave = divisao(copy);
  novo->data = d;
  novo->prox = 0;

  if (H[chave] == 0)
  {
    H[chave] = copy;
    return 0;
  }
  else if (H[chave] != 0)
  {
    novo->prox = H[chave]->inicio;
    H[chave]->inicio = novo;
    return 0;
  }

  return -1;
}

/*
void remover(dataItem *d){
  if (d->inicio->prox == 0){
    d->inicio = 0;
  }
}
*/

dataItem *buscar(hash H, int id)
{
  int chave = id % SIZE;
  if (H[chave]->key == id)
  { // Caso (1) esteja esteja imaculado
    printf("O INICIO: %p\n", H[chave]->inicio);
    return H[chave];
  }
  else
  { // Caso haja colisão
    struct no *temp;
    // struct no *temp; // É realmente necessário alocar?
    temp = H[chave]->inicio; // Variável temporária para fins de iteração
    while (temp != NULL)
    { // Enquanto a variável temporária apontar para algo existente continua
      if (temp->data.key == id)
      { // Volta para o caso (1)
        printf("O INICIO: %p\n", temp->data.inicio);
        return &temp->data;
      }
      else
        temp = temp->prox; // Aponta para o próximo na fila
    }
  }
  return NULL;
}

/*
void escrever(hash H){
    for (int i = 0; i < SIZE; i++) {
        printf("P-> %d KEY-> %d\n", i, H[i]->data.key);
    }
}
*/
void removerNovo(no *PL, int miau)
{
  if (PL->data.inicio == NULL)
  {
    printf("\nA Lista se encontra VAZIA!!\n");
  }
  else if (PL->data.inicio->data.key == miau)
  {
    struct no *PIN = PL->data.inicio;
    free(PIN);
  }
  else if (PL->data.inicio->prox == NULL)
  {
    if (PL->data.key = !miau)
    {
      printf("\nEssa HASH Nao Existe!\n");
    }
  }
  else
  {
    struct no *pin; // Ponteiro Indice
    struct no *pan; // Ponteiro Auxiliar de No
    for (pin = PL->data.inicio; pin != NULL && pin->data.key == miau; pin = pin->prox)
    {
      pan = pin;
    }
    if (pin == NULL)
    {
      printf("impossivel a remocao!\n");
    }
    else
    {
      pan->prox = pin->prox;
      free(pin);
    }
  }
}

#endif
