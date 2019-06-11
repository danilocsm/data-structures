
#define Ordena1_c
#include <stdlib.h>
#include <string.h>
#include "Ordena1.h"
#define TRUE 1
#define FALSE 0

int m1SelectionSort(mSt **vet,int tam,int col,int *trocas,int *comp,int *atri)
{
	int i,j,min;
	mSt *troca;
	if(vet!=NULL){
		for(i=0;i<tam-1;i++){
			if(vet[i]!=NULL){
				min=i;
				(*atri)++;
				for(j=i+1;j<tam;j++){
					if(vet[j]!=NULL){
						(*comp)++;
						if((vet[j]->str[col])<(vet[min]->str[col]))
							min=j;
					}
				}
				troca=vet[min];
				vet[min]=vet[i];
				vet[i]=troca;
				(*atri)=(*atri)+3;
				(*trocas)++;
			}
		}
	}
	return TRUE;
}

int m1InsertionSort(mSt **vet,int tam,int col,int *trocas,int *comp,int *atri)
{
	int i,j;
	mSt *key;

	if(vet!=NULL){
		for(i=1;i<tam;i++){
			if(vet[i]!=NULL){
				key=vet[i];
				(*atri)++;
				j=i-1;
				while(j>=0 && (vet[j]->str[col])>(key->str[col])){
					(*comp)++;
					vet[j+1]=vet[j];
					(*atri)++;
					j--;
				}
				(*trocas)++;
				vet[j+1]=key;
			}
		}

	}
	return TRUE;
}

int m1ShellSort(mSt **vet,int tam,int col,int *trocas,int *comp,int *atri)
{
	int h=1,i,j;
	mSt *temp;
	if(vet!=NULL){
		while(h<tam){
			(*atri)++;
			h=(3*h)+1;
		}

		while(h>0){
			h=(h-1)/3;
			for(i=h;i<tam;i++){
				if(vet[i]!=NULL){
					temp=vet[i];
					(*atri)++;
					j=i;
					while(j>h && (vet[j-h]->str[col])>(temp->str[col])){
						(*comp)++;
						vet[j]=vet[j-h];
						(*atri)++;
						j=j-h;
					}
					(*trocas)++;
					vet[j]=temp;
				}
			}
		}
	}
	return TRUE;

}

void m1Merge(mSt **vet,int comeco,int meio,int fim,int col,int *trocas,int *comp,int *atri)
{
	int com1 = comeco, com2 = meio+1, comAux = 0;
   	mSt *vetAux[fim-comeco+1];
	while(com1<=meio && com2<=fim){
		  (*comp)++;
        if((vet[com1]->str[col]) <= (vet[com2]->str[col])){
			//	strcpy(vetAux[comAux],vet[com1]);
				vetAux[comAux] = vet[com1];
				(*atri)++;
            com1++;
        }else{
			//	strcpy(vetAux[comAux],vet[com2]);
				(*atri)++;
         	vetAux[comAux] = vet[com2];
            com2++;
        }
        comAux++;
    }

    while(com1<=meio){
		//strcpy(vetAux[comAux],vet[com1]);
		(*atri)++;
        vetAux[comAux] = vet[com1];
        comAux++;com1++;
    }

    while(com2<=fim){
		//strcpy(vetAux[comAux],vet[com2]);
		(*atri)++;
        vetAux[comAux] = vet[com2];
        comAux++;com2++;
    }

   for(comAux=comeco;comAux<=fim;comAux++){
	   //strcpy(vet[comAux],vetAux[comAux-comeco]);
			(*atri)++;
        vet[comAux] = vetAux[comAux-comeco];
    }
}

void m1MergeSort(mSt **vet,int esq,int dir,int col,int *trocas,int *comp,int *atri)
{
	int meio;

	if(esq<dir){
		meio=(esq+dir)/2;

		m1MergeSort(vet,esq,meio,col,trocas,comp,atri);
		m1MergeSort(vet,meio+1,dir,col,trocas,comp,atri);
		m1Merge(vet,esq,meio,dir,col,trocas,comp,atri);
	}
}

int m1Particiona1(mSt **vet,int beg,int end,int col,int *trocas,int *comp,int *atri)
{
	mSt *pivo=vet[beg];
	int i=beg+1,f=end;
	while(i<=f){
		(*comp)++;
		if((vet[i]->str[col])<=(pivo->str[col]))
			i++;
		else if((vet[f]->str[col])>(pivo->str[col]))
			f--;
		else{
			mSt *troca=vet[i];
			vet[i]=vet[f];
			vet[f]=troca;
			(*atri)=(*atri)+3;
			(*trocas)++;
			i++;
			f--;
		}
	}
	(*trocas)++;
	vet[beg]=vet[f];
	vet[f]=pivo;
	return f;
}

int m1Particiona2(mSt **vet,int beg,int end,int col,int *trocas,int *comp,int *atri)
{
	mSt *pivo=vet[end];
	int i=beg,f=end-1;
	while(i<=f){
		(*comp)++;
		if((vet[i]->str[col])<=(pivo->str[col]))
			i++;
		else if((vet[f]->str[col])>(pivo->str[col]))
			f--;
		else{
			mSt *troca=vet[i];
			vet[i]=vet[f];
			vet[f]=troca;
			(*trocas)++;
			(*atri)=(*atri)+3;
			i++;
			f--;
		}
	}
	vet[end]=vet[i];
	vet[i]=pivo;
	(*trocas)++;
	return i;
}

