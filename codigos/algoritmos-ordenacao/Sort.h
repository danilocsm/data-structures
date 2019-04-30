#ifndef SORT_H_INCLUDED
	

	#define SORT_H_INCLUDED

	#ifdef Sort_c
		int SelectionSort(int *vet,int tam);
		int InsertionSort(int *vet,int tam);
		int ShellSort(int *vet,int tam);
		void Merge(int *vet,int comemo,int meio,int fim);
		void MergeSort(int *vet,int esq,int dir);
		int Particiona(int *vet,int beg,int end);
		void QuickSort(int *vet,int inicio,int fim);
		void Heapify(int *vet,int tam,int pos);
		void HeapSort(int *vet,tam);
		int *CountingSort(int *vet,int tam,int range);
	#else
		extern int SelectionSort(int *vet,int tam);
		extern int InsertionSort(int *vet,int tam);
		extern int ShellSort(int *vet,int tam);
		extern void Merge(int *vet,int comemo,int meio,int fim);
		extern void MergeSort(int *vet,int esq,int dir);
		extern int Particiona(int *vet,int beg,int end);
		extern void QuickSort(int *vet,int inicio,int fim);
		extern void Heapify(int *vet,int tam,int pos);
		extern void HeapSort(int *vet,tam);
		extern int *CountingSort(int *vet,int tam,int range);
		
	#endif

#endif