#include <stdio.h>
#include <stdlib.h>

int *lerMatriz(int n,int m)
{
	int i,j,k;
	int *v;
	v=(int*)malloc(sizeof(int)*(n*m));
	if(v!=NULL){
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				k=i*m+j;
				printf("MATRIZ[%d][%d]: ",i+1,j+1);
				scanf("%d",&v[k]);
			}
		}
		return v;
	}
	return NULL;
}

int *multMatriz(int *v1,int *v2,int n,int m,int p,int q)
{
	int i,j,k,l;
	int *mult=NULL;

	if(v1!=NULL&&v2!=NULL){
		if(m==p){
			mult=(int*)malloc(sizeof(int)*(n*q));
			if(mult!=NULL){
				for(i=0;i<n;i++){
					for(j=0;j<q;j++){
						k=i*q+j;
						mult[k]=0;
						for(l=0;l<m;l++){
							mult[k]=mult[k]+(v1[i*m+l])*(v2[m*l+j]);
						}
					}
				}
				return mult;
			}
		}
	}
	return NULL;
}

int *multMatrizTrans(int *v1,int *v2,int n,int m,int p,int q)
{
	int i,j,k,l;
	int *mult=NULL;
	if(v1!=NULL&&v2!=NULL){
		if(m==p){
			mult=(int*)malloc(sizeof(int)*(n*q));
			if(mult!=NULL){
				for(i=0;i<p;i++){
					for(j=0;j<q;j++){
						k=i*q+j;
						mult[k]=0;
						for(l=0;l<m;l++){
							mult[k]=mult[k]+(v1[i*m+l])*(v2[j*m+l]);
						}
					}
				}
				return mult;
			}
		}
	}
	return NULL;
}

int *somaMatrizTrans(int *v1,int *v2,int n,int m,int p,int q){
	int i,j,k,l;
	int *mat;
	if((n==p)&&(m==q)){
		mat=(int*)malloc(sizeof(int)*(n*m));
		if(mat!=NULL){
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					k=i*m+j;
					l=m*j+i;
					mat[k]=v1[k]+v2[l];
				}
			}
			return mat;
		}
	}
	return NULL;
}

int *retornaTrans(int *vet,int n,int m)
{
	int *aux=NULL;
	int i,j,k,l;
	aux=(int*)malloc(sizeof(int)*(n*m));
	if(aux!=NULL){
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				k=i*n+j;
				l=j*m+i;
				aux[k]=vet[l];
			}
		}
		return aux;
	}
	return NULL;
}

void main(void)
{
	int *v1=NULL;
	int *v2=NULL;
	int i,j,lin,col,k,*aux,*piroca;
	v1=lerMatriz(3,3);
	lin=3;
	col=3;
	v2=lerMatriz(3,3);
	printf("<-----MATRIZ1------>\n");
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			k=i*col+j;
			printf("%d\t",v1[k]);
		}
		printf("\n");
	}
	printf("\n<-----MATRIZ2------>\n");
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			k=i*col+j;
			printf("%d\t",v2[k]);
		}
		printf("\n");
	}

	aux=multMatrizTrans(v1,v2,3,3,3,3);
	printf("<-----MATRIZ------>\n");
	for(i=0;i<col;i++){
		for(j=0;j<lin;j++){
			k=i*col+j;
			printf("%d\t",aux[k]);
		}
		printf("\n");
	}
	piroca=somaMatrizTrans(v1,v2,3,3,3,3);
	printf("<-----MATRIZ------>\n");
	for(i=0;i<col;i++){
		for(j=0;j<lin;j++){
			k=i*col+j;
			printf("%d\t",piroca[k]);
		}
		printf("\n");
	}
	free(aux);
}
