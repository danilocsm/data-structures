#define linkqueue_c
#include <stdlib.h>
#include "linkqueue.h"
#define TRUE 1
#define FALSE 0

LQueue *lqCreate()
{
	LQueue *lq;
	lq=(LQueue*)malloc(sizeof(LQueue));
	if(lq!=NULL){
		lq->first=NULL;
		lq->last=NULL;
		return lq;
	}
	return NULL;
}

int lqDestroy(LQueue *lq)
{
	if(lq!=NULL){
		if(lq->first==NULL){
			free(lq);
			return TRUE;
		}
	}
	return FALSE;
}

int lqEnqueue(LQueue *lq,void *elm)
{
	SLNode *new;
	if(lq!=NULL){
		new=(SLNode*)malloc(sizeof(SLNode));
		if(new!=NULL){
			new->data=elm;
			new->next=NULL;
			if(lq->first==NULL){
				lq->first=new;
			}
			else{
				lq->last->next=new;
			}
			lq->last=new;
			lq->last->next=l->first;
			return TRUE;
		}
	}
	return FALSE;
}

void *lqDequeue(LQueue *lq)
{
	void *aux;
	SLNode *curr;
	if(lq!=NULL){
		if(lq->first!=NULL){
			curr=lq->first;
			aux=aux2->data;
			if(curr->next==NULL){
				lq->first=NULL;
				lq->last=NULL;
			}
			else{
				lq->first=curr->next;
			}
			free(aux2);
			return aux;
		}
	}
	return NULL;
}
