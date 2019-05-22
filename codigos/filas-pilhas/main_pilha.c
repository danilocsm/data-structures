#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define TRUE 1
#define FALSE 0

Stack *InverteTopoFundo(Stack *s)
{
	Stack *aux,*ret;
	void *aux2,*aux3;
	int teste;
	if(s!=NULL){
		if(s->top>=0){
			aux=stkCreate(((s->top)+1));
			ret=stkCreate(s->tam);
			if(aux!=NULL&&ret!=NULL){
				aux2=stkPop(s);
				teste=stkPush(ret,aux2);
				aux3=stkPop(s);
				while(aux3!=NULL){
					teste=stkPush(aux,aux3);
                    aux3=stkPop(s);
				}
                aux2=stkPop(aux);
                aux3=stkPop(aux);
                while(aux3!=NULL){
                    teste=stkPush(ret,aux3);
                    aux3=stkPop(aux);
                }
				teste=stkPush(ret,aux2);
                return ret;
            }
        }
    }
	return NULL;
}

int OrganizaParImp(Stack *s)
{
    void *aux2;
	void **aux;
	int *pt;
	int teste,i=0,tam=s->top+1;
	aux=(void**)malloc(sizeof(void*)*(tam));
	if(aux!=NULL){
		aux2=stkPop(s);
		while(aux2!=NULL){
            aux[i]=aux2;
            aux2=stkPop(s);
            i++;
		}
		for(i=0;i<tam;i++){
			pt=(int*)malloc(sizeof(int));
			pt=(int*)aux[i];
			if((*pt)%2==0){
				teste=stkPush(s,(void*)pt);
            }
		}
		for(i=0;i<tam;i++){
			pt=(int*)malloc(sizeof(int));
			pt=(int*)aux[i];
			if((*pt)%2!=0)
				teste=stkPush(s,(void*)pt);
		}
		return 1;
	}
    return 0;
}

int PuneTopo(Stack *s,int n)
{
    int i,k;
    void *aux;
    if(s!=NULL){
        if(s->top>-1){
            aux=s->vet[s->top];
            k=s->top;
            i=1;
            while(i<n){
                s->vet;
            }
        }
    }
}


int compara(void*a,void*b)
{
    int *pa,*pb;
    pa=(int*)a;
    pb=(int*)b;
    if(*pa>*pb)
        return TRUE;
    else
        return FALSE;
}

int removeTillKey(Stack *s,void *key,int(*compara)(void*,void*))
{
    if(s->top>-1){
        while(s->top>-1&&(compara(key,s->vet[s->top]))){
            s->top--;
        }
        return 1;
    }
    return 0;
}

void main(void)
{
    Stack *s;
    dStack *s2;
    int n=5,*aux,i,teste,*pt;
    s=stkCreate(n); //cria pilha unica
    if(s!=NULL){
        printf("FUNCIONOU----/%d/-----%d\n",s->top,s->tam);
    }
    else
        printf("VAI SE FUDER PT\n");
    s2=dstkCreate(n); //cria pilha dupla
    if(s2!=NULL){ // manipulando pilha dupla
        printf("FUNCIONOU-----/%d/-----/%d/-----/%d/\n",s2->top1,s2->top2,s2->tam);
        for(i=0;i<3;i++){
            aux=(int*)malloc(sizeof(int));
            *aux=(i+1)*i;
            teste=dstkPush1(s2,(void*)aux);
            if(teste)
            printf("INSERIU----%d\n",*aux);
        }
        for(i=0;i<2;i++){
            aux=(int*)malloc(sizeof(int));
            *aux=(i+1)*i;
            teste=dstkPush2(s2,(void*)aux);
            if(teste)
            printf("INSERIU----%d\n",*aux);
            else
                printf("NAO INSERIU\n");
        }

    }
    for(i=0;i<n;i++){
        aux=(int*)malloc(sizeof(int));
        *aux=(i+1);
        teste=stkPush(s,(void*)aux);
        if(teste)
            printf("INSERIU----%d\n",*aux);
    }

   s=InverteTopoFundo(s);

    if(s!=NULL){
        for(i=0;i<s->top+1;i++){
            printf("%d\n",*(int*)s->vet[i]);
        }
    }
    else
        printf("CAIO É PETISTA\n\n");
    printf("%d------TOPO\n",s->top);
    printf("\n\n");
    teste=OrganizaParImp(s);
    printf("%d------TOPO\n",s->top);
    if(teste){
        for(i=s->top;i>=0;i--){
            printf("%d\n",*(int*)s->vet[i]);
        }
    }
    else
        printf("CAIO PETISTA 2\n");
    pt=(int*)malloc(sizeof(int));
    *pt=6;
    teste=removeTillKey(s,(void*)pt,compara);
    printf("CHUPA MEU PAU PETISTAS----%d------%d\n",s->top,*pt);
    if(teste){
        for(i=s->top;i>=0;i--){
            printf("%d\n",*(int*)s->vet[i]);
        }
    }
    else
        printf("CAIO PETISTA 2\n");
}
