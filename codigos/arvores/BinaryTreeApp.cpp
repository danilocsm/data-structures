#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#define TRUE 1
#define FALSE 0

int getValue(void *a)
{
	int *p;
	p=(int*)a;
	return *p;
}

int cmp(void *a,void *b)
{
	int *pa,*pb;
	pa=(int*)a;
	pb=(int*)b;
	if(*pa==*pb)
		return 0;
	else
		return 1;
}

int compara(void *a,void *b)	
{
	int *pa,*pb;
	pa=(int*)a;
	pb=(int*)b;

	if(*pa>*pb)
		return TRUE;
	else if(*pb>*pa)
		return FALSE;
}

void visit(void *data)
{
	int *p;
	p=(int*)data;
	printf("DATA: %d\n",*p);
}

int *aloca(){
	int *aux;
	aux=(int*)malloc(sizeof(int));
	return aux;
}

int main(void)
{
	TNode *root1,*root2;
	int *pi,num,i,maior=-1,stat=0;
	root1=btCreateEmpty();
	root2=btCreateEmpty();
	if(root1==NULL && root2==NULL){
		for(i=0;i<7;i++){
			printf("Valor 1:");
			scanf("%d",&num);
			pi=aloca();
			*pi=num;
			root1=bstInsert(root1,(void*)pi,&compara);
		}
		printf("Arvore (post-order)\n");
		btPosordem(root1,&visit);
		printf("Arvore (pre-order)\n");
		btPreordem(root1,&visit);
		printf("Arvore (in-order)\n");
		btSimetrica(root1,&visit);
		btBigger(root1,&getValue,&maior);
		printf("Maior Valor da Arvore= %d\n",maior);
		if(btIsBinarySearchTree(root1,&compara))
			printf("Arvore Binaria de Pesquisa\n");
		num=btContaNodesTillH(root1,2,0);
		printf("Nodes ate H --->%d \n",num);
		num=btAltura(root1);
		printf("Altura da arvore --->%d\n",num);
	}
	else
		printf("Afs,não funcionou\n");
	return 0;
}