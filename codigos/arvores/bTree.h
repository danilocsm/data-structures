#ifndef BTREE_H_INCLUDED
  #define BINARYTREE_H_INCLUDED

  typedef struct _bnode_{
    int count;
    void **data;
    struct _bnode_ **links;
    int isLeaf;
    int minDeg;
  }Bnode;
  Bnode *bTreeCreateNode(int t);
  void bTreeSplitNode(Bnode **node,int pos,Bnode **child);
  void bTreeInsertNonFull(Bnode **node,void*elm,int(*cmp)(void*,void*));
  Bnode* bTreeInsert(Bnode *root,void *elm,int(*cmp)(void*,void*),void*(*helpFunction)(void*),int degree);

#endif
