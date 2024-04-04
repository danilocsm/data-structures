#ifndef RED_BLACK_TREE_H_INCLUDED

#define RED_BLACK_TREE_H_INCLUDED
typedef struct _rbnode_ {
  void *data;
  int color;
  struct _rbnode_ *left, *right, *parent;
} RBnode;
RBnode *rbCreateNode(void *elm);
void rbRotateLeft(RBnode **root, RBnode **pt);
void rbRotateRight(RBnode **root, RBnode **pt);
RBnode *rbFixInsertion(RBnode *root, RBnode *pt);
RBnode *btInsert(RBnode *root, RBnode *pt, int (*cmp)(void *, void *),
                 void *(*helpFunction)(void *), int *flag);
RBnode *rbInsert(RBnode *root, void *elm, int (*cmp)(void *, void *),
                 void *(*helpFunction)(void *), int *distinct);
RBnode *rbFixRemoval(RBnode *root, RBnode *pt, RBnode *pt_parent);
RBnode *rbRemove(RBnode *root, void *key, int (*cmp)(void *, void *));
RBnode *rbDeleteTree(RBnode *root, int (*cmp)(void *, void *));
void *rbGetMax(RBnode *root);
void *rbGetMin(RBnode *root);
void rbTransverse(RBnode *t, void (*visit)(void *));
void *rbSearch(RBnode *root, void *key, int (*cmp)(void *, void *));
/*#else
   typedef struct _rbnode_ RBnode;
   extern RBnode *rbCreateNode(void *elm);
   extern void rbRotateLeft(RBnode **root,RBnode **pt);
   extern void rbRotateRight(RBnode **root,RBnode **pt);
   extern RBnode *rbFixInsertion(RBnode *root,RBnode *pt);
   extern RBnode *bstInsert(RBnode *root,RBnode
*pt,int(*cmp)(void*,void*),void(*helpFunction)(void**)); extern RBnode *
rbInsert(RBnode *root,void
*elm,int(*cmp)(void*,void*),void(*helpFunction)(void**)); extern RBnode
*rbFixRemoval(RBnode *root,RBnode *pt,RBnode *pt_parent); extern RBnode
*rbRemove(RBnode *root,void *key,int(*cmp)(void*,void*)); extern int
rbSearch(RBnode *t,void *key,int(*cmp)(void*,void*)); extern int rbAltura(RBnode
*t); extern void rbTransverse(RBnode *t,void(*visit)(void*,int)); #endif*/
#endif
