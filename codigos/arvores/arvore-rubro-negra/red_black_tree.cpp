#define red_black_tree_c
#include "red_black_tree.h"
#include <stdlib.h>
#include <stdio.h>

void rbRotateLeft(RBnode **root,RBnode **pt)
{																						 // pivo, atualizando a raiz. Os ponteiros são passados por referencia
	RBnode *pt_right=(*pt)->right;

	(*pt)->right=pt_right->left;
	if((*pt)->right!=NULL)
	(*pt)->right->parent=(*pt);

	pt_right->parent=(*pt)->parent;
	if((*pt)->parent== NULL)
		(*root)=pt_right;
	else if((*pt)==(*pt)->parent->left)
		(*pt)->parent->left=pt_right;
	else
		(*pt)->parent->right=pt_right;

	pt_right->left=(*pt);
	(*pt)->parent=pt_right;
}

void rbRotateRight(RBnode **root,RBnode **pt)
{
	   RBnode *pt_left=(*pt)->left;
	   (*pt)->left = pt_left->right;
	   if ((*pt)->left != NULL)
	      (*pt)->left->parent =(*pt);
	   pt_left->parent = (*pt)->parent;
	   if ((*pt)->parent == NULL)
	       (*root) = pt_left;
	   else if ((*pt)==(*pt)->parent->left)
	       (*pt)->parent->left = pt_left;
	   else
	       (*pt)->parent->right = pt_left;
	   pt_left->right = (*pt);
	   (*pt)->parent = pt_left;
}

RBnode *rbFixInsertion(RBnode *root,RBnode *pt)
{
	RBnode *parent_pt=NULL;
	RBnode *grandp_pt=NULL;
	while((pt)!=(root)&& (pt->color!=0) && (pt->parent->color==1)){
		parent_pt=(pt)->parent;
		grandp_pt=(pt)->parent->parent;
		if(parent_pt == grandp_pt->left){               // caso pai seja filho a esquerda
			RBnode *uncle_pt= grandp_pt->right;
			if(uncle_pt!=NULL && uncle_pt->color==1){ // caso tio é vermelho
				grandp_pt->color=1;
				parent_pt->color=0;
				uncle_pt->color=0;
				(pt)=grandp_pt;
			}
			else{ // caso tio seja preto
				if((pt)==parent_pt->right){
					rbRotateLeft(&root,&parent_pt);
					(pt)= parent_pt;
					parent_pt =(pt)->parent;
				}
				rbRotateRight(&root,&grandp_pt);
				parent_pt->color=0;
				grandp_pt->color=1;
				(pt)=parent_pt;
			}
		}
		else{                                       // caso o pai seja filho a direita
			RBnode *uncle_pt=grandp_pt->left;
			if((uncle_pt !=NULL) && (uncle_pt->color ==1)){ // caso tio vermelho
				grandp_pt->color=1;
				parent_pt->color=0;
				uncle_pt->color=0;
				(pt)=grandp_pt;
			}
			else{ // caso tio seja preto
				if((pt)==parent_pt->left){
					rbRotateRight(&root,&parent_pt);
					(pt)=parent_pt;
					parent_pt=(pt)->parent;
				}
				rbRotateLeft(&root,&grandp_pt);
				parent_pt->color=0;
				grandp_pt->color=1;
				(pt)=parent_pt;
			}
		}
	}
	root->color=0;
	return root;
}

RBnode *rbCreateNode(void *elm)
{
	RBnode *ret=NULL;
	ret=(RBnode*)malloc(sizeof(RBnode));
	if(ret!=NULL){
		ret->data=elm;
		ret->color=1;
		ret->left=ret->right=ret->parent=NULL;
		return ret;
	}
	return NULL;

}

RBnode *btInsert(RBnode *root,RBnode *pt,int(*cmp)(void*,void*),void*(*helpFunction)(void *),int *flag) //função auxiliar de inserção numa árvore binaria de pesquisa
{
	if(root==NULL){
		*flag=0;
		return pt;
	}
	else if(cmp(root->data,pt->data)==1){
		root->left=btInsert(root->left,pt,cmp,helpFunction,flag);
		root->left->parent=root;
	}
	else if(cmp((root)->data,pt->data)==-1){
		root->right=btInsert(root->right,pt,cmp,helpFunction,flag);
		root->right->parent=root;
	}
	else if(cmp(root->data,pt->data)==0){
		root->data=helpFunction(root->data);
	}
	return root;
}

