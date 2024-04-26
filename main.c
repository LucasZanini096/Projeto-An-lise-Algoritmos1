#include <stdio.h>

void afunda(int *a, int *b){ //Função que realiza a troca entre o elemento do nó pai e o elemento do nó filho
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

void criaHeapMax(int array[], int size, int indexNode) {
    int biggest = indexNode;
    int left = 2 * indexNode + 1;
    int right = 2 * indexNode + 2;

    if(left < size && (array[left] > array[biggest])){  //Caso o elemento da esquerda é maior que o nó pai
      biggest = left; //Atribui o valor do elemento da esquerda ao nó pai
    }

    if(right < size && (array[right] > array[biggest])){ //Caso o elemento da direita é maior que o nó pai
      biggest = right; //Atribui o valor do elemento da direta ao nó pai
    }

    if(biggest != indexNode){ //Se ocorreu alguma atribuição ao nó pai
      afunda(&array[indexNode], &array[biggest]); //Realiza a troca entre o elemento filho e o seu pai
      criaHeapMax(array, size, biggest); 
    }
} 

void HeapSort(int array[], int size){
  
  for (int i = ( size / 2) - 1; i >= 0; i-- ){ //Loop para criar a Máx-Heap
    criaHeapMax(array, size, i);
  }

  for (int j = size - 1; j >= 0 ; j--){

    afunda(&array[0], &array[j]); //Faz a troca entre o primeiro e o último elemento
    criaHeapMax(array, j, 0); //Construir novamente o max-heap com o último elemento na raiz da heap
  }
}

void mostrarVetor(int array[], int size){ //Função para mostrar o vetor
  for (int i = 0 ; i <= size - 1 ; i++){
    printf("%d ", array[i]);
  }
}
int main(){

  int vetor[] = {1,5,9,4,6,7};
  int tamanhoVetor = sizeof(vetor)/sizeof(vetor[0]);
  HeapSort(vetor, tamanhoVetor);
  mostrarVetor(vetor, tamanhoVetor);

  return 0;
}