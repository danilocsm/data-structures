#define stk_c
#include <stdlib.h>
#include "stk.h"
#define TRUE 1
#define FALSE 0

Stack *stkCreate(int max)
{
	Stack *s;
	if(max>0){
		s=(Stack*)malloc(sizeof(Stack));
		if(s!=NULL){
			s->vet=(void**)malloc(sizeof(void*)*max);
			if(s->vet!=NULL){
				s->tam=max;
				s->top=-1;
				return s;
			}
			free(s);
		}
	}
	return NULL;
}

int stkDestroy(Stack *s)
{
	if(s!=NULL){
		if(s->vet!=NULL){
			if(s->top<0){
				free(s->vet);
				free(s);
				return TRUE;
			}
		}
	}
	return FALSE;
}

int stkPush(Stack *s,void *key)
{
	if(s!=NULL){
		if(s->vet!=NULL){
			if(s->top<s->tam-1){
				s->top++;
				s->vet[s->top]=key;
				return TRUE;
			}
		}
	}
	return FALSE;
}

void* stkPop(Stack *s)
{
    void *aux;
	if(s!=NULL){
		if(s->vet!=NULL){
			if(s->top>=0){
				aux=s->vet[s->top];
				s->top--;
				return aux;
			}
		}
	}
	return NULL;
}

int isEmpty(Stack *s)
{
	if(s!=NULL){
		if(s->vet!=NULL){
			if(s->top>=0)
				return TRUE;
		}
	}
	return FALSE;
}