RBnode *rbInsert(RBnode *root,void *elm,int(*cmp)(void*,void*),void*(*helpFunction)(void *),int *distinct) // função para inserção na arvore rubro negra
{
	int flag=1;
	RBnode *new;
	new=rbCreateNode(elm);
	if(new!=NULL){
		root=btInsert(root,new,cmp,helpFunction,&flag);
		if(flag==0){
			root=rbFixInsertion(root,new);
			(*distinct)++;
		}else{
				free(new->data);
				free(new);
		}
		return root;
	}
	else{
		exit(1);
	}
}

// Função com erro em alguns casos de remoção. Consertar.
RBnode *rbFixRemoval(RBnode *root,RBnode *pt,RBnode *pt_parent)
{
	RBnode *sibling_pt=NULL;
	if(pt!=NULL){
		while(pt!=root && pt->color==0){
			if(pt==pt->parent->left){   // o pivo é filho à esquerda
				sibling_pt=pt->parent->right;
				if(sibling_pt->color==1){  // caso irmão seja vermelho
					sibling_pt->color=0;
					rbRotateLeft(&root,&pt->parent);
					sibling_pt=pt->parent->right;
				}
				if((sibling_pt->left==NULL || sibling_pt->left->color==0) && (sibling_pt->right==NULL || sibling_pt->right->color==0)){ // caso irmão seja preto com dois filhos pretos
					sibling_pt->color=1;
					pt=pt->parent;
				}
				else{ // caso irmão preto com filho vermelho
					if(sibling_pt->right==NULL || sibling_pt->right->color==0){
						sibling_pt->left->color=0;
						sibling_pt->color=1;
						rbRotateRight(&root,&sibling_pt);
						sibling_pt=pt->parent->right;
					}
					sibling_pt->color=pt->parent->color;
					pt->parent->color=0;
					sibling_pt->right->color=0;
					rbRotateLeft(&root,&pt->parent);
					pt=root;
				}
			}
			else{ // caso simetrico ao de cima, invertendo direita com esquerda
				sibling_pt=pt->parent->left;
				if(sibling_pt->color==1){
					sibling_pt->color=0;
					rbRotateRight(&root,&pt->parent);
					sibling_pt=pt->parent->left;
				}
				if((sibling_pt->left==NULL || sibling_pt->left->color==0) && (sibling_pt->right==NULL || sibling_pt->right->color==0)){
					sibling_pt->color=1;
					pt=pt->parent;
				}
				else{
					if(sibling_pt->left==NULL || sibling_pt->left->color==0){
						sibling_pt->right->color=0;
						sibling_pt->color=1;
						rbRotateLeft(&root,&sibling_pt);
						sibling_pt=pt->parent->left;
					}
					sibling_pt->color=pt->parent->color;
					pt->parent->color=0;
					sibling_pt->left->color=0;
					rbRotateRight(&root,&pt->parent);
					pt=root;
				}
			}
		}
		pt->color=0;
		return root;
	}else if(pt==NULL && pt_parent!=NULL){                                                       // ao se remover um nó que não possui filhos, ou seja, remoção de folhas, o pivô passado como
		RBnode *aux=NULL;
		RBnode *aux_parent=pt_parent;                                          // parâmetro será null. Esse caso trata esta situação utilizando o pai do nó removido como pivô,
		while(aux!=root && (aux==NULL || aux->color==0)){                                                // e utiliza um ponteiro auxiliar para fazer o balanceamento.
			if(aux==aux_parent->left){
				sibling_pt=aux_parent->right;
				if(sibling_pt->color==1){
					sibling_pt->color=0;
					rbRotateLeft(&root,&aux_parent);
					sibling_pt=aux_parent->right;
				}
				if((sibling_pt->left==NULL || sibling_pt->left->color==0) && (sibling_pt->right==NULL || sibling_pt->right->color==0)){
					sibling_pt->color=1;
					aux=aux_parent;
					aux_parent=aux->parent;
				}
				else{
					if(sibling_pt->right==NULL || sibling_pt->right->color==0){
						sibling_pt->left->color=0;
						sibling_pt->color=1;
						rbRotateRight(&root,&sibling_pt);
						sibling_pt=aux_parent->right;
					}
					sibling_pt->color=aux_parent->color;
					aux_parent->color=0;
					sibling_pt->right->color=0;
					rbRotateLeft(&root,&aux_parent);
					aux=root;
				}
			}
			else{
				sibling_pt=aux_parent->left;
				if(sibling_pt->color==1){
					sibling_pt->color=0;
					rbRotateRight(&root,&aux_parent);
					sibling_pt=aux_parent->left;
				}
				if((sibling_pt->left==NULL || sibling_pt->left->color==0) && (sibling_pt->right==NULL || sibling_pt->right->color==0)){
					sibling_pt->color=1;
					aux=aux_parent;
					aux_parent=aux->parent;
				}
				else{
					if(sibling_pt->left==NULL || sibling_pt->left->color==0){
						sibling_pt->right->color=0;
						sibling_pt->color=1;
						rbRotateLeft(&root,&sibling_pt);
						sibling_pt=aux_parent->left;
					}
					sibling_pt->color=aux_parent->color;
					aux_parent->color=0;
					sibling_pt->left->color=0;
					rbRotateRight(&root,&aux_parent);
					aux=root;
				}
			}
		}
		aux->color=0;
		return root;
	}else{
		return NULL;
	}

}

