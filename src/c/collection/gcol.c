#define gcol_c
#include "gcol.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

gCol *colCreate(int max) {
  gCol *c;
  if (max > 0) {
    c = (gCol *)malloc(sizeof(gCol));
    if (c != NULL) {
      c->vet = (void **)malloc(sizeof(void *) * max);
      if (c->vet != NULL) {
        c->curr = -1;
        c->tam = max;
        c->nelm = 0;
        return c;
      }
    }
  }
  return NULL;
}
int colDestroy(gCol *c) {
  if (c != NULL) {
    if (c->vet != NULL) {
      if (c->nelm == 0) {
        free(c->vet);
        free(c);
        return TRUE; // Só para garantir que destruiu a coleção;
      }
    }
  }
  return FALSE;
}
int colInsert(gCol *c, void *key) {
  if (c != NULL) {
    if (c->vet != NULL) {
      if (c->nelm < c->tam) {
        c->vet[c->nelm] = key;
        c->nelm++;
        return TRUE;
      }
    }
  }
  return FALSE;
}
void *colSearch(gCol *c, void *key, int (*compara)(void *, void *)) {
  int i;
  if (c != NULL) {
    if (c->vet != NULL) {
      if (c->nelm > 0) {
        for (i = 0; i < c->nelm; i++) {
          if (compara(c->vet[i], key) == 1)
            return c->vet[i];
        }
      }
    }
  }
  return NULL;
}

void *colRemove(gCol *c, void *key, int (*compara)(void *, void *)) {
  void *aux;
  int i = 0;
  if (c != NULL) {
    if (c->nelm > 0) {
      while (compara(c->vet[i], key) != 1 && i < c->nelm - 1) {
        i++;
      }
      if (compara(c->vet[i], key) == 1) {
        aux = c->vet[i];
        for (int j = i; j < c->nelm - 1; j++) {
          c->vet[j] = c->vet[j + 1];
        }
        c->nelm--;
        return aux;
      }
    }
  }
  return NULL;
}

void *colGet(gCol *c) {
  if (c != NULL) {
    if (c->vet != NULL) {
      if (c->nelm > 0) {
        c->curr++;
        return c->vet[c->curr];
      }
    }
  }
  return NULL;
}
