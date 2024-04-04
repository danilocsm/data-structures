#ifndef DLINKEDLIST_H_INCLUDED
#define DLINKEDLIST_H_INCLUDED
#define TRUE 1
#define FALSE 0

#ifdef dlinkedlist_c
typedef struct _dlnode_ {
  void *data;
  struct _dlnode_ *next, *prev;
} DLNode;

typedef struct _dllist_ {
  DLNode *first;
  DLNode *curr;
} DLList;
DLList *dllCreate();
int dllDestroy(DLList *l);
int dllInsertFirst(DLList *l, void *elm);
int dllInsertLast(DLList *l, void *elm);
int dllInsertAfterSpec(DLList *l, void *elm, void *key,
                       int (*cmp)(void *, void *));
int dllInsertBeforeSpec(DLList *l, void *elm, void *key,
                        int (*cmp)(void *, void *));
int dllInsertKesimo(DLList *l, void *elm, int k);
void *dllRemoveFirst(DLList *l);
void *dllRemoveLast(DLList *l);
void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *));
void *dllRemoveKesimo(DLList *l, int k);
int dllSearch(DLList *l, void *key, int (*cmp)(void *, void *));
void *dllGetFirst(DLList *l);
void *dllGetNext(DLList *l);
int dllContaNodes(DLList *l);
int dllInterlay(DLList *l1, DLList *l2);
int dllRemovePares(DLList *l);
int dllCompList(DLList *l1, DLList *l2);
int dllMoveNode(DLList *l, void *key, int n, int (*cmp)(void *, void *));
int dllBind(DLList *l1, DLList *l2);
int dllReverse(DLList *l);
int dllFix(DLList *l);
#else
typedef struct _dlnode_ DLNode;
typedef struct _dllist_ DLList;
extern DLList *dllCreate();
extern int dllDestroy(DLList *l);
extern int dllInsertFirst(DLList *l, void *elm);
extern int dllInsertLast(DLList *l, void *elm);
extern int dllInsertAfterSpec(DLList *l, void *elm, void *key,
                              int (*cmp)(void *, void *));
extern int dllInsertBeforeSpec(DLList *l, void *elm, void *key,
                               int (*cmp)(void *, void *));
extern int dllInsertKesimo(DLList *l, void *elm, int k);
extern void *dllRemoveFirst(DLList *l);
extern void *dllRemoveLast(DLList *l);
extern void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *));
extern void *dllRemoveKesimo(DLList *l, int k);
extern int dllSearch(DLList *l, void *key, int (*cmp)(void *, void *));
extern void *dllGetFirst(DLList *l);
extern void *dllGetNext(DLList *l);
extern int dllContaNodes(DLList *l);
extern int dllInterlay(DLList *l1, DLList *l2);
extern int dllRemovePares(DLList *l);
extern int dllCompList(DLList *l1, DLList *l2);
extern int dllMoveNode(DLList *l, void *key, int n, int (*cmp)(void *, void *));
extern int dllBind(DLList *l1, DLList *l2);
extern int dllReverse(DLList *l);
extern int dllFix(DLList *l);
#endif

#endif // DOUBLELIST_H_INCLUDED
