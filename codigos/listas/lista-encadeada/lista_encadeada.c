// Código que implementa uma simples lista encadeada.
// Funçõesimplementadas:
// 1 - Inserir no começo da lista
// 2 - Inserir no final da lista
// 3 - Inserir na posição i, passada como argumento
// 4 - Remover do começo da lista
// 5 - Remover do final da lista
// 6 - Remover da posição i, passada como argumento
// 7 - Imprimir todos os elementos da lista
// 8 - Deletar todos os elementos da lista
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct _carro
{
	char model[100],owner[100],marca[100];
	int ano,cor;
}carro;

typedef struct _Lista_ //Criando a variavel lista.
{
	carro cars;
	struct _Lista_ *prox;
}lista;

lista *cria(int year,int color,char mod[],char own[],char marc[]) // função que cria um nova celula com os dados e retorna para a lista
{
	lista *novo=NULL;
	novo=(lista*)malloc(1*sizeof(lista)); //aloca espaço para novo celula
	if(novo!=NULL)
	{	//insere os dados na celula
		strcpy(novo->cars.model,mod);
		strcpy(novo->cars.owner,own);
		strcpy(novo->cars.marca,marc);
		novo->cars.ano=year;
		novo->cars.cor=color;
		novo->prox=NULL;
		return novo;
	}
	return NULL;
}

void removeFim(lista **cab) // remove uma celula do fim da lista
{
	lista *ultimo= *cab;
	lista *penultimo=ultimo->prox;
	if(ultimo==NULL)
	{
		printf("LISTA VAZIA.\n");
	}
	else
	{
		while(ultimo->prox!=NULL) // verifica se chegou a ultima celula(sempre aponta para um endereço vazio)
		{
			penultimo=ultimo;
			ultimo=ultimo->prox;
		}
		free(ultimo); // apaga a ultima celula
		penultimo->prox=NULL; // faz a penultima celula apontar para um endereço vazio

	}
}

void insereComeco(lista **cab,int year,int color,char mod[],char own[],char marc[]) // insere nova celula no começo da lista
{
	lista *tmp= *cab;
	lista *novo=NULL;

	if(tmp==NULL)
	{
		*cab=cria(year,color,mod,own,marc);
	}
	else
	{
		novo=cria(year,color,mod,own,marc); // recebe os dados
		novo->prox=tmp;
		*cab=novo;
	}

}

void insereFim(lista **cab,int year,int color,char mod[],char own[],char marc[]) // insere nova celula no fim da lista
{
	lista *tmp= *cab;

	if(tmp==NULL)
	{
		*cab=cria(year,color,mod,own,marc);
	}
	else
	{
		while(tmp->prox!=NULL) // verifica se chegou à ultima celula
		{
			tmp=tmp->prox;
		}
		tmp->prox=cria(year,color,mod,own,marc); // faz nova celula receber os dados e apontar para endereço vazio

	}
}

void imprimirLista(lista *tmp) // imprime as celulas da lista com seus dados
{
	while(tmp!=NULL)
	{
		printf("Nome: %s",tmp->cars.model);
		printf("Proprietario: %s",tmp->cars.owner);
		printf("Marca: %s",tmp->cars.marca);
		printf("Ano: %d",tmp->cars.ano);
		printf("\nCor: %d\n",tmp->cars.cor);
		tmp=tmp->prox;
	}
}

void liberaLista(lista **cab) // apaga todas as celulas da lista
{
	lista *tmp= *cab;
	lista *aux;

	while(tmp!=NULL)
	{
		aux=*cab;
		*cab=tmp->prox;
		free(aux);
		tmp=tmp->prox;
	}
	*cab=NULL; // garante que a cabeça aponte para um endereço vazio

}
void searchNome(lista *cab,char busca[])
{
	char *aux;
	while(cab!=NULL)
	{
		aux=strstr(cab->cars.model,busca);
		if(aux!=NULL)
		{
			printf("Elemento Encontrado: %s",cab->cars.model);
			break;
		}
		else
		{
			cab=cab->prox;
		}
	}
	if(cab==NULL)
		printf("Elemento nao Encontrado.\n");
}