void m1QuickSort1(mSt **vet,int inicio,int fim,int col,int *trocas,int *comp,int *atri)
{
	int posicaoPivo;			//pivo é o primeiro elementos
	if(vet!=NULL){
		if(inicio<fim){
			posicaoPivo=m1Particiona1(vet,inicio,fim,col,trocas,comp,atri);
			m1QuickSort1(vet,inicio,posicaoPivo-1,col,trocas,comp,atri);
			m1QuickSort1(vet,posicaoPivo+1,fim,col,trocas,comp,atri);
		}
	}
}

void m1QuickSort2(mSt **vet,int inicio,int fim,int col,int *trocas,int *comp,int *atri)
{
	int posicaoPivo;			//pivo é o ultimo elemento
	if(vet!=NULL){
		if(inicio<fim){
			posicaoPivo=m1Particiona2(vet,inicio,fim,col,trocas,comp,atri);
			m1QuickSort2(vet,inicio,posicaoPivo-1,col,trocas,comp,atri);
			m1QuickSort2(vet,posicaoPivo+1,fim,col,trocas,comp,atri);
		}
	}
}

void m1Heapify(mSt **vet,int tam,int pos,int col,int *trocas,int *comp,int *atri)
{
	int largest=pos;
	int left=2*pos+1;
	int right=2*pos+2;
	(*comp)++;
	if(left<tam && (vet[left]->str[col])>(vet[largest]->str[col]))
		largest=left;
	(*comp)++;
	if(right<tam && (vet[right]->str[col])>(vet[largest]->str[col]))
		largest=right;
	(*atri)++;

	if(largest!=pos){
		mSt *troca=vet[pos];
		vet[pos]=vet[largest];
		vet[largest]=troca;
		(*trocas)++;
		(*atri)=(*atri)+3;
		m1Heapify(vet,tam,largest,col,trocas,comp,atri);
	}
}

void m1HeapSort(mSt **vet,int tam,int col,int *trocas,int *comp,int *atri)
{
	int i;
	for(i=(tam/2)-1;i>=0;i--)
		m1Heapify(vet,tam,i,col,trocas,comp,atri);

	for(i=tam-1;i>=0;i--){
		mSt *troca=vet[i];
		vet[i]=vet[0];
		vet[0]=troca;
		(*trocas)++;
		(*atri)=(*atri)+3;
		m1Heapify(vet,i,0,col,trocas,comp,atri);
	}
}

int m2SelectionSort(mSt **vet,int tam,int *trocas,int *comp,int *atri)
{
	int i,j,min;
	mSt *troca;
	if(vet!=NULL){
		for(i=0;i<tam-1;i++){
			if(vet[i]!=NULL){
				min=i;
				(*atri)++;
				for(j=i+1;j<tam;j++){
					if(vet[j]!=NULL){
						(*comp)++;
						if((vet[j]->cont)<(vet[min]->cont))
							min=j;
					}
				}
				troca=vet[min];
				vet[min]=vet[i];
				vet[i]=troca;
				(*atri)=(*atri)+3;
				(*trocas)++;
			}
		}
	}
	return TRUE;
}

int m2InsertionSort(mSt **vet,int tam,int *trocas,int *comp,int *atri)
{
	int i,j;
	mSt *key;

	if(vet!=NULL){
		for(i=1;i<tam;i++){
			if(vet[i]!=NULL){
				key=vet[i];
				(*atri)++;
				j=i-1;
				while(j>=0 && (vet[j]->cont)>(key->cont)){
					(*comp)++;
					vet[j+1]=vet[j];
					(*atri)++;
					j--;
				}
				(*trocas)++;
				vet[j+1]=key;
			}
		}

	}
	return TRUE;
}

int m2ShellSort(mSt **vet,int tam,int *trocas,int *comp,int *atri)
{
	int h=1,i,j;
	mSt *temp;
	if(vet!=NULL){
		while(h<tam){
			(*atri)++;
			h=(3*h)+1;
		}

		while(h>0){
			h=(h-1)/3;
			for(i=h;i<tam;i++){
				if(vet[i]!=NULL){
					temp=vet[i];
					(*atri)++;
					j=i;
					while(j>h && (vet[j-h]->cont)>(temp->cont)){
						(*comp)++;
						vet[j]=vet[j-h];
						(*atri)++;
						j=j-h;
					}
					(*trocas)++;
					vet[j]=temp;
				}
			}
		}
	}
	return TRUE;

}

