#include <stdio.h>
#include <stdlib.h>
#include "SimpleList.h"
#define TRUE 1
#define FALSE 0

int compara(void *a,void *b)
{
	
}

void main(void)
{
	SLList *l;
	SLNode *aux;
	int i,*px;
	l=sllCreate();
	if(l!=NULL){
		for(i=0;i<10;i++){
			px=(int*)malloc(sizeo(int));
			*px=i+1;
			sllInsertFirst(l,(void*)px);
		}
		aux=l->first;
		while(aux!=NULL){
			px=(int*)aux->data;
			aux=aux->next;
			printf("%d----\n",*px);

		}
		printf("\n------\n");
		aux=l->first;
		while(aux!=NULL){
			px=(int*)aux->data;
			aux=aux->next;
			printf("%d----\n",*px);

		}
		printf("\n------\n");
		px=(int*)sllRemoveLast(l);
		printf("%d----\n",*px);
		px=sllRemove(l,3);
		printf("\n------\n");
		printf("%d----\n",*px);
		sllInsert(l,(void*)px,5);
		printf("\n------\n");
		aux=l->first;
		while(aux!=NULL){
			px=(int*)aux->data;
			aux=aux->next;
			printf("%d----\n",*px);

		}

	}
}