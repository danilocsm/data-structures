#ifndef GCOL_H_INCLUDED
#define GCOL_H_INCLUDED

// void collection of items
typedef struct _gCol {
  int tam;
  int nelm;
  int curr;
  void **vet;
} gCol;

gCol *colCreate(int max);
int colDestroy(gCol *c);
int colInsert(gCol *c, void *key);
void *colGet(gCol *c);
void *colRemoveFirst(gCol *c);
void *colSearch(gCol *c, void *key, int (*compara)(void *, void *));
void *colRemove(gCol *c, void *key, int (*compara)(void *, void *));

#endif
