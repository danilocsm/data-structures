#ifndef SIMPLELIST_H_INCLUDED
#define SIMPLELIST_H_INCLUDED
#define TRUE 1
#define FALSE 0
#ifdef SimpleList_c

typedef struct slnode_ {
  void *data;
  struct slnode_ *next;
} SLNode;

typedef struct sllist_ {
  SLNode *first;
  SLNode *curr;
} SLList;

SLList *sllCreate();
int sllDestroy(SLList *l);
int sllInsertFirst(SLList *l, void *elm);
int sllInsertLast(SLList *l, void *elm);
int sllInsertKesimo(SLList *l, void *elm, int k);
int sllInsertAfterSpec(SLList *l, void *elm, void *key,
                       int (*cmp)(void *, void *));
int sllInsertBeforeSpec(SLList *l, void *elm, void *key,
                        int (*cmp)(void *, void *));
void *sllRemoveFirst(SLList *l);
void *sllRemoveLast(SLList *l);
void *sllRemoveKesimo(SLList *l, int k);
void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *));
int sllSearch(SLList *l, void *key, int (*cmp)(void *, void *));
int contaNodes(SLList *l);
void *sllGetFirst(SLList *l);
void *sllGetNext(SLList *l);
int sllCompList(SLList *l1, SLList *l2);
SLList *sllComuns(SLList *l1, SLList *l2, int (*cmp)(void *, void *));
int sllReverse(SLList *l);
int sllMoveNode(SLList *l, void *key, int n, int (*cmp)(void *, void *));
int sllBind(SLList *l1, SLList *l2);
int sllRemoveImpar(SLList *l);
#else
typedef struct slnode_ SLNode;
typedef struct sllist_ SLList;
extern SLList *sllCreate();
extern int sllDestroy(SLList *l);
extern int sllInsertFirst(SLList *l, void *elm);
extern int sllInsertLast(SLList *l, void *elm);
extern int sllInsertKesimo(SLList *l, void *elm, int k);
extern int sllInsertAfterSpec(SLList *l, void *elm, void *key,
                              int (*cmp)(void *, void *));
extern int sllInsertBeforeSpec(SLList *l, void *elm, void *key,
                               int (*cmp)(void *, void *));
extern void *sllRemoveFirst(SLList *l);
extern void *sllRemoveLast(SLList *l);
extern void *sllRemoveKesimo(SLList *l, int k);
extern void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *));
extern int sllSearch(SLList *l, void *key, int (*cmp)(void *, void *));
extern int contaNodes(SLList *l);
extern void *sllGetFirst(SLList *l);
extern void *sllGetNext(SLList *l);
extern int sllCompList(SLList *l1, SLList *l2);
extern SLList *sllComuns(SLList *l1, SLList *l2, int (*cmp)(void *, void *));
extern int sllReverse(SLList *l);
extern int sllMoveNode(SLList *l, void *key, int n, int (*cmp)(void *, void *));
extern int sllBind(SLList *l1, SLList *l2);
extern int sllRemoveImpar(SLList *l);
#endif

#endif // SIMPLELIST_C_INCLUDED