void m2Merge(mSt **vet,int comeco,int meio,int fim,int *trocas,int *comp,int *atri)
{
	int com1 = comeco, com2 = meio+1, comAux = 0;
   	mSt *vetAux[fim-comeco+1];
	while(com1<=meio && com2<=fim){
		  (*comp)++;
        if((vet[com1]->cont) <= (vet[com2]->cont)){
			//	strcpy(vetAux[comAux],vet[com1]);
				vetAux[comAux] = vet[com1];
				(*atri)++;
            com1++;
        }else{
			//	strcpy(vetAux[comAux],vet[com2]);
				(*atri)++;
         	vetAux[comAux] = vet[com2];
            com2++;
        }
        comAux++;
    }

    while(com1<=meio){
		//strcpy(vetAux[comAux],vet[com1]);
		(*atri)++;
        vetAux[comAux] = vet[com1];
        comAux++;com1++;
    }

    while(com2<=fim){
		//strcpy(vetAux[comAux],vet[com2]);
		(*atri)++;
        vetAux[comAux] = vet[com2];
        comAux++;com2++;
    }

   for(comAux=comeco;comAux<=fim;comAux++){
	   //strcpy(vet[comAux],vetAux[comAux-comeco]);
			(*atri)++;
        vet[comAux] = vetAux[comAux-comeco];
    }
}

void m2MergeSort(mSt **vet,int esq,int dir,int *trocas,int *comp,int *atri)
{
	int meio;

	if(esq<dir){
		meio=(esq+dir)/2;

		m2MergeSort(vet,esq,meio,trocas,comp,atri);
		m2MergeSort(vet,meio+1,dir,trocas,comp,atri);
		m2Merge(vet,esq,meio,dir,trocas,comp,atri);
	}
}

int m2Particiona1(mSt **vet,int beg,int end,int *trocas,int *comp,int *atri)
{
	mSt *pivo=vet[beg];
	int i=beg+1,f=end;
	while(i<=f){
		(*comp)++;
		if((vet[i]->cont)<=(pivo->cont))
			i++;
		else if((vet[f]->cont)>(pivo->cont))
			f--;
		else{
			mSt *troca=vet[i];
			vet[i]=vet[f];
			vet[f]=troca;
			(*atri)=(*atri)+3;
			(*trocas)++;
			i++;
			f--;
		}
	}
	(*trocas)++;
	vet[beg]=vet[f];
	vet[f]=pivo;
	return f;
}

int m2Particiona2(mSt **vet,int beg,int end,int *trocas,int *comp,int *atri)
{
	mSt *pivo=vet[end];
	int i=beg,f=end-1;
	while(i<=f){
		(*comp)++;
		if((vet[i]->cont)<=(pivo->cont))
			i++;
		else if((vet[f]->cont)>(pivo->cont))
			f--;
		else{
			mSt *troca=vet[i];
			vet[i]=vet[f];
			vet[f]=troca;
			(*trocas)++;
			(*atri)=(*atri)+3;
			i++;
			f--;
		}
	}
	vet[end]=vet[i];
	vet[i]=pivo;
	(*trocas)++;
	return i;
}

void m2QuickSort1(mSt **vet,int inicio,int fim,int *trocas,int *comp,int *atri)
{
	int posicaoPivo;			//pivo é o primeiro elementos
	if(vet!=NULL){
		if(inicio<fim){
			posicaoPivo=m2Particiona1(vet,inicio,fim,trocas,comp,atri);
			m2QuickSort1(vet,inicio,posicaoPivo-1,trocas,comp,atri);
			m2QuickSort1(vet,posicaoPivo+1,fim,trocas,comp,atri);
		}
	}
}

void m2QuickSort2(mSt **vet,int inicio,int fim,int *trocas,int *comp,int *atri)
{
	int posicaoPivo;			//pivo é o ultimo elemento
	if(vet!=NULL){
		if(inicio<fim){
			posicaoPivo=m2Particiona2(vet,inicio,fim,trocas,comp,atri);
			m2QuickSort2(vet,inicio,posicaoPivo-1,trocas,comp,atri);
			m2QuickSort2(vet,posicaoPivo+1,fim,trocas,comp,atri);
		}
	}
}

void m2Heapify(mSt **vet,int tam,int pos,int *trocas,int *comp,int *atri)
{
	int largest=pos;
	int left=2*pos+1;
	int right=2*pos+2;
	(*comp)++;
	if(left<tam && (vet[left]->cont)>(vet[largest]->cont))
		largest=left;
	(*atri)++;
	(*comp)++;
	if(right<tam && (vet[right]->cont)>(vet[largest]->cont))
		largest=right;
	(*atri)++;

	if(largest!=pos){
		mSt *troca=vet[pos];
		vet[pos]=vet[largest];
		vet[largest]=troca;
		(*trocas)++;
		(*atri)=(*atri)+3;
		m2Heapify(vet,tam,largest,trocas,comp,atri);
	}
}

void m2HeapSort(mSt **vet,int tam,int *trocas,int *comp,int *atri)
{
	int i;
	for(i=(tam/2)-1;i>=0;i--)
		m2Heapify(vet,tam,i,trocas,comp,atri);

	for(i=tam-1;i>=0;i--){
		mSt *troca=vet[i];
		vet[i]=vet[0];
		vet[0]=troca;
		(*trocas)++;
		(*atri)=(*atri)+3;
		m2Heapify(vet,i,0,trocas,comp,atri);
	}
}
