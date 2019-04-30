#include <stdio.h>
#include <stdlib.h>
#include "DoubleList.h"
#include "ConjDllAux.h"
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

void mostraConjs(DLList *A,DLList *B)
{	

	if(A!=NULL && B!=NULL){
		printf("A = ");
		dllListaConj(A);
		printf("\nB = ");
		dllListaConj(B);
		printf("\n");
	}
}

void menu()
{	
	printf("1-INSERIR (N) ELEMENTOS NO CONJUNTO\n");
	printf("2-UNIAO DOIS CONJUNTOS\n");
	printf("3-INTERSEÇAO DOIS CONJUNTOS\n");
	printf("4-DIFERENÇA DOIS CONJUNTOS\n");
	printf("5-COMPLEMENTO DOIS CONJUNTOS\n");
	printf("6-ESTA CONTIDO\n");
	printf("7-LIMPAR CONJUNTOS\n");
	printf("0-SAIR\n");

}

void main(void)
{
	DLList *A=NULL,*B=NULL,*C=NULL;
	int opt,estado=1,num;
	char ch;
	A=dllCreate();
	B=dllCreate();
	printf("CONJUNTOS NUMERICOS\n");
	while(estado==1){
		mostraConjs(A,B);
		printf("\n\n\n\n");
		menu();
		printf("Digite Opçao: ");
		scanf("%d",&opt);
		__fpurge(stdin);
		system("clear");
		switch(opt){

			case 1:
				printf("QUAL CONJUNTO DESEJA INSERIR OS ELEMENTOS? A/B\n");
				scanf("%c",&ch);
				__fpurge(stdin);
				if(ch=='a' || ch=='A'){
					printf("QUANTOS ELEMENTOS?\n");
					scanf("%d",&num);
					__fpurge(stdin);
					if(dllInsereElms(num,A,compara)){
						printf("ELEMENTOS INSERIDOS,pressione qualquer tecla para continuar\n");
					}
					else
						printf("ERRO\n");
				}
				else if(ch=='b' || ch=='B'){
					printf("QUANTOS ELEMENTOS?\n");
					scanf("%d",&num);
					__fpurge(stdin);
					if(dllInsereElms(num,B,compara)){
						printf("ELEMENTOS INSERIDOS,pressione qualquer tecla para continuar\n");
					}
					else
						printf("ERRO\n");
				}
				else
					printf("CONJUNTO INVALIDO,aperte qualquer tecla para continuar\n");
				getchar();
				__fpurge(stdin);
				system("clear");
				break;
			case 2:
				if(C==NULL){
					printf("UNIAO C = A U B:\n");
					C=dllCreate();
					if(dlluniaoConjuntos(A,B,C,compara)){
						printf("C = ");
						dllListaConj(C);
						printf("\n");
						if(dllDestroy(C))
							C=NULL;
					}
					else
						printf("ERRO\n");
					printf("Pressione qualquer tecla para continuar.\n");
					getchar();
					__fpurge(stdin);
					system("clear");
				}
				break;
			case 3:
				if(C==NULL){
					printf("INTERSEÇAO C = A ꓵ B:\n");
					C=dllCreate();
					if(dllinterConjuntos(A,B,C,compara)){
						printf("C = ");
						dllListaConj(C);
						printf("\n");
						if(dllDestroy(C))
							C=NULL;
					}
					else
						printf("ERRO\n");
					printf("Pressione qualquer tecla para continuar.\n");
					getchar();
					__fpurge(stdin);
					system("clear");
				}
				break;
			case 4:
				if(C==NULL){
					printf("DIFERENÇA C = A - B:\n");
					C=dllCreate();
					if(dlldiferConjuntos(A,B,C,compara)){
						printf("C = ");
						dllListaConj(C);
						printf("\n");
						if(dllDestroy(C))
							C=NULL;
					}	
					else
						printf("ERRO\n");
					printf("Pressione qualquer tecla para continuar.\n");
					getchar();
					__fpurge(stdin);
					system("clear");
				}
				break;
			case 5:
				if(C==NULL){
					printf("COMPLEMENTO C = Comp(A,B)\n");
					C=dllCreate();
					if(dllcompleConjuntos(A,B,C,compara)){
						printf("C = ");
						dllListaConj(C);
						printf("\n");
						if(dllDestroy(C))
							C=NULL;
					}
					else
						printf("ERRO\n");
					printf("Pressione qualquer tecla para continuar.\n");
					getchar();
					__fpurge(stdin);
					system("clear");
				}
				break;
			case 6:
				if(dllisContido(A,B,compara))
					printf("A ᑕ B\n");
				else
					printf("A !ᑕ B\n");
				printf("Pressione qualquer tecla para continuar.\n");
				getchar();
				__fpurge(stdin);
				system("clear");
				break;
			case 7:
				if(dllLimpaConj(A) && dllLimpaConj(B))
					printf("Conjuntos esvaziados\n");
				else
					printf("ERRO\n");
				printf("Pressione qualquer tecla para continuar.\n");
				getchar();
				__fpurge(stdin);
				system("clear");
				break;
			case 0:
				estado=0;
				dllDestroy(A);
				dllDestroy(B);
				dllDestroy(C);
				break;
			default:
				printf("OPÇAO INVALIDA\n");
				break;
		}
	}
}