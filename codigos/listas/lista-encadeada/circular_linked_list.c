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