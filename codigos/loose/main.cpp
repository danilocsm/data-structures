#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"
#include "btAVL.h"
#include "hash.h"
#include "btRB.h"
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include "bTree.h"

typedef struct _index_{
  char str[20];
  int qnt[5];
}Index;

typedef struct _relevance{
  float r;
  char name[20];
}Relevance;

int minSize=4;
SLList **hashTable=NULL;      // variáveis referentes a cada TAD.
TNode *bstTree=NULL;
RBnode *rbTree=NULL;
AVLNode *avlTree=NULL;
Bnode *bTree;
FILE *fp;
int degree=2; //variável para receber o grau da árvore B
int qntDoc=0;
int opt;
int size=23; // variável para determinar o tamanho da tabela hash;
char *inputs[]={"entrada1.txt","entrada2.txt","entrada3.txt","entrada4.txt"}; //entradas para serem realizados os testes
int disTerms[4];
Relevance relevance[4];

void *helpFunction(void *a) // função que auxilia a contar as ocorrencias das palavras
{
  Index *pa=(Index*)(a);
  pa->qnt[qntDoc]=pa->qnt[qntDoc]+1;
  return (void*)pa;
}

char *getValue(void*a) // retorna uma string
{
  Index *pa=(Index*)a;
  return pa->str;
}

void createHash()
{
  hashTable=createHashTable(size);
  if(hashTable==NULL)
    exit(1);
}

int cmp(void *a,void *b)
{
  Index *pa=(Index*)a;
  char *pb=(char*)b;
  if((strcmp(pa->str,pb))==0)
    return 0;
  else if((strcmp(pa->str,pb))<0) //str1 vem antes da str2
    return -1;
  else //str1 vem depois da str2
    return 1;
}

void insertHash(Index *new,int *qnt) // inseri na tabela hash
{
  int h;
  int cont=0;
  if(hashTable!=NULL){
    h=hashFunction(size,(void*)new,&getValue);
    hashInsert(hashTable[h],(void*)new,&cmp,&helpFunction,&cont);
    *qnt=cont;
  }
}

void visit(void *a)// função para imprimir a palavra, qnt de ocorrencias e a identificação documento
{
   Index *pa=(Index*)a;
   //if(pa!=NULL)
   int i;
    printf("PALAVRA %s -----> ",pa->str);
    for(i=0;i<qntDoc;i++)
      printf(" %d %s ",pa->qnt[i],inputs[i]);
    printf("\n");
}


void showHashTable(int size)
{
  for(int i=0;i<size;i++){
    printf("LISTA[%d] ----> ",i+1);
    printHash(hashTable[i],&visit);
    printf("\n");
  }
}

void destroyHash()
{
  int i;
  if(hashTable!=NULL){
    for(i=0;i<qntDoc;i++){
      sllDestroy(hashTable[i]);
    }
    free(hashTable);
  }
}

void destroyBSTtree()
{
  if(bstTree!=NULL)
    bstTree=bstDeleteTree(bstTree,&cmp);
}

void destroyAVLtree()
{
  if(avlTree!=NULL)
    avlTree=avlDeleteTree(avlTree,&cmp);
}

void destroyRBtree()
{
  if(rbTree!=NULL)
    rbTree=rbDeleteTree(rbTree,&cmp);
}

/*void destroyBtree()
{

}*/

void destroyTADs()
{
  destroyHash();
  destroyBSTtree();
  destroyAVLtree();
  destroyRBtree();
  //destroyBtree();
}

void createBINARYTREE()
{
  Index *new;
  int i=0;
  char *rest;
  char *token;
  char buffer[1024];
  int qnt=0;
  while(i<4){
    strcpy(buffer,inputs[i]);
    fp=fopen(buffer,"r");
    if(fp==NULL){
      printf("ERRO AO TENTAR ABRIR ARQUIVO\n");
      destroyTADs();
      exit(1);
    }
    else{
      while((fgets(buffer,1024,fp))!=NULL){
        //puts(buffer);
        rest=buffer;
        while((token=strtok_r(rest," -;,.:!?\n\t",&rest))){
          token[0]=tolower(token[0]);
          if((strlen(token))>=minSize){
            new=(Index*)malloc(sizeof(Index));
            strcpy(new->str,token);
            new->qnt[i]=1;
            bstTree=bstInsert(bstTree,(void*)new,&cmp,&helpFunction,&qnt);
          }
        }
      }
    }
    disTerms[i]=qnt;
    qntDoc++;
    i++;
    fclose(fp);
  }
}
void createAVLTREE()
{
  Index *new;
  int i=0;
  char *rest;
  char *token;
  char buffer[1024];
  int qnt=0;
  while(i<4){
    strcpy(buffer,inputs[i]);
    fp=fopen(buffer,"r");
    if(fp==NULL){
      printf("ERRO AO TENTAR ABRIR ARQUIVO\n");
      destroyTADs();
      exit(1);
    }
    else{
      while((fgets(buffer,1024,fp))!=NULL){
        //puts(buffer);
        rest=buffer;
        while((token=strtok_r(rest," -;,.:!?\n\t",&rest))){
          token[0]=tolower(token[0]);
          if((strlen(token))>=minSize){
            new=(Index*)malloc(sizeof(Index));
            strcpy(new->str,token);
            new->qnt[i]=1;
            avlTree=avlInsert(avlTree,(void*)new,&cmp,&helpFunction,&qnt);
          }
        }
      }
    }
    disTerms[i]=qnt;
    qntDoc++;
    i++;
    fclose(fp);
  }
}

