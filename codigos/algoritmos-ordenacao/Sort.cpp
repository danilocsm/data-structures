#define Sort_c
#include <stdio.h>
#include "Sort.h"
#define TRUE 1
#define FALSE 0


int SelectionSort(int *vet,int tam)
{
	int i,j,key,min;
	if(vet!=NULL){
		for(i=0;i<tam-1;i++){
			min=i;
			for(j=i+1;j<tam;j++){
				if(vet[j]<vet[min])
					min=j;
			}
			key=vet[min];
			vet[min]=vet[i];
			vet[i]=key;
		}
		return TRUE;
	}
	return FALSE;
}

int InsertionSort(int *vet,int tam)
{
	int i,j;
	int key;

	if(vet!=NULL){
		for(i=1;i<tam;i++){
			key=vet[i];
			j=i-1;
			while(j>=0 && vet[j]>key){
				vet[j+1]=vet[j];
				j--;
			}
			vet[j+1]=key;
		}
		return TRUE;
	}
	return FALSE;
}

int ShellSort(int *vet,int tam)
{
	int h=1,temp,i,j;

	if(vet!=NULL){
		while(h<tam)
			h=(3*h)+1;

		while(h>0){
			h=(h-1)/3;
			for(i=h;i<tam;i++){
				temp=vet[i];
				j=i;
				while(j>h && vet[j-h]>temp){
					vet[j]=vet[j-h];
					j=j-h;
				}
				vet[j]=temp;
			}
		}
		return TRUE;
	}
	return FALSE;

}

void Merge(int *vet,int comemo,int meio,int fim)
{
	int com1 = comeco, com2 = meio+1, comAux = 0;
   	int vetAux[fim-comeco+1];
	while(com1<=meio && com2<=fim){
        if(vetor[com1] <= vetor[com2]){
            vetAux[comAux] = vetor[com1];
            com1++;
        }else{
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1<=meio){
        vetAux[comAux] = vetor[com1];
        comAux++;com1++;
    }

    while(com2<=fim){
        vetAux[comAux] = vetor[com2];
        comAux++;com2++;
    }

   for(comAux=comeco;comAux<=fim;comAux++){
        vetor[comAux] = vetAux[comAux-comeco];
    }
}



void MergeSort(int *vet,int esq,int dir)
{
	int meio;

	if(esq<dir){
		meio=(esq+dir)/2;

		MergeSort(vet,esq,meio);
		MergeSort(vet,meio+1,dir);
		Merge(vet,esq,meio,dir);
	}
}

int Particion1(int *vet,int beg,int end)
{
	int pivo=vet[beg];
	int i=beg+1,f=end;

	while(i<=f){
		if(vet[i]<=pivo)
			i++;
		else if(vet[f]>pivo)
			f--;
		else{
			int troca=vet[i];
			vet[i]=vet[f];
			vet[f]=troca;
			i++;
			f--;
		}
	}
	vet[beg]=vet[f];
	vet[f]=pivo;
	return f;
}

int Particiona2(int *vet,int beg,int end)
{
	int pivo=vet[end];
	int i=beg,f=end-1;

	while(i<=f){
		if(vet[i]<=pivo)
			i++;
		else if(vet[f]>pivo)
			f--;
		else{
			int troca=vet[i];
			vet[i]=vet[f];
			vet[f]=troca;
			i++;
			f--:
		}
	}
	vet[end]=vet[f];
	vet[f]=pivo;
	return f;
}

void QuickSort1(int *vet,int inicio,int fim)
{
	int posicaoPivo;			//pivo é o primeiro elementos
	if(vet!=NULL){
		if(inicio<fim){
			posicaoPivo=Particiona1(vet,inicio,fim);
			QuickSort(vet,inicio,posicaoPivo-1);
			QuickSort(vet,posicaoPivo+1,fim);
		}
	}
}

void QuickSort2(int *vet,int inicio,int fim)
{
	int posicaoPivo;			//pivo é o ultimo elemento
	if(vet!=NULL){
		if(inicio<fim){
			posicaoPivo=Particiona2(vet,inicio,fim);
			QuickSort(vet,inicio,posicaoPivo-1);
			QuickSort(vet,posicaoPivo+1,fim);
		}
	}
}

void Heapify(int *vet,int tam,int pos)
{
	int largest=pos;
	int left=2*pos+1;
	int right=2*pos+2;

	if(left<tam && vet[left]>vet[largest])
		largest=left;
	if(right<tam && vet[right]>vet[largest])
		largest=right;

	if(largest!=pos){
		int troca=vet[pos];
		vet[pos]=vet[largest];
		vet[largest]=troca;
		Heapify(vet,tam,largest);
	}
}

void HeapSort(int *vet,tam)
{
	int i;
	for(i=(tam/2)-1;i>=0;i--)
		Heapify(vet,tam,i);

	for(i=tam-1;i>=0;i--){
		int troca=vet[i];
		vet[i]=vet[0];
		vet[0]=troca;
		Heapify(vet,i,0);
	}
}

int *CountingSort(int *vet,int tam,int range)
{
	int count[range+1];
	int *aux;
	int i,j;

	aux=(int*)malloc(sizeof(int)*tam);

	for(i=0;i<range+1;i++)
		count[i]=0;
	for(i=0;i<tam;i++)
		count[vet[i]]++;

	i=0;
	j=0;
	while(j<range+1){
		if(count[i]!=0){
			aux[j]=i;
			count[i]--;
			j++;
		}else{
			i++;
		}
	}
	return aux;
}
