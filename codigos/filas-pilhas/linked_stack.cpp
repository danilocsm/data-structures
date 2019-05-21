#include <stdio.h>
#include <stdlib.h>
#include "linkstk.h"

void imprimePilha(LStack *ls)
{
	SLNode *aux=ls->top;
	int *px;
	while(aux!=NULL){
		px=(int*)aux->data;
		printf("<----%d---->\n",*px);
		aux=aux->next;
	}
}


void main(void)
{	
	int i,*px;
	LStack *ls;
	ls=lsCreate();
	if(ls!=NULL){
		printf("FUNCIOUNOU\n");
		for(i=1;i<11;i++){
			px=(int*)malloc(sizeof(int));
			*px=i+10;
			if(lsPush(ls,(void*)px))
				printf("ENTROU---->%d\n",i+10);
		}
		for(i=0;i<3;i++)
			px=lsPop(ls);
		imprimePilha(ls);
	}
	else 
		exit(1);
}