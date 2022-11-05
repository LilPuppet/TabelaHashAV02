#include "Hash.cpp"
#include "cidade.cpp"
#include "lerArquivos.cpp"
#include <cstdio>
// #define SIZE 16

void printHashTable(hash H);

int main()
{
  dataItem *d = (dataItem *)malloc(sizeof(dataItem));      // Criando pointeiro de dataItem e guardando espaço para a variavel criada
  char *arquivo1 = (char *)"bancoDeDados/legenda.txt";     // Criando variavel ponteiro do tipo char que armazena a string "bancoDeDados/legenda.txt"
  cidade *todasCidades = getCidades(arquivo1);             // Criando variavel ponteiro do tipo cidade que armazenará os dados do arquivo "legenda.txt"
  char *arquivo2 = (char *)"bancoDeDados/coordenadas.csv"; // Criando variavel ponteiro do tipo GPS que armazenará os dados do arquivo "coordenadas.csv"
  gps *locais = getGps(arquivo2);
  d = getItens(todasCidades, locais);
  hash H;       // Criando um vetor de ponteiro de dataItem
  init(H);      // Iniciando posições da tabela hash
  dataItem aux; // Criando uma variavel local auxiliar do tipo dataItem
  for (int i = 0; i <= SIZE; i++)
  {
    aux = d[i];          // Cada vez que incrementamos o i, passamos os dados de uma nova posição do vetor de dataItem para o dataItem auxiliar
    inserirNovo(H, aux); // chamada da função de inserção
  }
  // imprimindo as posições da tabela Hash
  printHashTable(H);

  // Testando busca

  // if (dummy != NULL)
  //  printf("%s\n",dummy->city.cidade);
  int target;
  dataItem *dummy;
  do
  {
    printf("Dite um ID para buscar: \n");
    scanf("%d", &target);
    dummy = buscar(H, target);
    if (dummy == NULL)
    {
      printf("tente novamente\n\n");
    }
    else if (dummy != NULL)
    {
      printf("O INICIO: %p\n", dummy->inicio);
      printf("\n ID: %i\n Estado: %s\n Cidade: %s\n Longitude: %.2f Latitude: %.2f\n\n", dummy->key, dummy->city.estado, dummy->city.cidade, dummy->GPS.lo, dummy->GPS.la);

      //  printf("%s\n",dummy->city.cidade);
    }
  } while (dummy == NULL);
  removerNovo(&No, target);
  printf("\n ID: %i\n Estado: %s\n Cidade: %s\n Longitude: %.2f Latitude: %.2f\n\n", dummy->key, dummy->city.estado, dummy->city.cidade, dummy->GPS.lo, dummy->GPS.la);
}

void printHashTable(hash H)
{
  for (int i = 0; i < SIZE; i++)
  {
    // Caso a posição não esteja vazia ela imprime o seu conteudo
    if ((H[i] != NULL))
    {
      struct no *aux = (struct no *)malloc(sizeof(struct no)); // Alocando uma variavel no auxiliar para percorrer as listas do dataItem
      aux = H[i]->inicio;                                      // Fazendo com que o no aponte para o inicio da lista
      // Imprime o conteudo da posição da tabela Hash em questão (não confundir com o inicio da lista dessa posição)
      printf("\n ID: %i\n Estado: %s \n Cidade: %s Longitude: %.2f Latitude: %.2f\n\n", H[i]->key, H[i]->city.estado, H[i]->city.cidade, H[i]->GPS.lo, H[i]->GPS.la);
      // Agora iremos imprimir os elementos da lista da posição em questão
      while (aux != 0)
      {
        // Imprime o elemento atual da lista armazenado na variavel auxiliar
        printf("\n ID: %i\n Estado: %s \n Cidade: %s Longitude: %.2f Latitude: %.2f\n\n", aux->data.key, aux->data.city.estado, aux->data.city.cidade, aux->data.GPS.lo, aux->data.GPS.la);
        aux = aux->prox; // Armazena os dados do proximo elemento da lista na nossa variavel auxiliar para imprimi-los
        // Caso o valor do proximo elemento armazenado na variavel auxiliar seja nulo, executamos uma quebra em nosso laço de repetição e partimos para o proximo elemento da tabela hash e sua respectiva lista
        if (aux == NULL)
        {
          break;
        }
      }
    }
  }
}
