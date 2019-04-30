#include <stdio.h>
#include <stdlib.h>
#include "DoubleList.h"
#define TRUE 1
#define FALSE 0

int compara(void *a,void *b)
{
	int *pa,*pb;
	pa=(int*)a;
	pb=(int*)b;
	if(*pa==*pb)
		return TRUE;
	else
		return FALSE;
}

int *aloca()
{
	int *px=NULL;
	px=(int*)malloc(sizeof(int));
	if(px!=NULL)
		return px;
	return NULL;
}

void imprimeDLList(DLList *l)
{
	int *pi;
	if(l!=NULL){
		pi=(int*)dllGetFirst(l);
		while(pi!=NULL){
			printf("%d\n",*pi);
			pi=(int*)dllGetNext(l);
		}
	}
}

void main(void)
{
	int *px,*key,*aux,i,num;
	DLList *l1,*l2,*l3;
	l1=dllCreate();
	l2=dllCreate();
	l3=dllCreate();
	for(i=0;i<5;i++){
		px=aloca();
		printf("Inserir Elemento: ");
		scanf("%d",&num);
		*px=num;
		if(dllInsertLast(l1,(void*)px))
			printf("Inserido com sucesso\n");
	}
	imprimeDLList(l1);
	printf("<><><>><><>\n");
	for(i=0;i<2;i++){
		px=aloca();
		printf("Inserir Elemento: ");
		scanf("%d",&num);
		*px=num;
		if(dllInsertLast(l2,(void*)px))
			printf("Inserido com sucesso\n");
	}
	imprimeDLList(l2);
	dllComuns(l1,l2,l3,&compara);
	if(l3!=NULL){
		printf("\nLISTA 1\n");
		imprimeDLList(l1);
		printf("\nLISTA 2\n");
		imprimeDLList(l2);
		printf("\nLISTA 3\n");
		imprimeDLList(l3);

	}
	printf("<><><>><><>\n");
	if(dllBind(l1,l2))
		imprimeDLList(l1);
	printf("<><><>><><>\n");
	printf("\nBUSCA:");
	scanf("%d",&num);
	if(dllMoveNode(l1,(void*)&num,2,&compara))
		imprimeDLList(l1);
	printf("<><><>><><>\n");
	if(dllReverse(l1))
		imprimeDLList(l1);
}