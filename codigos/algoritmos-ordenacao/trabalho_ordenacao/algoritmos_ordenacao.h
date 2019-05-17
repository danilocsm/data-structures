//#ifndef ORDENA1_H_INCLUDED


		#define ORDENA1_H_INCLUDED

//	#ifdef Ordena1_c
		typedef struct myStruct{ // estrutura que contem uma string e um contador
			char str[25];
			int cont;
		}mSt;
		int m1SelectionSort(mSt **vet,int tam,int col,int *trocas,int *comp,int *atri);
		int m1InsertionSort(mSt **vet,int tam,int col,int *trocas,int *comp,int *atri);
		int m1ShellSort(mSt **vet,int tam,int col,int *trocas,int *comp,int *atri);
		void m1Merge(mSt **vet,int comeco,int meio,int fim,int col,int *trocas,int *comp,int *atri);
		void m1MergeSort(mSt **vet,int esq,int dir,int col,int *trocas,int *comp,int *atri);
		int m1Particiona1(mSt **vet,int beg,int end,int col,int *trocas,int *comp,int *atri);
		int m1Particiona2(mSt **vet,int beg,int end,int col,int *trocas,int *comp,int *atri);
		void m1QuickSort1(mSt **vet,int inicio,int fim,int col,int *trocas,int *comp,int *atri);
		void m1QuickSort2(mSt **vet,int inicio,int fim,int col,int *trocas,int *comp,int *atri);
		void m1Heapify(mSt **vet,int tam,int pos,int col,int *trocas,int *comp,int *atri);
		void m1HeapSort(mSt **vet,int tam,int col,int *trocas,int *comp,int *atri);
		int m2SelectionSort(mSt **vet,int tam,int *trocas,int *comp,int *atri);
		int m2InsertionSort(mSt **vet,int tam,int *trocas,int *comp,int *atri);
		int m2ShellSort(mSt **vet,int tam,int *trocas,int *comp,int *atri);
		void m2Merge(mSt **vet,int comeco,int meio,int fim,int *trocas,int *comp,int *atrim);
		void m2MergeSort(mSt **vet,int esq,int dir,int *trocas,int *comp,int *atri);
		int m2Particiona1(mSt **vet,int beg,int end,int *trocas,int *comp,int *atri);
		int m2Particiona2(mSt **vet,int beg,int end,int *trocas,int *comp,int *atri);
		void m2QuickSort1(mSt **vet,int inicio,int fim,int *trocas,int *comp,int *atri);
		void m2QuickSort2(mSt **vet,int inicio,int fim,int *trocas,int *comp,int *atri);
		void m2Heapify(mSt **vet,int tam,int pos,int *trocas,int *comp,int *atri);
		void m2HeapSort(mSt **vet,int tam,int *trocas,int *comp,int *atri);
//	#else
	/*	typedef struct myStruct mSt;
		extern int m1SelectionSort(mSt **vet,int tam,int col);
		extern int m1InsertionSort(mSt **vet,int tam,int col);
		extern int m1ShellSort(mSt **vet,int tam,int col);
		extern void m1Merge(mSt **vet,int comeco,int meio,int fim,int col);
		extern void m1MergeSort(mSt **vet,int esq,int dir,int col);
		extern int m1Particiona1(mSt **vet,int beg,int end,int col);
		extern int m1Particiona2(mSt **vet,int beg,int end,int col);
		//extern int m1Particiona3(mSt *vet,int beg,int end,int col);
		//extern char m1getMediana(mSt *vet,int beg,int end,int col);
		extern void m1QuickSort1(mSt **vet,int inicio,int fim,int col);
		extern void m1QuickSort2(mSt **vet,int inicio,int fim,int col);
		//extern void m1QuickSort3(mSt *vet,int inicio,int fim,int col);
		extern void m1Heapify(mSt **vet,int tam,int pos,int col);
		extern void m1HeapSort(mSt **vet,int tam,int col);
		extern mSt **m1CountingSort(mSt **vet,int tam,int range,int col);
		*/
//	#endif

//#endif
