#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Ordena1.h"
#include "Ordena2.h"
#include <time.h>
#define TRUE 1
#define FALSE 0

typedef struct ocorPal{
    char *str;
    int cont=0;
}oP;
char command[50];
int booleano=TRUE;
int qntPal=0;
int ordena,met,entrada;
char **palavras1=NULL;
FILE *arq=NULL;
oP *palavras2;

void contaPalavras()
{
    char *aux
    int tam;
    system(command);
    FILE *auxArq;
    auxArq=fopen("resultado.txt","r");
    if(auxArq!=NULL){
        while((fscanf(auxArq,"%d %s",&tam,&aux))!=EOF);

        qntPal=tam;
    }

}

char **aloca(FILE *arq)
{
    int i;
    char **mat=NULL;
    char *aux=NULL;
    contaPalavras();
    mat=(char**)malloc(sizeof(char*)*qntPal);
    if(mat!=NULL){
        for(i=0;i<qntPal;i++){
            mat[i]=(char*)malloc(sizeof(char)*25);
            if(mat[i]==NULL){
                free(mat);
                exit(-1);
            }
        }
        return mat;
    }
    return NULL;
}

void preencheMatriz()
{
    char *aux;
    char auxBuffer[100];
    int cont=0,i=0;
    if(arq!=NULL){
        palavras1=aloca(arq);
        if(palavras1!=NULL){
            fseek(arq,0,SEEK_SET);
            while(fgets(auxBuffer,100,arq)!=NULL){
                aux=strtok(auxBuffer," ,.?!-;:()""");
                while(aux!=NULL){
                    if(strlen(aux)>=4){
                        strcpy(palavras1[i],aux);
                        i++;
                    }
                    aux=strtok(NULL," ,.?!-;:()""");
                }
            }
            int j;
            for(j=i;j<qntPal;j++)
                palavras1[j]=NULL;
        }
    }
}

void preencheMetodo1(FILE *arq)
{
    int pos,i;
    if(arq!=NULL){
        preencheMatriz();
    }
}

void preencheMetodo2()
{
    palavras2=(oP*)malloc(sizeof(oP)*qntPal);
}

void escolheMet(int opt)
{

    switch(opt){
        case 1:
            preencheMetodo1();
            system("clear");
            break;
        case 2:
            system("clear");
            break;
        default:
            printf("Metodo Invalido\n");
            booleano=FALSE;
            break;
    }
}

void escolheEntrada(int opt)
{
    switch(opt){
        case 1:
            strcpy(command,"wc -w entrada1.txt > resultado.txt");
            arq=fopen("entrada1.txt","r");
            break;
        case 2:
            strcpy(command,"wc -w entrada2.txt > resultado.txt");
            arq=fopen("entrada2.txt","r");
            break;
        case 3:
            strcpy(command,"wc -w entrada3.txt > resultado.txt");
            arq=fopen("entrada3.txt","r");
            break;
        case 4:
            strcpy(command,"wc -w entrada4.txt > resultado.txt");
            arq=fopen("entrada4.txt","r");
            break;
        case 5:
            strcpy(command,"wc -w entrada5.txt > resultado.txt");
            arq=fopen("entrada5.txt","r");
            break;
        default:

    }
}

void escolheOrdena(int opt)
{
    int col=2;
    switch(opt){
        case 1:
            if(met==1){
                while(col>=0){
                    SelectionSort(mat,tam,col);
                    col--;
                }
            }
            else{

            }
            break;
        case 2:
            if(met==1){
                while(col>=0){
                    InsertionSort(mat,tam,col);
                    col--;
                }
            }
            else{

            }
            break;
        case 3:
            if(met==1){
                while(col>=0){
                    ShellSort(mat,tam,col);
                    col--;
                }
            }
            else{

            }
            break;
        case 4:
            if(met==1){
                while(col>=0){
                    MergeSort(mat,0,tam-1,col);
                    col--;
                }
            }
            else{

            }
            break;
        case 5:
            if(met==1){
                while(col>=0){
                    QuickSort1(mat,0,tam-1,col);
                    col--;
                }
            }
            else{

            }
            break;
        case 6:
            if(met==1){
                while(col>=0){
                    QuicksSort2(mat,0,tam-1,col);
                    col--;
                }
            }
            else{

            }
            break;
        case 7:
            if(met==1){
                while(col>=0){
                    QuickSort3(mat,0,tam-1,col);
                    col--;
                }
            }
            else{

            }
            break;
        case 8:
            if(met==1){
                while(col>=0){
                    HeapSort(mat,tam,col);
                    col--;
                }
            }
            else{

            }
            break;
        case 9:
            if(met==1){
                while(col>=0){
                    CountingSort(mat,tam,RANGE,col);
                    col--;
                }
            }
            else{

            }
            break;
        default:
            printf("Opção invalida\n");
            booleano=FALSE;
            break;
    }

}

void define()
{
    menu1();
    scanf("%d",&ordena);
    system("clear");
    menu2();
    scanf("%d"&met);
    system("clear");
    menu3();
    scanf("%d",&entrada);
    escolheEntrada(entrada);
    escolheMet(met);
    escolheOrdena(ordena);
}

void defineArgs()
{

}

int main(int argc,char *argv[])
{
    while(booleano){
        define();
    }
}
