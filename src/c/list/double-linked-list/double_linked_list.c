#define dlinkedlist_c
#include "double_linked_list.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

DLList *dllCreate() {
  DLList *l;
  l = (DLList *)malloc(sizeof(DLList));
  if (l != NULL) {
    l->first = NULL;
    l->curr = NULL;
    return l;
  }
  return NULL;
}

int dllDestroy(DLList *l) {
  DLNode *curr, *destroy;
  if (l != NULL) {
    if (l->first == NULL) {
      free(l);
      return TRUE;
    } else {
      curr = l->first;
      while (curr != NULL) {
        destroy = curr;
        curr = curr->next;
        free(destroy->data);
        free(destroy);
      }
      free(l);
      return TRUE;
    }
  }
  return FALSE;
}

int dllInsertFirst(DLList *l, void *elm) {
  DLNode *new;
  if (l != NULL) {
    new = (DLNode *)malloc(sizeof(DLNode));
    if (new != NULL) {
      new->data = elm;
      new->prev = NULL;
      new->next = l->first;
      l->first = new;
      return TRUE;
    }
  }
  return FALSE;
}

int dllInsertLast(DLList *l, void *elm) {
  DLNode *new, *curr;
  if (l != NULL) {
    curr = l->first;
    new = (DLNode *)malloc(sizeof(DLNode));
    if (new != NULL) {
      if (curr != NULL) {
        while (curr->next != NULL)
          curr = curr->next;
        new->data = elm;
        new->next = NULL;
        new->prev = curr;
        curr->next = new;
        return TRUE;
      } else {
        dllInsertFirst(l, elm);
        return TRUE;
      }
    }
  }
  return FALSE;
}

int dllInsertKesimo(DLList *l, void *elm, int k) {
  DLNode *new, *atual;
  int i = 1;
  if (l != NULL) {
    new = (DLNode *)malloc(sizeof(DLNode));
    if (new != NULL) {
      atual = l->first;
      if (atual != NULL) {
        if (k == 1) {
          dllInsertFirst(l, elm);
          return TRUE;
        } else if (k > 1) {
          while (atual->next != NULL && i < k - 1) {
            atual = atual->next;
            i++;
          }
          new->data = elm;
          new->prev = atual;
          new->next = atual->next;
          if (atual->next != NULL) {
            atual->next->prev = new;
            atual->next = new;
          } else {
            atual->next = new;
          }
          return TRUE;
        }
      } else {
        dllInsertFirst(l, elm);
        return TRUE;
      }
    }
  }
  return FALSE;
}

int dllInsertAfterSpec(DLList *l, void *elm, void *key,
                       int (*cmp)(void *, void *)) {
  DLNode *new, *actual;
  int stat;
  if (l != NULL) {
    actual = l->first;
    if (actual != NULL) {
      new = (DLNode *)malloc(sizeof(DLNode));
      if (new != NULL) {
        stat = cmp(actual->data, key);
        while (actual->next != NULL && stat != TRUE) {
          actual = actual->next;
          stat = cmp(actual->data, key);
        }
        if (stat) {
          new->data = elm;
          new->prev = actual;
          new->next = actual->next;
          if (actual->next != NULL) {
            actual->next->prev = new;
          }
          actual->next = new;
          return TRUE;
        }
        free(new);
      }
    }
  }
  return FALSE;
}

int dllInsertBeforeSpec(DLList *l, void *elm, void *key,
                        int (*cmp)(void *, void *)) {
  DLNode *new, *actual;
  int stat;
  if (l != NULL) {
    actual = l->first;
    if (actual != NULL) {
      new = (DLNode *)malloc(sizeof(DLNode));
      if (new != NULL) {
        stat = cmp(actual->data, key);
        while (actual->next != NULL && stat != TRUE) {
          actual = actual->next;
          stat = cmp(actual->data, key);
        }
        if (stat) {
          new->data = elm;
          new->next = actual;
          actual->prev = new;
          if (actual->prev == NULL) {
            new->prev = NULL;
            l->first = new;
          } else {
            new->prev = actual->prev;
            actual->prev->next = new;
          }
          return TRUE;
        }
        free(new);
      }
    }
  }
  return FALSE;
}

