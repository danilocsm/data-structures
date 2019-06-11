#include <stdio.h>
#include <stdlib.h>
#include "SimpleList.h"
#define TRUE 1
#define FALSE 0

int compara(void *a,void *b)
{
	int *pa,*pb;
	pa=(int*)a;
	pb=(int*)b;
	if((*pa)==(*pb))
		return TRUE;
	else
		return FALSE;
}

void sllImprime(SLList *l)
{
	int *aux;
	if(l!=NULL){
		aux=(int*)sllGetFirst(l);
		while(aux!=NULL){
			printf("%d---\n",*aux);
			aux=(int*)sllGetNext(l);
		}
	}
}


void main(void)
{
	SLList *l1,*l2,*l3;
	SLNode *aux;
	int i,*px,*key,rec,nodes;
	void *caio;
	l1=sllCreate();
	l2=sllCreate();
	if(l1!=NULL && l2!=NULL){
		for(i=0;i<10;i++){
			px=(int*)malloc(sizeof(int));
			*px=i+1;
			sllInsertLast(l1,(void*)px);
		}
		for(i=0;i<10;i++){
			px=(int*)malloc(sizeof(int));
			*px=i*2;
			sllInsertLast(l2,(void*)px);
		}
		printf("\n---LISTA 1---\n");
		sllImprime(l1);
		printf("\n---LISTA 2---\n");
		sllImprime(l2);
		sllReverse(l1);
		printf("\n---LISTA 1 REVERSE---\n");
		sllImprime(l1);
		printf("\nBUSCA:");
		scanf("%d",&rec);
		if(sllMoveNode(l1,(void*)&rec,2,&compara))
			sllImprime(l1);
		else
			printf("\nBUGOU?\n");
		
		if(sllRemoveImpar(l1)){
			printf("\n---LISTA 1---\n");
			sllImprime(l1);
		}
	}
	
}