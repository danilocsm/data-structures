

typedef struct _pilhaDupla{
	int tam;
	int top1,top2;
	void **vet;
}dStack;

dStack *dstkCreate(int num)
{
	dStack *s;
	if(num>0){
		s=(dStack*)malloc(sizeof(dStack))
		if(s!=NULL){
			s->vet=(void**)malloc(sizeof(void*)*num);
			if(s->vet!=NULL){
				s->tam=num;
				s->top1=-1;
				s->top2=num;
				return s;
			}
			free(s);
		}
	}
	return NULL;
}

int dstkDestroy(dStack *s)
{
	if(s!=NULL){
		if(s->top1>-1&&s->top2==s->num){
			free(s->vet);
			free(s);
			return 1;
		}
	}
	return 0;
}

int dstkPush1(dStack *s,void *key)
{
	if(s!=NULL){
		if(s->top1!=s->top2-1){
			s->top1++;
			s->vet[s->top1]=key;
			return 1;
		}
	}
	return 0;
}

int dstkPush2(dStack *s,void *key)
{
	if(s!=NULL){
		if(s->top1!=s->top2-1){
			s->top2--;
			s->vet[s->top2]=key;
			return 1;
		}
	}
	return 0;
}

void *dstkPop1(dStack *s)
{
	void *aux;
	if(s!=NULL){
		if(s->vet!=NULL){
			if(s->top1>-1){
				aux=s->vet[s->top1];
				s->top1--;
				return aux;
			}
		}
	}
	return NULL;
}

void *dstkPop2(dStack *s)
{
	void *aux;
	if(s!=NULL){
		if(s->vet!=NULL){
			if(s->top2<num){
				aux=s->vet[s->top2];
				s->top2++;
				return aux;
			}
		}
	}
	return NULL;
}

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
				teste=stkPush(s,aux2);
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
			pt=(int*)aux[i];
			if((*pt)%2==0){
				teste=stkPush(s,(void*)pt);
            }
		}
		for(i=0;i<tam;i++){
			pt=(int*)aux[i];
			if((*pt)%2==1)
				teste=stkPush(s,(void*)pt);
		}
		return 1;
	}
    return 0;
}

int PuneTop(Stack *s,int n)
{
	int i;
	void *aux,*aux2;
	Stack *aux3;
	aux3=stkCreate(n);
	if(aux3!=NULL){
		aux=stkPop(s);
		for(i=0;i<n;i++){
			teste=stkPush(aux3,aux2=stkPop(s));
		}
		stkPush(s,aux);
		for(i=0;i<n;i++){
			aux2=stkPop(aux3)
			teste=stkPush(s,aux2);
		}
	}
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

int isPalindromo(char text[],int size)
{
	Stack *s;
	int i,teste,state;
	char *ch;
	
	s=stkCreate(size-1);
	if(s!=NULL){
		for(i=0;i<size-1;i++){
			teste=stkPush(s,(void*)text[i]);
		}
		for(i=0;i<size-1;i++){
			ch=(char*)stkPop(s);
			if(text[i]==*ch)
				state=1;
			else{
				state=0
				break;
			}
		}
		return state;
	}	
}

int formato(char* frase,int zeros){
	stack*s=NULL;
	int i,teste,j,k;
	int aux;
	char* letra;
	int n=strlen(frase);
	char *c;
	int armazena=0;
	int subSize=0;
	int contZero=0;
	int inicio=0;
	int w;
	
		s=stkCreate(n-1);
		w=0;
		k=0;
		i=0;
		j=0;
		inicio=0;
		//busca pelo tamanho das substrings
		if(s!=NULL){
		for(w=0;w<n;w++){
			if(frase[w]=='0'){
				contZero++;
					if(contZero==1)
						subSize=w;
			}
		}
		if(contZero==0){
			puts("FORA DO FORMATO T_T");
			exit(1);
		}
		//define as dimensões
		printf("FORMATO COM %d ZEROS\n",contZero);
		printf("TAMANHO DA SUB STRING: %d\n",subSize);
		
		while(armazena<=contZero && i<n-1){
			aux=0;
			if(frase[i]=='0'){
					for(j=i+1;j<i+subSize+1;j++){
						teste=stkPush(s,(char*)&frase[j]);
					}
					printf("Conferindo sub que inicia na posicao %d\n",inicio);
					for(k=inicio;k<subSize+inicio;k++){
						letra=(char*)stkPop(s);
						if(frase[k]==*letra){
						printf("%c e %c sao iguais\n",frase[k],*letra);
						aux=1;
						}
						else{
						aux=0;
						break;
						}
					}
					inicio=inicio+subSize+1;
					if(aux==1){
						armazena++;
					}
								
			}	
			i++;
		}
		printf("ARMAZENA %d\n",armazena);
		
		if(armazena==zeros){
			return true;
		}
		else{
			return false;
		}
	}
}
