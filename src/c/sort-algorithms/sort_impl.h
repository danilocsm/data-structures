#ifndef SORT_H_INCLUDED

#define SORT_H_INCLUDED

#ifdef Sort_Impl_c
int SelectionSort(int *vet, int size);
int InsertionSort(int *vet, int size);
int ShellSort(int *vet, int size);
void Merge(int *vet, int begin, int mid, int end);
void MergeSort(int *vet, int left, int right);
int Particiona(int *vet, int begin, int end);
void QuickSort(int *vet, int begin, int end);
void Heapify(int *vet, int size, int pos);
void HeapSort(int *vet, int size);
int *CountingSort(int *vet, int size, int range);
#else
extern int SelectionSort(int *vet, int size);
extern int InsertionSort(int *vet, int size);
extern int ShellSort(int *vet, int size);
extern void Merge(int *vet, int begin, int mid, int end);
extern void MergeSort(int *vet, int left, int right);
extern int Particiona(int *vet, int begin, int end);
extern void QuickSort(int *vet, int begin, int end);
extern void Heapify(int *vet, int size, int pos);
extern void HeapSort(int *vet, int size);
extern int *CountingSort(int *vet, int size, int range);

#endif

#endif
