#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Ordena1.h"
#include <time.h>
#define TRUE 1
#define FALSE 0
#define RANGE 255

char *algoritmosO[]={"SelectionSort","InsertionSort","ShellSort","MergeSort","QuickSort1","QuickSort2","HeapSort","CountingSort"};// vetores para definir os argumentos
char *metodos[]={"metodo1","metodo2"};
char *entradas[]={"entrada1.txt","entrada2.txt","entrada3.txt","entrada4.txt","entrada5.txt"};
int qntPal=0;//qnt de palavras
int ordena,met,entrada;//varivaveis para definir metodo de ordenaçao,metodo e a etnrada
mSt **palavras=NULL;//vetor da estrutura criada
mSt **alloc=NULL;// auxiliar para utilizar a função reallo()
FILE *arq=NULL;//ponteiro para arquivo
int trocas=0,comp=0,atri=0; // variaveis para calcular numero de trocas,comparaçoes e atribuiçoes realizadas na ordenação

int getBigger()
{
   int i;
   int bigger=palavras[0]->cont;
   for(i=1;i<qntPal;i++){
      if((palavras[i]->cont)>bigger)
         bigger=palavras[i]->cont;
   }
   return bigger;
}

void desaloca()// limpa toda a memoria utilizada
{
    int i;
    for(i=0;i<qntPal;i++)
        free(palavras[i]);
    free(palavras);
}

int verificaExiste(char *key) // verifica a existencia da palavra no vetor de ponteiros "palavras", se aa palavra ja existir, apenas incrementa-se seu contador
{
   int i;
   char *aux;
   if(palavras!=NULL){
      for(i=0;i<qntPal;i++){
         if((strcmp((palavras[i]->str),key))==0){
            (palavras[i]->cont)++;
            return 0;//palavra já existe
         }
      }
   }
   return 1;// palavra não existe
}

void aloca(char *key) //aloca nova posição de memória para inserir uma palavra nova
{
    qntPal++;
    alloc=(mSt**)realloc(palavras,qntPal*sizeof(mSt*));
    if(alloc!=NULL){
      palavras=alloc;
      palavras[qntPal-1]=(mSt*)malloc(sizeof(mSt));
      palavras[qntPal-1]->cont=0;
      strcpy((palavras[qntPal-1]->str),key);
   }
   else{
      desaloca();
      printf("ERRO AO ALOCAR MEMORIA\n");
      exit(-1);
   }

}

void preenchePalavras() // ler o arquivo linha a linha, e adicionam-se as palavras no vetor de ponteiros da estrutura myStruct
{
    char *aux;
    char auxBuffer[100];
    if(arq!=NULL){
      fseek(arq,0,SEEK_SET);
      while(fgets(auxBuffer,100,arq)!=NULL){
         aux=strtok(auxBuffer," ,.?!;-");
         while(aux!=NULL){
           if(strlen(aux)>=5){
               if(verificaExiste(aux)){
                  aloca(aux);
               }
            }
            aux=strtok(NULL," ,.?!;-");
         }
      }
   }
}


void escolheEntrada() // escolhe o arquivo a ser lido
{
    switch(entrada){
        case 1:
            arq=fopen("entrada1.txt","r");
            break;
        case 2:
            arq=fopen("entrada2.txt","r");
            break;
        case 3:
            arq=fopen("entrada3.txt","r");
            break;
        case 4:
            arq=fopen("entrada4.txt","r");
            break;
        case 5:
            arq=fopen("entrada5.txt","r");
            break;
        default:
            printf("ERRO!\n");
            exit(-1);
            break;

    }
}