void removeCom(lista **cab) // remove celula do começo da lista
{
	lista *tmp= *cab, *aux;
	if(tmp!=NULL)
	{
		aux=*cab;
		*cab=tmp->prox; //faz a cabeça receber a proxima celula
		free(aux);
	}
}

void menu()
{
	printf("1-Inserir carro no começo.\n");
	printf("2-Inserir carro no final.\n");
	printf("3-Inserir em qualquer posiçao.\n");
	printf("4-Remover carro do começo.\n");
	printf("5-Remover carro do final.\n");
	printf("6-Remover dde qualquer posição.\n");
	printf("7-Mostrar lista completa.\n");
	printf("8-Buscar por nome.\n");
	printf("9-Deletar lista.\n");
}

void insere(lista **cab,int year,int color,char mod[],char own[],char marc[],int pos,int tam) // insere celula em qualquer posição da lista
{
	lista *atual= *cab ,*anterior=atual->prox;
	lista *novo=NULL;
	int i;

		for(i=1;i<pos;i++) // move ate a posição desejada
		{
			anterior=atual;
			atual=atual->prox;
		}
		novo=cria(year,color,mod,own,marc);
		anterior->prox=novo; // nova celula é colocada entre celula anterio e a celula atual
		novo->prox=atual;
}

void remover(lista **cab,int pos) // remove celula de qualquer posiçao da lista
{
	lista *atual=*cab,*anterior=atual->prox;
	int i;
	for(i=1;i<pos;i++) // move ate a posição desejada
	{
		anterior=atual;
		atual=atual->prox;
	}
	anterior->prox=atual->prox; //faz o anterior apontar para a celula posterior à atual
	free(atual);
}

int main()
{
	lista *node=NULL;
	char mod[20],own[20],marc[20],busca[20],ch;
	int pos,ano,cor,opt,tam=0;
	printf("INICIAR? Y-sim N-nao\n");
	ch=getchar();
	__fpurge(stdin);
	while(ch=='y'||ch=='Y')
	{
		menu();
		scanf("%d",&opt);
                __fpurge(stdin);
                if(opt >= 1 && opt <= 3 ){
		      __fpurge(stdin);
                      printf("MODELO: ");
		      fgets(mod,20,stdin);
		      __fpurge(stdin);
		      printf("\nPROPRIETARIO: ");
		      fgets(own,20,stdin);
		      __fpurge(stdin);
		      printf("\nMARCA: ");
		      fgets(marc,20,stdin);
		      __fpurge(stdin);
		      printf("\nANO: ");
		      scanf("%d",&ano);
		      printf("\nCOR: ");
		      scanf("%d",&cor);
		      __fpurge(stdin);
                }
		switch(opt)
		{
			case 1:
			        insereComeco(&node,ano,cor,mod,own,marc);
				tam++;
				printf("%d\n",tam);
				break;
			case 2:
				insereFim(&node,ano,cor,mod,own,marc);
				tam++;
				printf("%d\n",tam);
				break;
			case 3:
				printf("\nDigite a posiçao para inserir: ");
				scanf("%d",&pos);
				__fpurge(stdin);
				insere(&node,ano,cor,mod,own,marc,pos,tam);
				tam++;
				break;
			case 4:
				removeCom(&node);
				tam--;
				break;
			case 5:
				removeFim(&node);
				tam--;
				break;
			case 6:
				printf("\nDigite posiçao pra remover: ");
				scanf("%d",&pos);
                                __fpurge(stdin);
				remover(&node,pos);
				break;
			case 7:
				imprimirLista(node);
				break;
			case 8:
				printf("\nDigite o nome do carro: ");
				fgets(busca,20,stdin);
				__fpurge(stdin);
				searchNome(node,busca);
				break;
			case 9:
				liberaLista(&node);
				tam=0;
				break;
			default:
				printf("Opçao invalida.\n");
				break;
		}
		__fpurge(stdin);
		printf("Continuar? Y-SIM N-NAO.\n");
		ch=getchar();
		__fpurge(stdin);
	}
	if(ch=='N'||ch=='n')
	{
		liberaLista(&node);
	}
}
