#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;

    pivot = array[start];
    left = start;
    right = end;

    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }

        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }

        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }

    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;

    // La nueva posición del pivot
    return right;
}

// Función recursiva para hacer el ordenamiento
void Quicksort(int *array, int start, int end)
{
    int pivot;

    if (start < end) {
        pivot = divide(array, start, end);

        // Ordeno la lista de los menores
        Quicksort(array, start, pivot - 1);

        // Ordeno la lista de los mayores
        Quicksort(array, pivot + 1, end);
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Funcion para implementar Metodo Burbuja
void Bubblesort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void MostrarArreglo(int array[], int n)
{
  int i;
  for(i=0;i<n;i++)
  {
      cout<< array[i] << " ";
  }
}

int main() {
  int i;
  int largo = 100;
  int array1[largo];
  int array2[largo];

  // Se llena el arreglo de forma aleatorea
  for (i = 0; i < largo; i++)
  {
        array1[i] = rand() % largo;
  }

  // Se copia el arreglo para que en ambos metodos se obtengan el mismo resultado
  for (int i = 0; i < largo; i++)
  {
        array2[i] = array1[i];
  }

  //Se captura el tiempo inicial y se ejecuta Quicksort, luego se calcula el tiempo de ejecucion.
  clock_t start = clock();
  Quicksort(array1,0,largo);
  float tiempo1 = ((double)clock() - start) / CLOCKS_PER_SEC;

  MostrarArreglo(array1, largo);

  cout << "\n";
  cout << "\n";

  //Se captura el tiempo inicial y se ejecuta Bubblesort, luego se calcula el tiempo de ejecucion.
  start = clock();
  Bubblesort(array2, largo);
  float tiempo2 = ((double)clock() - start) / CLOCKS_PER_SEC;

  MostrarArreglo(array2, largo);

  cout << "\n";
  cout << "Tiempo transcurrido: quicksort\n" << tiempo1 <<"\n";
  cout <<"Tiempo transcurrido: bubbleSort\n" << tiempo2 <<"\n";
  return 0;

}
