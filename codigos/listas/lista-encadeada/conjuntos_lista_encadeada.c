#include <stdio.h>
#include <stdlib.h>
#include "SimpleList.h"
#include <stdio_ext.h>
#define TRUE 1
#define FALSE 0

int compara(void *a,void *b)
{
	int *pa,*pb;
	pa=(int*)a;
	pb=(int*)b;
	if(*pa == *pb)
		return TRUE;
	else
		return FALSE;
}

int uniaoConjuntos(SLList *A,SLList *B,SLList *C)  
{	
	void *dados;
	if(A!=NULL && B!=NULL && C!=NULL){
		dados=sllGetFirst(A);
		while(dados!=NULL){
			if(!sllSearch(C,dados,&compara))
				sllInsertLast(C,dados);
			dados=sllGetNext(A);
		}
		dados=sllGetFirst(B);
		while(dados!=NULL){
			if(!sllSearch(C,dados,&compara))
				sllInsertLast(C,dados);
			dados=sllGetNext(B);
		}
		return TRUE;	
	}
	return FALSE;
}

int interConjuntos(SLList *A,SLList *B,SLList *C,int(*cmp)(void*,void*))
{
	void *aux1,*aux2;
	if(A!=NULL && B!=NULL && C!=NULL){
		aux1=sllGetFirst(A);
		while(aux1!=NULL){
			aux2=sllGetFirst(B);
			while(aux2!=NULL){
				if(cmp(aux1,aux2)){
					if(!sllSearch(C,aux1,&compara))
						sllInsertLast(C,aux1);
					aux1=sllGetNext(A);
					break;
				}
				else
					aux2=sllGetNext(B);
			}
			if(aux2==NULL)
				aux1=sllGetNext(A);
		}
		return TRUE;	
	}
	return FALSE;
}

int diferConjuntos(SLList *A,SLList *B,SLList *C,int(*cmp)(void*,void*))
{
	void *aux1,*aux2;
	if(A!=NULL && B!=NULL && C!=NULL){
		aux1=sllGetFirst(A);
		while(aux1!=NULL){
			aux2=sllGetFirst(B);
			while(aux2!=NULL){
				if(cmp(aux1,aux2)){
					aux1=sllGetNext(A);
					break;
				}
				else{
					aux2=sllGetNext(B);
				}
			}
			if(aux2==NULL){
				if(sllSearch(C,aux1,&compara))
					sllInsertLast(C,aux1);
				aux1=sllGetNext(A);
			}
		}	
		return TRUE;
	}
	return FALSE;
}

int compleConjuntos(SLList *A,SLList *B,SLList *C,int(*cmp)(void*,void*))
{
	void *aux1,*aux2;
	if(A!=NULL && B!=NULL && C!=NULL){
		aux1=sllGetFirst(B);
		while(aux1!=NULL){
			aux2=sllGetFirst(A);
			while(aux2!=NULL){
				if(cmp(aux1,aux2)){
					aux1=sllGetNext(B);
					break;
				}
				else
					aux2=sllGetNext(A);
			}
			if(aux2==NULL){
				if(!sllSearch(C,aux1,&compara))
					sllInsertLast(C,aux1);
				aux1=sllGetNext(B);
			}
		}
		return TRUE;			
	}
	return FALSE;
}

int isContido(SLList *A,SLList *B,int(*cmp)(void*,void*))
{
	void *aux1,*aux2;
	int ocorre=1;
	if(A!=NULL && B!=NULL){
		if(A->first!=NULL && B->first!=NULL){
			aux1=sllGetFirst(A);
			while(aux1!=NULL && ocorre){
				aux2=sllGetFirst(B);
				while(aux2!=NULL){
					if(cmp(aux1,aux2)){
						aux1=sllGetNext(A);
						break;
					}
					else
						aux2=sllGetNext(B);
				}
				if(aux2==NULL)
					ocorre=0;
			}
			if(ocorre)
				return TRUE;
		}
	}
	return FALSE;
}

void menu()
{	
	printf("1-CRIAR CONJUNTOS\n");
	printf("2-INSERIR (N) ELEMENTOS NO CONJUNTO\n");
	printf("3-UNIAO DOIS CONJUNTOS\n");
	printf("4-INTERSEÇAO DOIS CONJUNTOS\n");
	printf("5-DIFERENÇA DOIS CONJUNTOS\n");
	printf("6-COMPLEMENTO DOIS CONJUNTOS\n");
	printf("7-ESTA CONTIDO\n");
	printf("8-LISTAR CONJUNTOS\n");
	printf("9-DESTRUIR CONJUNTOS\n");
	printf("0-SAIR\n");

}

int InsereElms(int n,SLList *l)
{	
	int i,*elm,aux;
	if(n>0){
		if(l!=NULL){
			for(i=0;i<n;i++){
				elm=(int*)malloc(sizeof(int));
				printf("ELEMENTO: ");
				scanf("%d",&aux);
				*elm=aux;
				__fpurge(stdin);
				if(!sllSearch(l,(void*)elm,&compara))
					sllInsertLast(l,(void*)elm);
				else{
					printf("Elemento ja foi inserido, insira outro\n");
					i--;
					free(elm);
				}
			}
			return TRUE;
		}
	}
	return FALSE;
}

