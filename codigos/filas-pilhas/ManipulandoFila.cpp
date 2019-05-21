#include <stdlib.h>
#include "queue.h"
#include <stdio.h>

int organizaFila1(Queue *q) // bota o primeiro elemento da fila na primeira posiçao do vetor
{
	int i,ant;
	void *aux;

	if(q!=NULL){
		if(q->nelm>0){
			if(q->nelm<q->tam){	
				while(q->beg!=0){
					aux=q->vet[q->end];
					i=q->beg;
					while(i!=q->end){
						if(i==0)
							ant=q->tam-1;
						else
							ant=i-1;
						q->vet[ant]=q->vet[i];
						if(i==q->tam-1)
							i=0;
						else
							i++;
					}
					if(i==0){
						q->vet[q->tam-1]=aux;
					}
					else
						q->vet[i-1]=aux;

					q->beg--;
					if(q->end==0)
                        q->end=q->tam-1;       
                    else
                        q->end--;
				}
				return 1;
			}
		}
	}
	return 0;
}

int organizaFila2(Queue *q) //bota o ultimo elemento da fila na ultima posição do vetor
{
	int i,ant;
	void *aux;
	if(q!=NULL){
		if(q->nelm>0){
			if(q->nelm<q->tam){
				while(q->end!=q->tam-1){
					aux=q->vet[q->beg];
					i=q->end;
					while(i!=q->beg){
						if(i==q->tam-1)
							ant=0;
						else 
							ant=i+1;
						q->vet[ant]=q->vet[i];
						if(i==0)
							i=q->tam-1;
						else
							i--;
					}
					if(i==q->tam-1)
						q->vet[0]=aux;
					else
						q->vet[i+1]=aux;
					
					q->end++;
					if(q->beg==q->tam-1)
						q->beg=0;
					else
						q->beg++;
				}
				return 1;
			}
		}
	}
	return 0;
}

int PuneFirst(Queue *q)
{
	int i,j,k;
	void *aux;
	if(q!=NULL){
		if(q->nelm>0){
			i=q->nelm;//qnt de elementos q vai ter q andar
			k=q->beg;// variaveis pra andar os elementos pra frente
			j=q->beg;
			aux=q->vet[q->beg];//guarda o primeiro element que sera punido
			while(i!=1){
				if(k==q->tam-1)
					k=0;
				else
					k++;
				q->vet[j]=q->vet[k];
				if(j==q->tam-1)
					j=0;
				else
					j++;
				i--;
			}
			q->vet[j]=aux;
			return 1;
		}
	}
	return 0;
}

int PromoveLast(Queue *q)
{
	int i,j,p;
	void *aux;

	if(q!=NULL){
		if(q->nelm>0){
			aux=q->vet[q->end];
			i=q->nelm;
			p=q->end;
			j=q->end;
			while(i!=1){
				if(p==0)
					p=q->tam-1;
				else
					p--;
				q->vet[j]=q->vet[p];
				if(j==0)
					j=q->tam-1;
				else
					j--;
				i--;
			}
			q->vet[j]=aux;
			return 1;
		}
	}
	return 0;										
}


void main(void)
{
	Queue *q=NULL;
	void *aux;
	int teste,*pt,i;
	q=qCreate(8);
	if(q!=NULL)
	{
		for(i=0;i<8;i++){
			pt=(int*)malloc(sizeof(int));
			*pt=i+1;
			if(teste=qEnqueue(q,(void*)pt)){
				printf("FUNFOU\n");
			}
		}
		for(i=0;i<3;i++){
			aux=qDequeue(q);
		}
		for(i=0;i<2;i++){
			pt=(int*)malloc(sizeof(int));
			*pt=i+5;
			if(teste=qEnqueue(q,(void*)pt))
				printf("FUNFOU/\n");
		}
		teste=organizaFila1(q);
		if(teste){
			for(i=0;i<q->nelm;i++){
				printf("%d\n",*(int*)q->vet[i]);
			}
			printf("QUERO PAU\n");
		}
		else
			printf("\nPIROCA GROSSA\n");
	}

}
