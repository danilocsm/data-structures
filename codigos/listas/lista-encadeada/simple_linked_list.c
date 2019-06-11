#define SimpleList_c
#include <stdlib.h>
#include "SimpleList.h"
#define TRUE 1
#define FALSE 0


SLList *sllCreate()
{
	SLList *l;
	l=(SLList*)malloc(sizeof(SLList));
	if(l!=NULL){
		l->first=NULL;
		l->curr=NULL;
		return l;
	}
	return NULL;
}

int sllDestroy(SLList *l)
{
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
				free(destroy->data);
				free(destroy);
			}
			free(l);
			return TRUE;
		}
	}
	return FALSE;
}

int sllInsertFirst(SLList *l,void *elm) //stkPush()/ qEnqueue()
{
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

int sllInsertLast(SLList *l,void *elm) // qEnqueue()
{
	SLNode *new,*aux;

	if(l!=NULL){
		new=(SLNode*)malloc(sizeof(SLNode));
		if(new!=NULL){
			aux=l->first;
			if(aux!=NULL){
				while(aux->next!=NULL){
					aux=aux->next;
				}
				new->data=elm;
				new->next=NULL;
				aux->next=new;
				return TRUE;
			}
			else{
				sllInsertFirst(l,elm);
				return TRUE;
			}
		}
	}
	return FALSE;
}

int sllInsertKesimo(SLList *l,void *elm,int k)
{
	int i=1;
	SLNode *prox,*atual,*new;
	if(l!=NULL){
		if(l->first==NULL){
			new=(SLNode*)malloc(sizeof(SLNode));
			if(new!=NULL){
				new->data=elm;
				new->next=l->first;
				l->first=new;
				return TRUE;
			}
		}
		else{
			atual=l->first;
			prox=atual->next;
			while(prox!=NULL&&i<k){
				atual=prox;
				prox=atual->next;
				i++;
			}
			new=(SLNode*)malloc(sizeof(SLNode));
			if(new!=NULL){
				new->data=elm;
				new->next=prox;
				atual->next=new;
				return TRUE;
			}
		}
	}
	return FALSE;
}

int sllInsertBeforeSpec(SLList *l,void *elm,void *key,int(*cmp)(void*,void*))
{
	SLNode *new,*spec,*prev;
	int stat;
	if(l!=NULL){
		new=(SLNode*)malloc(sizeof(SLNode));
		if(new!=NULL){
			spec=l->first;
			prev=NULL;
			if(spec==NULL){
				new->data=elm;
				new->next=spec;
				l->first=new;
				return TRUE;
			}
			else{
				stat=cmp(key,spec->data);
				while((spec->next!=NULL)&&(stat!=TRUE)){
					prev=spec;
					spec=spec->next;
					stat=cmp(key,spec->data);
				}
				if(stat==TRUE){
					if(prev==NULL){
						new->data=elm;
						new->next=spec;
						l->first=new;
						return TRUE;
					}
					else{
						new->data=elm;
						new->next=spec;
						prev->next=new;
						return TRUE;
					}
				}

			}
		}
	}
	return FALSE;
}

int sllInsertAfterSpec(SLList *l,void* elm,void *key,int(*cmp)(void*,void*))
{
	SLNode *new,*spec,*prox;
	int stat;
	if(l!=NULL){
		new=(SLNode*)malloc(sizeof(SLNode));
		if(new!=NULL){
			spec=l->first;
			if(spec==NULL){
				new->data=elm;
				new->next=spec;
				l->first=new;
				return TRUE;
			}
			else{
				stat=cmp(key,spec->data);
				prox=spec->next;
				while((prox!=NULL)&&(stat!=TRUE)){
					spec=prox;
					prox=spec->next;
					stat=cmp(key,spec->data);
				}
				if(stat==TRUE){
					new->data=elm;
					new->next=prox;
					spec->next=new;
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

void *sllRemoveFirst(SLList *l) //stkPop()/ qDequeue()
{
	void *aux;
	SLNode *aux2;
	if(l!=NULL){
		if(l->first!=NULL){
			aux=l->first->data;
			aux2=l->first;
			l->first=aux2->next;
			free(aux2);
			return aux;
		}
	}
	return NULL;
}

void *sllRemoveLast(SLList *l) // qDequeue()
{
	void *aux;
	SLNode *aux2,*penultimo,*ultimo;
	if(l!=NULL){
		if(l->first!=NULL){
			ultimo=l->first;
			penultimo=ultimo->next;
			while(ultimo->next!=NULL){
				penultimo=ultimo;
				ultimo=ultimo->next;
			}
			aux2=ultimo;
			aux=ultimo->data;
			penultimo->next=NULL;
			free(aux2);
			return aux;
		}
	}
	return NULL;
}

void *sllRemoveKesimo(SLList *l,int k)
{
	int i=1;
	void *dados;
	SLNode *aux,*prev,*actual;
	if(l!=NULL){
		if(l->first!=NULL){
			actual=l->first;
			prev=NULL;
			while(actual->next!=NULL&&i<k){
				prev=actual;
				actual=actual->next;
				i++;
			}
			if(prev==NULL){
				dados=actual->data;
				aux=actual;
				l->first=actual->next;
				free(aux);
				return dados;
			}
			else{
				dados=actual->data;
				aux=actual;
				prev->next=actual->next;
				free(aux);
				return dados;
			}

		}
	}
	return NULL;
}

void *sllRemoveSpec(SLList *l,void *key,int(*cmp)(void*,void*))
{
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

int sllSearch(SLList *l,void *key,int(*cmp)(void*,void*))
{
	SLNode *curr;
	int stat;
	if(l!=NULL){
		if(l->first!=NULL){
			curr=l->first;
			stat=cmp(curr->data,key);
			while(curr->next!=NULL && stat!=TRUE){
				curr=curr->next;
				stat=cmp(curr->data,key);
			}
			if(stat){
				return TRUE;
			}
		}
	}
	return FALSE;
}

int contaNodes(SLList *l)
{
	int cont=0;
	SLNode *curr;
	if(l!=NULL){
		if(l->first==NULL)
			return cont;
		else{
			curr=l->first;
			while(curr!=NULL){
				curr=curr->next;
				cont++;
			}
			return cont;
		}
	}
	return cont;
}

void *sllGetFirst(SLList *l)
{
	if(l!=NULL){
		if(l->first!=NULL){
			l->curr=l->first;
			return l->curr->data;
		}
	}
	return NULL;
}

void *sllGetNext(SLList *l)
{
	if(l!=NULL){
		if(l->first!=NULL){
			if(l->curr!=NULL){
				l->curr=l->curr->next;
				if(l->curr!=NULL)
					return l->curr->data;
			}
		}
	}
	return NULL;
}


int sllCompList(SLList *l1,SLList *l2)
{
	int tam1,tam2;
	if(l1!=NULL && l2!=NULL){
		tam1=contaNodes(l1);
		tam2=contaNodes(l2);
		if(tam1==tam2)
			return 0;
		else if(tam1>tam2)
			return 1;
		else
			return -1;
	}
	return -2;
}

SLList *sllComuns(SLList *l1,SLList *l2,int(*cmp)(void*,void*))
{
	SLList *ret;
	SLNode *curr1,*curr2,*prev1,*aux;
	ret=sllCreate();
	if(ret!=NULL){
		if(l1!=NULL && l2!=NULL){
			curr1=l1->first;
			prev1=NULL;
			while(curr1!=NULL){
				curr2=l2->first;
				while(curr2!=NULL){
					if(cmp(curr1->data,curr2->data)){
						aux=curr1;
						if(prev1==NULL){
							curr1=curr1->next;
							l1->first=curr1;
						}
						else{
							prev1->next=curr1->next;
							curr1=curr1->next;
						}
						aux->next=ret->first;
						ret->first=aux;
						break;
					}
					else
						curr2=curr2->next;
				}
				if(curr2==NULL){
					prev1=curr1;
					curr1=curr1->next;
				}
			}
			return ret;
		}
	}
	return NULL;
}

int sllReverse(SLList *l)
{
	SLNode *last,*curr,*prev,*newfirst;
	if(l!=NULL){
		if(l->first!=NULL){
			if(l->first->next!=NULL){
				last=NULL;
				while(l->first->next!=NULL){
					curr=l->first;
					prev=NULL;
					while(curr->next!=last){
						prev=curr;
						curr=curr->next;
					}
					if(last==NULL)
						newfirst=curr;
					curr->next=prev;
					last=curr;
				}
				l->first=newfirst;
				return TRUE;
			}
		}
	}
	return FALSE;
}

int sllMoveNode(SLList *l,void *key,int n,int(*cmp)(void*,void*))
{
	SLNode *curr,*prev,*move;
	int stat,i=0;
	if(l!=NULL){
		if(l->first!=NULL){
			if(l->first->next!=NULL){
				curr=l->first;
				prev=NULL;
				stat=cmp(curr->data,key);
				while(curr->next!=NULL && stat!=TRUE){
					prev=curr;
					curr=curr->next;
					stat=cmp(curr->data,key);
				}
				if(stat && curr->next!=NULL){
					move=curr;
					if(prev!=NULL)
						prev->next=curr->next;
					while(i<n && curr->next!=NULL){
						curr=curr->next;
						i++;
					}
					if(i==n){
						if(move==l->first)
							l->first=move->next;
						move->next=curr->next;
						curr->next=move;
						return TRUE;
					}
				}
			}
		}
	}
	return FALSE;
}

int sllBind(SLList *l1,SLList *l2)
{
	SLNode *last;
	if(l1!=NULL && l2!=NULL){
		if(l1->first!=NULL && l2->first!=NULL){
			last=l1->first;
			while(last->next!=NULL)
				last=last->next;
			last->next=l2->first;
			l2->first=NULL;
			return TRUE;
		}
	}
	return FALSE;
}

int sllRemoveImpar(SLList *l)
{
	SLNode *curr,*prev,*destroy;
	int count=1;
	if(l!=NULL){
		if(l->first!=NULL){
			curr=l->first;
			prev=NULL;
			while(curr!=NULL){
				if(count%2==1){
					if(prev==NULL){
						l->first=curr->next;
					}
					else{
						prev->next=curr->next;
					}
					destroy=curr;
					curr=curr->next;
					free(destroy->data);
					free(destroy);
				}
				else{
					prev=curr;
					curr=curr->next;
				}
				count++;
			}
			return TRUE;
		}
	}
	return FALSE;
}
