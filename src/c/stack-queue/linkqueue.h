#ifndef LINKQUEUE_C_INCLUDED
#define LINKQUEUE_C_INCLUDED

typedef struct slnode_ {
  void *data;
  struct slnode_ *next;
} SLNode;
typedef struct _linkedqueue {
  SLNode *first;
  SLNode *last;
} LQueue;

LQueue *lqCreate();
int lqDestroy(LQueue *lq);
int lqEnqueue(LQueue *lq, void *elm);
void *lqDequeue(LQueue *lq);

#endif // LINKQUEUE_C_INCLUDED