void createRBTREE()
{
  Index *new;
  int i=0;
  char *rest;
  char *token;
  int qnt=0;
  char buffer[1024];
  while(i<4){
    strcpy(buffer,inputs[i]);
    fp=fopen(buffer,"r");
    if(fp==NULL){
      printf("ERRO AO TENTAR ABRIR ARQUIVO\n");
      destroyTADs();
      exit(1);
    }
    else{
      while((fgets(buffer,1024,fp))!=NULL){
        //puts(buffer);
        rest=buffer;
        while((token=strtok_r(rest," -;,.:!?\n\t",&rest))){
          token[0]=tolower(token[0]);
          if((strlen(token))>=minSize){
            new=(Index*)malloc(sizeof(Index));
            strcpy(new->str,token);
            new->qnt[i]=1;
            rbTree=rbInsert(rbTree,(void*)new,&cmp,&helpFunction,&qnt);
          }
        }
      }
    }
    disTerms[i]=qnt;
    qntDoc++;
    i++;
    fclose(fp);
  }
}

void createBTREE()
{
  Index *new;
  int i=0;
  char *rest;
  char *token;
  int qnt=0;
  char buffer[1024];
  while(i<4){
    strcpy(buffer,inputs[i]);
    fp=fopen(buffer,"r");
    if(fp==NULL){
      printf("ERRO AO TENTAR ABRIR ARQUIVO\n");
      destroyRBtree();
      exit(1);
    }
    else{
      while((fgets(buffer,1024,fp))!=NULL){
        //puts(buffer);
        rest=buffer;
        while((token=strtok_r(rest," -;,.:!?\n\t",&rest))){
          token[0]=tolower(token[0]);
          new=(Index*)malloc(sizeof(Index));
          strcpy(new->str,token);
          new->qnt[i]=1;
          bTree=bTreeInsert(bTree,(void*)new,&cmp,&helpFunction,degree);
        }
      }
    }
    disTerms[i]=qnt;
    qntDoc++;
    i++;
    fclose(fp);
  }
}

void createHASH()
{
  Index *new;
  int i=0;
  char *rest;
  char *token;
  char buffer[1024];
  char input[30];
  int qnt=0;
  hashTable=createHashTable(13);
  while(i<4){
    strcpy(input,inputs[i]);
    fp=fopen(input,"r");
    if(fp==NULL){
      printf("ERRO AO TENTAR ABRIR ARQUIVO\n");
      destroyTADs();
      exit(1);
    }
    else{
      while((fgets(buffer,1024,fp))!=NULL){
        //puts(buffer);
        rest=buffer;
        while((token=strtok_r(rest," -;,.:!?\n\t",&rest))){
          token[0]=tolower(token[0]);
          if((strlen(token))>=minSize){
            new=(Index*)malloc(sizeof(Index));
            strcpy(new->str,token);
            new->qnt[i]=1;
            insertHash(new,&qnt);
          }
        }
      }
    }
    disTerms[i]=qnt;
    qntDoc++;
    i++;
    fclose(fp);
  }
}

void createTAD(int opt)
{
  switch(opt){
    case 1:
      createHASH();
      break;
    case 2:
      createBINARYTREE();
      break;
    case 3:
      createAVLTREE();
      break;
    case 4:
      createRBTREE();
      break;
    case 5:
      //createBTREE();
      break;
    default:
      break;

  }
}

