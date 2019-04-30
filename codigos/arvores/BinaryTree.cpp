#define BinaryTree_c
#include <stdlib.h>
#include "BinaryTree.h"
#define TRUE 1
#define FALSE 0

/*TNode *btCreateEmpty()
{
	return NULL;
}*/

TNode *bstInsert(TNode *t,void *elm,int(*cmp)(void*,void*),void*(*helpFunction)(void*),int *distincts)
{
	if(t==NULL){
		t=(TNode*)malloc(sizeof(TNode));
		if(t!=NULL){
			t->data=elm;
			t->left=t->right=NULL;
		}
		(*distincts)++;
	}
	else if(cmp(t->data,elm)==1)
		t->left=bstInsert(t->left,elm,cmp,helpFunction,distincts);
	else if(cmp(t->data,elm)==-1)
		t->right=bstInsert(t->right,elm,cmp,helpFunction,distincts);
	else{
		t->data=helpFunction((t->data));
		free(elm);
	}
	return t;
}

/*void *bstBigger(TNode *t)
{
	if(t!=NULL){
		if(t->right!=NULL)
			return bstBigger(t->right);
		else
			return t->data;
	}
	return NULL;
}*/

TNode *bstRemove(TNode *t,void *elm,int(*cmp)(void*,void*))
{
	TNode *aux;
	if(t==NULL){
		return NULL;
	}
	else if(cmp(t->data,elm)==1){
		t->left=bstRemove(t->left,elm,cmp);
	}
	else if(cmp(t->data,elm)==-1){
		t->right=bstRemove(t->right,elm,cmp);
	}
	else{
		if(t->right==NULL && t->left==NULL){
			//free(t->data);
			free(t);
			t=NULL;
		}
		else if(t->right==NULL && t->left!=NULL){
			aux=t;
			t=t->left;
			//free(aux->data);
			free(aux);
		}
		else if(t->right!=NULL && t->left==NULL){
			aux=t;
			t=t->right;
			//free(aux->data);
			free(aux);
		}
		else if(t->right!=NULL && t->left!=NULL){
			aux=t->left;
			while(aux->right!=NULL)
				aux=aux->right;
			t->data=aux->data;
			aux->data=elm;
			t->left=bstRemove(t->left,elm,cmp);
		}
	}
	return t;
}

void* bstSearch(TNode *t,void *key,int(*cmp)(void*,void*))
{
	if(t==NULL)
		return NULL;
	else if(cmp(t->data,key)==1)
		return bstSearch(t->left,key,cmp);
	else if(cmp(t->data,key)==-1)
		return bstSearch(t->right,key,cmp);
	else
		return t->data;
}

TNode* bstGetMax(TNode *root)
{
	TNode *aux;
	aux=root;
	while(aux->right!=NULL)
		aux=aux->right;
	return aux;
}


TNode* bstGetMin(TNode *root)
{
	TNode *aux;
	aux=root;
	while(aux->left!=NULL)
		aux=aux->left;
	return aux;
}

TNode* bstDeleteTree(TNode *root,int(*cmp)(void*,void*))
{
	TNode *destroy;
	while(root->left!=NULL)
	{
		destroy=bstGetMin(root);
		root=bstRemove(root,destroy->data,cmp);
	}
	while(root->right!=NULL){
		destroy=bstGetMax(root);
		root=bstRemove(root,destroy->data,cmp);
	}
	root=bstRemove(root,root->data,cmp);
	return root;
}

/*int btIsComplete(TNode *t)
{	int l,r;
	if(t!=NULL){
		if(t->right!=NULL && t->left!=NULL){
			l=btIsComplete(t->left);
			r=btIsComplete(t->right);
			return (l&&r);
		}
		else if(t->right==NULL && t->left==NULL)
			return TRUE;
	}
	return FALSE;
}*/

/*void btPreordem(TNode *t,void(*visit)(void*))
{
	if(t!=NULL){
		visit(t->data);
		btPreordem(t->left,visit);
		btPreordem(t->right,visit);
	}
}

void btPosordem(TNode *t,void(*visit)(void*))
{
	if(t!=NULL){
		btPosordem(t->left,visit);
		btPosordem(t->right,visit);
		visit(t->data);
	}
}*/

