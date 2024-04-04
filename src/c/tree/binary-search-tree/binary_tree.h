#ifndef BINARYTREE_H_INCLUDED

#define BINARYTREE_H_INCLUDED

typedef struct _tnode_ {
  void *data;
  struct _tnode_ *left, *right;
} TNode;
TNode *bstInsert(TNode *t, void *elm, int (*cmp)(void *, void *),
                 void *(*helpFunction)(void *), int *distincts);
TNode *bstRemove(TNode *t, void *elm, int (*cmp)(void *, void *));
void *bstSearch(TNode *t, void *key, int (*cmp)(void *, void *));
void bstTransverse(TNode *t, void (*visit)(void *));
TNode *bstDeleteTree(TNode *root, int (*cmp)(void *, void *));
TNode *bstGetMin(TNode *root);
TNode *bstGetMax(TNode *root);

#endif
