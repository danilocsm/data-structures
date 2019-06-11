int csllReverse(SLList *l)
{
	SLNode *last,*prev,*curr,*newfirst=NULL; 
	if(l!=NULL){
		if(l->first!=NULL){
			if(l->first->next!=NULL){
				last=l->first;
				while(l->first->next!=newfirst){
					curr=l->first;
					prev=NULL;
					while(curr->next!=last){
						prev=curr;
						curr=curr->next;
					}
					if(last==l->first)
						newfirst=curr;
					curr->next=prev;
					last=curr;
					if(curr->next==NULL)
						curr->next=newfirst;
				}
				l->first=newfirst;
				return TRUE;
			}
		}
	}	
	return FALSE;
}

int csllBind(SLList *l1,SLList *l2)
{	
	SLNode *last;
	if(l1!=NULL && l2!=NULL){
		if(l1->firs!=NULL && l2->first!=NULL){
			last=l1->first;
			while(last->next!=l1->first)
				last=last->next;
			last->next=l2->first;
			while(last->next!=l2->first)
				last=last->next;
			last->next=l1->first;
			l2->first=NULL;
			return TRUE;
		}
	}
	return FALSE;
}

int csllInterlay(SLList *l1,SLList* l2)
{	
	SLNode *curr1,*curr2,*move,*aux,*beg;
	int tam1,tam2,retorno;
	if(l1!=NULL && l2!=NULL){
		if(l1->first!=NULL && l2->first!=NULL){
			tam1=sllSize(l1);
			tam2=sllSize(l2);
			if(tam1>tam2 || tam1==tam2){
				curr1=l1->first;
				curr2=l2->first;
				l2->first=NULL;
				retorno=1;
			}
			else if(tam2>tam1){
				curr1=l2->first;
				curr2=l1->first;
				l1->first=NULL;
				retorno=0;
			}
			beg=curr2;
			while(curr2->next!=beg){
				move=curr2;
				aux=curr1;
				curr2=curr2->next;
				curr1=curr1->next;
				move->next=aux->next;
				aux->next=move;	
			}
			curr2->next=curr1->next;
			curr1->next=curr2;
			return retorno;
		}
	}
	return -1;
}