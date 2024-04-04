#define Sort_Implc_c
#include "sort_impl.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int SelectionSort(int *vet, int size) {
  int i, j, key, min;
  if (vet != NULL) {
    for (i = 0; i < size - 1; i++) {
      min = i;
      for (j = i + 1; j < size; j++) {
        if (vet[j] < vet[min])
          min = j;
      }
      key = vet[min];
      vet[min] = vet[i];
      vet[i] = key;
    }
    return TRUE;
  }
  return FALSE;
}

int InsertionSort(int *vet, int size) {
  int i, j;
  int key;
  if (vet != NULL) {
    for (i = 1; i < size; i++) {
      key = vet[i];
      j = i - 1;
      while (j >= 0 && vet[j] > key) {
        vet[j + 1] = vet[j];
        j--;
      }
      vet[j + 1] = key;
    }
    return TRUE;
  }
  return FALSE;
}

int ShellSort(int *vet, int size) {
  int h = 1, temp, i, j;
  if (vet != NULL) {
    while (h < size)
      h = (3 * h) + 1;
    while (h > 0) {
      h = (h - 1) / 3;
      for (i = h; i < size; i++) {
        temp = vet[i];
        j = i;
        while (j > h && vet[j - h] > temp) {
          vet[j] = vet[j - h];
          j = j - h;
        }
        vet[j] = temp;
      }
    }
    return TRUE;
  }
  return FALSE;
}
void Merge(int *vet, int begin, int mid, int end) {

  int com1 = begin, com2 = mid + 1, comAux = 0;
  int vetAux[end - begin + 1];
  while (com1 <= mid && com2 <= end) {
    if (vet[com1] <= vet[com2]) {
      vetAux[comAux] = vet[com1];
      com1++;
    } else {
      vetAux[comAux] = vet[com2];
      com2++;
    }
    comAux++;
  }
  while (com1 <= mid) {
    vetAux[comAux] = vet[com1];
    comAux++;
    com1++;
  }
  while (com2 <= end) {
    vetAux[comAux] = vet[com2];
    comAux++;
    com2++;
  }
  for (comAux = begin; comAux <= end; comAux++) {
    vet[comAux] = vetAux[comAux - begin];
  }
}

void MergeSort(int *vet, int left, int right) {
  int meio;
  if (left < right) {
    meio = (left + right) / 2;
    MergeSort(vet, left, meio);
    MergeSort(vet, meio + 1, right);
    Merge(vet, left, meio, right);
  }
}

int Partition_1(int *vet, int begin, int end) {
  int pivot = vet[begin];
  int i = begin + 1, f = end;
  while (i <= f) {
    if (vet[i] <= pivot)
      i++;
    else if (vet[f] > pivot)
      f--;
    else {
      int troca = vet[i];
      vet[i] = vet[f];
      vet[f] = troca;
      i++;
      f--;
    }
  }
  vet[begin] = vet[f];
  vet[f] = pivot;
  return f;
}

int Partition_2(int *vet, int begin, int end) {
  int pivot = vet[end];
  int i = begin, f = end - 1;
  while (i <= f) {
    if (vet[i] <= pivot)
      i++;
    else if (vet[f] > pivot)
      f--;
    else {
      int troca = vet[i];
      vet[i] = vet[f];
      vet[f] = troca;
      i++;
      f--;
    }
  }
  vet[end] = vet[f];
  vet[f] = pivot;
  return f;
}

void QuickSort1(int *vet, int begin, int end) {
  int pivotPosition; // pivot is the first element
  if (vet != NULL) {
    if (begin < end) {
      pivotPosition = Partition_1(vet, begin, end);
      QuickSort(vet, begin, pivotPosition - 1);
      QuickSort(vet, pivotPosition + 1, end);
    }
  }
}

void QuickSort2(int *vet, int begin, int end) {
  int pivotPosition; // pivot is the last element
  if (vet != NULL) {
    if (begin < end) {
      pivotPosition = Partition_2(vet, begin, end);
      QuickSort(vet, begin, pivotPosition - 1);
      QuickSort(vet, pivotPosition + 1, end);
    }
  }
}

void Heapify(int *vet, int size, int pos) {
  int largest = pos;
  int left = 2 * pos + 1;
  int right = 2 * pos + 2;
  if (left < size && vet[left] > vet[largest])
    largest = left;
  if (right < size && vet[right] > vet[largest])
    largest = right;

  if (largest != pos) {
    int swap = vet[pos];
    vet[pos] = vet[largest];
    vet[largest] = swap;
    Heapify(vet, size, largest);
  }
}

void HeapSort(int *vet, int size) {
  int i;
  for (i = (size / 2) - 1; i >= 0; i--)
    Heapify(vet, size, i);
  for (i = size - 1; i >= 0; i--) {
    int swap = vet[i];
    vet[i] = vet[0];
    vet[0] = swap;
    Heapify(vet, i, 0);
  }
}

int *CountingSort(int *vet, int size, int range) {
  int count[range + 1];
  int *aux;
  int i, j;
  aux = (int *)malloc(sizeof(int) * size);
  for (i = 0; i < range + 1; i++)
    count[i] = 0;
  for (i = 0; i < size; i++)
    count[vet[i]]++;
  i = 0;
  j = 0;
  while (j < range + 1) {
    if (count[i] != 0) {
      aux[j] = i;
      count[i]--;
      j++;
    } else {
      i++;
    }
  }
  return aux;
}
