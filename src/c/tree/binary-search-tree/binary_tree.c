#define BinaryTree_c
#include "binary_tree.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

TNode *bstInsert(TNode *t, void *elm, int (*cmp)(void *, void *),
                 void *(*helpFunction)(void *), int *distincts) {
  if (t == NULL) {
    t = (TNode *)malloc(sizeof(TNode));
    if (t != NULL) {
      t->data = elm;
      t->left = t->right = NULL;
    }
    (*distincts)++;
  } else if (cmp(t->data, elm) == 1)
    t->left = bstInsert(t->left, elm, cmp, helpFunction, distincts);
  else if (cmp(t->data, elm) == -1)
    t->right = bstInsert(t->right, elm, cmp, helpFunction, distincts);
  else {
    t->data = helpFunction((t->data));
    free(elm);
  }
  return t;
}

TNode *bstRemove(TNode *t, void *elm, int (*cmp)(void *, void *)) {
  TNode *aux;
  if (t == NULL) {
    return NULL;
  } else if (cmp(t->data, elm) == 1) {
    t->left = bstRemove(t->left, elm, cmp);
  } else if (cmp(t->data, elm) == -1) {
    t->right = bstRemove(t->right, elm, cmp);
  } else {
    if (t->right == NULL && t->left == NULL) {
      // free(t->data);
      free(t);
      t = NULL;
    } else if (t->right == NULL && t->left != NULL) {
      aux = t;
      t = t->left;
      // free(aux->data);
      free(aux);
    } else if (t->right != NULL && t->left == NULL) {
      aux = t;
      t = t->right;
      // free(aux->data);
      free(aux);
    } else if (t->right != NULL && t->left != NULL) {
      aux = t->left;
      while (aux->right != NULL)
        aux = aux->right;
      t->data = aux->data;
      aux->data = elm;
      t->left = bstRemove(t->left, elm, cmp);
    }
  }
  return t;
}

void *bstSearch(TNode *t, void *key, int (*cmp)(void *, void *)) {
  if (t == NULL)
    return NULL;
  else if (cmp(t->data, key) == 1)
    return bstSearch(t->left, key, cmp);
  else if (cmp(t->data, key) == -1)
    return bstSearch(t->right, key, cmp);
  else
    return t->data;
}

TNode *bstGetMax(TNode *root) {
  TNode *aux;
  aux = root;
  while (aux->right != NULL)
    aux = aux->right;
  return aux;
}

TNode *bstGetMin(TNode *root) {
  TNode *aux;
  aux = root;
  while (aux->left != NULL)
    aux = aux->left;
  return aux;
}

TNode *bstDeleteTree(TNode *root, int (*cmp)(void *, void *)) {
  TNode *destroy;
  while (root->left != NULL) {
    destroy = bstGetMin(root);
    root = bstRemove(root, destroy->data, cmp);
  }
  while (root->right != NULL) {
    destroy = bstGetMax(root);
    root = bstRemove(root, destroy->data, cmp);
  }
  root = bstRemove(root, root->data, cmp);
  return root;
}


void bstTransverse(TNode *t, void (*visit)(void *)) {
  if (t != NULL) {
    bstTransverse(t->left, visit);
    visit(t->data);
    bstTransverse(t->right, visit);
  }
}