void escolheOrdena() // escolhe o algoritmo de ordenação baseada no metodo escolhido
{
    preenchePalavras();
    int col=2;
    switch(ordena){
        case 1:
            if(met==1){
                while(col>=0){
                    m1SelectionSort(palavras,qntPal,col,&trocas,&comp,&atri);
                    col--;
                }
            }
            else{
               m2SelectionSort(palavras,qntPal,&trocas,&comp,&atri);
            }
            break;
        case 2:
            if(met==1){
                while(col>=0){
                    m1InsertionSort(palavras,qntPal,col,&trocas,&comp,&atri);
                    col--;
                }
            }
            else{
               m2InsertionSort(palavras,qntPal,&trocas,&comp,&atri);
            }
            break;
        case 3:
            if(met==1){
                while(col>=0){
                    m1ShellSort(palavras,qntPal,col,&trocas,&comp,&atri);
                    col--;
                }
            }
            else{
               m2ShellSort(palavras,qntPal,&trocas,&comp,&atri);
            }
            break;
        case 4:
            if(met==1){
                while(col>=0){
                    m1MergeSort(palavras,0,qntPal-1,col,&trocas,&comp,&atri);
                    col--;
                }
            }
            else{
               m2MergeSort(palavras,0,qntPal-1,&trocas,&comp,&atri);
            }
            break;
        case 5:
            if(met==1){
                while(col>=0){
                    m1QuickSort1(palavras,0,qntPal-1,col,&trocas,&comp,&atri);
                    col--;
                }
            }
            else{
               m2QuickSort1(palavras,0,qntPal-1,&trocas,&comp,&atri);
            }
            break;
        case 6:
            if(met==1){
                while(col>=0){
                    m1QuickSort2(palavras,0,qntPal-1,col,&trocas,&comp,&atri);
                    col--;
                }
             }
            else{
                m2QuickSort2(palavras,0,qntPal-1,&trocas,&comp,&atri);
            }
            break;
        case 7:
            if(met==1){
                while(col>=0){
                    m1HeapSort(palavras,qntPal,col,&trocas,&comp,&atri);
                    col--;
                }
            }
            else{
               m2HeapSort(palavras,qntPal,&trocas,&comp,&atri);
            }
            break;
        case 8:
            if(met==1){
                while(col>=0){
                  // m1CountingSort(palavras,qntPal,RANGE,col);
                    col--;
                }
            }
            else{
               //m2CountingSort(palavras,qntPal,getBigger()+1);
            }
            break;
        default:
            printf("Opção invalida\n");
            exit(-1);
            break;
    }

}

void defineArgs(int qntArg,char *args[]) // recebe os argumentos passados no terminal de comando e define as variaveis ordena,met e entrada
{
    if(qntArg>4){
        printf("ERRO! ARGUMENTOS INVÁLIDOS\n");
        exit(-1);
    }else{
        if((strcmp(args[1],algoritmosO[0]))==0)
            ordena=1;
        else if((strcmp(args[1],algoritmosO[1]))==0)
            ordena=2;
        else if((strcmp(args[1],algoritmosO[2]))==0)
            ordena=3;
        else if((strcmp(args[1],algoritmosO[3]))==0)
            ordena=4;
        else if((strcmp(args[1],algoritmosO[4]))==0)
            ordena=5;
        else if((strcmp(args[1],algoritmosO[5]))==0)
            ordena=6;
        else if((strcmp(args[1],algoritmosO[6]))==0)
            ordena=7;
        else if((strcmp(args[1],algoritmosO[7]))==0)
            ordena=8;
        else{
            printf("ERRO! ARGUMENTOS INVÁLIDOS\n");
            exit(-1);
        }

        if((strcmp(args[2],metodos[0]))==0)
            met=1;
        else if((strcmp(args[2],metodos[1]))==0)
            met=2;
        else{
            printf("ERRO! ARGUMENTOS INVÁLIDOS\n");
            exit(-1);
        }

        if((strcmp(args[3],entradas[0]))==0)
            entrada=1;
        else if((strcmp(args[3],entradas[1]))==0)
            entrada=2;
        else if((strcmp(args[3],entradas[2]))==0)
            entrada=3;
        else if((strcmp(args[3],entradas[3]))==0)
            entrada=4;
        else if((strcmp(args[3],entradas[4]))==0)
            entrada=5;
        else{
            printf("ERRO! ARGUMENTOS INVÁLIDOS\n");
            exit(-1);
        }
    }
}

void imprime(){ // imprime todas as palavras e a qnt de ocorrencias
    int i;
    for(i=0;i<qntPal;i++)
        printf("%s---%d\n ",palavras[i]->str,palavras[i]->cont);
    printf("\n");
}

int main(int argc,char *argv[])
{
    defineArgs(argc,argv);
    escolheEntrada();
    //escolheMet();
    escolheOrdena();
    printf("QUANTIDADE DE PALAVRAS: %d \n",qntPal);
    printf("Foram feitas %d comparaçoes.\nForam feitas %d atribuiçoes.\nForam feitas %d trocas.\n",comp,atri,trocas);
    desaloca();
    fclose(arq);
}
