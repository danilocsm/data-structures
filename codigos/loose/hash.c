#define hash_c
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#define TRUE 1
#define FALSE 0


SLList *sllCreate(){
	SLList *l;
	l=(SLList*)malloc(sizeof(SLList));
	if(l!=NULL){
		l->first=NULL;
		l->curr=NULL;
		return l;
	}
	return NULL;
}

SLList **createHashTable(int size){
	SLList **result;
	result=(SLList**)malloc(sizeof(SLList*)*size);
	if(result!=NULL){
		for(int i=0;i<size;i++){
			result[i]=sllCreate();
 			if(result[i]==NULL){
				for(int j=0;j<i;j++)
					free(result[i]);
					free(result);
					return NULL;
			}
		}
		return result;
	}
	return NULL;
}

int sllDestroy(SLList *l){
	SLNode *curr,*destroy;
	if(l!=NULL){
		if(l->first==NULL){
			free(l);
			return TRUE;
		}
		else{
			curr=l->first;
			while(curr!=NULL){
				destroy=curr;
				curr=curr->next;
				//free(destroy->data);
				free(destroy);
			}
			free(l);
			return TRUE;
		}
	}
	return FALSE;
}

int sllInsertFirst(SLList *l,void *elm){
	SLNode *new;
	if(l!=NULL){
		new=(SLNode*)malloc(sizeof(SLNode));
		if(new!=NULL){
			new->data=elm;
			new->next=l->first;
			l->first=new;
			return TRUE;
		}
	}
	return FALSE;
}

void *sllRemoveSpec(SLList *l,void *key,int(*cmp)(void*,void*)){
	void *aux;
	SLNode *spec,*prev;
	int stat;
	if(l!=NULL){
		if(l->first!=NULL){
			prev=NULL;
			spec=l->first;
			stat=cmp(key,spec->data);
			while(spec->next!=NULL&&!stat){
				prev=spec;
				spec=spec->next;
				stat=cmp(key,spec->data);
			}
			if(stat){
				if(prev==NULL){
					aux=spec->data;
					l->first=spec->next;
					free(spec);
					return aux;
				}
				else{
					aux=spec->data;
					prev->next=spec->next;
					free(spec);
					return aux;
				}
			}
		}
	}
	return NULL;
}

void* sllSearch(SLList *l,void *key,int(*cmp)(void*,void*),void*(*helpFunction)(void*),int flag)
{
	SLNode *curr;
	int stat;
	if(l!=NULL){
		if(l->first!=NULL){
			curr=l->first;
			stat=cmp(curr->data,key);
			while(curr->next!=NULL && stat!=0){
				curr=curr->next;
				stat=cmp(curr->data,key);
			}
			if(stat==0){
				if(flag==0){
					curr->data=helpFunction(curr->data);
				}
				return curr->data;
			}
		}
	}
	return NULL;
}

int hashFunction(int size,void *elm,char*(*getValue)(void*))
{
	   int i;
		 char *str;
		 unsigned int h;
		 str=getValue(elm);
		 h=str[0];
	   for (i = 1; str[i] != '\0'; i++)
	      h = ((h*256)+str[i]) % size;
		 h=h%size;
	   return h;
}

int hashInsert(SLList *list,void *elm,int(*cmp)(void*,void*),void*(helpFunction)(void*),int *distincts)
{
	int flag=0;
	void *aux;
	if(list!=NULL){
		if((aux=sllSearch(list,elm,cmp,helpFunction,flag))!=NULL)
			free(elm);
		else{
			sllInsertFirst(list,elm);
			(*distincts)++;
		}
		return TRUE;
	}
	return FALSE;
}

void printHash(SLList *list,void (*visit)(void*))
{
	SLNode *curr;
	if(list!=NULL){
		if(list->first!=NULL){
			curr=list->first;
			while(curr!=NULL){
				visit(curr->data);
				curr=curr->next;
			}
		}
	}
}
