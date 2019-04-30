#include <stdio.h>
#include <stdlib.h>
#include "cDoubleList.h"
#define TRUE 1
#define FALSE 0

int compara(void *a,void*b)
{
	int *pa,*pb;
	pa=(int*)a;
	pb=(int*)b;
	if(*pa == *pb)
		return TRUE;
	else
		return FALSE;
}

void ImprimeCLL(DLList *l)
{
	int *aux;
	if(l!=NULL){
		aux=(int*)cdllGetFirst(l);
		while(aux!=NULL){
			printf("DATA--->%d\n",*aux);
			aux=(int*)cdllGetNext(l);
		}
	}
}

int DestroyList(DLList *l)
{
	void *destroy;
	if(l!=NULL){
		destroy=cdllRemoveFirst(l);
		while(destroy!=NULL){
			free(destroy);
			destroy=cdllRemoveFirst(l);
		}
		if(cdllDestroy(l))
			return TRUE;
	}
	return FALSE;
}

void main(void)
{
	int *pi,i,*key,*lixo;
	DLList *l;
	l=cdllCreate();
	if(l!=NULL){
		for(i=0;i<5;i++){
			pi=(int*)malloc(sizeof(int));
			*pi=i+1;
			if(cdllInsertLast(l,(void*)pi))
				printf("INSERIDO\n");
		}
		ImprimeCLL(l);
		for(i=0;i<5;i++){
			pi=(int*)malloc(sizeof(int));
			*pi=i+6;
			if(cdllInsertFirst(l,(void*)pi))
				printf("INSERIDO\n");
		}
		printf("PIROCAS\n");
		ImprimeCLL(l);
		printf("\nBUSCA:");
		scanf("%d",&i);
		if(cdllRemoveCloser(l,(void*)&i,&compara))
			ImprimeCLL(l);
		printf("\n-------\n");
		if(cdllReverse(l))
			ImprimeCLL(l);
		else
			printf("AFF\n");
		if(DestroyList(l)){
			printf("\nLISTA DESTRUIDA\n");
			l=NULL;
		}
	}
}