#include <stdio.h>
#include <stdlib.h>
#include "DoubleList.c"
#include "cDoubleList.c"
#define TRUE 1
#define FALSE 0

int compara(void *a,void *b)
{
	int *pa,*pb;
	pa=(int*)a;
	pb=(int*)b;
	if(*pa==*pb)
		return TRUE;
	return FALSE;
}

void ImprimeCDLL(DLList *l)
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

void main(void)
{
	int *pi,*key,i;
	DLList *l;
	l=dllCreate();
	if(l!=NULL){
		printf("PREENCHENDO LISTA\n");
		for(i=0;i<5;i++){
			pi=(int*)malloc(sizeof(int));
			*pi=i+1;
			if(cdllInsertLast(l,(void*)pi))
				printf("Inserido\n");
		}
		ImprimeCDLL(l);
	}
}