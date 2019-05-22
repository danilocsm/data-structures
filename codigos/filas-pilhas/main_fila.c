#include <stdio.h>
#include "fila.h"
#include <stdlib.h>


int PuneFirst(Queue *q)
{
	int i,j,p;
	void *aux;
	if(q!=NULL){
		if(q->nelm>0){
            aux=q->vet[q->beg];
			i=q->nelm;
			p=q->beg;
			j=q->beg;
			while(i!=1){
				if(p==q->tam-1)
					p=0;
				else
					p++;
				q->vet[j]=q->vet[p];
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
int PunenFirst(Queue *q,int n)
{
	int i,j,p;
	void *aux;
	if(q!=NULL){
		if(q->nelm>0){
            aux=q->vet[q->beg];
			i=n;
			p=q->beg;
			j=q->beg;
			while(i!=0){
				if(p==q->tam-1)
					p=0;
				else
					p++;
				q->vet[j]=q->vet[p];
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
			aux=q->vet[q->fim];
			i=q->nelm;
			p=q->fim;
			j=q->fim;
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

int PromovenLast(Queue *q,int n)
{
	int i,j,p;
	void *aux;

	if(q!=NULL){
		if(q->nelm>0){
			aux=q->vet[q->fim];
			i=n;
			p=q->fim;
			j=q->fim;
			while(i!=0){
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

int organizaFila2(Queue *q)
{
	int i,ant;
	void *aux;
	if(q!=NULL){
		if(q->nelm>0){
			if(q->nelm<q->tam){
				while(q->fim!=q->tam-1){
					aux=q->vet[q->beg];
					i=q->fim;
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

					q->fim++;
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

int RemoveImpares(Queue *q)
{
	int i,k=1,j=0,tam=(q->nelm)/2;
	void **aux;
	aux=(void**)malloc(sizeof(void*)*tam);
	if(aux!=NULL){
        if(q!=NULL){
            if(q->nelm>0){
                i=q->beg;
                while(i!=q->fim){
                    if(k%2==0){
                        aux[j]=q->vet[i];
                        j++;
                        q->nelm--;
                    }
                    k++;

                    if(i==q->tam-1)
                        i=0;
                    else
                        i++;
                }
                if(q->nelm%2==0){
                    aux[j]=q->vet[i];
                    q->nelm--;
                }
                for(i=0;i<tam;i++){
                    q->vet[i]=aux[i];
                }
                q->beg=0;
                q->fim=tam-1;
                return 1;
            }
        }
    }
	return 0;
}

void main(void)
{
    Queue *q=NULL;
	void *aux;
	int teste,*pt,i,k;
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
		for(i=0;i<q->nelm;i++)
            printf("%d ",*(int*)q->vet[i]);

        printf("\n----%d-----%d----%d----\n",q->beg,q->fim,q->nelm);
        teste=PuneFirst(q);
        if(teste){
            for(i=0;i<q->nelm;i++)
                printf("%d ",*(int*)q->vet[i]);
        }
        else
            printf("CAIO PAU NO CU\n");

        printf("\n----%d-----%d----%d----\n",q->beg,q->fim,q->nelm);
        teste=PromovenLast(q,3);
        if(teste){
            for(i=0;i<q->nelm;i++)
                printf("%d ",*(int*)q->vet[i]);
        }
        else
            printf("CAIO PAU NO CU\n");
		for(i=0;i<3;i++){
			aux=qDequeue(q);
		}
        for(i=0;i<1;i++){
			pt=(int*)malloc(sizeof(int));
			*pt=i+10;
			if(teste=qEnqueue(q,(void*)pt)){
				printf("FUNFOU\n");
			}
		}
        printf("\n----%d-----%d----%d----\n",q->beg,q->fim,q->nelm);
        teste=organizaFila2(q);
		printf("\n----%d-----%d----%d----\n",q->beg,q->fim,q->nelm);
        if(teste){
            for(i=q->fim;i>=q->beg;i--)
                printf("%d ",*(int*)q->vet[i]);
        }
        else
            printf("CAIO PAU NO CU\n");

		printf("\n----%d-----%d----%d----\n",q->beg,q->fim,q->nelm);
		teste=organizaFila(q);
        if(teste){
            for(i=0;i<q->nelm;i++)
                printf("%d ",*(int*)q->vet[i]);
            printf("\n----%d-----%d----%d----\n",q->beg,q->fim,q->nelm);
        }
        else
            printf("CAIO PAU NO CU\n");
        printf("REMOVE ELMS IMPARES------%d \n",q->nelm);
        teste=RemoveImpares(q);
        printf("------%d-----\n",q->nelm);
        if(teste){
            for(i=0;i<q->nelm;i++)
                printf("%d ",*(int*)q->vet[i]);
            printf("\n----%d-----%d----%d----\n",q->beg,q->fim,q->nelm);
        }
        else
            printf("CAIO PAU NO CU\n");
    }
}