// Melhorar o nome das váriaveis e comentar passo a passo desta função.
RBnode *rbRemove(RBnode *root,void *key,int(*cmp)(void*,void*)) //função para remover um nó da arvore rubro-negra
{
  int flag=0;
	RBnode *parent_y=NULL;
	RBnode *y=NULL;
	RBnode *x=NULL;
	RBnode *z=root;
	if(root==NULL) return NULL;

	while(z!=NULL){
		if((cmp(z->data,key))==0)
			break;
		else if((cmp(z->data,key))==-1)
			z=z->right;
		else
			z=z->left;
	}
	if(z==NULL)
		return root;

	if(z->left==NULL || z->right==NULL)
		y=z;
	else{
		RBnode *aux=z->left;
		while(aux->right!=NULL)
			aux=aux->right;
		y=aux;
	}

	if(y->left!=NULL)
		x=y->left;
	else if(y->right!=NULL)
		x=y->right;
	else{
		x=NULL; // remoção de folha
  }
	parent_y=y->parent; // guarda a referencia para o pai do nó a ser removido
	if(x!=NULL)
		x->parent=y->parent;

	if(y->parent==NULL)
		root=x;
	else if(y==y->parent->left)
		y->parent->left=x;
	else if(y==y->parent->right)
		y->parent->right=x;

	if(y!=z)
		z->data=y->data;
	if(y->color==0){
		if(x!=NULL){
			root=rbFixRemoval(root,x,x->parent);
		}
		else{ // folha foi removida
			root=rbFixRemoval(root,x,parent_y);
		}
	}
	free(y->data);
	free(y);
	return root;
}


void* rbSearch(RBnode *root,void *key,int(*cmp)(void*,void*))
{
	if(root==NULL)
		return NULL;
	else if(cmp(root->data,key)==1)
		return rbSearch(root->left,key,cmp);
	else if(cmp(root->data,key)==-1)
		return rbSearch(root->right,key,cmp);
	else
		return root->data;
}


void *rbGetMax(RBnode *root)
{
	RBnode *aux;
	aux=root;
	while(aux->right!=NULL)
		aux=aux->right;
	return aux->data;
}


void *rbGetMin(RBnode *root)
{
	RBnode *aux;
	aux=root;
	while(aux->left!=NULL)
		aux=aux->left;
	return aux->data;
}

RBnode *rbDeleteTree(RBnode *root,int(*cmp)(void*,void*))
{

	void *destroy;
	destroy=rbGetMin(root);
	while(root->left!=NULL){
		root=rbRemove(root,destroy,cmp);
		destroy=rbGetMin(root);
	}
	destroy=rbGetMax(root);
	while(root->right!=NULL){
		root=rbRemove(root,destroy,cmp);
		destroy=rbGetMax(root);
	}
	root=rbRemove(root,root->data,cmp);
	return root;
}

void rbSimetrica(RBnode *t,void(*visit)(void*))
{
	if(t!=NULL){
		rbSimetrica(t->left,visit);
                visit(t->data);
		rbSimetrica(t->right,visit);
	}
}
