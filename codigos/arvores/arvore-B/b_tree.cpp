#define b_tree_c
#include "b_tree.h"
#include <stdlib.h>
#include <stdio.h>

void* bTreeSearch(Bnode *root,void *key,int(*cmp)(void*,void*))
{
  int i=0;
  while(i<root->count && (cmp(root->data[i],key))==-1)
    i++;
  if((cmp(root->data[i],key))==0)
    return root->data[i];
  if(root->isLeaf==1)
    return NULL;

  return bTreeSearch(root->links[i],key,cmp);
}

Bnode *bTreeCreateNode(int t)
{
  Bnode *new=NULL;
  new=(Bnode*)malloc(sizeof(Bnode));
  if(new!=NULL){
    new->count=0;
    new->data=(void**)malloc(sizeof(void*)*(2*t-1));
    if(new->data!=NULL){
      new->links=(Bnode**)malloc(sizeof(Bnode*)*(2*t));
      if(new->links!=NULL){
        for(int i=0;i<(2*t);i++) new->links[i]=NULL;
        new->isLeaf=1;
        new->minDeg=t;
        return new;
      }
      free(new->data);
    }
    free(new);
  }
  return NULL;
}

void bTreeSplitNode(Bnode **node,int pos,Bnode **child)
{
  Bnode *z;
  int t=(*child)->minDeg;
  z=bTreeCreateNode(t);
  z->count=t-1;
  for(int j=0;j<t-1;j++)
    z->data[j]=(*child)->data[j+t];
  if((*child)->isLeaf==0){
    for(int j=0;j<t;j++)
      z->links[j]=(*child)->links[j+t];
  }
  (*child)->count=t-1;
  for(int j=(*node)->count;j>=pos+1;j--)
    (*node)->links[j+1]=(*node)->links[j];
  (*node)->links[pos+1]=z;

  for(int j=(*node)->count-1;j>=pos;j--)
    (*node)->data[j+1]=(*node)->data[j];

  (*node)->data[pos]=(*child)->data[t-1];
  (*node)->count++;
}

void bTreeInsertNonFull(Bnode **node,void*elm,int(*cmp)(void*,void*))
{
  int i=((*node)->count)-1;
  if((*node)->isLeaf==1){
    while(i>=0 && (cmp((*node)->data[i],elm))==1){
      (*node)->data[i+1]=(*node)->data[i];
      i--;
    }
    (*node)->data[i+1]=elm;
    (*node)->count++;
  }
  else{
    while(i>=0 && (cmp((*node)->data[i],elm))==1){
      i--;
    }
    if((*node)->links[i+1]->count==((*node)->minDeg)*2-1){
      bTreeSplitNode(node,i+1,&((*node)->links[i+1]));
      if((cmp((*node)->data[i+1],elm))==-1)
        i++;
    }
    bTreeInsertNonFull(&(*node)->links[i+1],elm,cmp);
  }
}

Bnode* bTreeInsert(Bnode *root,void *elm,int(*cmp)(void*,void*),void*(*helpFunction)(void*),int degree)
{
  if(root==NULL){
    root=bTreeCreateNode(degree);
    if(root!=NULL){
      root->data[0]=elm;
      root->count=1;
    }
  }
  else{
    if(root->count<(2*degree-1)){
      bTreeInsertNonFull(&root,elm,cmp);
    }
    else{
      Bnode *newRoot;
      newRoot=bTreeCreateNode(degree);
      newRoot->links[0]=root;
      newRoot->isLeaf=0;
      bTreeSplitNode(&newRoot,0,&root);
      int i=0;
      if((cmp(newRoot->data[0],elm))==-1)
        i++;
      Bnode *aux=newRoot->links[i];
      bTreeInsertNonFull(&aux,elm,cmp);
      root=newRoot;
    }
  }
  return root;
}
/*
int bTreeFindKey(Bnode *root,void *elm,int(*cmp)(void*,void*))
{
  int id=0;
  while(id<root->count && (cmp(root->data,elm)==-1))
    ++id;
  return id;
}

Bnode* bTreeRemove(Bnode *root,void *elm,int(*cmp)(void*,void*))
{
  int id=bTreeFindKey(root,elm,cmp);
  if(id<root->count && (cmp(root->data[id],elm))==0){
    if(root->isLeaf==1)
      bTreeRemoveFromLeaf(&root,id);
    else
      bTreeRemoveFromNonLeaf(&root,id);
  }
  else{
    if(root->isLeaf==1){
      return root;
    }
    //int flag;

    if(root->links[id]->count < root->minDeg)
      bTreeFill(root,id,cmp);
    if(flag && id >root->count)
      root->links[id-1]=bTreeRemove(root->links[id-1],elm,cmp);
    else
      root->links[id]=bTreeRemove(root->links[id],elm,cmp);
  }
  return root;
}

void bTreeRemoveFromLeaf(Bnode **root,int id)
{
  for(int i=id+1;i<(*root)->count;i++)
    (*root)->data[i-1]=(*root)->data[i];

  (*root)->count--;
}

void bTreeRemoveFromNonLeaf(Bnode **root,int id,int(*cmp),(void*,void*))
{
  void* k=(*root)->data[id];
  if((*root)->links[id]->count>=(*root)->minDeg){
    void *pred=getPred(id);
    (*root)->data[id]=pred;
    (*root)->links[id]=bTreeRemove((*root)->links[id],pred,cmp)
  }
  else if((*root)->links[id+1]->count>=(*root)->minDeg){
    void succ=getSucc(id);
    (*root)->data[id]=succ;
    (*root)->links[id+1]=bTreeRemove((*root)->links[id+1],succ,cmp);
  }
  else{
    bTreeMerge(id);
    (*root)->links[id]=bTreeRemove((*root)->links[id],elm,cmp);
  }
}

void *getPred(Bnode *root,int id)
{
  Bnode *curr=root->links[id];
  while(!cur->isLeaf)
    cur=cur->links[cur->count];

  return cur->data[cur->count-1];
}

void *getSucc(Bnode *root,int id)
{
  Bnode *curr=root->links[id+1];
  while(!cur->isLeaf)
    cur=cur->links[0];

  return cur->data[0];
}

void bTreeFill(Bnode **root,int id)
{
  if(id!=0 && (*root)->links[id-1]->count>=(*root)->minDeg)
    borrowFromprev(&(*root),id);
  else if(id!=n && (*root)->links[id=1]->count>=(*root)->minDeg)
    borroFromNext(&(*root),id);
  else{
    if(id!=n)
      merge((*root),id);
    else
      merge((*root),id-1);
  }
}

void borrowFromPrev(Bnode **root,int id)
{

}
*/
