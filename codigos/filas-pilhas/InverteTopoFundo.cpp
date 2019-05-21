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