#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct _Queue {
  int tam;
  int beg, end, nelm;
  void **vet;
} Queue;

Queue *qCreate(int max);
int qDestroy(Queue *q);
int qEnqueue(Queue *q, void *key);
void *qDequeue(Queue *q);

#endif