void btSimetrica(TNode *t,void(*visit)(void*))
{
	if(t!=NULL){
		btSimetrica(t->left,visit);
		visit(t->data);
		btSimetrica(t->right,visit);
	}
}

/*int btQntBigger(TNode *t,void *elm,int(*cmp)(void*,void*))
{
	int ncur=0,nl,nr;
	if(t!=NULL){
		if(cmp(t->data,elm)==1)
			ncur=1;
		nl=btQntBigger(t->left,elm,cmp);
		nr=btQntBigger(t->right,elm,cmp);
		return nl+nr+ncur;
	}
	return 0;
}

int btContaNodes(TNode *t)
{
	int nl,nr;
	if(t!=NULL){
		nl=btContaNodes(t->left);
		nr=btContaNodes(t->right);
		return nl+nr+1;
	}
	return 0;
}

int bstAlturaNodeRec(TNode *t,void *key,int(*cmp)(void*,void*),int l)
{
	if(t!=NULL){
		if(cmp(t->data,key)==1)
			return bstAlturaNodeRec(t->left,key,cmp,l+1);
		else if(cmp(t->data,key)==0)
			return bstAlturaNodeRec(t->right,key,cmp,l+1);
		else{
			return l;
		}
	}
	return -1;
}

int bstAlturaNode(TNode *t,void *key,int(*cmp)(void*,void*))
{
	int h;
	if(t!=NULL){
		h=bstAlturaNodeRec(t,key,cmp,0);
		return h;
	}
	return -1;
}

int btIsBinarySearchTree(TNode *t,int(*cmp)(void*,void*))
{	int statCur=0,statL,statR;
	if(t!=NULL){
		if(t->left!=NULL){
			if(t->right!=NULL){
				if(cmp(t->left->data,t->data)==0 && cmp(t->right->data,t->data)==1)
					statCur=1;
			}
			else{
				if(cmp(t->left->data,t->data)==0)
					statCur=1;
			}
		}
		else if(t->right!=NULL){
			if(cmp(t->right->data,t->data)==1)
				statCur=1;
		}
		else if(t->right==NULL)
			return TRUE;
		statL=btIsBinarySearchTree(t->left,cmp);
		statR=btIsBinarySearchTree(t->right,cmp);
		return (statCur&&statL&&statR);

	}
	return TRUE;
}

int btContaNodesAtLeastOne(TNode *t)
{
	int nl,nr,ncur=0;
	if(t!=NULL){
		if(t->right!=NULL || t->left!=NULL)
			ncur=1;
		nl=btContaNodesAtLeastOne(t->left);
		nr=btContaNodesAtLeastOne(t->right);
		return nl+nr+ncur;
	}
	return 0;
}

int btContaNodesOnlyOne(TNode *t)
{
	int nl,nr,ncur=0;
	if(t!=NULL){
		if((t->right==NULL && t->left!=NULL)||(t->left==NULL && t->right!=NULL))
			ncur=1;
		nl=btContaNodesOnlyOne(t->left);
		nr=btContaNodesOnlyOne(t->right);
		return nl+nr+ncur;
	}
	return 0;
}

int btContaNodesOnlyLeft(TNode *t)
{
	int nl,nr,ncur=0;
	if(t!=NULL){
		if(t->left!=NULL && t->right==NULL)
			ncur=1;
		nl=btContaNodesOnlyLeft(t->left);
		nr=btContaNodesOnlyLeft(t->right);
		return nl+nr+ncur;
	}
	return 0;
}

int btContaNodesOnlyTwo(TNode *t)
{
	int nl,nr,ncur=0;
	if(t!=NULL){
		if(t->left!=NULL && t->right!=NULL)
			ncur=1;
		nl=btContaNodesOnlyTwo(t->left);
		nr=btContaNodesOnlyTwo(t->right);
		return nl+nr+ncur;
	}
	return 0;
}

int btAltura(TNode *t)
{
	int hl=0,hr=0;
	if(t==NULL)
		return -1;

	hl=btAltura(t->left);
	hr=btAltura(t->right);
	if(hl>hr){
		return hl+1;
	}
	else{
		return hr+1;
	}
}

int btContaNodesTillH(TNode *t,int h,int l)
{
	int ncur=0,nr,nl;
	if(t!=NULL){
		if(l<h)
			ncur=1;
		nl=btContaNodesTillH(t->left,h,l+1);
		nr=btContaNodesTillH(t->right,h,l+1);
		return nl+nr+ncur;
	}
	return 0;
}

int btContaNodesAlturaH(TNode *t,int h,int l)
{	int ncur=0,nl,nr;
	if(t!=NULL){
		if(l==h)
			ncur=1;
		nl=btContaNodesAlturaH(t->left,h,l+1);
		nr=btContaNodesAlturaH(t->right,h,l+1);
		return nl+nr+ncur;
	}
	return 0;
}

int btIsEqual(TNode *t1,TNode *t2,int(*cmp)(void*,void*))
{
	int l,r;
	if(t1!=NULL){
		if(t2!=NULL){
			l=btIsEqual(t1->left,t2->left,cmp);
			r=btIsEqual(t1->right,t2->right,cmp);
			return (l&&r&&cmp(t1->data,t2->data));
		}
		else
			return FALSE;

	}
	else if(t2==NULL)
		return TRUE;
	return FALSE;
}

int btIsEqualH(TNode *t1,TNode *t2,int(*cmp)(void*,void*),int h,int l)
{
	int isL,isR,stat=0;
	if(t1!=NULL){
		if(t2!=NULL){
			if(l==h){
				stat=cmp(t1->data,t2->data);
			}
			isL=btIsEqualH(t1->left,t2->left,cmp,h,l+1);
			isR=btIsEqualH(t1->right,t2->right,cmp,h,l+1);
			return (isL&&isR&&stat);
		}
		else
			return FALSE;
	}
	else if(t2==NULL)
		return TRUE;
	return FALSE;
}

void bstPrintLeafDec(TNode *t,void(*visit)(void*))
{
	if(t!=NULL){
		if(t->right==NULL && t->left==NULL)
			visit(t->data);
		bstPrintLeafDec(t->right,visit);
		bstPrintLeafDec(t->left,visit);

	}
}

int btSoma(TNode *t,int(*getValue)(void*))
{
	int somaL,somaR,atual;
	if(t!=NULL){
		atual=getValue(t->data);
		somaL=btSoma(t->left,getValue);
		somaR=btSoma(t->right,getValue);
		return somaL+somaR+atual;
	}
	return 0;
}

void *getRoot(TNode *t)
{
	if(t!=NULL)
		return t->data;
	return NULL;
}

void btBigger(TNode *t,int(*getValue)(void*),int *maior)
{
	int atual;
	if(t!=NULL){
		btBigger(t->left,getValue,maior);
		atual=getValue(t->data);
		if(atual>(*maior))
			*maior=atual;
		btBigger(t->right,getValue,maior);
	}
}

void btSmaller(TNode *t,int(*getValue)(void*),int *menor)
{
	int atual;
	if(t!=NULL){
		btSmaller(t->left,getValue,menor);
		atual=getValue(t->data);
		if(atual<(*menor))
			*menor=atual;
		btSmaller(t->right,getValue,menor);
	}
}

void btSearch(TNode *t,void* key,int(*cmp)(void*,void*),int *stat)
{
	if(t!=NULL){
		if(cmp(key,t->data)==0)
			*stat=1;
		btSearch(t->left,key,cmp,stat);
		btSearch(t->right,key,cmp,stat);
	}
}


TNode *btInsert(TNode *t,void *elm,int(*getValue)(void*),int(*cmp)(void*,void*))
{
	int val;
	if(t!=NULL){
		val=getValue(elm);
		if(val%2==0){
			t->left=bstInsert(t->left,elm,cmp);
		}
		else
			t->right=bstInsert(t->right,elm,cmp);
	}
	else{
		t=(TNode*)malloc(sizeof(TNode));
		if(t!=NULL){
			t->data=elm;
			t->left=t->right=NULL;
			return t;
		}
	}
}*/
