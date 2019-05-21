#ifndef AVL_BINARY_TREE_H_INCLUDED

  #define AVL_BINARY_TREE_H_INCLUDED
  // #ifdef btAVL_c
      typedef struct _avlnode_{
         void *data;
         int height;
         struct _avlnode_ *left,*right;
      }AVLNode;
      int max(int a,int b);
      AVLNode *avlCreateEmpty();
      AVLNode *avlInsert(AVLNode *t,void *elm,int(*cmp)(void*,void*),void*(*helpFunction)(void*),int *distincts);
      AVLNode *avlRemove(AVLNode *t,void *elm,int(*cmp)(void*,void*));
      void *avlSearch(AVLNode *t,void *key,int(*cmp)(void*,void*));
      int avlHeight(AVLNode *t);
      int getBalance(AVLNode *t);
      AVLNode *rotateRight(AVLNode *t);
      AVLNode *rotateLeft(AVLNode *t);
      AVLNode* avlGetMax(AVLNode *root);
      AVLNode* avlGetMin(AVLNode *root);
      AVLNode* avlDeleteTree(AVLNode *root,int(*cmp)(void*,void*));
      void Simetrica(AVLNode *t,void(*visit)(void*));
   /*#else
      typedef struct _avlnode_ AVLNode;
      extern int max(int a,int b);
      extern AVLNode *avlCreateEmpty();
      extern AVLNode *avlInsert(AVLNode *t,void *elm,int(*cmp)(void*,void*),void(*helpFunction)(void**));
      extern AVLNode *avlRemove(AVLNode *t,void *elm,int(*cmp)(void*,void*));
      extern int avlSearch(AVLNode *t,void *key,int(*cmp)(void*,void*));
      extern int avlHeight(AVLNode *t);
      extern int getBalance(AVLNode *t);
      extern AVLNode *rotateRight(AVLNode *t);
      extern AVLNode *rotateLeft(AVLNode *t);
      extern void Simetrica(AVLNode *t,void(*visit)(void*));*/
  // #endif
  #endif
