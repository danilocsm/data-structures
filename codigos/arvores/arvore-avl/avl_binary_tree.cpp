#define avl_binary_tree_c
#include <stdlib.h>
#include "avl_binary_tree.h"
#define TRUE 1
#define FALSE 0


int max(int a,int b) //funçao auxiliar para pegar valor maximo entre dois inteiros
{
      if(a>b) return a;
      else return b;
}

int avlHeight(AVLNode *t) // função que retorna altura de uma arvore
{
   if(t==NULL)
      return 0;
   return t->height;
}

int getBalance(AVLNode *t) // função que retorna o fator de balanceamento de uma arvore
{
   if(t==NULL)
      return 0;

   return ((avlHeight(t->left))-(avlHeight(t->right)));
}

AVLNode *rotateRight(AVLNode *t) // função que realiza rotação a direita usando t como pivo
{
   AVLNode *p=t->left;
   AVLNode *temp=p->right;
   p->right=t;
   t->left=temp;
   t->height = max(avlHeight(t->left),avlHeight(t->right))+1;
   p->height = max(avlHeight(p->left),avlHeight(p->right))+1;

   return p;
}

AVLNode *rotateLeft(AVLNode *t) // função que realiza rotação a esquerda usando t como pivo
{
   AVLNode *p=t->right;
   AVLNode *temp=p->left;
   p->left=t;
   t->right=temp;
   t->height = max(avlHeight(t->left),avlHeight(t->right))+1;
   p->height = max(avlHeight(p->left),avlHeight(p->right))+1;

   return p;
}

AVLNode *avlInsert(AVLNode *t,void *elm,int(*cmp)(void*,void*),void*(*helpFunction)(void *),int *distincts) // inserer um novo nó na arvore AVL
{
  int balance;
	if(t==NULL){
		t=(AVLNode*)malloc(sizeof(AVLNode));
		if(t!=NULL){
			t->data=elm;
                        t->height=1;
			t->left=t->right=NULL;
		}
                (*distincts)++;
	}
	else if(cmp(t->data,elm)==1)
		t->left=avlInsert(t->left,elm,cmp,helpFunction,distincts);
	else if(cmp(t->data,elm)==-1)
		t->right=avlInsert(t->right,elm,cmp,helpFunction,distincts);
  else if(cmp(t->data,elm)==0){
      t->data=helpFunction((t->data));
      free(elm);
      return t;
  }

// verifica o balanceamento pós inserção e realiza as devidas rotações
   balance=getBalance(t);
   if(balance>1 && (cmp(t->left->data,elm)==1)) // LL case
      return rotateRight(t);
   if(balance<(-1) && (cmp(t->right->data,elm)==0)) // RR case
      return rotateLeft(t);
   if(balance>1 && (cmp(t->left->data,elm)==0)){ //LR case
      t->left=rotateLeft(t->left);
      return rotateRight(t);
   }
   if(balance<(-1) && (cmp(t->right->data,elm)==1)){ //RL case
      t->right=rotateRight(t->right);
      return rotateLeft(t);
   }

    return t;
}

AVLNode *avlRemove(AVLNode *t,void *elm,int(*cmp)(void*,void*)) // remove um nó da arvore AVL
{
	AVLNode *aux;
	if(t==NULL){
		return NULL;
	}
	else if(cmp(t->data,elm)==1){
		t->left=avlRemove(t->left,elm,cmp);
	}
	else if(cmp(t->data,elm)==-1){
		t->right=avlRemove(t->right,elm,cmp);
	}
	else{
		if(t->right==NULL && t->left==NULL){
			free(t->data);
                        free(t);
			t=NULL;
		}
		else if(t->right==NULL && t->left!=NULL){
			aux=t;
			t=t->left;
			free(aux->data);
                        free(aux);
		}
		else if(t->right!=NULL && t->left==NULL){
			aux=t;
			t=t->right;
                        free(aux->data);
			free(aux);
		}
		else if(t->right!=NULL && t->left!=NULL){
			aux=t->left;
			while(aux->right!=NULL)
				aux=aux->right;
			t->data=aux->data;
			aux->data=elm;
			t->left=avlRemove(t->left,elm,cmp);
		}
	}

   if(t==NULL)
      return t;

//analogo a função de inserir, verifica o balanceamento pós remoçao e faz as devidas rotações
   t->height=max(avlHeight(t->left),avlHeight(t->right))+1; // atualiza a altura
   int balance;
   balance=getBalance(t);

   if(balance>1 && (getBalance(t->left)>=0)) // LL case
      return rotateRight(t);
   if(balance>1 && (getBalance(t->left)<0)){ //LR case
      t->left=rotateLeft(t->left);
      return rotateRight(t);
   }
   if(balance< -1 && (getBalance(t->right)<=0)) // RR case
      return rotateLeft(t);
   if(balance< -1 && (getBalance(t->right)>0)){ // RL case
      t->right=rotateRight(t->right);
      return rotateLeft(t);
   }

	return t;
}

void *avlSearch(AVLNode *t,void *key,int(*cmp)(void*,void*)) // procura um nó em uma arvore e retorna TRUE se encontra-lo, falso caso contrario
{
	if(t==NULL)
		return NULL;
	else if(cmp(t->data,key)==1)
		return avlSearch(t->left,key,cmp);
	else if(cmp(t->data,key)==-1)
		return avlSearch(t->right,key,cmp);
	else
		return t->data;
}

AVLNode* avlGetMax(AVLNode *root)
{
	AVLNode *aux;
	aux=root;
	while(aux->right!=NULL)
		aux=aux->right;
	return aux;
}


AVLNode* avlGetMin(AVLNode *root)
{
	AVLNode *aux;
	aux=root;
	while(aux->left!=NULL)
		aux=aux->left;
	return aux;
}

AVLNode* avlDeleteTree(AVLNode *root,int(*cmp)(void*,void*))
{
	AVLNode *destroy;
	while(root->left!=NULL)
	{
		destroy=avlGetMin(root);
		root=avlRemove(root,destroy->data,cmp);
	}
	while(root->right!=NULL){
		destroy=avlGetMax(root);
		root=avlRemove(root,destroy->data,cmp);
	}
  root=avlRemove(root,root->data,cmp);
	return root;
}

void Simetrica(AVLNode *t,void(*visit)(void*)) // função para imprimir a arvore de maneira ordenada
{
	if(t!=NULL){
		Simetrica(t->left,visit);
    visit(t->data);
		Simetrica(t->right,visit);
	}
}