void *dllRemoveFirst(DLList *l) {
  void *dados;
  DLNode *aux;
  if (l != NULL) {
    if (l->first != NULL) {
      dados = l->first->data;
      aux = l->first;
      l->first = aux->next;
      if (l->first != NULL)
        l->first->prev = NULL;
      free(aux);
      return dados;
    }
  }
  return NULL;
}

void *dllRemoveLast(DLList *l) {
  void *dados;
  DLNode *aux, *atual;
  if (l != NULL) {
    if (l->first != NULL) {
      atual = l->first;
      while (atual->next != NULL) {
        atual = atual->next;
      }
      dados = atual->data;
      aux = atual;
      if (atual->prev == NULL) {
        l->first = atual->next;
        free(aux);
        return dados;
      } else {
        atual->prev->next = NULL;
        free(aux);
        return dados;
      }
    }
  }
  return NULL;
}

void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *)) {
  void *dados;
  DLNode *aux, *actual;
  int stat;
  if (l != NULL) {
    if (l->first != NULL) {
      actual = l->first;
      stat = cmp(actual->data, key);
      while (actual->next != NULL && stat != TRUE) {
        actual = actual->next;
        stat = cmp(actual->data, key);
      }
      if (stat) {
        if (actual->prev == NULL) {
          dados = dllRemoveFirst(l);
          return dados;
        } else if (actual->next == NULL) {
          dados = dllRemoveLast(l);
          return dados;
        } else {
          actual->prev->next = actual->next;
          actual->next->prev = actual->prev;
          aux = actual;
          dados = aux->data;
          free(aux);
          return dados;
        }
      }
    }
  }
  return NULL;
}

void *dllRemoveKesimo(DLList *l, int k) {

  void *dados;
  int i = 1;
  DLNode *atual;
  if (l != NULL) {
    if (l->first != NULL) {
      atual = l->first;
      while (atual->next != NULL && i < k) {
        atual = atual->next;
        i++;
      }
      if (atual->prev == NULL) {
        dados = dllRemoveFirst(l);
        return dados;
      } else if (atual->next == NULL) {
        dados = dllRemoveLast(l);
        return dados;
      } else {
        dados = atual->data;
        atual->prev->next = atual->next;
        atual->next->prev = atual->prev;
        free(atual);
        return dados;
      }
    }
  }
  return NULL;
}