void ListaConjs(SLList *A,SLList *B,SLList *C)
{
	int *aux1;
	if(A!=NULL && B!=NULL && C!=NULL){
		printf("<---CONJUNTO A--->\n");
		aux1=(int*)sllGetFirst(A);
		while(aux1!=NULL){
			printf("%d ",*aux1);
			aux1=(int*)sllGetNext(A);
		}
		printf("\n<---CONJUNTO B-->\n");
		aux1=(int*)sllGetFirst(B);
		while(aux1!=NULL){
			printf("%d ",*aux1);
			aux1=(int*)sllGetNext(B);
		}
		printf("\n<---CONJUNTO C--->\n");
		aux1=(int*)sllGetFirst(C);
		while(aux1!=NULL){
			printf("%d ",*aux1);
			aux1=(int*)sllGetNext(C);
		}
	}
	else
		printf("ERRO\n");
}

int DestroyConj(SLList *l)
{
	void *aux;
	if(l!=NULL){
		aux=sllRemoveFirst(l);
		while(aux!=NULL){
			aux=sllRemoveFirst(l);
		}
		if(sllDestroy(l))
			return TRUE;
	}
	return FALSE;
}

void main(void)
{
	SLList *A=NULL,*B=NULL,*C=NULL;
	int opt,estado=1,num;
	char ch;
	printf("CONJUNTOS NUMERICOS\n");
	while(estado==1){
		menu();
		printf("Digite Opçao: ");
		scanf("%d",&opt);
		__fpurge(stdin);
		system("clear");
		switch(opt){

			case 1:
				printf("QUAL CONJUNTO DESEJA CRIAR? A/B\n");
				scanf("%c",&ch);
				__fpurge(stdin);
				if(ch=='a' || ch=='A'){
					if(A==NULL){
						A=sllCreate();
						if(A!=NULL)
							printf("CONJUNTO CRIADO\n");
					}
				}
				else if(ch=='b' || ch=='B'){
					if(B==NULL){
						B=sllCreate();
						if(B!=NULL)
							printf("CONJUNTO CRIADO\n");
					}
				}
				else
					printf("CONJUNTO INVALIDO.\n");

				break;
			case 2:
				printf("QUAL CONJUNTO DESEJA INSERIR OS ELEMENTOS? A/B\n");
				scanf("%c",&ch);
				__fpurge(stdin);
				if(ch=='a' || ch=='A'){
					printf("QUANTOS ELEMENTOS?\n");
					scanf("%d",&num);
					__fpurge(stdin);
					if(InsereElms(num,A)){
						printf("ELEMENTOS INSERIDOS\n");
					}
					else
						printf("ERRO\n");
					system("clear");
				}
				else if(ch=='b' || ch=='B'){
					printf("QUANTOS ELEMENTOS?\n");
					scanf("%d",&num);
					__fpurge(stdin);
					if(InsereElms(num,B)){
						printf("ELEMENTOS INSERIDOS\n");
						system("clear");
					}
					else
						printf("ERRO\n");
					system("clear");
				}
				else
					printf("CONJUNTO INVALIDO\n");
				break;
			case 3:
				if(C==NULL){
					C=sllCreate();
					if(uniaoConjuntos(A,B,C))
						printf("SUCESSO\n");
					else
						printf("ERRO\n");
				}
				else
					printf("ERRO\n");
				break;
			case 4:
				if(C==NULL){
					C=sllCreate();
					if(interConjuntos(A,B,C,&compara))
						printf("SUCESSO\n");
					else
						printf("ERRO\n");
				}
				else
					printf("ERRO\n");
				break;
			case 5:
				if(C==NULL){
					C=sllCreate();
					if(diferConjuntos(A,B,C,&compara))
						printf("SUCESSO\n");
					else
						printf("ERRO\n");
				}
				else
					printf("ERRO\n");
				break;
			case 6:
				if(C==NULL){
					C=sllCreate();
					if(compleConjuntos(A,B,C,&compara))
						printf("SUCESSO\n");
					else
						printf("ERRO\n");
				}
				else
					printf("ERRO\n");
				break;
			case 7:
				if(isContido(A,B,&compara))
					printf("CONJUNTO A ESTA CONTIDO EM B\n");
				else
					printf("A NAO ESTA CONTIDO EM B\n");
				break;
			case 8:
				ListaConjs(A,B,C);
				printf("\n");
				break;
			case 9:
				printf("QUAL CONJUNTO DESEJA DESTRUIR? A/B/C?\n");
				scanf("%c",&ch);
				__fpurge(stdin);
				if(ch=='a' || ch=='A'){
					if(DestroyConj(A))
						printf("SUCESSO\n");
					A=NULL;
				}
				else if(ch=='b' || ch=='B'){
					if(DestroyConj(B))
						printf("SUCESSO\n");
					B=NULL;
				}
				else if(ch=='c' || ch=='C'){
					if(DestroyConj(C))
						printf("SUCESSO\n");
					C=NULL;
				}
				else
					printf("CONJUNTO INVALIDO\n");
				break;
			case 0:
				estado=0;
				DestroyConj(A);
				DestroyConj(B);
				DestroyConj(C);
				break;
			default:
				printf("OPÇAO INVALIDA\n");
				break;
		}
	}
}