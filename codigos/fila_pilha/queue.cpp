#define queue_c
#include <stdlib.h>
#include "queue.h"
#define TRUE 1
#define FALSE 0

Queue *qCreate(int max)
{
	Queue *q;
	q=(Queue*)malloc(sizeof(Queue));
	if(q!=NULL){
		if(max>0){
			q->vet=(void**)malloc(sizeof(void*)*max);
			if(q->vet!=NULL){
				q->tam=max;
				q->nelm=0;
				q->beg=0;
				q->end=-1;
				return q;
			}
		}
	}
	return NULL;
}

int qDestroy(Queue *q)
{
	if(q!=NULL){
		if(q->vet!=NULL){
			if(q->nelm==0){
				free(q->vet);
				free(q);
				return TRUE;
			}
		}
	}
	return FALSE;
}

 int qEnqueue(Queue *q,void *key)
 {
 	if(q!=NULL){
 		if(q->vet!=NULL){
 			if(q->nelm<q->tam){
 				if(q->end<q->tam-1)
 					q->end++;
 				else
 					q->end=0;
 				q->vet[q->end]=key;
 				q->nelm++;
 				return TRUE;
 			}
 		}
 	}
 	return FALSE;
 }

void *qDequeue(Queue *q)
{	
	void *aux;
	if(q!=NULL){
		if(q->vet!=NULL){
			if(q->nelm>0){
				aux=q->vet[q->beg];
				if(q->beg<q->tam-1)
					q->beg++;
				else
					q->beg=0;
				q->nelm--;
				return aux;
			}
		}
	}
	return NULL;
}