int dllSearch(DLList *l, void *key, int (*cmp)(void *, void *)) {
  DLNode *curr;
  int stat;
  if (l != NULL) {
    if (l->first != NULL) {
      curr = l->first;
      stat = cmp(curr->data, key);
      while (curr->next != NULL && stat != TRUE) {
        curr = curr->next;
        stat = cmp(curr->data, key);
      }
      if (stat) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

void *dllGetFirst(DLList *l) {
  if (l != NULL) {
    if (l->first != NULL) {
      l->curr = l->first;
      return l->curr->data;
    }
  }
  return NULL;
}

void *dllGetNext(DLList *l) {
  if (l != NULL) {
    if (l->first != NULL) {
      if (l->curr != NULL) {
        l->curr = l->curr->next;
        if (l->curr != NULL)
          return l->curr->data;
      }
    }
  }
  return NULL;
}

int dllContaNodes(DLList *l) {
  DLNode *curr;
  int cont = 0, erro = -1;
  if (l != NULL) {
    curr = l->first;
    while (curr != NULL) {
      curr = curr->next;
      cont++;
    }
    return cont;
  }
  return erro;
}

int dllRemovePares(DLList *l) {
  DLNode *curr, *destroy;
  int pair = 1;
  if (l != NULL) {
    if (l->first != NULL) {
      curr = l->first;
      while (curr != NULL) {
        if (pair % 2 == 0) {
          destroy = curr;
          destroy->prev->next = destroy->next;
          if (destroy->next != NULL)
            destroy->next->prev = destroy->prev;
          curr = curr->next;
          free(destroy);
        } else {
          curr = curr->next;
        }
        pair++;
      }
      return TRUE;
    }
  }
  return FALSE;
}

int dllInterlay(DLList *l1, DLList *l2) {
  DLNode *curr1, *curr2, *aux1, *aux2;
  int tam1, tam2;
  if (l1 != NULL && l2 != NULL) {
    tam1 = dllContaNodes(l1);
    tam2 = dllContaNodes(l2);
    if (tam1 > tam2 || tam1 == tam2) {
      curr1 = l1->first; // curr1 aponta pra lista que vai ser expandida
                         // enquanto curr2 aponta pra lista que
      curr2 = l2->first; // está doando os nodes
      l2->first = NULL;
    } else if (tam2 > tam1) {
      curr1 = l2->first;
      curr2 = l1->first;
      l1->first = NULL;
    }
    while (curr2 != NULL) {
      aux2 = curr2; // as auxiliares guardam o nodulo que vão sofrer
                    // modificações, pois ao mover o ponteiro curr
      aux1 =
          curr1; // se perderia as informações necessarias para inserir o node.
      curr1 = curr1->next;
      curr2 = curr2->next;
      aux2->prev = aux1;
      aux2->next = aux1->next;
      if (aux1->next != NULL)
        aux1->next->prev = aux2;
      aux1->next = aux2;
    }
    return TRUE;
  }
  return FALSE;
}

int dllCompList(DLList *l1, DLList *l2) {
  int tam1, tam2;
  if (l1 != NULL && l2 != NULL) {
    tam1 = dllContaNodes(l1);
    tam2 = dllContaNodes(l2);
    if (tam1 == tam2)
      return 0;
    else if (tam1 > tam2)
      return 1;
    else
      return -1;
  }
  return -2;
}

int dllMoveNode(DLList *l, void *key, int n, int (*cmp)(void *, void *)) {
  DLNode *curr, *move;
  int stat, i = 0;
  if (l != NULL) {
    if (l->first != NULL) {
      if (l->first->next != NULL) {
        curr = l->first;
        stat = cmp(curr->data, key);
        while (stat != TRUE && curr->next != NULL) {
          curr = curr->next;
          stat = cmp(curr->data, key);
        }
        if (stat && curr->next != NULL) {
          move = curr;
          if (curr->prev != NULL) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
          }
          while (i < n && curr->next != NULL) {
            curr = curr->next;
            i++;
          }
          if (i == n) {
            if (move == l->first) {
              l->first = move->next;
              l->first->prev = NULL;
            }
            move->prev = curr;
            move->next = curr->next;
            if (curr->next != NULL)
              curr->next->prev = move;
            curr->next = move;
            return TRUE;
          }
        }
      }
    }
  }
  return FALSE;
}

int dllBind(DLList *l1, DLList *l2) {
  DLNode *last;
  if (l1 != NULL && l2 != NULL) {
    if (l1->first != NULL && l2->first != NULL) {
      last = l1->first;
      while (last->next != NULL)
        last = last->next;
      last->next = l2->first;
      l2->first->prev = last;
      l2->first = NULL;
      return TRUE;
    }
  }
  return FALSE;
}

int dllReverse(DLList *l) {
  DLNode *curr, *last, *newfirst;
  if (l != NULL) {
    if (l->first != NULL) {
      if (l->first->next != NULL) {
        last = NULL;
        while (l->first->next != NULL) {
          curr = l->first;
          while (curr->next != last) {
            curr = curr->next;
          }
          if (last == NULL)
            newfirst = curr;
          curr->next = curr->prev;
          curr->prev = last;
          last = curr;
        }
        l->first = newfirst;
        return TRUE;
      }
    }
  }
  return FALSE;
}

int dllFix(DLList *l) {
  DLNode *curr;
  if (l != NULL) {
    if (l->first != NULL) {
      curr = l->first;
      while (curr != NULL) {
        if (curr->next == NULL)
          curr->prev = NULL;
        else {
          if (curr->next != NULL)
            curr->next->prev = curr;
        }
        curr = curr->next;
      }
      return TRUE;
    }
  }
  return FALSE;
}