float dealWithVoid(void *a,int id) // esta função recebe um ponteiro void apontando
{                                  // para uma estrutura Index e calcula o peso do termo
  Index *pa=(Index*)a;
  int aux=0;
  float weight;
  int dj=0;
  for(int i=0;i<qntDoc;i++){
    if(pa->qnt[i]!=0)
      dj++;
    if(pa->qnt[i]!=0 && id==i)
      aux=pa->qnt[i];
  }
  weight=((aux)*log10(qntDoc))/(dj);
  return weight;
}

float computeWeight(int qntTerms,char *vet[],int id)
{
  int pos,i;
  void *aux;
  float weight;
  float sumAux=0;
  int flag=1;
  switch(opt){
    case 1:
      for(i=1;i<qntTerms;i++){
        pos=hashFunction(13,(void*)vet[i],&getValue);
        aux=sllSearch(hashTable[pos],(void*)vet[i],&cmp,&helpFunction,flag);
        if(aux!=NULL){
          weight=dealWithVoid(aux,id);
          sumAux+=weight;
        }
      }
      return sumAux;
      break;
    case 2:
      for(i=1;i<qntTerms;i++){
        aux=bstSearch(bstTree,(void*)vet[i],&cmp);
        if(aux!=NULL){
          weight=dealWithVoid(aux,id);
          sumAux+=weight;
        }
      }
      return sumAux;
      break;
    case 3:
      for(i=1;i<qntTerms;i++){
        aux=avlSearch(avlTree,(void*)vet[i],&cmp);
        if(aux!=NULL){
          weight=dealWithVoid(aux,id);
          sumAux+=weight;
        }
      }
      return sumAux;
      break;
    case 4:
      for(i=1;i<qntTerms;i++){
        aux=rbSearch(rbTree,(void*)vet[i],&cmp);
        if(aux!=NULL){
          weight=dealWithVoid(aux,id);
          sumAux+=weight;
        }
      }
      return sumAux;
      break;
    case 5:
      /*for(i=1;i<qntTerms;i++){
        aux=bSearch(bTree,(void*)vet[i],&cmp);
        if(aux!=NULL)
          weight=dealWithVoid(aux,id);
        sumAux+=weight;
      }
      return sumAux;
      */break;
    default:
      printf("Something Went Wrong\n\n");
      destroyTADs();
      break;
  }
}

void computeRelevance(int argc,char *termos[])
{
  int i=0;
  while(i<qntDoc){
    float sumWeights;
    sumWeights=computeWeight(argc,termos,i);
    relevance[i].r=(sumWeights)/(disTerms[i]);
    strcpy(relevance[i].name,inputs[i]);
    i++;
  }
}

int SelectionSort(Relevance *vet,int tam)
{
	int i,j,min;
	Relevance troca;
	if(vet!=NULL){
		for(i=0;i<tam-1;i++){
			min=i;
			for(j=i+1;j<tam;j++){
				if((vet[j].r)<(vet[min].r))
					min=j;
			}
			troca=vet[min];
			vet[min]=vet[i];
			vet[i]=troca;
		}
	}
	return 1;
}

void showRelevance()
{
  SelectionSort(relevance,qntDoc);
  printf("\n\nRELEVÂNCIA DOS DOCUMENTOS\n\n");
  for(int i=qntDoc-1;i>=0;i--){
    printf("DOCUMENT: %s---> Relevance ----> %.2f \n",relevance[i].name,relevance[i].r);
  }
}

void showTAD()
{
    switch(opt){
      case 1:
        printf("TAD UTILIZADO : TABELA HASH\n");
        showHashTable(13);
        break;
      case 2:
        printf("TAD UTILIZADO : ÁRVORE BINÁRIA DE PESQUISA\n");
        btSimetrica(bstTree,&visit);
        break;
      case 3:
        printf("TAD UTILIZADO : ÁRVORE AVL\n");
        Simetrica(avlTree,&visit);
        break;
      case 4:
        printf("TAD UTILIZADO : ÁRVORE RUBRO-NEGRA\n");
        rbSimetrica(rbTree,&visit);
        break;
      case 5:
        break;
      default:
        printf("Erro\n\n");
        destroyTADs();
        break;
    }
}

void menu(int argc,char *argv[])
{
  printf("PICK A TAD:\n");
  printf("1)HASHTABLE\n");
  printf("2)BINARY SEARCH TREE\n");
  printf("3)AVL TREE\n");
  printf("4)RED-BLACK TREE\n");
  printf("5)B-TREE\n");
  scanf("%d",&opt);
  createTAD(opt);
  computeRelevance(argc,argv);
}

int main(int argc, char *argv[])
{
  setlocale(LC_ALL,"Portuguese");
  menu(argc,argv);
  showTAD();
  showRelevance();
  destroyTADs();
}
